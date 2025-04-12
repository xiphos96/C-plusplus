#include <map>
#include <iostream>
#include <string>
using namespace std;

struct PhoneData
{
	string name;
	string phone;
};

template <typename T>
void printMap(const T& m)
{
	if (!m.empty()) {
		for (auto& e : m)
			cout << e.first << "(" << e.second.name << ") : " <<
			  e.second.phone << endl;
	}
	cout << "-----------------------------------" <<
	  "size : " << m.size() << endl;
}

int main()
{
	map<int, PhoneData> studentPhoneBook;
	PhoneData pd1{ "doohun", "010-1234-1234" };
	PhoneData pd2 = { "wonjin", "010-4321-4321" };
	PhoneData pd3 = { "youngmi", "010-5678-5678" };
	studentPhoneBook.insert(make_pair(20163333, pd1));
	studentPhoneBook.insert({
			{ 20162222, pd2 },
			{ 20164444, pd3 }
	});
	printMap(studentPhoneBook);
	PhoneData pd4 = { "saejin", "010-8765-8765" };
	studentPhoneBook.insert(make_pair(20161111, pd4));
	pd4.phone = "010-1111-1111";
	studentPhoneBook[20161111] = pd4;
	PhoneData pd5{ "seongjin", "010-6789-6789" };
	studentPhoneBook[20165555] = pd5;
	printMap(studentPhoneBook);
	studentPhoneBook.erase(20163333);
	printMap(studentPhoneBook);
	map<int, PhoneData>::iterator it;
	it = studentPhoneBook.find(20164444);
	if (it == studentPhoneBook.end())
		cout << "등록되지 않았습니다" << endl;
	else
		cout << (*it).second.phone << endl;
	studentPhoneBook.erase(it);
	printMap(studentPhoneBook);
	studentPhoneBook.clear();
	printMap(studentPhoneBook);

	return 0;
}