#include <stdio.h>

#ifndef L_tmpnam
#define L_tmpnam 100
#endif
#ifndef P_tmpdir
#define P_tmpdir "/temp"
#endif
static char tmpnam_buffer[L_tmpnam];
static int tmpnam_counter;

char* tmpnam(char* s)
{
    int pid = 0;
    if (s == NULL)
        s = tmpnam_buffer;
    /*  Generate the filename and make sure that there isn't one called
        it already.  */
    while (1)
    {
        FILE* f;
        sprintf(s, "%s/%s%x.%x", "/temp", "t", pid, tmpnam_counter);
        f = fopen(s, "r");
        if (f == NULL)
            break;
        tmpnam_counter++;
        fclose(f);
    }
    return s;
}


FILE* tmpfile(void)
{
    char* tempName = tmpnam(0);
    FILE* fp = fopen(tempName, "rw");

    return fp;
}