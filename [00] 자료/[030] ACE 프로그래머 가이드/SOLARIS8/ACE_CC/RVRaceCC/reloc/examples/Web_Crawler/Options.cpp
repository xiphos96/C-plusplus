// Options.cpp,v 1.7 2001/12/26 15:46:05 schmidt Exp

#include "ace/Get_Opt.h"
#include "URL_Addr.h"
#include "Options.h"

ACE_RCSID(Web_Crawler, Options, "Options.cpp,v 1.7 2001/12/26 15:46:05 schmidt Exp")

int 
Options::parse_args (int argc, char *argv[])
{
  ACE_Get_Opt getopt (argc, argv, ACE_TEXT ("df:h:i:l:rt:u:vo:p:"));

  ACE_LOG_MSG->open (argv[0]);

  this->hostname_ = "www.cs.wustl.edu";
  this->uri_ = "index.html";
  this->recurse_ = 0;
  this->debug_ = 0;
  this->timeout_.sec (ACE_DEFAULT_TIMEOUT);
  this->url_filter_ = 0;
  this->verbose_ = 0;
  this->order_ = "FIFO";
  this->port_no_ = ACE_DEFAULT_HTTP_PORT;
  
  // The default is to make this limit as large as possible.
  this->handle_limit_ = -1;

  for (int c;
       (c = getopt ()) != EOF;
       )
    switch (c)
      {
      case 'd':
        this->debug_ = 1;
        break;
      case 'f':
        this->url_filter_ = getopt.opt_arg ();
        break;
      case 'h':
        this->hostname_ = getopt.opt_arg ();
        break;
      case 'i':
        this->uri_ = getopt.opt_arg ();
        break;
      case 'l':
        this->handle_limit_ = ACE_OS::atoi (getopt.opt_arg ());
        break;
      case 'r':
        this->recurse_ = 1;
        break;
      case 't':
        this->timeout_.sec (ACE_OS::atoi (getopt.opt_arg ()));
        break;
      case 'u':
        {
          this->hostname_ = getopt.opt_arg ();
          char *s = ACE_OS::strchr (getopt.opt_arg (), '/');
          if (s != 0)
            {
              this->uri_ = s + 1;
              *s = '\0';
            }
          else
            ACE_ERROR ((LM_ERROR,
                        "invalid URL %s\n",
                        getopt.opt_arg ()));
        }
        break;
      case 'v':
        this->verbose_ = 1;
        break;
      case 'o':
        {
        this->order_ = getopt.opt_arg ();
        }
        break;
      case 'p':
        this->port_no_ = ACE_OS::atoi (getopt.opt_arg ());
        break;
      default:
        ACE_ERROR ((LM_ERROR,
                    "usage: %n [-d] [-f filter] [-h hostname]"
                    " [-l handle-limit] [-r] [-t timeout] [-u URI]"
                    " [-v]\n%a",
                    1));

        /* NOTREACHED */
      }

  return 0;
}

int 
Options::port_no (void) const
{
  return this->port_no_;
}

int
Options::recurse (void) const
{
  return this->recurse_;
}

const ACE_Time_Value *
Options::timeout (void) const
{
  return &this->timeout_;
}

int
Options::debug (void) const
{
  return this->debug_;
}

int
Options::verbose (void) const
{
  return this->verbose_;
}

const ACE_TCHAR *
Options::order (void) const
{
  return this->order_;
}
const ACE_TCHAR *
Options::hostname (void) const
{
  return this->hostname_;
}

const ACE_TCHAR *
Options::path_name (void) const
{
  return this->uri_;
}

const ACE_TCHAR *
Options::url_filter (void) const
{
  return this->url_filter_;
}

Command_Processor *
Options::command_processor (void) const
{
  return this->command_processor_;
}

void
Options::command_processor (Command_Processor *cp)
{
  this->command_processor_ = cp;
}

URL_Visitor *
Options::visitor (void) const
{
  return this->visitor_;
}

void
Options::visitor (URL_Visitor *v)
{
  this->visitor_ = v;
}

int 
Options::handle_limit (void)
{
  return this->handle_limit_;
}
