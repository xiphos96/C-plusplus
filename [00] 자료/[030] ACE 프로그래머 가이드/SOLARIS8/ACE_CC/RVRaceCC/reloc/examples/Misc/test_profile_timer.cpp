// test_profile_timer.cpp,v 4.6 2002/03/06 21:48:02 nanbor Exp

#include "ace/Profile_Timer.h"
#include "ace/Log_Msg.h"

ACE_RCSID(Misc, test_profile_timer, "test_profile_timer.cpp,v 4.6 2002/03/06 21:48:02 nanbor Exp")

static const int DEFAULT_ITERATIONS = 100000000;

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  ACE_Profile_Timer timer;
  int iterations = argc > 1 ? ACE_OS::atoi (argv[1]) : DEFAULT_ITERATIONS;

  timer.start ();

  for (int i = 0; i < iterations; i++)
    ACE_OS::getpid ();

  timer.stop ();

  ACE_Profile_Timer::ACE_Elapsed_Time et;

  timer.elapsed_time (et);

  ACE_DEBUG ((LM_DEBUG, "iterations = %d\n", iterations));
  ACE_DEBUG ((LM_DEBUG, "real time = %f secs, user time = %f secs, system time = %f secs\n",
	    et.real_time, et.user_time, et.system_time));

  ACE_DEBUG ((LM_DEBUG, "time per call = %f usecs\n",
	      (et.real_time / double (iterations)) * 1000000));
  return 0;
}

