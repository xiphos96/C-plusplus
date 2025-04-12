#include <iostream>
#include <string_view>

void string_print(const std::string& str)		// ���۷��� ����
{
	std::cout << "���ڿ�:" << str << " ����:" << str.length() << std::endl;
}

void string_print(const std::string&& str)		// ������ ���۷��� ����
{
	std::cout << "���ڿ�:" << str << " ����:" << str.length() << std::endl;
}

void string_view_print(const std::string_view sview)
{
	std::cout << "���ڿ�:" << sview << " ����:" << sview.length() << std::endl;
}


int main()
{
	std::string s = "hello world";
	string_print(s);							// ���۷��� ����
	string_view_print(s);

	string_print("hi there");					// ������ ���۷��� ����
	string_view_print("hi there");

	std::string_view sv(s);
	string_view_print(sv);
	std::string_view sv2 = sv.substr(0, 5);
	string_view_print(sv2);

	return 0;
}