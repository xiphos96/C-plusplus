#include <iostream>
using namespace std;

#define NAME_LEN 20

class Person
{
protected:
	char name[NAME_LEN];
	int age;
public:
	Person(char * name, int age)
	{
		strcpy_s(this->name, name);
		this->age = age;
		cout << "Person::Person(name, age) ������ �Ϸ�" << endl;
	}
	~Person()
	{
		cout << "Person::~Person() �Ҹ��� �Ϸ�" << endl;
	}
	void introduce()
	{
		cout << "Person�� �̸�: " << name << endl;
		cout << "Person�� ����: " << age << endl;
	}
	void eat()
	{
		cout << "Person�� �Դ´�" << endl;
	}
	void sleep()
	{
		cout << "Person�� �ܴ�" << endl;
	}
};

class Chulsoo : public Person
{
private:
	int numOfBooks;
public:
	Chulsoo(char * name, int age, int numOfBooks)
		: Person(name, age)
	{
		this->numOfBooks = numOfBooks;
		cout << "Chulsoo::Chulsoo(name, age, numOfBooks) ������ �Ϸ�" << endl;
	}
	~Chulsoo()
	{
		cout << "Chulsoo::~Chulsoo() �Ҹ��� �Ϸ�" << endl;
	}
	void write()
	{
		cout << "ö���� å�� ����" << endl;
	}
	void introduce()
	{
		cout << "ö���� �̸�: " << name << endl;
		cout << "ö���� ����: " << age << endl;
	}
};

int main(void)
{
	Person person("���", 100);
	person.introduce();

	Chulsoo chulsoo("ö��", 32, 3);
	chulsoo.introduce();

	return 0;
}