#include <iostream>
using namespace std;

class Chulsoo
{
public:
	void Eat(void);
	void Eat(int SteakNum);
	void Eat(double SteakWeight);
	void Eat(int SteakNum1, int SteakNum2);
};

int main(void)
{
	Chulsoo chulsoo;
	chulsoo.Eat();
	chulsoo.Eat(20000);
	chulsoo.Eat(500.5);
	chulsoo.Eat(20000, 30000);
	return 0;
}

void Chulsoo::Eat(void)
{
	cout << "ö���� ������ũ�� �Դ´�" << endl;
}

void Chulsoo::Eat(int SteakNum)
{
	cout << "ö���� " << SteakNum << "�� ¥�� ������ũ�� �Դ´�" << endl;
}

void Chulsoo::Eat(double SteakWeight)
{
	cout << "ö���� " << SteakWeight << "g ¥�� ������ũ�� �Դ´�" << endl;
}

void Chulsoo::Eat(int SteakNum1, int SteakNum2)
{
	cout << "ö���� " << SteakNum1 << "�� ¥�� ������ũ�� �԰�, ";
	cout << SteakNum2 << "�� ¥�� ������ũ�� �Դ´�" << endl;
}