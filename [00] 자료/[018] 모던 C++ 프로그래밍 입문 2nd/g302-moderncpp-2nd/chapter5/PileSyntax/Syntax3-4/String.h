#pragma once

class String {
public:
	// char* Ÿ�� �Ķ���͸� ���ϴ� Ÿ�� ��ȯ ������
	String(const char* cstr = nullptr);
	// ���� ������
	String(const String& str);
	// �̵� ������
	String(String&& str);
	// �Ҹ���
	~String();
	// Ÿ�� ��ȯ ������
	operator char*();
	// ���� ���� ������
	String& operator=(const String& str);
	// �̵� ���� ������
	String& operator=(String&& str);
	String operator+(const String& str);
	bool operator==(const String& str);
private:
	// ��� ����
	int length;
	char* s;
};