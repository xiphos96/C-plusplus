// 5-16.cpp

#include <string.h>
#include "5-16.h"

int getCode(const char *name)
{
	int i=0;
	do
	{
		if ( !strcmp(name, NAME[i]) )
			return CODE[i];
	}  while( NAME[i++][0] );
	return 0;
}