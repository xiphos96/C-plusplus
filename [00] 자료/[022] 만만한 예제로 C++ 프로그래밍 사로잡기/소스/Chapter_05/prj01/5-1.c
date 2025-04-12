// 5-1.c

#include <stdio.h>

void main()
{
	extern int max();	/* function declaration */
	int i=10, j=20;

	printf("max = %d\n", max(i));
}

int max(a, b)		/* old-style prototype */
int a;
int	b;
{
	if (a > b)	return	a;
	else		return	b;
}