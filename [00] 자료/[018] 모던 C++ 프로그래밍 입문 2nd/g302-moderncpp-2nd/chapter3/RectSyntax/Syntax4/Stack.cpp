#include "Stack.h"

Stack::Stack(int s)
	: size(s)
{
	stackPtr = new char[s];
}

Stack::~Stack()
{
	delete[] stackPtr;
}

void Stack::push(const char& val)
{
	if (top < size)
		stackPtr[top++] = val;
}

char Stack::pop()
{
	if (top > 0)
		return stackPtr[--top];
}

int Stack::length()
{
	return top;
}