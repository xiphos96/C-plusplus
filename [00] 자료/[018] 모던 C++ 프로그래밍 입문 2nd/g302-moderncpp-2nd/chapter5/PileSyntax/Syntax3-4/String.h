#pragma once

class String {
public:
	// char* 타입 파라미터를 취하는 타입 변환 생성자
	String(const char* cstr = nullptr);
	// 복사 생성자
	String(const String& str);
	// 이동 생성자
	String(String&& str);
	// 소멸자
	~String();
	// 타입 변환 연산자
	operator char*();
	// 복사 배정 연산자
	String& operator=(const String& str);
	// 이동 배정 연산자
	String& operator=(String&& str);
	String operator+(const String& str);
	bool operator==(const String& str);
private:
	// 멤버 변수
	int length;
	char* s;
};