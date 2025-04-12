#include <iostream>
using namespace std;

class Chulsoo
{
public:
	int Eat(int SteakNum);
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