// 6-7.cpp
	
#include <iostream.h>

class C {
	int data;
public:
	void set(int n)	{ data = n; }	// data값 설정
	int	get() const { return data; }	// data값 얻기

	C	operator+(int n);				// 값을 리턴
	C&	operator*(int n);				// 레퍼런스를 리턴
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