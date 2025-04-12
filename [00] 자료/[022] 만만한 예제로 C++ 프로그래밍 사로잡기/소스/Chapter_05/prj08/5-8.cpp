// 5-8.cpp

#include <iostream.h>

class Complex {
	double	m_r;	// 실수부
	double	m_i;	// 허수부
public:
	inline double&	real()	{ return m_r; }	// 실수부 액세스
	inline double&	imag()	{ return m_i; }	// 허수부 액세스
};

void main()
{
	Complex z;
	z.real() = 3;
	z.imag() = 4;
	cout << "z = " << z.real() << '+' << z.imag() << "i\n";
}