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
	chulsoo.Eat(); // 20,000�� ¥�� ������ũ, 1,000�� ¥�� ��, 5,000�� ¥�� Ŀ�Ǹ� �Դ´�.
	chulsoo.Eat(30000); // 30,000�� ¥�� ������ũ�� �Դ´�.
	chulsoo.Eat(1500); // 1,500�� ¥�� ���� �Դ´�(?)
	chulsoo.Eat(20000, 1500); // 1,500�� ¥�� ���� �Դ´�.
	return 0;
}

int Chulsoo::Eat(int SteakNum, int WaterNum, int CoffeeNum)
{
	cout << "ö���� " << SteakNum << "�� ¥�� ������ũ�� �԰�, ";
	cout << WaterNum << "�� ¥�� ���� �԰�, ";
	cout << CoffeeNum << "�� ¥�� Ŀ�Ǹ� �Դ´�." << endl;
	return SteakNum;
}