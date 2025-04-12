#include <iostream>
#include <memory>
using namespace std;

int main()
{
	unique_ptr<int> p1(new int(5));
	unique_ptr<int> p2;
	// p2 = p1;
	unique_ptr<int> p3 = move(p1);		// 소유권 이전
	cout << p1.get() << endl;
	cout << p3.get() << endl;
	cout << *p3 << endl;
	auto a = *p3;
	cout << a << endl;
	auto& a2 = p3;
	cout << *a2 << endl;
	unique_ptr<int> p4(make_unique<int>(10));
	cout << *p4 << endl;
	p4.reset();

	return 0;
}