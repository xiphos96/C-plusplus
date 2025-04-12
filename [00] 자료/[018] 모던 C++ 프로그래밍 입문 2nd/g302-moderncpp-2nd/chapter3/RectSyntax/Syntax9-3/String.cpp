#include "String.h"
#include <cstring>

String::String(const char* cstr)
{
	if (cstr == nullptr)
		length = 1;
	else
		length = strlen(cstr) + 1;
	s = new char[length];
	if (cstr != nullptr)
		strcpy_s(s, length, cstr);
}

String::~String()
{
	delete[] s;
}

String::operator char*()
{
	return s;
}

bool String::operator==(const String& str)
{
	return strcmp(s, str.s) ? false : true;
}