#include <iostream>
using namespace std;

class Chulsoo
{
private:
	char * name;
public:
	Chulsoo(char * name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		cout << "Chulsoo::Chulsoo(name) 생성자 완료" << endl;
	}
	Chulsoo()
	{
		cout << "Chulsoo::Chulsoo() 생성자 완료" << endl;
	}
    /*Chulsoo(const Chulsoo& source) // 설명을 돕기 위한 주석 처리
	{
		this->name = new char[strlen(source.name) + 1];
		strcpy_s(this->name, strlen(source.name) + 1, source.name);
	}*/
	void introduce();
	~Chulsoo()
	{
		delete[] name;
		cout << "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
	}
};

int main(void)
{
	Chulsoo chulsoo("철수");
	Chulsoo chulhee(chulsoo);
	chulsoo.introduce();
	chulhee.introduce();
	return 0;
}

void Chulsoo::introduce()
{
	cout << "이름: " << name << endl;
}