#include <iostream>
#include <string_view>

void string_print(const std::string& str)		// 레퍼런스 전달
{
	std::cout << "문자열:" << str << " 길이:" << str.length() << std::endl;
}

void string_print(const std::string&& str)		// 우측값 레퍼런스 전달
{
	std::cout << "문자열:" << str << " 길이:" << str.length() << std::endl;
}

void string_view_print(const std::string_view sview)
{
	std::cout << "문자열:" << sview << " 길이:" << sview.length() << std::endl;
}


int main()
{
	std::string s = "hello world";
	string_print(s);							// 레퍼런스 전달
	string_view_print(s);

	string_print("hi there");					// 우측값 레퍼런스 전달
	string_view_print("hi there");

	std::string_view sv(s);
	string_view_print(sv);
	std::string_view sv2 = sv.substr(0, 5);
	string_view_print(sv2);

	return 0;
}