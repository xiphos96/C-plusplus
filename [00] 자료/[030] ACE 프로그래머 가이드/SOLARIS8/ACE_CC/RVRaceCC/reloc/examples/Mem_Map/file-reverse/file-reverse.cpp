// file-reverse.cpp,v 4.8 2002/03/06 21:48:02 nanbor Exp

// Print a file in reverse by using the ACE memory mapped file
// wrapper.  It is SO easy to do compared with alternatives!

#include "ace/Mem_Map.h"
#include "ace/Log_Msg.h"

ACE_RCSID(file_reverse, file_reverse, "file-reverse.cpp,v 4.8 2002/03/06 21:48:02 nanbor Exp")

static void
putline (const char *s)
{
  while (putchar (*s++) != '\n')
    continue;
}

static void
print_array_in_reverse (char *array,
                        int size)
{
  if (size <= 0)
    return;

  size--;

  if (array[size] == '\0')
    array[size] = '\n';

  while (--size >= 0)
    if (array[size] == '\n')
      putline (array + size + 1);

  putline (array);
}

int
ACE_TMAIN (int argc, ACE_TCHAR **argv)
{
  ACE_LOG_MSG->open (argv[0]);

  if (argc != 2)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "usage: %n file\n"),
                      -1);

  ACE_Mem_Map mmap;

  if (mmap.map (argv[1], -1, O_RDWR) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%n: %p\n",
                       "mmap"),
                      -1);

  print_array_in_reverse ((char *) mmap.addr (),
                          mmap.size ());
  return 0;
}
