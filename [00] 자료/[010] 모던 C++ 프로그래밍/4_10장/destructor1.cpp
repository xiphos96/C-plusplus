#include <iostream>
using namespace std;

class Chulsoo
{
private:
	char * name;
public:
	Chulsoo(char * name) // 생성자
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		cout << "Chulsoo::Chulsoo(name) 생성자 완료" << endl;
	}
	Chulsoo() // 기본 생성자
	{
		cout << "Chulsoo::Chulsoo() 생성자 완료" << endl;
	}
	void introduce();
	~Chulsoo() // 소멸자
	{
		delete[] name;
		cout << "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
	}
};

int main(void)
{
	Chulsoo chulsoo("철수");
	chulsoo.introduce();
	return 0;
}

void Chulsoo::introduce()
{
	cout << "이름: " << name << endl;
}