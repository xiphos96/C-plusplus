#include <iostream>
using namespace std;

class Chulsoo
{
private:
	int age;
public:
	Chulsoo(const Chulsoo & source) : age(source.age)
	{
		cout << "Chulsoo::Chulsoo(const Chulsoo &) ���� ������ �Ϸ�" << endl;
	}
	Chulsoo(int age) : age(age)
	{
		cout << "Chulsoo::Chulsoo(age) ������ �Ϸ�" << endl;
	}
	Chulsoo()
	{
		cout << "Chulsoo::Chulsoo() ������ �Ϸ�" << endl;
	}
	void introduce();
	Chulsoo copyConstructorCall2()
	{
	Chulsoo chulsooObj2(100);
	return chulsooObj2;
	}
	~Chulsoo()
	{
		cout << "Chulsoo::~Chulsoo() �Ҹ��� �Ϸ�" << endl;
	}
};

int main(void)
{
	Chulsoo chulsoo1(32);
	chulsoo1.copyConstructorCall2();
	return 0;
}