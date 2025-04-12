#include <iostream>
using namespace std;

class Chulsoo
{
private:
	char * name;
public:
	Chulsoo(char * name) // ������
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		cout << "Chulsoo::Chulsoo(name) ������ �Ϸ�" << endl;
	}
	Chulsoo() // �⺻ ������
	{
		cout << "Chulsoo::Chulsoo() ������ �Ϸ�" << endl;
	}
	void introduce();
	~Chulsoo() // �Ҹ���
	{
		delete[] name;
		cout << "Chulsoo::~Chulsoo() �Ҹ��� �Ϸ�" << endl;
	}
};

int main(void)
{
	Chulsoo chulsoo("ö��");
	chulsoo.introduce();
	return 0;
}

void Chulsoo::introduce()
{
	cout << "�̸�: " << name << endl;
}