#include "ace/Task.h"
#include "ace/SOCK_Stream.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Acceptor.h"

// Listing 1  code/ch12
struct DeviceCommandHeader
{
  int length_;
  int deviceId_;
};
// Listing 1

class HA_Device_Repository
{
public:
  HA_Device_Repository ();

  int update_device (int device_id, char *commands);
    
private:
  ACE_Task_Base *owner_;
};

HA_Device_Repository::HA_Device_Repository ()
{ }

int
HA_Device_Repository::update_device (int, char *)
{
  return 0;
}

class HA_CommandHandler : public ACE_Task<ACE_MT_SYNCH>
{
public:
  HA_CommandHandler (HA_Device_Repository &rep) : rep_(rep)
  { }

  virtual int svc();

private:
  HA_Device_Repository &rep_;
};

// Listing 5 code/ch12
int 
HA_CommandHandler::svc (void)
{
  while(1)
    {
      ACE_Message_Block *mb;
      ACE_ASSERT (this->getq (mb) != -1);
      if (mb->msg_type () == ACE_Message_Block::MB_HANGUP)
        {
          mb->release ();
          break;
        }
      else
        {
          // Get header pointer, then move past header to payload.
          DeviceCommandHeader *dch
            = (DeviceCommandHeader*)mb->rd_ptr ();
          mb->rd_ptr (sizeof (DeviceCommandHeader));
          ACE_DEBUG ((LM_DEBUG, 
                      ACE_TEXT ("Message for device #%d with ")
                      ACE_TEXT ("command payload of:\n%s"),
                      dch->deviceId_, mb->rd_ptr ()));
          this->rep_.update_device (dch->deviceId_,
                                    mb->rd_ptr ());
          mb->release ();
        }
    }

  ACE_Reactor::instance ()->end_reactor_event_loop ();

  return 0;
}
// Listing 5

class Message_Receiver :
  public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH>
{
public:
  Message_Receiver () : handler_(0)
  {
    ACE_ASSERT(0);
  }
  
  Message_Receiver (HA_CommandHandler *ch) : handler_(ch)
  { }

  ACE_Message_Block *shut_down_message (void);
    
  virtual int handle_input (ACE_HANDLE fd);

  virtual int handle_close (ACE_HANDLE = ACE_INVALID_HANDLE,
                            ACE_Reactor_Mask = ACE_Event_Handler::ALL_EVENTS_MASK)
  {
    this->peer ().close ();
    delete this;
    return 0;
  }
    
private:
  int read_header (DeviceCommandHeader *dch);
  int copy_payload (ACE_Message_Block *mb, int payload_length);

private:
  HA_CommandHandler *handler_;
};
// Listing 4 code/ch12
ACE_Message_Block * 
Message_Receiver::shut_down_message (void)
{
  ACE_Message_Block *mb;
  ACE_NEW_RETURN
    (mb, ACE_Message_Block (0, ACE_Message_Block::MB_HANGUP), 0);
  return mb;
}
// Listing 4
    
int 
Message_Receiver::read_header (DeviceCommandHeader *dch)
{
    ssize_t result = 
        this->peer ().recv_n (dch, sizeof (DeviceCommandHeader));
    if (result <= 0)
        ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("%p\n"),
                           ACE_TEXT ("Recieve Failure")),
                          -1);
    return 0;
}
// Listing 3 code/ch12
int 
Message_Receiver::copy_payload (ACE_Message_Block *mb,
                                int payload_length)
{
  int result = 
    this->peer ().recv_n (mb->wr_ptr (), payload_length);
    
    if (result <= 0)
      {
        mb->release ();
        return result;
      }

    mb->wr_ptr (payload_length);
    return 0;
}
// Listing 3
// Listing 2 code/ch12
int 
Message_Receiver::handle_input (ACE_HANDLE)
{
  DeviceCommandHeader dch;
  if (this->read_header (&dch) < 0)
    return -1;
    
  if (dch.deviceId_ < 0)
    {
      // Handle shutdown.
      this->handler_->putq (shut_down_message ());
      return -1;
    }
    
  ACE_Message_Block *mb;
  ACE_NEW_RETURN
    (mb, ACE_Message_Block (dch.length_ + sizeof dch), -1);
  // Copy the header.
  mb->copy ((const char*)&dch, sizeof dch);
  // Copy the payload.
  if (this->copy_payload (mb, dch.length_) < 0)
    ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("%p\n"),
                       ACE_TEXT ("Recieve Failure")), -1);
  // Pass it off to the handler thread.
  this->handler_->putq (mb);
  return 0;
}
// Listing 2

static void report_usage (int argc, ACE_TCHAR *argv[])
{
  if (argc < 2)
    {
      ACE_DEBUG ((LM_ERROR, ACE_TEXT ("%s port\n"), argv[1]));
      ACE_OS::exit (-1);
    }
}


class Acceptor : public ACE_Acceptor<Message_Receiver, ACE_SOCK_ACCEPTOR> 
{
public:
  Acceptor(HA_CommandHandler *handler) : handler_(handler)
  { }

protected:
  virtual int make_svc_handler (Message_Receiver *&mr)
  {
    ACE_NEW_RETURN (mr, Message_Receiver (handler_), -1);
    return 0;
  }

private:
  HA_CommandHandler *handler_;
};

int ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  report_usage (argc, argv);

  u_short port = ACE_OS::atoi (argv[1]);
    
  HA_Device_Repository rep;
  HA_CommandHandler handler (rep);
  ACE_ASSERT(handler.activate()==0);
  //start up the handler.
    
  Acceptor acceptor (&handler);
  ACE_INET_Addr addr (port);
  if (acceptor.open (addr) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("%p\n"),
                       ACE_TEXT ("Failed to open connection")), -1);
    
  ACE_Reactor::run_event_loop ();
  //run the reactive event loop
    
  handler.wait ();
  //reap the handler before exiting.

  return 0;
}
