/**
 * HA_Status_Static.cpp,v 1.1 2003/10/09 17:38:48 shuston Exp
 *
 * Home Automation Status server. Sample code from The ACE Programmer's Guide,
 * Copyright 2003 Addison-Wesley. All Rights Reserved.
 */

#include "ace/OS.h"
#include "ace/Configuration.h"
#include "ace/Configuration_Import_Export.h"
#include "ace/Get_Opt.h"
#include "HA_Status_Static.h"

// Listing 1 code/ch19
int
HA_Status::init (int argc, ACE_TCHAR *argv[])
{
  static const ACE_TCHAR options[] = ACE_TEXT (":f:");
  ACE_Get_Opt cmd_opts (argc, argv, options, 0);
  if (cmd_opts.long_option
      (ACE_TEXT ("config"), 'f', ACE_Get_Opt::ARG_REQUIRED) == -1)
    return -1;
  int option;
  ACE_TCHAR config_file[MAXPATHLEN];
  ACE_OS_String::strcpy (config_file, ACE_TEXT ("HAStatus.conf"));
  while ((option = cmd_opts ()) != EOF)
    switch (option)
      {
      case 'f':
        ACE_OS_String::strncpy (config_file,
                                cmd_opts.opt_arg (),
                                MAXPATHLEN);
        break;
      case ':':
        ACE_ERROR_RETURN
          ((LM_ERROR, ACE_TEXT ("-%c requires an argument\n"),
            cmd_opts.opt_opt ()),
           -1);
      default:
        ACE_ERROR_RETURN
          ((LM_ERROR, ACE_TEXT ("Parse error.\n")), -1);
      }

  ACE_Configuration_Heap config;
  config.open ();
  ACE_Registry_ImpExp config_importer (config);
  if (config_importer.import_config (config_file) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       config_file),
                      -1);

  ACE_Configuration_Section_Key status_section;
  if (config.open_section (config.root_section (),
                           ACE_TEXT ("HAStatus"),
                           0,
                           status_section) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("Can't open HAStatus section")),
                      -1);

  u_int status_port;
  if (config.get_integer_value (status_section,
                                ACE_TEXT ("ListenPort"),
                                status_port) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("HAStatus ListenPort does ")
                       ACE_TEXT ("not exist\n")),
                      -1);
  this->listen_addr_.set (ACE_static_cast (u_short, status_port));

  if (this->acceptor_.open (this->listen_addr_) != 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("HAStatus %p\n"),
                       ACE_TEXT ("accept")),
                      -1);

  return 0;
}
// Listing 1

// Listing 2 code/ch19
int
HA_Status::fini (void)
{
  this->acceptor_.close ();
  return 0;
}
// Listing 2

// Listing 3 code/ch19
int
HA_Status::info (ACE_TCHAR **str, size_t len) const
  {
    ACE_TCHAR buf[BUFSIZ];
    ACE_OS::sprintf (buf, ACE_TEXT ("HAStatus listening on port %hu\n"),
                     this->listen_addr_.get_port_number ());
    if (*str == 0)
      *str = ACE::strnew (buf);
    else
      ACE_OS_String::strncpy (*str, buf, len);
    return ACE_static_cast (int, ACE_OS::strlen (*str));
  }
// Listing 3

// Listing 4 code/ch19
ACE_FACTORY_DEFINE (ACE_Local_Service, HA_Status)

ACE_STATIC_SVC_DEFINE (HA_Status_Descriptor,
                       ACE_TEXT ("HA_Status_Static_Service"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (HA_Status),
                       ACE_Service_Type::DELETE_THIS |
                       ACE_Service_Type::DELETE_OBJ,
                       0)  // Service not initially active

ACE_STATIC_SVC_REQUIRE (HA_Status_Descriptor)
// Listing 4

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>;
template class ACE_Acceptor<ClientHandler, ACE_SOCK_ACCEPTOR>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#  pragma instantiate ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>;
#  pragma instantiate ACE_Acceptor<ClientHandler, ACE_SOCK_ACCEPTOR>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
