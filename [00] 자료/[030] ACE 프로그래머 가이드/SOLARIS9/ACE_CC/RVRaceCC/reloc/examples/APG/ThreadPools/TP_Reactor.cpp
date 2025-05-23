// == == == == == == == == == == == == == == == == == == == == == == ==
// Stolen from $ACE_ROOT/tests/Thread_Pool_Reactor_Test.cpp
// Thread_Pool_Reactor_Test.cpp, v 1.29 2001/03/20 01:07:21 irfan Exp
// = AUTHOR
//      Irfan Pyarali <irfan@cs.wustl.edu> and
//      Nanbor Wang <nanbor@cs.wustl.edu>
// == == == == == == == == == == == == == == == == == == == == == == ==
#include "ace/Svc_Handler.h"
#include "ace/SOCK_Connector.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Acceptor.h"
#include "ace/Thread_Manager.h"
#include "ace/TP_Reactor.h"


// Accepting end point.  This is actually "localhost:10010", but some
// platform couldn't resolve the name so we use the IP address
// directly here.
static const ACE_TCHAR *rendezvous = ACE_TEXT ("127.0.0.1:10010");

// Total number of server threads.
static size_t svr_thrno = 5;

// Total number of client threads.
static size_t cli_runs = 2;

// Total connection attemps of a client thread.
static size_t cli_conn_no = 2;

// Total requests a client thread sends.
static size_t cli_req_no = 5;

// Delay before a thread sending the next request (in msec.)
static int req_delay = 50;


class Request_Handler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH>
  {
    // = TITLE
    //   This class is the Svc_Handler used by <Acceptor>.
  public:
    Request_Handler (ACE_Thread_Manager *tm = 0);
    // The default constructor makes sure the right reactor is used.

  protected:
    virtual int handle_input (ACE_HANDLE fd = ACE_INVALID_HANDLE);
    virtual int handle_close (ACE_HANDLE fd, ACE_Reactor_Mask = 0);

  private:
    size_t  nr_msgs_rcvd_;
  };

typedef ACE_Strategy_Acceptor <Request_Handler, ACE_SOCK_ACCEPTOR> ACCEPTOR;


Request_Handler::Request_Handler (ACE_Thread_Manager *thr_mgr)
    : ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH> (thr_mgr),
    nr_msgs_rcvd_(0)
{
  this->reactor (ACE_Reactor::instance ());
}

int
Request_Handler::handle_input (ACE_HANDLE fd)
{
  ACE_TCHAR buffer[BUFSIZ];
  ACE_TCHAR len = 0;
  ssize_t result = this->peer ().recv (&len, sizeof (ACE_TCHAR));

  if (result > 0
      && this->peer ().recv_n (buffer, len * sizeof (ACE_TCHAR))
      == ACE_static_cast (ssize_t, len * sizeof (ACE_TCHAR)))
    {
      ++this->nr_msgs_rcvd_;

      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("(%t) svr input; fd: 0x%x; input: %s\n"),
                  fd,
                  buffer));
      if (ACE_OS::strcmp (buffer, ACE_TEXT ("shutdown")) == 0)
        ACE_Reactor::end_event_loop ();
      return 0;
    }
  else
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%t) Request_Handler: 0x%x peer closed (0x%x)\n"),
                this, fd));
  return -1;
}

int
Request_Handler::handle_close (ACE_HANDLE fd, ACE_Reactor_Mask)
{
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("(%t) svr close; fd: 0x%x, rcvd %d msgs\n"),
              fd,
              this->nr_msgs_rcvd_));
  
  if (this->nr_msgs_rcvd_ != cli_req_no)
    ACE_ERROR((LM_ERROR,
               ACE_TEXT ("(%t) Handler 0x%x: Expected %d messages; got %d\n"),
               this,
               cli_req_no,
               this->nr_msgs_rcvd_));
  
  this->destroy ();
  return 0;
}

// Listing 2 code/ch16
static int
reactor_event_hook (ACE_Reactor *)
{
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("(%t) handling events ....\n")));

  return 0;
}

class ServerTP : public ACE_Task_Base
{
public:
  virtual int svc (void)
  {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%t) Running the event loop\n")));

    int result =
      ACE_Reactor::instance ()->run_reactor_event_loop
        (&reactor_event_hook);

    if (result == -1)
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("(%t) %p\n"),
                         ACE_TEXT ("Error handling events")),
                        0);

    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%t) Done handling events.\n")));

    return 0;
  }
};
// Listing 2

class Client: public ACE_Task_Base
  {
  public:
    Client()
        :addr_(rendezvous)
    {}

    virtual int svc()
    {
      ACE_OS::sleep (3);
      const ACE_TCHAR *msg =
        ACE_TEXT ("Message from Connection worker");
      
      ACE_TCHAR buf [BUFSIZ];
      buf[0] = ACE_OS::strlen (msg) + 1;
      ACE_OS::strcpy (&buf[1], msg);

      for (size_t i = 0; i < cli_runs; i++)
        send_work_to_server(buf);

      shut_down();

      return 0;
    }

  private:
    void send_work_to_server(ACE_TCHAR* arg)
    {
      ACE_SOCK_Stream stream;
      ACE_SOCK_Connector connect;
      ACE_Time_Value delay (0, req_delay);
      size_t len = * ACE_reinterpret_cast (ACE_TCHAR *, arg);

      for (size_t i = 0 ; i < cli_conn_no; i++)
        {
          if (connect.connect (stream, addr_) < 0)
            {
              ACE_ERROR ((LM_ERROR,
                          ACE_TEXT ("(%t) %p\n"),
                          ACE_TEXT ("connect")));
              continue;
            }

          for (size_t j = 0; j < cli_req_no; j++)
            {
              ACE_DEBUG ((LM_DEBUG,
                          ACE_TEXT ("Sending work to server on handle 0x%x, req %d\n"),
                          stream.get_handle (),
                          j+1));
              if (stream.send_n (arg,
                                 (len + 1) * sizeof (ACE_TCHAR)) == -1)
                {
                  ACE_ERROR ((LM_ERROR,
                              ACE_TEXT ("(%t) %p\n"),
                              ACE_TEXT ("send_n")));
                  continue;
                }
              ACE_OS::sleep (delay);
            }

          stream.close ();
        }

    }

    void shut_down()
    {
      ACE_SOCK_Stream stream;
      ACE_SOCK_Connector connect;

      if (connect.connect (stream, addr_) == -1)
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("(%t) %p Error while connecting\n"),
                    ACE_TEXT ("connect")));

      const ACE_TCHAR *sbuf = ACE_TEXT ("\011shutdown");

      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("shutdown stream handle = %x\n"),
                  stream.get_handle ()));

      if (stream.send_n (sbuf, (ACE_OS::strlen (sbuf) + 1) * sizeof (ACE_TCHAR)) == -1)
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("(%t) %p\n"),
                    ACE_TEXT ("send_n")));

      stream.close ();
    }
  private:
    ACE_INET_Addr addr_;
  };
// Listing 1 code/ch16
int ACE_TMAIN (int, ACE_TCHAR *[])
{
  ACE_TP_Reactor sr;
  ACE_Reactor new_reactor (&sr);
  ACE_Reactor::instance (&new_reactor);

  ACCEPTOR acceptor;
  ACE_INET_Addr accept_addr (rendezvous);

  if (acceptor.open (accept_addr) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("open")),
                      1);

  ACE_DEBUG ((LM_DEBUG,
             ACE_TEXT ("(%t) Spawning %d server threads...\n"),
             svr_thrno));

  ServerTP serverTP;
  serverTP.activate (THR_NEW_LWP | THR_JOINABLE, svr_thrno);

  Client client;
  client.activate ();

  ACE_Thread_Manager::instance ()->wait ();

  return 0;
}
// Listing 1
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Accept_Strategy<Request_Handler, ACE_SOCK_ACCEPTOR>;
template class ACE_Concurrency_Strategy<Request_Handler>;
template class ACE_Creation_Strategy<Request_Handler>;
template class ACE_Scheduling_Strategy<Request_Handler>;
template class ACE_Acceptor<Request_Handler, ACE_SOCK_ACCEPTOR>;
template class ACE_Strategy_Acceptor<Request_Handler, ACE_SOCK_ACCEPTOR>;
template class ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate  ACE_Accept_Strategy<Request_Handler, ACE_SOCK_ACCEPTOR>
#pragma instantiate  ACE_Concurrency_Strategy<Request_Handler>
#pragma instantiate  ACE_Creation_Strategy<Request_Handler>
#pragma instantiate  ACE_Scheduling_Strategy<Request_Handler>
#pragma instantiate  ACE_Acceptor<Request_Handler, ACE_SOCK_ACCEPTOR>
#pragma instantiate  ACE_Strategy_Acceptor<Request_Handler, ACE_SOCK_ACCEPTOR>
#pragma instantiate  ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
