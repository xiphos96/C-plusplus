#include <iostream>
using std::cout;
using std::endl;

int main()
{
	// capture by value
	int intVal = 43;
	auto lambdaFunc = [intVal]()
	{ cout << "this lambda has copy of intVal: " << intVal << endl; };
	for (int i = 0; i < 3; ++i) {
		++intVal;
		lambdaFunc();
	}
	// capture by reference
	intVal = 43;
	auto lambdaFunc2 = [&intVal]()
	{ cout << "this lambda captures intVal by reference: " << intVal << endl; };
	for (int i = 0; i < 3; ++i) {
		++intVal;
		lambdaFunc2();
	}
	intVal = 43;
	auto lambdaFunc3 = [&intVal]()
	{ cout << "this lambda adds 10 to intVal" << endl; intVal += 10; };
	lambdaFunc3();
	cout << "intVal: " << intVal << endl;
	// another example
	int sum = 0;
	for (int i = 0; i < 3; ++i)
		[&sum](int x) { sum += x; cout << "sum: " << sum << endl; }(i);

	return 0;
}