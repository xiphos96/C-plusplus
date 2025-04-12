#pragma once

template <typename T>
class Stack
{
public:
	Stack(int s = 10);
	// 복사 생성자 함수
	Stack(const Stack& other);
	~Stack();
	// 복사 배정 연산자 함수
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

// 복사 생성자 함수
template <typename T>
Stack<T>::Stack(const Stack& other)
	: top(other.top), size(other.size), stackPtr(new T[other.size])
{
	for (int i = 0; i < other.size; ++i)
		stackPtr[i] = other.stackPtr[i];
	cout << "copy constructor" << endl;
}

// 복사 배정 연산자 함수
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