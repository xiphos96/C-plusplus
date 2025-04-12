#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

void modify23(int x, int& y, int& z)
{
	cout << "modify23 input: " << x << ' ' << y << ' ' << z << endl;
	y = y + x;
	z = z + y;
	cout << "modify23 output: " << x << ' ' << y << ' ' << z << endl;
}

int main()
{
	int int1 = 1;
	int int2 = 2;
	int int3 = 3;
	cout << "Bind with function that modifies parameters" << endl;
	cout << int1 << ' ' << int2 << ' ' << int3 << endl;
	auto functor1 = bind(modify23, int1, int2, int3);
	functor1();
	cout << int1 << ' ' << int2 << ' ' << int3 << endl;
	bind(modify23, int1, int2, ref(int3))();
	cout << int1 << ' ' << int2 << ' ' << int3 << endl;
	cout << "bind with placeholders" << endl;
	// call parameters are passed in by lvalue reference
	bind(modify23, int1, _1, _2)(int2, int3);
	cout << int1 << ' ' << int2 << ' ' << int3 << endl;
	//	bind(mod23, int1, _1, _2)(100, 200);			// 컴파일 오류
	cout << "using with constants" << endl;
	auto functor2 = bind(modify23, 1, 2, 3);
	functor2();
	functor2();
	//  bind(mod23, 1, 2, ref(3))();					// 컴파일 오류

	return 0;
}