#pragma once

template <typename T>
class Stack
{
public:
	Stack(int s = 100);
	~Stack();
	void push(const T& value);
	T pop();
	int length();
private:
	int top = 0;
	int size;
	T* stackPtr;
};

template <typename T>
Stack<T>::Stack(int s)
	: size(s)
{
	stackPtr = new T[s];
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr;
}

template <typename T>
void Stack<T>::push(const T& val)
{
	if (top < size)
		stackPtr[top++] = val;
}

template <typename T>
T Stack<T>::pop()
{
	if (top > 0)
		return stackPtr[--top];
}

template <typename T>
int Stack<T>::length()
{
	return top;
}