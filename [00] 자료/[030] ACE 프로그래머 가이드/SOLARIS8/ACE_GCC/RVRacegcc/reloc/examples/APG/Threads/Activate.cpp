// Listing 1 code/ch12
#include "ace/Task.h"

class HA_CommandHandler : public ACE_Task_Base
{
public:
  virtual int svc (void)
  {
    ACE_DEBUG
      ((LM_DEBUG, ACE_TEXT ("(%t) Handler Thread running\n")));
    ACE_OS::sleep (4);
    return 0;
  }
};

int ACE_TMAIN (int, ACE_TCHAR *[])
{
  ACE_DEBUG
    ((LM_DEBUG, ACE_TEXT ("(%t) Main Thread running\n")));

  HA_CommandHandler handler;
  int result = handler.activate ();
  ACE_ASSERT (result == 0);

  handler.wait ();
  return 0;
}
// Listing 1
