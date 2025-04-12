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
	void introduce();
	~Chulsoo()
	{
		cout << "Chulsoo::~Chulsoo() �Ҹ��� �Ϸ�" << endl;
	}
};

int main(void)
{
	Chulsoo chulsoo1(32);
	Chulsoo chulsoo2(chulsoo1);
	//Chulsoo chulsoo2 = chulsoo1;
	chulsoo1.introduce();
	chulsoo2.introduce();
	return 0;
}

void Chulsoo::introduce()
{
	cout << "����: " << age << endl;
}