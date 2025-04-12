#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person::Person() ������ ȣ��" << endl;
	}
	~Person()
	{
		cout << "Person::~Person() �Ҹ��� ȣ��" << endl;
	}
	virtual void write() = 0;
};

class Chulsoo : public Person
{
public:
	Chulsoo() : Person()
	{
		cout << "Chulsoo::Chulsoo() ������ ȣ��" << endl;
	}
	~Chulsoo()
	{
		cout << "Chulsoo::~Chulsoo() �Ҹ��� ȣ��" << endl;
	}
	void write()
	{
		cout << "å�� �� ����" << endl;
	}
};

class Younghee : public Person
{
public:
	Younghee() : Person()
	{
		cout << "Younghee::Younghee() ������ ȣ��" << endl;
	}
	~Younghee()
	{
		cout << "Younghee::~Younghee() �Ҹ��� ȣ��" << endl;
	}
	void write()
	{
		cout << "å�� �� ����" << endl;
	}
};

class Youngchul : public Chulsoo, public Younghee
{
public : 
	Youngchul() : Chulsoo(), Younghee()
	{
		cout << "Youngchul::Youngchul() ������ ȣ��" << endl;
	}
	~Youngchul()
	{
		cout << "Youngchul::~Youngchul() �Ҹ��� ȣ��" << endl;
	}
	void write()
	{
		//write();
		Chulsoo::write();
	}
};

int main(void)
{
	Youngchul youngchul;
	youngchul.write();
	return 0;
}