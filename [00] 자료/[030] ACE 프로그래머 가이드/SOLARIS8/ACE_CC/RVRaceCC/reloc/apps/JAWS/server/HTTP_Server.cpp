// HTTP_Server.cpp,v 1.41 2001/12/26 15:46:24 schmidt Exp

#define ACE_BUILD_SVC_DLL

#include "ace/Get_Opt.h"
#include "ace/Asynch_Acceptor.h"
#include "ace/LOCK_SOCK_Acceptor.h"
#include "ace/Proactor.h"

#include "IO.h"
#include "HTTP_Server.h"

ACE_RCSID(server, HTTP_Server, "HTTP_Server.cpp,v 1.41 2001/12/26 15:46:24 schmidt Exp")

// class is overkill
class JAWS
{
public:
  enum
  {
    POOL = 0,
    PER_REQUEST = 1
  };

  enum
  {
    SYNCH = 0,
    ASYNCH = 2
  };
};

void
HTTP_Server::parse_args (int argc,
			 char *argv[])
{
  int c;
  int thr_strategy = 0;
  int io_strategy = 0;
  const char *prog = argc > 0 ? argv[0] : "HTTP_Server";

  // Set some defaults
  this->port_ = 0;
  this->threads_ = 0;
  this->backlog_ = 0;
  this->throttle_ = 0;

  ACE_Get_Opt get_opt (argc, argv, "p:n:t:i:b:");

  while ((c = get_opt ()) != -1)
    switch (c)
      {
      case 'p':
	this->port_ = ACE_OS::atoi (get_opt.opt_arg ());
	break;
      case 'n':
	this->threads_ = ACE_OS::atoi (get_opt.opt_arg ());
	break;
      case 't':
	// POOL        -> thread pool
	// PER_REQUEST -> thread per request
	// THROTTLE    -> thread per request with throttling
        if (ACE_OS::strcmp (get_opt.opt_arg (), "POOL") == 0)
          thr_strategy = JAWS::POOL;
        else if (ACE_OS::strcmp (get_opt.opt_arg (), "PER_REQUEST") == 0)
          {
            thr_strategy = JAWS::PER_REQUEST;
            this->throttle_ = 0;
          }
        else if (ACE_OS::strcmp (get_opt.opt_arg (), "THROTTLE") == 0)
          {
            thr_strategy = JAWS::PER_REQUEST;
            this->throttle_ = 1;
          }
	break;
      case 'f':
        if (ACE_OS::strcmp (get_opt.opt_arg (), "THR_BOUND") == 0)
          {
            // What happened here?
          }
        else if (ACE_OS::strcmp (get_opt.opt_arg (), "THR_DAEMON") == 0)
          {
          }
        else if (ACE_OS::strcmp (get_opt.opt_arg (), "THR_DETACHED") == 0)
          {
          }
      case 'i':
	// SYNCH  -> synchronous I/O
	// ASYNCH -> asynchronous I/O
        if (ACE_OS::strcmp (get_opt.opt_arg (), "SYNCH") == 0)
          io_strategy = JAWS::SYNCH;
        else if (ACE_OS::strcmp (get_opt.opt_arg (), "ASYNCH") == 0)
          io_strategy = JAWS::ASYNCH;
	break;
      case 'b':
	this->backlog_ = ACE_OS::atoi (get_opt.opt_arg ());
	break;
      default:
	break;
      }

  // No magic numbers.
  if (this->port_ <= 0)
    this->port_ = 5432;
  if (this->threads_ <= 0)
    this->threads_ = 5;
  // Don't use number of threads as default
  if (this->backlog_ <= 0)
    this->backlog_ = this->threads_;

  this->strategy_ = thr_strategy | io_strategy;

  ACE_UNUSED_ARG (prog);
  ACE_DEBUG ((LM_DEBUG,
              "in HTTP_Server::init, %s port = %d, number of threads = %d\n",
              prog, this->port_, this->threads_));
}

int
HTTP_Server::init (int argc, char *argv[])
  // Document this function
{
  // Ignore signals generated when a connection is broken unexpectedly.
  ACE_Sig_Action sig ((ACE_SignalHandler) SIG_IGN, SIGPIPE);
  ACE_UNUSED_ARG (sig);

  // Parse arguments which sets the initial state.
  this->parse_args (argc, argv);

  // Choose what concurrency strategy to run.
  switch (this->strategy_)
    {
    case (JAWS::POOL | JAWS::ASYNCH) :
      return this->asynch_thread_pool ();

    case (JAWS::PER_REQUEST | JAWS::SYNCH) :
      return this->thread_per_request ();

    case (JAWS::POOL | JAWS::SYNCH) :
    default:
      return this->synch_thread_pool ();
    }

  ACE_NOTREACHED (return 0);
}

int
HTTP_Server::fini (void)
{
  this->tm_.close ();
  return 0;
}


int
HTTP_Server::synch_thread_pool (void)
{
  // Main thread opens the acceptor
  if (this->acceptor_.open (ACE_INET_Addr (this->port_), 1,
                            PF_INET, this->backlog_) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "HTTP_Acceptor::open"), -1);

  // Create a pool of threads to handle incoming connections.
  Synch_Thread_Pool_Task t (this->acceptor_, this->tm_, this->threads_);

  this->tm_.wait ();
  return 0;
}

Synch_Thread_Pool_Task::Synch_Thread_Pool_Task (HTTP_Acceptor &acceptor,
                                                ACE_Thread_Manager &tm,
                                                int threads)
  : ACE_Task<ACE_NULL_SYNCH> (&tm),
    acceptor_ (acceptor)
{
  if (this->activate (THR_DETACHED | THR_NEW_LWP, threads) == -1)
    ACE_ERROR ((LM_ERROR, "%p\n", "Synch_Thread_Pool_Task::open"));
}

int
Synch_Thread_Pool_Task::svc (void)
{
  // Creates a factory of HTTP_Handlers binding to synchronous I/O strategy
  Synch_HTTP_Handler_Factory factory;

  for (;;)
    {
      ACE_SOCK_Stream stream;

      // Lock in this accept.  When it returns, we have a connection.
      if (this->acceptor_.accept (stream) == -1)
	ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "HTTP_Acceptor::accept"), -1);

      ACE_Message_Block *mb;
      ACE_NEW_RETURN (mb,
                      ACE_Message_Block (HTTP_Handler::MAX_REQUEST_SIZE + 1),
                      -1);

      // Create an HTTP Handler to handle this request
      HTTP_Handler *handler = factory.create_http_handler ();
      handler->open (stream.get_handle (), *mb);
      // Handler is destroyed when the I/O puts the Handler into the
      // done state.

      mb->release ();
      ACE_DEBUG ((LM_DEBUG,
                  " (%t) in Synch_Thread_Pool_Task::svc, recycling\n"));
    }

  ACE_NOTREACHED(return 0);
}

int
HTTP_Server::thread_per_request (void)
{
  int grp_id = -1;

  // thread per request
  // Main thread opens the acceptor
  if (this->acceptor_.open (ACE_INET_Addr (this->port_), 1,
                            PF_INET, this->backlog_) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "HTTP_Acceptor::open"), -1);

  ACE_SOCK_Stream stream;

  // When we are throttling, this is the amount of time to wait before
  // checking for runnability again.
  const ACE_Time_Value wait_time (0, 10);

  for (;;)
    {
      if (this->acceptor_.accept (stream) == -1)
	ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "HTTP_Acceptor::accept"), -1);

      Thread_Per_Request_Task *t;
      // Pass grp_id as a constructor param instead of into open.
      ACE_NEW_RETURN (t, Thread_Per_Request_Task (stream.get_handle (),
                                                  this->tm_,
                                                  grp_id),
                      -1);


      if (t->open () != 0)
	ACE_ERROR_RETURN ((LM_ERROR,
                           "%p\n", "Thread_Per_Request_Task::open"),
                          -1);

      // Throttling is not allowing too many threads to run away.
      // Should really use some sort of condition variable here.
      if (!this->throttle_)
	continue;

      // This works because each task has only one thread.
      while (this->tm_.num_tasks_in_group (grp_id) > this->threads_)
	this->tm_.wait (&wait_time);
    }

  ACE_NOTREACHED(return 0);
}

Thread_Per_Request_Task::Thread_Per_Request_Task (ACE_HANDLE handle,
						  ACE_Thread_Manager &tm,
                                                  int &grp_id)
  : ACE_Task<ACE_NULL_SYNCH> (&tm),
    handle_ (handle),
    grp_id_ (grp_id)
{
}


// HEY!  Add a method to the thread_manager to return total number of
// threads managed in all the tasks.

int
Thread_Per_Request_Task::open (void *)
{
  int status = -1;

  if (this->grp_id_ == -1)
    status = this->grp_id_ = this->activate (THR_DETACHED | THR_NEW_LWP);
  else
    status = this->activate (THR_DETACHED | THR_NEW_LWP,
                             1, 0, -1, this->grp_id_, 0);

  if (status == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "Thread_Per_Request_Task::open"),
                      -1);
  return 0;
}

int
Thread_Per_Request_Task::svc (void)
{
  ACE_Message_Block *mb;
  ACE_NEW_RETURN (mb, ACE_Message_Block (HTTP_Handler::MAX_REQUEST_SIZE + 1),
                  -1);
  Synch_HTTP_Handler_Factory factory;
  HTTP_Handler *handler = factory.create_http_handler ();
  handler->open (this->handle_, *mb);
  mb->release ();
  return 0;
}

int
Thread_Per_Request_Task::close (u_long)
{
  ACE_DEBUG ((LM_DEBUG,
	      " (%t) Thread_Per_Request_Task::svc, dying\n"));
  delete this;
  return 0;
}

// Understanding the code below requires understanding of the
// WindowsNT asynchronous completion notification mechanism and the
// Proactor Pattern.

// (1) The application submits an asynchronous I/O request to the
//     operating system and a special handle with it (Asynchronous
//     Completion Token).
// (2) The operating system commits to performing the I/O request,
//     while application does its own thing.
// (3) Operating system finishes the I/O request and places ACT onto
//     the I/O Completion Port, which is a queue of finished
//     asynchronous requests.
// (4) The application eventually checks to see if the I/O request
//     is done by checking the I/O Completion Port, and retrieves the
//     ACT.

int
HTTP_Server::asynch_thread_pool (void)
{
// This only works on Win32
#if defined (ACE_WIN32)
  // Create the appropriate acceptor for this concurrency strategy and
  // an appropriate handler for this I/O strategy
  ACE_Asynch_Acceptor<Asynch_HTTP_Handler_Factory> acceptor;

  // Tell the acceptor to listen on this->port_, which makes an
  // asynchronous I/O request to the OS.
  if (acceptor.open (ACE_INET_Addr (this->port_),
		     HTTP_Handler::MAX_REQUEST_SIZE + 1) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n",
                       "ACE_Asynch_Acceptor::open"), -1);

  // Create the thread pool.
  // Register threads with the proactor and thread manager.
  Asynch_Thread_Pool_Task t (*ACE_Proactor::instance (),
                             this->tm_);

  // The proactor threads are waiting on the I/O Completion Port.

  // Wait for the threads to finish.
  return this->tm_.wait ();
#endif /* ACE_WIN32 */
  return -1;
}

// This only works on Win32
#if defined (ACE_WIN32)

Asynch_Thread_Pool_Task::Asynch_Thread_Pool_Task (ACE_Proactor &proactor,
                                                  ACE_Thread_Manager &tm)
  : ACE_Task<ACE_NULL_SYNCH> (&tm),
    proactor_ (proactor)
{
  if (this->activate () == -1)
    ACE_ERROR ((LM_ERROR, "%p\n", "Asynch_Thread_Pool_Task::open"));
}

int
Asynch_Thread_Pool_Task::svc (void)
{
  for (;;)
    if (this->proactor_.handle_events () == -1)
      ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "ACE_Proactor::handle_events"),
                        -1);

  return 0;
}

#endif /* ACE_WIN32 */

// Define the factory function.
ACE_SVC_FACTORY_DEFINE (HTTP_Server)

// Define the object that describes the service.
ACE_STATIC_SVC_DEFINE (HTTP_Server, "HTTP_Server", ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (HTTP_Server),
                       ACE_Service_Type::DELETE_THIS
                       | ACE_Service_Type::DELETE_OBJ, 0)

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_LOCK_SOCK_Acceptor<ACE_SYNCH_MUTEX>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_LOCK_SOCK_Acceptor<ACE_SYNCH_MUTEX>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
