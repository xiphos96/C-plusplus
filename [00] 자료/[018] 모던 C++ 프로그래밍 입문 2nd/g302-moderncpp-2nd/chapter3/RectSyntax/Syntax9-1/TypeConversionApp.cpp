#include <iostream>

int main()
{
	// �ڵ� Ÿ�� ��ȯ
	std::cout << "implicit type conversion" << std::endl;
	short a = 3;
	int b = 4;
	long c = a * b;
	std::cout << c << std::endl;
	// ���� Ÿ�� ��ȯ(Ÿ�� ĳ����)
	std::cout << "explicit type conversion" << std::endl;
	int x = 5;
	double y = 3.14;
	y = double(x) + y;				// or (double)x
	std::cout << y << std::endl;
	double z = static_cast<double> (x);
	std::cout << z << std::endl;
	// ������ ������ Ÿ�� ��ȯ
	std::cout << "type conversion of pointers" << std::endl;
	int* i = new int(7);
	void* v;
	v = static_cast<void*> (i);
	int* j = static_cast<int*> (v);
	std::cout << *j << std::endl;

	return 0;
}