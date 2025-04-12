#include <iostream>
using namespace std;

class Chulsoo
{
public:
	int Eat(int SteakNum = 20000, int WaterNum = 1000, int CoffeeNum = 5000);
};

int main(void)
{
	Chulsoo chulsoo;
	chulsoo.Eat(); // 20,000원 짜리 스테이크, 1,000원 짜리 물, 5,000원 짜리 커피를 먹는다.
	chulsoo.Eat(30000); // 30,000원 짜리 스테이크를 먹는다.
	chulsoo.Eat(1500); // 1,500원 짜리 물을 먹는다(?)
	chulsoo.Eat(20000, 1500); // 1,500원 짜리 물을 먹는다.
	return 0;
}

int Chulsoo::Eat(int SteakNum, int WaterNum, int CoffeeNum)
{
	cout << "철수는 " << SteakNum << "원 짜리 스테이크를 먹고, ";
	cout << WaterNum << "원 짜리 물을 먹고, ";
	cout << CoffeeNum << "원 짜리 커피를 먹는다." << endl;
	return SteakNum;
}