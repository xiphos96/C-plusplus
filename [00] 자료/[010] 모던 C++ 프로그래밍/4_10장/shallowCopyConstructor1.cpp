#include <iostream>
using namespace std;

class Chulsoo
{
private:
	char * name;
public:
	Chulsoo(char * name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		cout << "Chulsoo::Chulsoo(name) ������ �Ϸ�" << endl;
	}
	Chulsoo()
	{
		cout << "Chulsoo::Chulsoo() ������ �Ϸ�" << endl;
	}
    /*Chulsoo(const Chulsoo& source) // ������ ���� ���� �ּ� ó��
	{
		this->name = new char[strlen(source.name) + 1];
		strcpy_s(this->name, strlen(source.name) + 1, source.name);
	}*/
	void introduce();
	~Chulsoo()
	{
		delete[] name;
		cout << "Chulsoo::~Chulsoo() �Ҹ��� �Ϸ�" << endl;
	}
};

int main(void)
{
	Chulsoo chulsoo("ö��");
	Chulsoo chulhee(chulsoo);
	chulsoo.introduce();
	chulhee.introduce();
	return 0;
}

void Chulsoo::introduce()
{
	cout << "�̸�: " << name << endl;
}