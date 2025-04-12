// 6-5-1.cpp

#include <iostream.h>
#include <time.h>
#include "6-5.h"

// gab between two timevals, converting result to msec
double
Timer::diff(const timeb &start, const timeb &stop) const
{
  double gab;
  gab = 1.0e3 * difftime(stop.time, start.time);
  gab += (double)(stop.millitm - start.millitm);
  return gab;
}

void
Timer::on()
{
	ftime(&start);
}

void
Timer::off()
{
	ftime(&stop);
}

void
Timer::print()	const
{
	cout << diff(start, stop) / 1.0e3 << "ÃÊ" << endl;
}