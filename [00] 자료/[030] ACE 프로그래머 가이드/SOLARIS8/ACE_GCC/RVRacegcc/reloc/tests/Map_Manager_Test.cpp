// Map_Manager_Test.cpp,v 4.71 2002/03/06 21:48:03 nanbor Exp

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Map_Manager_Test.cpp
//
// = DESCRIPTION
//     This is a simple test of the <ACE_Map_Manager> and
//     <ACE_Hash_Map_Manager> that illustrates how to use the forward
//     and reverse iterators.
//
// = AUTHOR
//    Irfan Pyarali <irfan@cs.wustl.edu>,
//    Douglas C. Schmidt <schmidt@cs.wustl.edu>, and
//    Kirthika Parameswaran  <kirthika@cs.wustl.edu>
//
// ============================================================================

#include "test_config.h"
#include "ace/Map_Manager.h"
#include "ace/Hash_Map_Manager.h"
#include "ace/Active_Map_Manager.h"
#include "ace/Profile_Timer.h"
#include "ace/Synch.h"
#include "ace/Hash_Cache_Map_Manager_T.h"
#include "ace/Caching_Strategies_T.h"
#include "ace/Pair_T.h"

ACE_RCSID(tests, Map_Manager_Test, "Map_Manager_Test.cpp,v 4.71 2002/03/06 21:48:03 nanbor Exp")

typedef ACE_Null_Mutex MUTEX;
typedef ACE_UINT32 TYPE;
typedef ACE_Active_Map_Manager_Key
        ACTIVE_KEY;
typedef ACE_Hash<TYPE>
        HASH_KEY;
typedef ACE_Equal_To<TYPE>
        COMPARE_KEYS;

typedef ACE_Map_Manager <TYPE, TYPE, MUTEX>
        MAP_MANAGER;
typedef ACE_Map_Iterator <TYPE, TYPE, MUTEX>
        ITERATOR;
typedef ACE_Map_Reverse_Iterator <TYPE, TYPE, MUTEX>
        REVERSE_ITERATOR;
typedef ACE_Map_Entry <TYPE, TYPE>
        ENTRY;
typedef ACE_Hash_Map_Manager_Ex <TYPE, TYPE, HASH_KEY, COMPARE_KEYS, MUTEX>
        HASH_MAP_MANAGER;
typedef ACE_Hash_Map_Iterator_Ex <TYPE, TYPE, HASH_KEY, COMPARE_KEYS, MUTEX>
        HASH_ITERATOR;
typedef ACE_Hash_Map_Reverse_Iterator_Ex <TYPE, TYPE, HASH_KEY, COMPARE_KEYS, MUTEX>
        HASH_REVERSE_ITERATOR;
typedef ACE_Hash_Map_Entry <TYPE, TYPE>
        HASH_ENTRY;
typedef ACE_Active_Map_Manager <TYPE>
        ACTIVE_MAP_MANAGER;

typedef ACE_Hash_Map_Manager_Ex<TYPE, ACE_Pair<TYPE, int>, HASH_KEY, COMPARE_KEYS, MUTEX>
        CACHE_MAP_IMPL;
typedef ACE_Hash_Map_Iterator_Ex<TYPE, ACE_Pair<TYPE, int>, HASH_KEY, COMPARE_KEYS, MUTEX>
        CACHE_ITER_IMPL;
typedef ACE_Hash_Map_Reverse_Iterator_Ex<TYPE, ACE_Pair<TYPE, int>, HASH_KEY, COMPARE_KEYS, MUTEX>
        CACHE_REV_ITER_IMPL;
typedef int ATTR;
typedef ACE_Null_Cleanup_Strategy<TYPE, TYPE, CACHE_MAP_IMPL>
        NULL_CLEANUP;
typedef ACE_Null_Caching_Utility <TYPE, TYPE, CACHE_MAP_IMPL, CACHE_ITER_IMPL, ATTR>
        NULL_UTILITY;
typedef ACE_Null_Caching_Strategy<ATTR, NULL_UTILITY>
        NULL_CACHING_STRATEGY;
typedef ACE_Cache_Map_Manager<TYPE, TYPE, CACHE_MAP_IMPL, CACHE_ITER_IMPL, CACHE_REV_ITER_IMPL, NULL_CACHING_STRATEGY, ATTR>
        CACHE_MAP_MANAGER;
typedef ACE_Hash_Cache_Map_Manager<TYPE, TYPE, HASH_KEY, COMPARE_KEYS, NULL_CACHING_STRATEGY, ATTR>
        HASH_CACHE_MAP_MANAGER;

static void
test_cache_map_manager (size_t table_size,
                        size_t iterations,
                        int test_iterators)
{
  NULL_CACHING_STRATEGY null_caching_strategy;
  CACHE_MAP_MANAGER map (null_caching_strategy,
                         table_size);
  TYPE i;
  TYPE j;
  ssize_t k;

  for (i = 0; i < iterations; i++)
    ACE_ASSERT (map.bind (i, i) != -1);

  if (test_iterators)
    {
      {
        i = 0;

        CACHE_MAP_MANAGER::ITERATOR end = map.end ();

        for (CACHE_MAP_MANAGER::ITERATOR iter = map.begin ();
             iter != end;
             ++iter)
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        i,
                        (*iter).first (),
                        (*iter).second ()));
            ++i;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (i == iterations);
      }


      {
        k = iterations - 1;

        CACHE_MAP_MANAGER::REVERSE_ITERATOR rend = map.rend ();

        for (CACHE_MAP_MANAGER::REVERSE_ITERATOR iter = map.rbegin ();
             iter != rend;
             ++iter)
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        k,
                        (*iter).first (),
                        (*iter).second ()));
            k--;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (k == -1);
      }


      {
        i = 0;

        CACHE_MAP_MANAGER::iterator end = map.end ();

        for (CACHE_MAP_MANAGER::iterator iter = map.begin ();
             iter != end;
             ++iter)
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        i,
                        (*iter).first (),
                        (*iter).second ()));
            ++i;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (i == iterations);
      }


      {
        k = iterations - 1;

        CACHE_MAP_MANAGER::reverse_iterator rend = map.rend ();

        for (CACHE_MAP_MANAGER::reverse_iterator iter = map.rbegin ();
             iter != rend;
             ++iter)
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        k,
                        (*iter).first (),
                        (*iter).second ()));
            k--;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (k == -1);
      }


    }

  for (i = 0; i < iterations; ++i)
    {
      ACE_ASSERT (map.find (i, j) != -1);
      ACE_ASSERT (i == j);
    }

  size_t remaining_entries = iterations;
  for (i = 0; i < iterations; ++i)
    {
      ACE_ASSERT (map.unbind (i) != -1);
      --remaining_entries;
      ACE_ASSERT (map.current_size () == remaining_entries);
    }

}

static void
test_hash_cache_map_manager (size_t table_size,
                             size_t iterations,
                             int test_iterators)
{
  NULL_CACHING_STRATEGY null_caching_strategy;
  HASH_CACHE_MAP_MANAGER map (null_caching_strategy,
                              table_size);
  TYPE i;
  TYPE j;
  ssize_t k;

  for (i = 0; i < iterations; i++)
    ACE_ASSERT (map.bind (i, i) != -1);

  if (test_iterators)
    {
      {
        i = 0;

        HASH_CACHE_MAP_MANAGER::ITERATOR end = map.end ();

        for (HASH_CACHE_MAP_MANAGER::ITERATOR iter = map.begin ();
             iter != end;
             ++iter)
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        i,
                        (*iter).first (),
                        (*iter).second ()));
            ++i;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (i == iterations);
      }


      {
        k = iterations - 1;

        HASH_CACHE_MAP_MANAGER::REVERSE_ITERATOR rend = map.rend ();

        for (HASH_CACHE_MAP_MANAGER::REVERSE_ITERATOR iter = map.rbegin ();
             iter != rend;
             ++iter)
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        k,
                        (*iter).first (),
                        (*iter).second ()));
            k--;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (k == -1);
      }


      {
        i = 0;

        HASH_CACHE_MAP_MANAGER::iterator end = map.end ();

        for (HASH_CACHE_MAP_MANAGER::iterator iter = map.begin ();
             iter != end;
             ++iter)
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        i,
                        (*iter).first (),
                        (*iter).second ()));
            ++i;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (i == iterations);
      }


      {
        k = iterations - 1;

        HASH_CACHE_MAP_MANAGER::reverse_iterator rend = map.rend ();

        for (HASH_CACHE_MAP_MANAGER::reverse_iterator iter = map.rbegin ();
             iter != rend;
             ++iter)
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        k,
                        (*iter).first (),
                        (*iter).second ()));
            k--;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (k == -1);
      }


    }

  for (i = 0; i < iterations; ++i)
    {
      ACE_ASSERT (map.find (i, j) != -1);
      ACE_ASSERT (i == j);
    }

  size_t remaining_entries = iterations;
  for (i = 0; i < iterations; ++i)
    {
      ACE_ASSERT (map.unbind (i) != -1);
      --remaining_entries;
      ACE_ASSERT (map.current_size () == remaining_entries);
    }
}


static void
test_active_map_manager (size_t table_size,
                         size_t iterations,
                         int test_iterators)
{
  ACTIVE_MAP_MANAGER map (table_size);
  TYPE i;
  TYPE j;
  ssize_t k;

  ACTIVE_MAP_MANAGER::key_type *active_keys;

  ACE_NEW (active_keys,
           ACTIVE_MAP_MANAGER::key_type[iterations]);

  for (i = 0;
       i < iterations;
       i++)
    ACE_ASSERT (map.bind (i, active_keys[i]) != -1);

  if (test_iterators)
    {
      {
        i = 0;

        ACTIVE_MAP_MANAGER::iterator end = map.end ();

        for (ACTIVE_MAP_MANAGER::iterator iter = map.begin ();
             iter != end;
             ++iter)
          {
            ACTIVE_MAP_MANAGER::ENTRY &entry = *iter;
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d-%d|%d)"),
                        i,
                        entry.ext_id_.slot_index (),
                        entry.ext_id_.slot_generation (),
                        entry.int_id_));
            ++i;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (i == iterations);
      }

      {
        k = iterations - 1;

        ACTIVE_MAP_MANAGER::reverse_iterator rend = map.rend ();

        for (ACTIVE_MAP_MANAGER::reverse_iterator iter = map.rbegin ();
             iter != rend;
             ++iter)
          {
            ACTIVE_MAP_MANAGER::ENTRY &entry = *iter;
            ACE_UNUSED_ARG (entry);
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d-%d|%d)"),
                        k,
                        entry.ext_id_.slot_index (),
                        entry.ext_id_.slot_generation (),
                        entry.int_id_));
            k--;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (k == -1);
      }
    }

  for (i = 0; i < iterations; ++i)
    {
      ACE_ASSERT (map.find (active_keys[i], j) != -1);
      ACE_ASSERT (i == j);
    }

  size_t remaining_entries = iterations;
  for (i = 0; i < iterations; ++i)
    {
      ACE_ASSERT (map.unbind (active_keys[i]) != -1);
      --remaining_entries;
      ACE_ASSERT (map.current_size () == remaining_entries);
    }

  delete [] active_keys;
}

static void
test_hash_map_manager (size_t table_size,
                       size_t iterations,
                       int test_iterators)
{
  HASH_MAP_MANAGER map (table_size);
  TYPE i;
  TYPE j;
  ssize_t k;

  for (i = 0; i < iterations; i++)
    ACE_ASSERT (map.bind (i, i) != -1);

  if (test_iterators)
    {
      {
        i = 0;

        HASH_ITERATOR end = map.end ();
        for (HASH_ITERATOR iter = map.begin ();
             iter != end;
             ++iter)
          {
            HASH_ENTRY &entry = *iter;
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        i,
                        entry.ext_id_,
                        entry.int_id_));
            ++i;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (i == iterations);
      }

      {
        i = 0;
        HASH_ENTRY *entry = 0;

        for (HASH_ITERATOR iterator (map);
             iterator.next (entry) != 0;
             iterator.advance ())
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        i,
                        entry->ext_id_,
                        entry->int_id_));
            ++i;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (i == iterations);
      }

      {
        k = iterations - 1;
        HASH_REVERSE_ITERATOR rend = map.rend ();

        for (HASH_REVERSE_ITERATOR iter = map.rbegin ();
             iter != rend;
             ++iter)
          {
            HASH_ENTRY &entry = *iter;
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        k,
                        entry.ext_id_,
                        entry.int_id_));
            k--;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (k == -1);
      }

      {
        k = iterations - 1;
        HASH_ENTRY *entry = 0;

        for (HASH_REVERSE_ITERATOR iterator (map);
             iterator.next (entry) != 0;
             iterator.advance ())
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        k,
                        entry->ext_id_,
                        entry->int_id_));
            k--;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (k == -1);
      }

      {
        i = 0;

        HASH_MAP_MANAGER::iterator end = map.end ();
        for (HASH_MAP_MANAGER::iterator iter = map.begin ();
             iter != end;
             ++iter)
          {
            HASH_MAP_MANAGER::ENTRY &entry = *iter;
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        i,
                        entry.ext_id_,
                        entry.int_id_));
            ++i;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (i == iterations);
      }

      {
        i = 0;
        HASH_MAP_MANAGER::ENTRY *entry = 0;

        for (HASH_MAP_MANAGER::ITERATOR iterator (map);
             iterator.next (entry) != 0;
             iterator.advance ())
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        i,
                        entry->ext_id_,
                        entry->int_id_));
            ++i;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (i == iterations);
      }

      {
        k = iterations - 1;
        HASH_MAP_MANAGER::reverse_iterator rend = map.rend ();

        for (HASH_MAP_MANAGER::reverse_iterator iter = map.rbegin ();
             iter != rend;
             ++iter)
          {
            HASH_MAP_MANAGER::ENTRY &entry = *iter;
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        k,
                        entry.ext_id_,
                        entry.int_id_));
            k--;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (k == -1);
      }

      {
        k = iterations - 1;
        HASH_MAP_MANAGER::ENTRY *entry = 0;

        for (HASH_MAP_MANAGER::REVERSE_ITERATOR iterator (map);
             iterator.next (entry) != 0;
             iterator.advance ())
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        k,
                        entry->ext_id_,
                        entry->int_id_));
            k--;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (k == -1);
      }
    }

  for (i = 0; i < iterations; ++i)
    {
      ACE_ASSERT (map.find (i, j) != -1);
      ACE_ASSERT (i == j);
    }

  size_t remaining_entries = iterations;
  for (i = 0; i < iterations; ++i)
    {
      ACE_ASSERT (map.unbind (i) != -1);
      --remaining_entries;
      ACE_ASSERT (map.current_size () == remaining_entries);
    }
}

static void
test_map_manager (size_t table_size,
                  size_t iterations,
                  int test_iterators)
{
  MAP_MANAGER map (table_size);
  TYPE i;
  TYPE j;
  ssize_t k;

  for (i = 0; i < iterations; ++i)
    ACE_ASSERT (map.bind (i, i) != -1);

  if (test_iterators)
    {
      {
        i = 0;

        ITERATOR end = map.end ();
        for (ITERATOR iter = map.begin ();
             iter != end;
             ++iter)
          {
            ENTRY &entry = *iter;
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        i,
                        entry.ext_id_,
                        entry.int_id_));
            ++i;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (i == iterations);
      }

      {
        i = 0;
        ENTRY *entry = 0;

        for (ITERATOR iterator (map);
             iterator.next (entry) != 0;
             iterator.advance ())
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        i,
                        entry->ext_id_,
                        entry->int_id_));
            ++i;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (i == iterations);
      }

      {
        k = iterations - 1;
        REVERSE_ITERATOR rend = map.rend ();

        for (REVERSE_ITERATOR iter = map.rbegin ();
             iter != rend;
             ++iter)
          {
            ENTRY &entry = *iter;
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        k,
                        entry.ext_id_,
                        entry.int_id_));
            k--;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (k == -1);
      }

      {
        k = iterations - 1;
        ENTRY *entry = 0;

        for (REVERSE_ITERATOR iterator (map);
             iterator.next (entry) != 0;
             iterator.advance ())
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        k,
                        entry->ext_id_,
                        entry->int_id_));
            k--;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (k == -1);
      }

      {
        i = 0;

        MAP_MANAGER::iterator end = map.end ();
        for (MAP_MANAGER::iterator iter = map.begin ();
             iter != end;
             ++iter)
          {
            MAP_MANAGER::ENTRY &entry = *iter;
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        i,
                        entry.ext_id_,
                        entry.int_id_));
            ++i;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (i == iterations);
      }

      {
        i = 0;
        MAP_MANAGER::ENTRY *entry = 0;

        for (MAP_MANAGER::ITERATOR iterator (map);
             iterator.next (entry) != 0;
             iterator.advance ())
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        i,
                        entry->ext_id_,
                        entry->int_id_));
            ++i;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (i == iterations);
      }

      {
        k = iterations - 1;
        MAP_MANAGER::reverse_iterator rend = map.rend ();

        for (MAP_MANAGER::reverse_iterator iter = map.rbegin ();
             iter != rend;
             ++iter)
          {
            ENTRY &entry = *iter;
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        k,
                        entry.ext_id_,
                        entry.int_id_));
            k--;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (k == -1);
      }

      {
        k = iterations - 1;
        MAP_MANAGER::ENTRY *entry = 0;

        for (MAP_MANAGER::REVERSE_ITERATOR iterator (map);
             iterator.next (entry) != 0;
             iterator.advance ())
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%d|%d|%d)"),
                        k,
                        entry->ext_id_,
                        entry->int_id_));
            k--;
          }

        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("\n")));
        ACE_ASSERT (k == -1);
      }
    }

  for (i = 0; i < iterations; ++i)
    {
      ACE_ASSERT (map.find (i, j) != -1);
      ACE_ASSERT (i == j);
    }

  size_t remaining_entries = iterations;
  for (i = 0; i < iterations; ++i)
    {
      ACE_ASSERT (map.unbind (i) != -1);
      --remaining_entries;
      ACE_ASSERT (map.current_size () == remaining_entries);
    }

  //
  // This is extra for the map manager.
  //
  for (i = 0; i < iterations; ++i)
    ACE_ASSERT (map.bind (i, i) != -1);

  // Unbind in one swoop.
  map.unbind_all ();
  ACE_ASSERT (map.current_size () == 0);

  for (i = 0; i < iterations; ++i)
    ACE_ASSERT (map.bind (i, i) != -1);

  // Unbind one at a time.
  MAP_MANAGER::iterator end = map.end ();
  while (1)
    {
      MAP_MANAGER::iterator iter = map.begin ();
      if (iter == end)
        break;
      ACE_ASSERT (map.unbind ((*iter).ext_id_) != -1);
    }

  ACE_ASSERT (map.current_size () == 0);
}

static void
run_test (void (*ptf) (size_t, size_t, int),
          size_t table_size,
          size_t iterations,
          int test_iterators,
          const ACE_TCHAR *test_name)
{
  ACE_Profile_Timer timer;
  timer.start ();

  (*ptf) (table_size, iterations, test_iterators);

  timer.stop ();

  ACE_Profile_Timer::ACE_Elapsed_Time et;

  timer.elapsed_time (et);

  ACE_TCHAR *test_iterators_string = 0;

  if (test_iterators)
    test_iterators_string =
      ACE_const_cast (ACE_TCHAR*,
                      ACE_TEXT ( "includes executing iterators"));
  else
    test_iterators_string =
      ACE_const_cast (ACE_TCHAR*,
                      ACE_TEXT ("doesn't include executing iterators"));

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("time to test a map of size %d for %d iterations using %s (%s)\n"),
              table_size,
              iterations,
              test_name,
              test_iterators_string));

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("real time = %f secs, user time = %f secs, system time = %f secs\n"),
              et.real_time,
              et.user_time,
              et.system_time));

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("time per call = %f usecs\n"),
              (et.real_time / ACE_timer_t (iterations)) * 1000000));
}

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  ACE_START_TEST (ACE_TEXT ("Map_Manager_Test"));
  ACE_LOG_MSG->clr_flags (ACE_Log_Msg::VERBOSE_LITE);

  size_t table_size = ACE_MAX_ITERATIONS / 2;
  size_t iterations = ACE_MAX_ITERATIONS;
  int test_iterators = 1;

  if (argc > 1)
    table_size = ACE_OS::atoi (argv[1]);

  if (argc > 2)
    iterations = ACE_OS::atoi (argv[2]);

  if (argc > 3)
    test_iterators = ACE_OS::atoi (argv[3]);

  // Test the <ACE_Map_Manager>.
  run_test (&test_map_manager,
            table_size,
            iterations,
            test_iterators,
            ACE_TEXT ("Map_Manager"));

  // Test the <ACE_Hash_Map_Manager>.
  run_test (&test_hash_map_manager,
            table_size,
            iterations,
            test_iterators,
            ACE_TEXT ("Hash_Map_Manager"));

  // Test the <ACE_Hash_Map_Manager>.
  run_test (&test_active_map_manager,
            table_size,
            iterations,
            test_iterators,
            ACE_TEXT ("Active_Map_Manager"));

  // Test the <ACE_Cache_Map_Manager>.
  run_test (&test_cache_map_manager,
            table_size,
            iterations,
            test_iterators,
            ACE_TEXT ("Cache_Map_Manager"));

  // Test the <ACE_Hash_Cache_Map_Manager>.
  run_test (&test_hash_cache_map_manager,
            table_size,
            iterations,
            test_iterators,
            ACE_TEXT ("Hash_Cache_Map_Manager"));
  ACE_LOG_MSG->set_flags (ACE_Log_Msg::VERBOSE_LITE);
  ACE_END_TEST;
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  // The explicit instantiations are necessary with g++ 2.91.66
  // with -frepo, because it misses some of them.
template class ACE_Pair<TYPE, ATTR>;
template class ACE_Reference_Pair<TYPE, TYPE>;
template class ACE_Hash_Map_Manager_Ex<TYPE, TYPE, HASH_KEY, COMPARE_KEYS, MUTEX>;
template class ACE_Hash_Map_Iterator_Base_Ex<TYPE, TYPE, HASH_KEY, COMPARE_KEYS, MUTEX>;
template class ACE_Hash_Map_Iterator_Ex<TYPE, TYPE, HASH_KEY, COMPARE_KEYS, MUTEX>;
template class ACE_Hash_Map_Reverse_Iterator_Ex<TYPE, TYPE, HASH_KEY, COMPARE_KEYS, MUTEX>;
template class ACE_Hash_Map_Entry<TYPE, TYPE>;
template class ACE_Map_Manager<TYPE, TYPE, MUTEX>;
template class ACE_Map_Iterator_Base<TYPE, TYPE, MUTEX>;
template class ACE_Map_Iterator<TYPE, TYPE, MUTEX>;
template class ACE_Map_Reverse_Iterator<TYPE, TYPE, MUTEX>;
template class ACE_Map_Entry<TYPE, TYPE>;
template class ACE_Active_Map_Manager<TYPE>;
template class ACE_Map_Manager<ACE_Active_Map_Manager_Key, TYPE, MUTEX>;
template class ACE_Map_Iterator_Base<ACE_Active_Map_Manager_Key, TYPE, MUTEX>;
template class ACE_Map_Iterator<ACE_Active_Map_Manager_Key, TYPE, MUTEX>;
template class ACE_Map_Reverse_Iterator<ACE_Active_Map_Manager_Key, TYPE, MUTEX>;
template class ACE_Map_Entry<ACE_Active_Map_Manager_Key, TYPE>;
template class ACE_Hash_Map_Manager_Ex<TYPE, ACE_Pair<TYPE, ATTR>, HASH_KEY, COMPARE_KEYS, MUTEX>;
template class ACE_Hash_Map_Iterator_Base_Ex<TYPE, ACE_Pair<TYPE, ATTR>, HASH_KEY, COMPARE_KEYS, MUTEX>;
template class ACE_Hash_Map_Iterator_Ex<TYPE, ACE_Pair<TYPE, ATTR>, HASH_KEY, COMPARE_KEYS, MUTEX>;
template class ACE_Hash_Map_Reverse_Iterator_Ex<TYPE, ACE_Pair<TYPE, ATTR>, HASH_KEY, COMPARE_KEYS, MUTEX>;
template class ACE_Hash_Map_Entry<TYPE, ACE_Pair<TYPE, ATTR> >;
template class ACE_Cleanup_Strategy<TYPE, TYPE, CACHE_MAP_IMPL>;
template class ACE_Null_Cleanup_Strategy<TYPE, TYPE, CACHE_MAP_IMPL>;
template class ACE_Null_Caching_Utility<TYPE, TYPE, CACHE_MAP_IMPL, CACHE_ITER_IMPL, ATTR>;
template class ACE_Null_Caching_Strategy<ATTR, NULL_UTILITY>;
template class ACE_Hash_Cache_Map_Manager<TYPE, TYPE, HASH_KEY, COMPARE_KEYS, NULL_CACHING_STRATEGY, ATTR>;
template class ACE_Cache_Map_Manager<TYPE, TYPE, CACHE_MAP_IMPL, CACHE_ITER_IMPL, CACHE_REV_ITER_IMPL, NULL_CACHING_STRATEGY, ATTR>;
template class ACE_Cache_Map_Iterator<TYPE, TYPE, CACHE_ITER_IMPL, NULL_CACHING_STRATEGY, ATTR>;
template class ACE_Cache_Map_Reverse_Iterator<TYPE,TYPE, CACHE_REV_ITER_IMPL, NULL_CACHING_STRATEGY, ATTR>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Pair<TYPE, ATTR>
#pragma instantiate ACE_Reference_Pair<TYPE, TYPE>
#pragma instantiate ACE_Hash_Map_Manager_Ex<TYPE, TYPE, HASH_KEY, COMPARE_KEYS, MUTEX>
#pragma instantiate ACE_Hash_Map_Iterator_Base_Ex<TYPE, TYPE, HASH_KEY, COMPARE_KEYS, MUTEX>
#pragma instantiate ACE_Hash_Map_Iterator_Ex<TYPE, TYPE, HASH_KEY, COMPARE_KEYS, MUTEX>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator_Ex<TYPE, TYPE, HASH_KEY, COMPARE_KEYS, MUTEX>
#pragma instantiate ACE_Hash_Map_Entry<TYPE, TYPE>
#pragma instantiate ACE_Map_Manager<TYPE, TYPE, MUTEX>
#pragma instantiate ACE_Map_Iterator_Base<TYPE, TYPE, MUTEX>
#pragma instantiate ACE_Map_Iterator<TYPE, TYPE, MUTEX>
#pragma instantiate ACE_Map_Reverse_Iterator<TYPE, TYPE, MUTEX>
#pragma instantiate ACE_Map_Entry<TYPE, TYPE>
#pragma instantiate ACE_Active_Map_Manager<TYPE>
#pragma instantiate ACE_Map_Manager<ACE_Active_Map_Manager_Key, TYPE, MUTEX>
#pragma instantiate ACE_Map_Iterator_Base<ACE_Active_Map_Manager_Key, TYPE, MUTEX>
#pragma instantiate ACE_Map_Iterator<ACE_Active_Map_Manager_Key, TYPE, MUTEX>
#pragma instantiate ACE_Map_Reverse_Iterator<ACE_Active_Map_Manager_Key, TYPE, MUTEX>
#pragma instantiate ACE_Map_Entry<ACE_Active_Map_Manager_Key, TYPE>
#pragma instantiate ACE_Hash_Map_Manager_Ex<TYPE, ACE_Pair<TYPE, ATTR>, HASH_KEY, COMPARE_KEYS, MUTEX>
#pragma instantiate ACE_Hash_Map_Iterator_Base_Ex<TYPE, ACE_Pair<TYPE, ATTR>, HASH_KEY, COMPARE_KEYS, MUTEX>
#pragma instantiate ACE_Hash_Map_Iterator_Ex<TYPE, ACE_Pair<TYPE, ATTR>, HASH_KEY, COMPARE_KEYS, MUTEX>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator_Ex<TYPE, ACE_Pair<TYPE, ATTR>, HASH_KEY, COMPARE_KEYS, MUTEX>
#pragma instantiate ACE_Hash_Map_Entry<TYPE, ACE_Pair<TYPE, ATTR> >
#pragma instantiate ACE_Null_Cleanup_Strategy<TYPE, TYPE, CACHE_MAP_IMPL>
#pragma instantiate ACE_Cleanup_Strategy<TYPE, TYPE, CACHE_MAP_IMPL>
#pragma instantiate ACE_Null_Caching_Utility<TYPE, TYPE, CACHE_MAP_IMPL, CACHE_ITER_IMPL, ATTR>
#pragma instantiate ACE_Null_Caching_Strategy<ATTR, NULL_UTILITY>
#pragma instantiate ACE_Hash_Cache_Map_Manager<TYPE, TYPE, HASH_KEY, COMPARE_KEYS, NULL_CACHING_STRATEGY, ATTR>
#pragma instantiate ACE_Cache_Map_Manager<TYPE, TYPE, CACHE_MAP_IMPL, CACHE_ITER_IMPL, CACHE_REV_ITER_IMPL, NULL_CACHING_STRATEGY, ATTR>
#pragma instantiate ACE_Cache_Map_Iterator<TYPE, TYPE, CACHE_ITER_IMPL, NULL_CACHING_STRATEGY, ATTR>
#pragma instantiate ACE_Cache_Map_Reverse_Iterator<TYPE,TYPE, CACHE_REV_ITER_IMPL, NULL_CACHING_STRATEGY, ATTR>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
