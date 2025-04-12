#pragma once

class Stack
{
public:
	Stack(int s = 100);
	~Stack();
	void push(const char& value);
	char pop();
	int length();
private:
	int top = 0;
	int size;
	char* stackPtr;
};