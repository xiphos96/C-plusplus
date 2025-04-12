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
	cout << "»ç¶÷Àº ÀÜ´Ù" << endl;
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
		cout << "Ã¶¼ö ÀÌ¸§Àº : " << name << endl;
		cout << "Ã¶¼ö ³ªÀÌ´Â : " << age << endl;
		cout << "Ã¶¼ö°¡ ¾´ Ã¥ÀÇ ¼ö´Â : " << numOfBooks << endl;
	}
	virtual void eat()
	{
		cout << "Ã¶¼ö´Â ¸Ô´Â´Ù" << endl;
	}
	virtual void sleep()
	{
		cout << "Ã¶¼ö´Â ÀÜ´Ù" << endl;
	}
};

int main(void)
{
	//Person * person = new Person("»ç¶÷", 100);

	Person * person = new Chulsoo("Ã¶¼ö", 32, 3);
	person->introduce();
	person->eat();
	person->sleep();
	return 0;
}