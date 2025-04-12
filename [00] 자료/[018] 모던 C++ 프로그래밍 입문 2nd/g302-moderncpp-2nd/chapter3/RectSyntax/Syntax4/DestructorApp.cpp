#include "Stack.h"
#include <iostream>

void reversePrint()
{
	Stack charStack(15);
	charStack.push('a');
	charStack.push('b');
	charStack.push('c');
	int cnt = charStack.length();
	for (int k = 0; k < cnt; k++) {
		std::cout << charStack.pop() << std::endl;
	}
}

int main()
{
	reversePrint();

	return 0;
}