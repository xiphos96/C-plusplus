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
	cout << "=========(Chulsoo -> Person) ��ĳ���� (����)=========" << endl;
	Chulsoo chulsooUpRef = Chulsoo("ö��", 32, 3);
	Person& personUpRef = chulsooUpRef;
	personUpRef.introduce();

	cout << "=========(Chulsoo -> Person) ��ĳ���� (������)=========" << endl;
	Person* personUpPtr = new Chulsoo("ö��", 32, 3);
	personUpPtr->introduce();

	return 0;
}