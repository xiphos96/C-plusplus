// 6-5.cpp

#include <iostream.h>
#include "6-5.h"

struct BigType {
	int	data[100];
	char	name[256];
};

BigType	retVal(BigType val)
{
	return	val;
}

BigType*	retPtr(BigType *ptr)
{
	return	ptr;
}

BigType&	retRef(BigType &ref)
{
	return	ref;
}

void main()
{
	BigType	big;
	Timer	timer;

	cout << "값에 의한 리턴:" << endl;
	timer.on();
	for (long i=0; i<1000000L; i++)	retVal(big);
	timer.off();
	timer.print();

	cout << "포인터 의한 리턴:" << endl;
	timer.on();
	for (long j=0; j<1000000L; j++)	retPtr(&big);
	timer.off();
	timer.print();

	cout << "레퍼런스에 의한 리턴" << endl;
	timer.on();
	for (long k=0; k<1000000L; k++)	retRef(big);
	timer.off();
	timer.print();
	cout << endl;
}