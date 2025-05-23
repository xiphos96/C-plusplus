#include <iostream>
using namespace std;

class Chulsoo
{
private:
	int age;
public:
	Chulsoo(const Chulsoo & source) : age(source.age)
	{
		cout << "Chulsoo::Chulsoo(const Chulsoo &) 복사 생성자 완료" << endl;
	}
	Chulsoo(int age) : age(age)
	{
		cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
	}
	Chulsoo()
	{
		cout << "Chulsoo::Chulsoo() 생성자 완료" << endl;
	}
	void introduce();
	Chulsoo copyConstructorCall2()
	{
	Chulsoo chulsooObj2(100);
	return chulsooObj2;
	}
	~Chulsoo()
	{
		cout << "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
	}
};

int main(void)
{
	Chulsoo chulsoo1(32);
	chulsoo1.copyConstructorCall2();
	return 0;
}