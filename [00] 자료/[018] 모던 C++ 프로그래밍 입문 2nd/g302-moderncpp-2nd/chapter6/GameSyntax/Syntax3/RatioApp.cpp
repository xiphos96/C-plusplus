#include <iostream>
#include <ratio>
using std::cout; using std::endl;
using std::ratio; using std::boolalpha;
using std::ratio_add; using std::ratio_less;

int main()
{
	typedef ratio<1, 60> r1;
	cout << r1::num << "/" << r1::den << endl;
	intmax_t numerator = r1::num;
	intmax_t denominator = r1::den;
	cout << numerator << "/" << denominator << endl;
	typedef ratio<20, 30> r2;
	cout << r2::num << "/" << r2::den << endl;
	typedef ratio_add<r1, r2> r;
	cout << r::num << "/" << r::den << endl;
	typedef ratio_less<r2, r1> result;
	cout << boolalpha << result::value << endl;

	return 0;
}