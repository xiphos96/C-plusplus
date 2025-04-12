// 5-14.cpp

#include <string.h>
#include "5-14.h"

int getCode(const char *name)
{
	for (int i=0; i<sizeof(NAME)/sizeof(NAME[0]); i++)
	{
		if ( !strcmp(name, NAME[i]) )
			return CODE[i];
	}
	return 0;
}