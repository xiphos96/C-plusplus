#include <iostream>
using namespace std;

class Chulsoo
{
private:
	char * name;
	int * age;
public:
	Chulsoo(char * name, int age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = new int;
		*this->age = age;
		cout << "Chulsoo::Chulsoo(name) ������ �Ϸ�" << endl;
	}
	~Chulsoo()
	{
		delete[] name;
		delete age;
		cout << "Chulsoo::~Chulsoo() �Ҹ��� �Ϸ�" << endl;
	}
	void introduce();
};

int main(void)
{
	Chulsoo chulsoo("ö��", 32);
	chulsoo.introduce();
	return 0;
}

void Chulsoo::introduce()
{
	cout << "�̸�: " << name << endl;
	cout << "����: " << *age << endl;
}