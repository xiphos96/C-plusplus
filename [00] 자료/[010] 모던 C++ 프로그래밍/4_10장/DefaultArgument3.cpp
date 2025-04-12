#include <iostream>
using namespace std;

class Chulsoo
{
public:
	int Eat(int SteakNum=20000); // 디폴트 매개변수 값 지정
};

int main(void)
{
	Chulsoo chulsoo;
	chulsoo.Eat();
	return 0;
}

int Chulsoo::Eat(int SteakNum)
{
	cout << "철수는 " << SteakNum << "원 짜리 스테이크를 먹는다" << endl;
	return SteakNum;
}