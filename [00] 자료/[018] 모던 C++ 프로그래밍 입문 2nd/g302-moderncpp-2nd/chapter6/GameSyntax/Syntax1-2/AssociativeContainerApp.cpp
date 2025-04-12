#include <set>
#include <map>
#include <iostream>
#include <string>
using namespace std;

struct PhoneData
{
	string name;
	string phone;
};

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
	PhoneData pd4 = { "saejin", "010-8765-8765" };
	studentPhoneBook.insert(make_pair(20161111, pd4));
	pd4.phone = "010-1111-1111";
	studentPhoneBook[20161111] = pd4;
	PhoneData pd5{ "seongjin", "010-6789-6789" };
	studentPhoneBook[20165555] = pd5;
	set<string> phoneAccess;
	phoneAccess.insert(pd1.name);
	phoneAccess.insert(pd3.name);
	if (phoneAccess.count("doohun") == 1) {
		map<int, PhoneData>::iterator it;
		for (it = studentPhoneBook.begin(); it != studentPhoneBook.end(); ++it)
			cout << it->first << "(" << it->second.name << ") : " <<
			it->second.phone << endl;
	}
	else {
		cout << "권한이 없습니다" << endl;
	}

	return 0;
}