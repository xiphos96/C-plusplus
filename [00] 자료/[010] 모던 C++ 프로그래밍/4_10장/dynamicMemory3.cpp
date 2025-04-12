#include <iostream>
using namespace std;

class Chulsoo
{
private:
	int age;
public:
	Chulsoo(int age) : age(age)
	{
		cout << "Chulsoo::Chulsoo(age) ������ �Ϸ�" << endl;
	}
	Chulsoo()
	{
		cout << "Chulsoo::Chulsoo() ������ �Ϸ�" << endl;
	}
	~Chulsoo()
	{
		cout << "Chulsoo::~Chulsoo() �Ҹ��� �Ϸ�" << endl;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	void introduce();
};

int main(void)
{
	Chulsoo * chulsooPtr2 = new Chulsoo(32);
	chulsooPtr2->introduce();

	delete chulsooPtr2;
	return 0;
}

void Chulsoo::introduce()
{
	cout << "ö�� ����: " << age << endl;
}