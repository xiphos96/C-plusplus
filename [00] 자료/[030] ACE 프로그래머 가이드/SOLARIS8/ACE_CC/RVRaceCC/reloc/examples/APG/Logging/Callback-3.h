#include "ace/streams.h"
#include "ace/Log_Msg.h"
#include "ace/Log_Msg_Callback.h"
#include "ace/Log_Record.h"
#include "ace/SOCK_Stream.h"
#include "ace/SOCK_Connector.h"
#include "ace/INET_Addr.h"

#define LOGGER_PORT 20009

class Callback : public ACE_Log_Msg_Callback
{
public:
  Callback ()
    {
      this->logger_ = new ACE_SOCK_Stream;
      ACE_SOCK_Connector connector;
      ACE_INET_Addr addr (LOGGER_PORT, ACE_DEFAULT_SERVER_HOST);

      if (connector.connect (*(this->logger_), addr) == -1)
	{
	  delete this->logger_;
	  this->logger_ = 0;
	}
    }

  virtual ~Callback ()
    {
      if (this->logger_)
	{
	  this->logger_->close ();
	}
      delete this->logger_;
    }

  void log (ACE_Log_Record &log_record)
    {
      if (!this->logger_)
	{
	  log_record.print
            (ACE_TEXT (""), ACE_Log_Msg::VERBOSE, cerr);
	  return;
	}

      size_t len = log_record.length();
      log_record.encode ();

      if (this->logger_->send_n ((char *) &log_record, len) == -1)
	{
	  delete this->logger_;
	  this->logger_ = 0;
	}
    }

private:
  ACE_SOCK_Stream *logger_;
};
