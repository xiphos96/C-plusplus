// 6-5.h

//#include <sys/timerb.h>
#include <sys/timeb.h>	

class Timer {
	timeb	start;	
	timeb	stop;

	double diff(const timeb &start, const timeb &stop) const;

public:

	void 	on();
	void 	off();
	void	print() const;
};