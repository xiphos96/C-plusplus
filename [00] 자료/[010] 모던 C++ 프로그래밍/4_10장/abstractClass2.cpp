#include <iostream>
using namespace std;

#define NAME_LEN 20

class Person
{
protected:
	char name[NAME_LEN];
	int age;
public:
	Person(char * name, int age) : age(age)
	{
		strcpy_s(this->name, name);
	}
	virtual void introduce()= 0;
	virtual void eat()= 0;
	virtual void sleep();
};

void Person::sleep()
{
	cout << "����� �ܴ�" << endl;
}

class Chulsoo : public Person
{
private:
	int numOfBooks;
public:
	Chulsoo(char * name, int age, int numOfBooks)
		: Person(name, age), numOfBooks(numOfBooks) {}
	virtual void introduce()
	{
		cout << "ö�� �̸��� : " << name << endl;
		cout << "ö�� ���̴� : " << age << endl;
		cout << "ö���� �� å�� ���� : " << numOfBooks << endl;
	}
	virtual void eat()
	{
		cout << "ö���� �Դ´�" << endl;
	}
	virtual void sleep()
	{
		cout << "ö���� �ܴ�" << endl;
	}
};

int main(void)
{
	//Person * person = new Person("���", 100);

	Person * person = new Chulsoo("ö��", 32, 3);
	person->introduce();
	person->eat();
	person->sleep();
	return 0;
}