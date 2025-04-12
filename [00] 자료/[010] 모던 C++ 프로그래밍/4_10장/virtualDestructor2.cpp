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
		cout << "Person::Person(name, age) 생성자 호출" << endl;
	}
	virtual ~Person() // 가상 소멸자의 정의
	{
		delete[] name;
		cout << "Person::~Person() 소멸자 호출" << endl;
	}
	virtual void introduce()
	{
		cout << "Person의 이름: " << name << endl;
		cout << "Person의 나이: " << age << endl;
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
		cout << "Chulsoo::~Chulsoo() 소멸자 호출" << endl;
	}
	void introduce()
	{
		cout << "철수의 이름: " << name << endl;
		cout << "철수의 나이: " << age << endl;
		cout << "철수가 쓴 책이름: " << bookName << endl;
	}
};

int main(void)
{
	Person * personPtr = new Chulsoo("철수", 32, "C++");
	personPtr->introduce();
	delete personPtr;
	return 0;
}