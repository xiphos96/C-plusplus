#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1 = "hello ";
	string str2("world");
	const char* cstr = str2.c_str();
	cout << "C string is " << cstr << endl;
	string str3 = str1 + str2;
	cout << "combined string is " << str3 << endl;
	if (str3 == "hello world")
		cout << "two strings are same" << endl;
	string myString = "hi";
	myString += ", there";
	string myOtherString = myString;
	if (myString == myOtherString)
		myOtherString[0] = 'H';
	cout << "value of myString is " << myString << endl;
	cout << "value of myOtherString is " << myOtherString << endl;
	long double d = 3.14;
	string s1 = to_string(d);
	cout << "double number is " << d << endl;
	cout << "string version is " << s1 << endl;
	const string s2 = "1234";
	int i = stoi(s2);
	cout << "string is " << s2 << endl;
	cout << "integer vesion is " << i << endl;

	return 0;
}