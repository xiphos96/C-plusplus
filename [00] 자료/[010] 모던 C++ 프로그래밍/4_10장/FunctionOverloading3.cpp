#include <iostream>
using namespace std;

class Chulsoo
{
public:
	void Eat(void);
	int Eat(int SteakNum);
	double Eat(double SteakWeight);
	int Eat(int SteakNum1, int SteakNum2);
	double Eat(int SteakWeight1, int SteakWeight2);
};

int main(void)
{
	Chulsoo chulsoo;
	chulsoo.Eat();
	chulsoo.Eat(20000);
	chulsoo.Eat(500.5);
	chulsoo.Eat(20000, 30000); // 어떤 함수를 호출해야 할까?
	return 0;
}

void Chulsoo::Eat(void)
{
	cout << "철수는 스테이크를 먹는다" << endl;
}

int Chulsoo::Eat(int SteakNum)
{
	cout << "철수는 " << SteakNum << "원 짜리 스테이크를 먹는다" << endl;
	return SteakNum;
}

double Chulsoo::Eat(double SteakWeight)
{
	cout << "철수는 " << SteakWeight << "g 짜리 스테이크를 먹는다" << endl;
	return SteakWeight;
}

int Chulsoo::Eat(int SteakNum1, int SteakNum2)
{
	cout << "철수는 " << SteakNum1 << "원 짜리 스테이크를 먹고, ";
	cout << SteakNum2 << "원 짜리 스테이크를 먹는다" << endl;
	return SteakNum2;
}

double Chulsoo::Eat(int SteakWeight1, int SteakWeight2)
{
	cout << "철수는 " << SteakWeight1 << "g 짜리 스테이크를 먹고, ";
	cout << SteakWeight2 << "g 짜리 스테이크를 먹는다" << endl;
	return SteakWeight2;
}