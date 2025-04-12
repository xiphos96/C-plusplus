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
	}
	void write()
	{
		cout << "ö���� å�� ����" << endl;
	}
	void introduce()
	{
		cout << "ö���� �̸�: " << name << endl;
		cout << "ö���� ����: " << age << endl;
		cout << "ö���� �� å�� ��: " << numOfBooks << endl;
	}
};

int main(void)
{
	cout << "=========(Chulsoo -> Person) ��ĳ����=========" << endl;
	Chulsoo chulsooUp = Chulsoo("ö��", 32, 3);
	Person personUp = chulsooUp; // �� ĳ����
	personUp.introduce();
	
	//Person personDown = Person("���", 100);
	//Chulsoo chulsooDown = personDown; // �ٿ� ĳ����
	//chulsooDown.introduce();

	return 0;
}