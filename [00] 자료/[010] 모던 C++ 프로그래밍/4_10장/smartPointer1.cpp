#include <iostream>
#include <memory>
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
	void introduce();
};

int main(void)
{
	//Chulsoo * chulsooPtr2 = new Chulsoo(32);
	//chulsooPtr2->introduce();
	//delete chulsooPtr2;

	auto_ptr<Chulsoo> chulsooSmptr(new Chulsoo(32));
	chulsooSmptr->introduce();
	return 0;
}

void Chulsoo::introduce()
{
	cout << "ö�� ����: " << age << endl;
}