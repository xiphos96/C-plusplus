#include <iostream>
#include <string>
using namespace std;
#include "Stack.h"

template <typename T, int S>
void reversePrint(Stack<T, S>& stk)
{
	int cnt = stk.length();
	for (int i = 0; i < cnt; ++i) {
		cout << stk.pop() << endl;
	}
}

int main()
{
	{
		Stack<char> charStack;
		charStack.push('e');
		charStack.push('u');
		charStack.push('m');
	}
	Stack<string, 20> strStack;
	strStack.push(*(new string("doo")));
	strStack.push(*(new string("hun")));
	cout << "length of string stack = " << strStack.length() << endl;
	reversePrint(strStack);
	cout << "length of string stack = " << strStack.length() << endl;

	return 0;
}