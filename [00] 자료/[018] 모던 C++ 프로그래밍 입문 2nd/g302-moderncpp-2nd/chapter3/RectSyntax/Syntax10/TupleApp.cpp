#include "Rect.h"
#include <string>
#include <tuple>
using std::string; using std::tuple;
using std::make_tuple; using std::get;
using std::tuple_size;

struct Person
{
	string name;
	int birthDate;
};

int main()
{
	cout << "student1-----" << endl;
	Person p1;
	p1.name = "wonjin";
	p1.birthDate = 820301;
	tuple<int, string, Person> student1 =
							tuple<int, string, Person>(20167777, "cs", p1);
	cout << get<1>(student1) << endl;
	cout << get<2>(student1).name << endl;
	cout << "student2-----" << endl;
	Person p2{ "doohun", 821112 };
	tuple<int, string, Person> student2 = make_tuple(20168888, "english", p2);
	cout << get<2>(student2).birthDate << endl;
	auto count = tuple_size<decltype(student2)>::value;
	cout << count << endl;
	cout << "student3-----" << endl;
	Person p3{ "youngmi", 830117 };
	tuple<int, string, Person> student3;
	get<0>(student3) = 20173333;
	get<1>(student3) = "fashion design";
	get<2>(student3) = p3;
	cout << get<1>(student3) << endl;
	cout << get<2>(student3).name << endl;
	cout << "Rect Class-----" << endl;
	Rect theRect(30, 40, 50, 70);
	string rectName("the rectangle");
	// tuple<string&, Rect&> rect = tie(rectName, theRect);
	auto rect = tie(rectName, theRect);
	get<0>(rect) = "smart rectangle";
	cout << rectName << endl;
	// tuple<int, string, Person, string&, Rect&> rectOwner =
	//											tuple_cat(student1, rect);
	auto rectOwner = tuple_cat(student1, rect);
	cout << get<2>(student1).name << "'s rectangle is "
			<< get<3>(rectOwner) << endl;

	return 0;
}