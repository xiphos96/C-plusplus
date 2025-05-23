// Peer.cpp,v 1.2 2003/05/14 23:16:30 shuston Exp
// Peer.cpp,v 4.42 2002/07/09 15:14:52 shuston Exp

#define ACE_BUILD_SVC_DLL

#include "Peer.h"

ACE_RCSID(Peer, Peer, "Peer.cpp,v 1.2 2003/05/14 23:16:30 shuston Exp")

Stdin_Reader::Stdin_Reader (Peer_Handler *my_peer)
  : peer_ (my_peer), working_ (0)
{
}

// Tell this guy to start reading stdin
void
Stdin_Reader::start (void)
{
  if (!this->working_)
    {
      if (ACE_Event_Handler::register_stdin_handler
            (this,
             ACE_Reactor::instance (),
             ACE_Thread_Manager::instance ()) == -1)
        ACE_ERROR ((LM_ERROR,
                    "(%t) %p\n",
                    "register_stdin_handler"));
      else
        this->working_ = 1;
    }
  return;
}

int
Stdin_Reader::handle_input (ACE_HANDLE)
{
  int result = 0;
  ACE_Message_Block *mb;

  ACE_NEW_RETURN (mb, ACE_Message_Block (sizeof (Event)), -1);

  // Cast the message block payload into an <Event> pointer.
  Event *event = (Event *) mb->rd_ptr ();

  ssize_t n = ACE_OS::read (ACE_STDIN, event->data_, sizeof event->data_);
  switch (n)
    {
    case 0:
      ACE_DEBUG ((LM_DEBUG, "stdin closing down\n"));
      mb->release ();
      result = -1;
      break;
      /* NOTREACHED */
    case -1:
      mb->release ();
      ACE_ERROR ((LM_ERROR, "%p\n", "read"));
      result = -1;
      break;
      /* NOTREACHED */
    default:
      // Do not return directly, save the return value.
      result = this->peer_->transmit (mb, n, ROUTING_EVENT);
      break;
      /* NOTREACHED */
    }

  return result == -1 ? -1 : 0;
}

int
Stdin_Reader::handle_close (ACE_HANDLE fd, ACE_Reactor_Mask)
{
  // If we get called with a handle, it's the stdin handle, whether
  // because of an error reading it in handle_input(), or being unregistered
  // because the associated Peer_Handler socket is closed.
  if (fd != ACE_INVALID_HANDLE)
    this->working_ = 0;
  this->peer_->handle_close ();
  return 0;
}

Peer_Handler::Peer_Handler (void)
  : connection_id_ (-1),  // Maybe it's better than 0.
    msg_frag_ (0),
    total_bytes_ (0),
    stdin_reader_ (this)
{
  // Set the high water mark of the <ACE_Message_Queue>.  This is used
  // to exert flow control.
  this->msg_queue ()->high_water_mark (Options::instance ()->max_queue_size ());
}

// Upcall from the <ACE_Acceptor::handle_input> that turns control
// over to our application-specific Gateway handler.

int
Peer_Handler::open (void *a)
{
  ACE_DEBUG ((LM_DEBUG,
              "handle = %d\n",
              this->peer ().get_handle ()));

  // Call down to the base class to activate and register this handler
  // with an <ACE_Reactor>.
  if (this->inherited::open (a) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "open"),
                      -1);

  if (this->peer ().enable (ACE_NONBLOCK) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "enable"),
                      -1);

  ACE_Time_Value timeout (Options::instance ()->timeout ());

  // Schedule the time between disconnects.  This should really be a
  // "tunable" parameter.
  if (ACE_Reactor::instance ()->schedule_timer
      (this, 0, timeout) == -1)
    ACE_ERROR ((LM_ERROR,
                "%p\n",
                "schedule_timer"));

  // If there are events left in the queue, make sure we enable the
  // <ACE_Reactor> appropriately to get them sent out.
  if (this->msg_queue ()->is_empty () == 0
      && ACE_Reactor::instance ()->schedule_wakeup
          (this, ACE_Event_Handler::WRITE_MASK) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "schedule_wakeup"),
                      -1);

  // First action is to wait to be notified of our connection id.
  this->do_action_ = &Peer_Handler::await_connection_id;

  // Reset standard input and set up our Stdin reader
  ACE_OS::rewind (stdin);
  this->stdin_reader_.start ();

  return 0;
}

int
Peer_Handler::transmit (ACE_Message_Block *mb,
                        size_t n,
                        int event_type)
{
  Event *event = (Event *) mb->rd_ptr ();

  // Initialize the header.
  new (&event->header_) Event_Header (n,
                                      this->connection_id_,
                                      event_type,
                                      0);

  // Convert all the fields into network byte order.
  event->header_.encode ();

  // Move the write pointer to the end of the event.
  mb->wr_ptr (sizeof (Event_Header) + n);

  if (this->put (mb) == -1)
    {
      if (errno == EWOULDBLOCK) // The queue has filled up!
        ACE_ERROR ((LM_ERROR,
                    "%p\n",
                    "gateway is flow controlled, so we're dropping events"));
      else
        ACE_ERROR ((LM_ERROR,
                    "%p\n",
                    "transmission failure in transmit()")); // Function name fixed.
      // Caller is responsible for freeing a ACE_Message_Block
      // if failures occur.
      mb->release ();
      return -1;
    }
  return 0;
}


// Perform a non-blocking <put> of event MB.  If we are unable to send
// the entire event the remainder is re-queue'd at the *front* of the
// Message_Queue.

int
Peer_Handler::nonblk_put (ACE_Message_Block *mb)
{
  // Try to send the event.  If we don't send it all (e.g., due to
  // flow control), then re-queue the remainder at the head of the
  // <ACE_Message_Queue> and ask the <ACE_Reactor> to inform us (via
  // <handle_output>) when it is possible to try again.

  ssize_t n = this->send (mb);

  if (n == -1)
    // -1 is returned only when things have really gone wrong (i.e.,
    // not when flow control occurs).
    return -1;
  else if (errno == EWOULDBLOCK)
    {
      // We didn't manage to send everything, so requeue.
      ACE_DEBUG ((LM_DEBUG,
                  "queueing activated on handle %d to connection id %d\n",
                 this->get_handle (),
                  this->connection_id_));

      // Re-queue in *front* of the list to preserve order.
      if (this->msg_queue ()->enqueue_head
          (mb,
           (ACE_Time_Value *) &ACE_Time_Value::zero) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "%p\n",
                           "enqueue_head"),
                          -1);
      // Tell ACE_Reactor to call us back when we can send again.
      if (ACE_Reactor::instance ()->schedule_wakeup
          (this, ACE_Event_Handler::WRITE_MASK) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "%p\n",
                           "schedule_wakeup"),
                          -1);
      return 0;
    }
  else 
    return n;
}

// Finish sending a event when flow control conditions abate.  This
// method is automatically called by the ACE_Reactor.

int
Peer_Handler::handle_output (ACE_HANDLE)
{
  ACE_Message_Block *mb = 0;

  ACE_DEBUG ((LM_DEBUG,
              "in handle_output\n"));

  if (this->msg_queue ()->dequeue_head
      (mb,
       (ACE_Time_Value *) &ACE_Time_Value::zero) != -1)
    {
      switch (this->nonblk_put (mb))
        {
        case 0:           // Partial send.
          ACE_ASSERT (errno == EWOULDBLOCK);
          // Didn't write everything this time, come back later...
          break;
          /* NOTREACHED */
        case -1:
          // Caller is responsible for freeing a ACE_Message_Block if
          // failures occur.
          mb->release ();
          ACE_ERROR ((LM_ERROR,
                      "%p\n",
                      "transmission failure in handle_output"));
          /* FALLTHROUGH */
        default: // Sent the whole thing.
          // If we succeed in writing the entire event (or we did not
          // fail due to EWOULDBLOCK) then check if there are more
          // events on the <ACE_Message_Queue>.  If there aren't, tell
          // the <ACE_Reactor> not to notify us anymore (at least
          // until there are new events queued up).

          if (this->msg_queue ()->is_empty ())
            {
              ACE_DEBUG ((LM_DEBUG,
                          "queue now empty on handle %d to connection id %d\n",
                          this->get_handle (),
                          this->connection_id_));

              if (ACE_Reactor::instance ()->cancel_wakeup
                  (this, ACE_Event_Handler::WRITE_MASK) == -1)
                ACE_ERROR ((LM_ERROR,
                            "%p\n",
                            "cancel_wakeup"));
            }
        }
      return 0;
    }
  else
    // If the list is empty there's a bug!
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "dequeue_head"),
                      0);
}

// Send an event to a peer (may block if necessary).

int
Peer_Handler::put (ACE_Message_Block *mb, ACE_Time_Value *)
{
  if (this->msg_queue ()->is_empty () && this->connection_id_ != -1)
    // Try to send the event *without* blocking!
    return this->nonblk_put (mb);
  else
    // If we have queued up events due to flow control then just
    // enqueue and return.
    return this->msg_queue ()->enqueue_tail
      (mb, (ACE_Time_Value *) &ACE_Time_Value::zero);
}

// Send an Peer event to gatewayd.

int
Peer_Handler::send (ACE_Message_Block *mb)
{
  size_t len = mb->length ();

  ssize_t n = this->peer ().send (mb->rd_ptr (), len);

  if (n <= 0)
    return errno == EWOULDBLOCK ? 0 : n;
  else if (n < (ssize_t) len)
    {
      // Re-adjust pointer to skip over the part we did send.
      mb->rd_ptr (n);
      this->total_bytes_ += n;
    }
  else // if (n == length).
    {
      // The whole event is sent, we can now safely deallocate the
      // buffer.  Note that this should decrement a reference count...
      this->total_bytes_ += n;
      mb->release ();
      errno = 0;
    }

  ACE_DEBUG ((LM_DEBUG,
              "sent %d bytes, total bytes sent = %d\n",
              n,
              this->total_bytes_));
  return n;
}

// Receive an Event from gatewayd.  Handles fragmentation.

int
Peer_Handler::recv (ACE_Message_Block *&mb)
{
  if (this->msg_frag_ == 0)
    // No existing fragment...
    ACE_NEW_RETURN (this->msg_frag_,
                    ACE_Message_Block (sizeof (Event)),
                    -1);

  Event *event = (Event *) this->msg_frag_->rd_ptr ();
  ssize_t header_received = 0;

  const size_t HEADER_SIZE = sizeof (Event_Header);
  ssize_t header_bytes_left_to_read =
    HEADER_SIZE - this->msg_frag_->length ();

  if (header_bytes_left_to_read > 0)
    {
      header_received = this->peer ().recv
        (this->msg_frag_->wr_ptr (),
         header_bytes_left_to_read);

      if (header_received == -1 /* error */
          || header_received == 0  /* EOF */)
        {
          ACE_ERROR ((LM_ERROR,
                      "%p\n",
                      "Recv error during header read"));
          ACE_DEBUG ((LM_DEBUG,
                      "attempted to read %d bytes\n",
                      header_bytes_left_to_read));
          this->msg_frag_ = this->msg_frag_->release ();
          return header_received;
        }

      // Bump the write pointer by the amount read.
      this->msg_frag_->wr_ptr (header_received);

      // At this point we may or may not have the ENTIRE header.
      if (this->msg_frag_->length () < HEADER_SIZE)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "Partial header received: only %d bytes\n",
                     this->msg_frag_->length ()));
          // Notify the caller that we didn't get an entire event.
          errno = EWOULDBLOCK;
          return -1;
        }

      // Convert the header into host byte order so that we can access
      // it directly without having to repeatedly muck with it...
      event->header_.decode ();

      if (event->header_.len_ > ACE_INT32 (sizeof event->data_))
        {
          // This data_ payload is too big!
          errno = EINVAL;
          ACE_DEBUG ((LM_DEBUG,
                      "Data payload is too big (%d bytes)\n",
                      event->header_.len_));
          return -1;
        }
    }

  // At this point there is a complete, valid header in Event.  Now we
  // need to get the event payload.  Due to incomplete reads this may
  // not be the first time we've read in a fragment for this message.
  // We account for this here.  Note that the first time in here
  // <msg_frag_->wr_ptr> will point to <event->data_>.  Every time we
  // do a successful fragment read, we advance <wr_ptr>.  Therefore,
  // by subtracting how much we've already read from the
  // <event->header_.len_> we complete the
  // <data_bytes_left_to_read>...

  ssize_t data_bytes_left_to_read =
    ssize_t (event->header_.len_ - (msg_frag_->wr_ptr () - event->data_));

  // peer().recv() should not be called when data_bytes_left_to_read is 0.
  ssize_t data_received = !data_bytes_left_to_read ? 0 :
    this->peer ().recv (this->msg_frag_->wr_ptr (),
                        data_bytes_left_to_read);

  // Try to receive the remainder of the event.

  switch (data_received)
    {
    case -1:
      if (errno == EWOULDBLOCK)
        // This might happen if only the header came through.
        return -1;
      else
        /* FALLTHROUGH */;

    case 0: // Premature EOF.
      if (data_bytes_left_to_read)
      {
      this->msg_frag_ = this->msg_frag_->release ();
      return 0;
      }
      /* FALLTHROUGH */;

    default:
      // Set the write pointer at 1 past the end of the event.
      this->msg_frag_->wr_ptr (data_received);

      if (data_received != data_bytes_left_to_read)
        {
          errno = EWOULDBLOCK;
          // Inform caller that we didn't get the whole event.
          return -1;
        }
      else
        {
          // Set the read pointer to the beginning of the event.
          this->msg_frag_->rd_ptr (this->msg_frag_->base ());

          mb = this->msg_frag_;

          // Reset the pointer to indicate we've got an entire event.
          this->msg_frag_ = 0;
        }

      ACE_DEBUG ((LM_DEBUG,
                  "(%t) connection id = %d, cur len = %d, total bytes read = %d\n",
                  event->header_.connection_id_,
                  event->header_.len_,
                  data_received + header_received));
      if (Options::instance ()->enabled (Options::VERBOSE))
        ACE_DEBUG ((LM_DEBUG,
                    "data_ = %*s\n",
                    event->header_.len_ - 2,
                    event->data_));
      return data_received + header_received;
    }
}

// Receive various types of input (e.g., Peer event from the gatewayd,
// as well as stdio).

int
Peer_Handler::handle_input (ACE_HANDLE sd)
{
  ACE_DEBUG ((LM_DEBUG, "in handle_input, sd = %d\n", sd));
  // Perform the appropriate action depending on the state we are
  // in.
  return (this->*do_action_) ();
}

// Action that receives our connection id from the Gateway.

int
Peer_Handler::await_connection_id (void)
{
  ssize_t n = this->peer ().recv (&this->connection_id_,
                                  sizeof this->connection_id_);

  if (n != sizeof this->connection_id_)
    {
      if (n == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "gatewayd has closed down unexpectedly\n"),
                          -1);
      else
        ACE_ERROR_RETURN ((LM_ERROR,
                           "%p, bytes received on handle %d = %d\n",
                          "recv",
                           this->get_handle (),
                           n),
                          -1);
    }
  else
    {
      this->connection_id_ = ntohl (this->connection_id_);
      ACE_DEBUG ((LM_DEBUG,
                  "assigned connection id %d\n",
                  this->connection_id_));
    }

  // Subscribe for events if we're a Consumer.
  if (Options::instance ()->enabled (Options::CONSUMER_CONNECTOR))
    this->subscribe ();

  // No need to disconnect by timeout.
  ACE_Reactor::instance ()->cancel_timer(this);
  // Transition to the action that waits for Peer events.
  this->do_action_ = &Peer_Handler::await_events;

  return 0;
}

int
Peer_Handler::subscribe (void)
{
  ACE_Message_Block *mb;

  ACE_NEW_RETURN (mb,
                  ACE_Message_Block (sizeof (Event)),
                  -1);

  Subscription *subscription =
    (Subscription *) ((Event *) mb->rd_ptr ())->data_;
  subscription->connection_id_ =
    Options::instance ()->connection_id ();

  return this->transmit (mb, sizeof *subscription, SUBSCRIPTION_EVENT);
}

// Action that receives events from the Gateway.

int
Peer_Handler::await_events (void)
{
  ACE_Message_Block *mb = 0;

  ssize_t n = this->recv (mb);

  switch (n)
    {
    case 0:
      ACE_ERROR_RETURN ((LM_ERROR,
                         "gatewayd has closed down\n"),
                        -1);
      /* NOTREACHED */
    case -1:
      if (errno == EWOULDBLOCK)
        // A short-read, we'll come back and finish it up later on!
        return 0;
      else
        ACE_ERROR_RETURN ((LM_ERROR,
                           "%p\n",
                           "recv"),
                          -1);
      /* NOTREACHED */
    default:
      {
        // We got a valid event, so let's process it now!  At the
        // moment, we just print out the event contents...

        Event *event = (Event *) mb->rd_ptr ();
        this->total_bytes_ += mb->length ();

        ACE_DEBUG ((LM_DEBUG,
                    "route id = %d, cur len = %d, total len = %d\n",
                    event->header_.connection_id_,
                    event->header_.len_,
                    this->total_bytes_));
        if (Options::instance ()->enabled (Options::VERBOSE))
          ACE_DEBUG ((LM_DEBUG,
                      "data_ = %*s\n",
                      event->header_.len_ - 2,
                      event->data_));
        mb->release ();
        return 0;
      }
    }
}

// Periodically send events via ACE_Reactor timer mechanism.

int
Peer_Handler::handle_timeout (const ACE_Time_Value &,
                              const void *)
{
  // Shut down the handler.
  return this->handle_close ();
}

Peer_Handler::~Peer_Handler (void)
{
  // Shut down the handler.
  this->handle_close ();
}

// Handle shutdown of the Peer object.

int
Peer_Handler::handle_close (ACE_HANDLE,
                            ACE_Reactor_Mask)
{
  if (this->get_handle () != ACE_INVALID_HANDLE)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "shutting down Peer on handle %d\n",
                  this->get_handle ()));
      this->shutdown ();
      ACE_Event_Handler::remove_stdin_handler
        (ACE_Reactor::instance (),
         ACE_Thread_Manager::instance ());
    }
  return 0;
}

int
Peer_Acceptor::start (u_short port)
{
  // This object only gets allocated once and is just recycled
  // forever.
  ACE_NEW_RETURN (peer_handler_, Peer_Handler, -1);

  this->addr_.set (port);

  ACE_DEBUG ((LM_DEBUG,
              "opening acceptor at port %d\n",
              port));

  // Call down to the <Acceptor::open> method.
  if (this->inherited::open (this->addr_) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "open"),
                      -1);
  else if (this->acceptor ().get_local_addr (this->addr_) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "get_local_addr"),
                      -1);
  else
    ACE_DEBUG ((LM_DEBUG,
                "accepting at port %d\n",
                this->addr_.get_port_number ()));
  return 0;
}

Peer_Acceptor::Peer_Acceptor (void)
  : peer_handler_ (0)
{
}

int
Peer_Acceptor::close (void)
{
  // Will trigger a delete.
  if (this->peer_handler_ != 0)
    this->peer_handler_->destroy ();

  // Close down the base class.
  return this->inherited::close ();
}

// Note how this method just passes back the pre-allocated
// <Peer_Handler> instead of having the <ACE_Acceptor> allocate a new
// one each time!

int
Peer_Acceptor::make_svc_handler (Peer_Handler *&sh)
{
  sh = this->peer_handler_;
  return 0;
}

int
Peer_Connector::open_connector (Peer_Handler *&peer_handler,
                                u_short port)
{
  // This object only gets allocated once and is just recycled
  // forever.
  ACE_NEW_RETURN (peer_handler,
                  Peer_Handler,
                  -1);

  ACE_INET_Addr addr (port,
                      Options::instance ()->connector_host ());

  ACE_DEBUG ((LM_DEBUG,
              "connecting to %s:%d\n",
              addr.get_host_name (),
              addr.get_port_number ()));

  if (this->connect (peer_handler, addr) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "connect"),
                      -1);
  else
    ACE_DEBUG ((LM_DEBUG,
                "connected to %s:%d\n",
                addr.get_host_name (),
                addr.get_port_number ()));
  return 0;
}

int
Peer_Connector::open (ACE_Reactor *, int)
{
  this->supplier_peer_handler_ = 0;
  this->consumer_peer_handler_ = 0;

  if (Options::instance ()->enabled (Options::SUPPLIER_CONNECTOR)
      && this->open_connector (this->supplier_peer_handler_,
                               Options::instance ()->supplier_connector_port ()) == -1)
    return -1;

  if (Options::instance ()->enabled (Options::CONSUMER_CONNECTOR)
      && this->open_connector (this->consumer_peer_handler_,
                               Options::instance ()->consumer_connector_port ()) == -1)
    return -1;

  return 0;
}

int
Peer_Factory::handle_signal (int signum, siginfo_t *, ucontext_t *)
{
  if (signum != SIGPIPE)
  {
    // Shut down the main event loop.
    ACE_DEBUG((LM_NOTICE, "Exit case signal\n")); // Why do I exit?
    ACE_Reactor::end_event_loop();
  }

  return 0;
}

// Returns information on the currently active service.

int
Peer_Factory::info (char **strp, size_t length) const
{
  char buf[BUFSIZ];
  char consumer_addr_str[BUFSIZ];
  char supplier_addr_str[BUFSIZ];

  ACE_INET_Addr addr;

  if (this->consumer_acceptor_.acceptor ().get_local_addr (addr) == -1)
    return -1;
  else if (addr.addr_to_string (consumer_addr_str,
                                sizeof addr) == -1)
    return -1;
  else if (this->supplier_acceptor_.acceptor ().get_local_addr (addr) == -1)
    return -1;
  else if (addr.addr_to_string (supplier_addr_str,
                                sizeof addr) == -1)
    return -1;

  ACE_OS::sprintf (buf,
                   "%s\t C:%s|S:%s/%s %s",
                   "peerd",
                   consumer_addr_str,
                   supplier_addr_str,
                   "tcp",
                   "# Gateway traffic generator and data sink\n");

  if (*strp == 0 && (*strp = ACE_OS::strdup (buf)) == 0)
    return -1;
  else
    ACE_OS::strncpy (*strp, buf, length);
  return ACE_OS::strlen (buf);
}

// Hook called by the explicit dynamic linking facility to terminate
// the peer.

int
Peer_Factory::fini (void)
{
  this->consumer_acceptor_.close ();
  this->supplier_acceptor_.close ();
  return 0;
}

// Hook called by the explicit dynamic linking facility to initialize
// the peer.

int
Peer_Factory::init (int argc, char *argv[])
{
  Options::instance ()->parse_args (argc, argv);

  ACE_Sig_Set sig_set;

  sig_set.sig_add (SIGINT);
  sig_set.sig_add (SIGQUIT);
  sig_set.sig_add (SIGPIPE);

  // Register ourselves to receive signals so we can shut down
  // gracefully.

  if (ACE_Reactor::instance ()->register_handler (sig_set,
                                                  this) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "register_handler"),
                      -1);

  if (Options::instance ()->enabled (Options::SUPPLIER_ACCEPTOR)
      && this->supplier_acceptor_.start
      (Options::instance ()->supplier_acceptor_port ()) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "Acceptor::open"),
                      -1);
  else if (Options::instance ()->enabled (Options::CONSUMER_ACCEPTOR)
           && this->consumer_acceptor_.start
           (Options::instance ()->consumer_acceptor_port ()) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "Acceptor::open"),
                      -1);
  else if (this->connector_.open () == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "Connector::open"),
                      -1);
  return 0;
}

// The following is a "Factory" used by the <ACE_Service_Config> and
// svc.conf file to dynamically initialize the <Peer_Acceptor> and
// <Peer_Connector>.

ACE_SVC_FACTORY_DEFINE (Peer_Factory)

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Acceptor<Peer_Handler, ACE_SOCK_ACCEPTOR>;
template class ACE_Connector<Peer_Handler, ACE_SOCK_CONNECTOR>;
template class ACE_Map_Manager<ACE_HANDLE, ACE_Svc_Tuple<Peer_Handler> *, ACE_SYNCH_RW_MUTEX>;
template class ACE_Map_Iterator<ACE_HANDLE, ACE_Svc_Tuple<Peer_Handler> *, ACE_SYNCH_RW_MUTEX>;
template class ACE_Map_Reverse_Iterator<ACE_HANDLE, ACE_Svc_Tuple<Peer_Handler> *, ACE_SYNCH_RW_MUTEX>;
template class ACE_Map_Iterator_Base<ACE_HANDLE, ACE_Svc_Tuple<Peer_Handler> *, ACE_SYNCH_RW_MUTEX>;
template class ACE_Map_Entry<ACE_HANDLE, ACE_Svc_Tuple<Peer_Handler> *>;
template class ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>;
template class ACE_Svc_Tuple<Peer_Handler>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Acceptor<Peer_Handler, ACE_SOCK_ACCEPTOR>
#pragma instantiate ACE_Connector<Peer_Handler, ACE_SOCK_CONNECTOR>
#pragma instantiate ACE_Map_Manager<ACE_HANDLE, ACE_Svc_Tuple<Peer_Handler> *, ACE_SYNCH_RW_MUTEX>
#pragma instantiate ACE_Map_Iterator_Base<ACE_HANDLE, ACE_Svc_Tuple<Peer_Handler> *, ACE_SYNCH_RW_MUTEX>
#pragma instantiate ACE_Map_Iterator<ACE_HANDLE, ACE_Svc_Tuple<Peer_Handler> *, ACE_SYNCH_RW_MUTEX>
#pragma instantiate ACE_Map_Reverse_Iterator<ACE_HANDLE, ACE_Svc_Tuple<Peer_Handler> *, ACE_SYNCH_RW_MUTEX>
#pragma instantiate ACE_Map_Entry<ACE_HANDLE, ACE_Svc_Tuple<Peer_Handler> *>
#pragma instantiate ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
#pragma instantiate ACE_Svc_Tuple<Peer_Handler>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
