// 5-6.cpp

#include <iostream.h>
#include <math.h>	// sqrt()

// ���Ҽ� Ÿ��
class Complex {
	double re, im;	// �Ǽ���, �����
public:
	Complex(double r=0., double i=0.) { re=r; im=i; };	// ������
	double& real() { return re; }			// �Ǽ��� ���/����
	double& imag() { return im; }			// ����� ���/����
	friend ostream& operator<<(ostream& os, Complex z)	// ���Ҽ� ���
	{
		return os << z.re << '+' << z.im << 'i';
	}
};

int my_sqrt(int);
double my_sqrt(double);
Complex my_sqrt(Complex z);
Complex my_sqrt(double r, double i);

void main()
{
	cout << my_sqrt(100) << endl;
	cout << my_sqrt(100.) << endl;
	Complex z = my_sqrt(100, 200);
	cout << z << endl;
	cout << my_sqrt(z) << endl;
}

int my_sqrt(int x)
{
	int nbits = sizeof(int)*8, i;
	unsigned long a=(unsigned long)x, t = 1L << (nbits-2), r = 0, s;

	for ( i = nbits/2; i > 0; i-- )
	{
		s = t + r;
		r >>= 1;
		if (s <= a)
		{
			a -= s;
			r |= t;
		}
		t >>= 2;
	}
return r;
}

double my_sqrt(double y)
{
	return sqrt(y);
}

Complex my_sqrt(Complex z)
{
	double r=z.real(), i=z.imag();
	double cabs = sqrt(r*r + i*i);
	Complex w;
	w.real() = sqrt(fabs((cabs + r) * 0.5));
	w.imag() = sqrt(fabs((cabs - r) * 0.5));
	if ( i<0.0 )
		w.real() = -w.real();
	return w;
}

Complex my_sqrt(double r, double i)
{
	return my_sqrt(Complex(r,i));
}