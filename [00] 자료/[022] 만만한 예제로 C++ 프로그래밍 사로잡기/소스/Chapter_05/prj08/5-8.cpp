// 5-8.cpp

#include <iostream.h>

class Complex {
	double	m_r;	// �Ǽ���
	double	m_i;	// �����
public:
	inline double&	real()	{ return m_r; }	// �Ǽ��� �׼���
	inline double&	imag()	{ return m_i; }	// ����� �׼���
};

void main()
{
	Complex z;
	z.real() = 3;
	z.imag() = 4;
	cout << "z = " << z.real() << '+' << z.imag() << "i\n";
}