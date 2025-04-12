// 6-7.cpp
	
#include <iostream.h>

class C {
	int data;
public:
	void set(int n)	{ data = n; }	// data�� ����
	int	get() const { return data; }	// data�� ���

	C	operator+(int n);				// ���� ����
	C&	operator*(int n);				// ���۷����� ����
};

C
C::operator+(int n)
{
	data += n;
	return *this;
}

C&
C::operator*(int n)
{
	data *= n;
	return *this;
}


void main()
{
	C obj;

	obj.set(0);
	obj + 1 + 2 + 3 + 4 + 5;
	cout << obj.get() << endl;

	obj.set(1);
	obj * 1 * 2 * 3 * 4 * 5;
	cout << obj.get() << endl;
}