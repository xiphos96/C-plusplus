#pragma once

class String {
public:
	// char* Ÿ�� �Ķ���͸� ���ϴ� Ÿ�� ��ȯ ������
	String(const char* cstr = nullptr);
	// �Ҹ���
	~String();
	// Ÿ�� ��ȯ ������
	operator char*();
	bool operator==(const String& str);
private:
	// ��� ����
	int length;
	char* s;
};