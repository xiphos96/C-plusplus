#include <iostream>
using namespace std;

class Chulsoo
{
private:
	int age;
public:
	Chulsoo(const Chulsoo & source) : age(source.age)
	{
		cout << "Chulsoo::Chulsoo() 복사 생성자 완료" << endl;
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
	~Chulsoo()
	{
		cout << "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
	}
};

int main(void)
{
	Chulsoo chulsoo1(32);
	Chulsoo chulsoo2(50);

	chulsoo1.introduce();
	chulsoo2.introduce();
	cout << "============대입 연산 전===========" << endl;
	chulsoo1 = chulsoo2;
	cout << "============대입 연산 후===========" << endl;
	chulsoo1.introduce();
	chulsoo2.introduce();
	return 0;
}

void Chulsoo::introduce()
{
	cout << "나이: " << age << endl;
}