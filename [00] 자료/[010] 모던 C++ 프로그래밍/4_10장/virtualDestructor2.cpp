#include <iostream>
using namespace std;

class Person
{
protected:
	char * name;
	int age;
public:
	Person(char * name, int age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
		cout << "Person::Person(name, age) ������ ȣ��" << endl;
	}
	virtual ~Person() // ���� �Ҹ����� ����
	{
		delete[] name;
		cout << "Person::~Person() �Ҹ��� ȣ��" << endl;
	}
	virtual void introduce()
	{
		cout << "Person�� �̸�: " << name << endl;
		cout << "Person�� ����: " << age << endl;
	}
};

class Chulsoo : public Person
{
private:
	char * bookName;
public:
	Chulsoo(char * name, int age, char * bookName)
		: Person(name, age)
	{
		this->bookName = new char[strlen(bookName) + 1];
		strcpy_s(this->bookName, strlen(bookName) + 1, bookName);
		cout << "Chulsoo::Chulsoo(name, age, bookName)" << endl;
	}
	~Chulsoo()
	{
		delete[] bookName;
		cout << "Chulsoo::~Chulsoo() �Ҹ��� ȣ��" << endl;
	}
	void introduce()
	{
		cout << "ö���� �̸�: " << name << endl;
		cout << "ö���� ����: " << age << endl;
		cout << "ö���� �� å�̸�: " << bookName << endl;
	}
};

int main(void)
{
	Person * personPtr = new Chulsoo("ö��", 32, "C++");
	personPtr->introduce();
	delete personPtr;
	return 0;
}