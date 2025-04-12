#include <iostream>
using namespace std;

class Chulsoo
{
private:
	int age;
public:
	Chulsoo(const Chulsoo & source)
	{
		this->age = age;
		cout << "Chulsoo::Chulsoo() ���� ������ �Ϸ�" << endl;
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
	~Chulsoo()
	{
		cout << "Chulsoo::~Chulsoo() �Ҹ��� �Ϸ�" << endl;
	}
	Chulsoo& operator=(const Chulsoo& chulsooObj)
	{
		this->age = chulsooObj.age;
		cout << "Chulsoo::operator=() ���� ���� ������ �Ϸ�" << endl;
		return *this;
	}
};

int main(void)
{
	Chulsoo chulsoo1(32);
	Chulsoo chulsoo2(50);

	chulsoo1.introduce();
	chulsoo2.introduce();
	cout << "============���� ���� ��===========" << endl;
	chulsoo1 = chulsoo2;
	cout << "============���� ���� ��===========" << endl;
	chulsoo1.introduce();
	chulsoo2.introduce();
	return 0;
}

void Chulsoo::introduce()
{
	cout << "����: " << age << endl;
}