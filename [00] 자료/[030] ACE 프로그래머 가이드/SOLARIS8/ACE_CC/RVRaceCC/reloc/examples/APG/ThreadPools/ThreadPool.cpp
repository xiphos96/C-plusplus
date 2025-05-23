#include "ace/Task.h"
#include "ace/Containers.h"
#include "ace/Synch.h"
#include "ace/SString.h"
#include "ace/Method_Request.h"
#include "ace/Future.h"
#include "ace/Activation_Queue.h"

class Worker;

class IManager
{
public:
  virtual int return_to_work (Worker *worker) = 0;
};

// Listing 2 code/ch16
class Worker : public ACE_Task<ACE_MT_SYNCH>
{
public:
  Worker (IManager *manager) : manager_(manager)
  { }

  virtual int svc (void)
  {
    thread_id_ = ACE_Thread::self ();
    while (1)
      {
        ACE_Message_Block *mb = NULL;
        ACE_ASSERT (this->getq (mb) != -1);
        if (mb->msg_type () == ACE_Message_Block::MB_HANGUP)
          {
            ACE_DEBUG ((LM_INFO,
                        ACE_TEXT ("(%t) Shutting down\n")));
            break;
          }

        // Process the message.
        process_message (mb);

        // Return to work.
        this->manager_->return_to_work (this);
      }

    return 0;
  }

  // Listing 2
  ACE_thread_t thread_id (void)
  {
    return thread_id_;
  }

private:
  void process_message (ACE_Message_Block *mb)
  {
    ACE_TRACE (ACE_TEXT ("Worker::process_message"));
    int msgId;
    ACE_OS::memcpy (&msgId, mb->rd_ptr (), sizeof(int));
    mb->release ();

    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%t) Started processing message %d\n"),
                msgId));
    ACE_OS::sleep (3);
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%t) Finished processing message %d\n"),
                msgId));
  }

  IManager *manager_;
  ACE_thread_t thread_id_;
};

// Listing 1 code/ch16
class Manager: public ACE_Task<ACE_MT_SYNCH>, IManager
{
public:
  enum {POOL_SIZE = 5, MAX_TIMEOUT = 5};

  Manager ()
    : shutdown_(0), workers_lock_(), workers_cond_(workers_lock_)
  {
    ACE_TRACE (ACE_TEXT ("Manager::Manager"));
  }

  int svc (void)
  {
    ACE_TRACE (ACE_TEXT ("Manager::svc"));

    ACE_DEBUG ((LM_INFO, ACE_TEXT ("(%t) Manager started\n")));

    // Create pool.
    create_worker_pool ();

    while (!done ())
      {
        ACE_Message_Block *mb = NULL;
        ACE_Time_Value tv ((long)MAX_TIMEOUT);
        tv += ACE_OS::time (0);
          
        // Get a message request.
        if (this->getq (mb, &tv) < 0)
          {
            shut_down ();
            break;
          }

        // Choose a worker.
        Worker *worker;
        {
          ACE_GUARD_RETURN (ACE_Thread_Mutex,
                            worker_mon, this->workers_lock_, -1);

          while (this->workers_.is_empty ())
            workers_cond_.wait ();

          this->workers_.dequeue_head (worker);
        }

        // Ask the worker to do the job.
        worker->putq (mb);
      }

    return 0;
  }

  int shut_down (void);

  int thread_id (Worker *worker);

  virtual int return_to_work (Worker *worker)
  {
    ACE_GUARD_RETURN (ACE_Thread_Mutex,
                      worker_mon, this->workers_lock_, -1);
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%t) Worker %d returning to work.\n"),
                worker->thr_mgr ()->thr_self ()));
    this->workers_.enqueue_tail (worker);
    this->workers_cond_.signal ();

    return 0;
  }

private:
  int create_worker_pool (void)
  {
    ACE_GUARD_RETURN (ACE_Thread_Mutex,
                      worker_mon,
                      this->workers_lock_,
                      -1);
    for (int i = 0; i < POOL_SIZE; i++)
      {
        Worker *worker;
        ACE_NEW_RETURN (worker, Worker (this), -1);
        this->workers_.enqueue_tail (worker);
        worker->activate ();
      }

    return 0;
  }

  int done (void);

private:
  int shutdown_;
  ACE_Thread_Mutex workers_lock_;
  ACE_Condition<ACE_Thread_Mutex> workers_cond_;
  ACE_Unbounded_Queue<Worker* > workers_;
};
// Listing 1

int Manager::done (void)
{
  return (shutdown_ == 1);
}

int
Manager::shut_down (void)
{
  ACE_TRACE (ACE_TEXT ("Manager::shut_down"));
  ACE_Unbounded_Queue<Worker* >::ITERATOR iter =
    this->workers_.begin ();
  Worker **worker_ptr = NULL;
  do
    {
      iter.next (worker_ptr);
      Worker *worker = (*worker_ptr);
      ACE_DEBUG ((LM_DEBUG,
                 ACE_TEXT ("(%t) Attempting shutdown of %d\n"),
                 thread_id (worker)));

      // Send the hangup message.
      ACE_Message_Block *mb;
      ACE_NEW_RETURN
        (mb,
         ACE_Message_Block(0,
                           ACE_Message_Block::MB_HANGUP),
         -1);
      worker->putq (mb);

      // Wait for the exit.
      worker->wait ();

      ACE_ASSERT (worker->msg_queue ()->is_empty ());
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("(%t) Worker %d shut down.\n)"),
                  thread_id (worker)));
      delete worker;
    }
  while (iter.advance ());

  shutdown_ = 1;

  return 0;
}

int
Manager::thread_id (Worker *worker)
{
  return worker->thread_id ();
}


int ACE_TMAIN (int, ACE_TCHAR *[])
{
  Manager tp;
  tp.activate ();

  // Wait for a moment every time you send a message.
  ACE_Time_Value tv;
  tv.msec (100);

  ACE_Message_Block *mb;
  for (int i = 0; i < 30; i++)
    {
      ACE_NEW_RETURN
        (mb, ACE_Message_Block(sizeof(int)), -1);

      ACE_OS::memcpy (mb->wr_ptr (), &i, sizeof(int));

      ACE_OS::sleep (tv);

      // Add a new work item.
      tp.putq (mb);
    }

  ACE_Thread_Manager::instance ()->wait ();
  return 0;
}
