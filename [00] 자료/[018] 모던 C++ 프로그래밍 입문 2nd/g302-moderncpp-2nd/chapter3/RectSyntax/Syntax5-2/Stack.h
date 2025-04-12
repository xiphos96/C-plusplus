#pragma once

template <typename T, int S = 100>
class Stack
{
public:
	Stack();
	~Stack();
	void push(const T& value);
	T pop();
	int length();
private:
	int top = 0;
	int size = S;
	T* stackPtr;
};

template <typename T, int S>
Stack<T, S>::Stack()
{
	stackPtr = new T[size];
}

template <typename T, int S>
Stack<T, S>::~Stack()
{
	delete[] stackPtr;
	cout << "stack deleted!" << endl;
}

template <typename T, int S>
void Stack<T, S>::push(const T& val)
{
	if (top < size)
		stackPtr[top++] = val;
}

template <typename T, int S>
T Stack<T, S>::pop()
{
	if (top > 0)
		return stackPtr[--top];
}

template <typename T, int S>
int Stack<T, S>::length()
{
	return top;
}