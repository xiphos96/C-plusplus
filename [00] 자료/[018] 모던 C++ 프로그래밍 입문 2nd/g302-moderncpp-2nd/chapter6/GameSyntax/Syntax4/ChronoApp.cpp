#include <iostream>
#include <chrono>
using std::cout;
using std::endl;
using std::chrono::duration; using std::chrono::hours;
using std::chrono::minutes; using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::system_clock;
using std::chrono::duration_cast;

int main()
{
	// duration
	duration<long> d1(0);
	duration<long> d2(14);
	duration<long> d3;
	d3 = ++d1 + d2 * 2;
	if(d3 > d2)
		cout << d3.count() << "sec" << endl;
	minutes m(23);
	auto t = hours(2) + m + d3;
	cout << seconds(t).count() << "sec" << endl;
	cout << minutes(duration_cast<minutes>(t)).count() << "min" << endl;
	// clock, time_point
	system_clock::time_point tpoint1 = system_clock::now();
	system_clock::time_point tpoint2;
	tpoint2 = tpoint1 + minutes(10);
	if (tpoint2 > tpoint1) {
		time_t tt = system_clock::to_time_t(tpoint2);
		char buff[30];
		ctime_s(buff, sizeof(buff),  &tt);
		cout << buff;
	}
	// execution time
	double d = 0.0;
	auto ct1 = system_clock::now();
	for (int i = 0; i < 1000000; ++i)
		d += sqrt(sin(i) * cos(i));
	auto ct2 = system_clock::now();
	auto delta = duration_cast<milliseconds>(ct2 - ct1).count();
	cout << "time to execute the for loop: " << delta << "msec" << endl;

	return 0;
}