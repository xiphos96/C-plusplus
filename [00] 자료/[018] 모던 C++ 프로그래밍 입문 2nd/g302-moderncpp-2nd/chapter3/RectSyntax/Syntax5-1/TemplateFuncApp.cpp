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
	Stack<char> charStack(10);
	charStack.push('e');
	charStack.push('u');
	charStack.push('m');
	reversePrint(charStack);
	Stack<string> strStack(10);
	string str("eum");
	string* strPtr = new string("doo");
	strStack.push(str);
	strStack.push(*strPtr);
	strStack.push(*(new string("hun")));
	reversePrint(strStack);
	
	return 0;
}