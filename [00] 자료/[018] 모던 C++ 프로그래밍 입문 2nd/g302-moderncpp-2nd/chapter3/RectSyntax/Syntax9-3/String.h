#pragma once

class String {
public:
	// char* 타입 파라미터를 취하는 타입 변환 생성자
	String(const char* cstr = nullptr);
	// 소멸자
	~String();
	// 타입 변환 연산자
	operator char*();
	bool operator==(const String& str);
private:
	// 멤버 변수
	int length;
	char* s;
};