#include <iostream>
#include <functional>		// bind
using namespace std;
using namespace std::placeholders;

int sum3(int x, int y, int z)
{
	int sum = x + y + z;
	cout << x << '+' << y << '+' << z << '=' << sum << endl;
	return sum;
}

int main()
{
	int int1 = 1;
	int int2 = 2;
	int int3 = 3;
	int result;
	cout << "bind with integer variables and constants" << endl;
	auto functor1 = bind(sum3, int1, int2, int3);
	result = functor1();
	cout << "result is " << result << endl;
	auto functor2 = bind(sum3, 5, int2, int3);
	result = functor2();
	cout << "result is " << result << endl;
//	auto functor3 = bind(sum3, int1);
//	result = functor3();							// 컴파일 오류
	cout << "bind with placeholders" << endl;
	auto functor4 = bind(sum3, int1, _1, _2);
	result = functor4(2, 3);
	cout << "result is " << result << endl;
	result = bind(sum3, int1, _2, _1)(3, 2);
	cout << "result is " << result << endl;
	cout << int1 << ' ' << int2 << ' ' << int3 << endl;

	return 0;
}