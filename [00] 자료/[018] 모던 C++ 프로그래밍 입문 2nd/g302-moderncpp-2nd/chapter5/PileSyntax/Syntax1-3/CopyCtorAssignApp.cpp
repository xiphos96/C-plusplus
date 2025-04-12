#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void reversePrint(Stack<T>& stk)
{
	int cnt = stk.length();
	for (int i = 0; i < cnt; ++i) {
		cout << stk.pop() << endl;
	}
}

int main()
{
	Stack<string> stringStack(10);
	stringStack.push("eum");
	stringStack.push("doo");
	stringStack.push("hun");
	Stack<string> stringStack2(stringStack);
	Stack<string> stringStack3;
	stringStack3 = stringStack;
	stringStack.pop();
	cout << "original stack:" << endl;
	reversePrint(stringStack);
	cout << "stack with copy constructor:" << endl;
	reversePrint(stringStack2);
	cout << "stack with copy assignment:" << endl;
	reversePrint(stringStack3);

	return 0;
}