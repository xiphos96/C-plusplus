#pragma once

template <typename T>
class Stack
{
public:
	Stack(int s = 10);
	// ���� ������ �Լ�
	Stack(const Stack& other);
	~Stack();
	// ���� ���� ������ �Լ�
	Stack& operator=(const Stack& other);
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

// ���� ������ �Լ�
template <typename T>
Stack<T>::Stack(const Stack& other)
	: top(other.top), size(other.size), stackPtr(new T[other.size])
{
	for (int i = 0; i < other.size; ++i)
		stackPtr[i] = other.stackPtr[i];
	cout << "copy constructor" << endl;
}

// ���� ���� ������ �Լ�
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this == &other)
		return *this;
	top = other.top;
	size = other.size;
	delete[] stackPtr;
	stackPtr = new T[other.size];
	for (int i = 0; i < other.size; ++i)
		stackPtr[i] = other.stackPtr[i];
	cout << "copy assignment" << endl;
	return *this;
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr;
	cout << "destructor" << endl;
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