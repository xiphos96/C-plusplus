#include <iostream>
#include <chrono>
using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
#include "Stack.h"

template <typename T>
Stack<T> copyStack(Stack<T> stk)
{
	Stack<T> tempStack(stk);
	return tempStack;
}

int main()
{
	Stack<int> intStack(50000000);
	for (int i = 0; i < 50000000; ++i)
		intStack.push(i);
	Stack<int> intStack2;
	auto ct1 = high_resolution_clock::now();
	intStack2 = copyStack(intStack);
	auto ct2 = high_resolution_clock::now();
	auto delta = duration_cast<milliseconds>(ct2 - ct1).count();
	cout << "COPY SEMANTICS: " << delta << " msec" << endl;
	intStack.pop();
	cout << "intStack's last element: " << intStack.pop() << endl;
	cout << "intStack2's last element: " << intStack2.pop() << endl;

	return 0;
}