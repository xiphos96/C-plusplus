#include <iostream>
using namespace std;

void func(int a)
{
	cout << "�Լ�-int" << endl;
}

void func(double* p)
{
	cout << "�Լ�-double*" << endl;
}

int main()
{
	func(0);
	func(NULL);
	func(static_cast<double*>(NULL));
	func(nullptr);

	return 0;
}