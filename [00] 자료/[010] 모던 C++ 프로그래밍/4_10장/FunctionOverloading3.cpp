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
	chulsoo.Eat(20000, 30000); // � �Լ��� ȣ���ؾ� �ұ�?
	return 0;
}

void Chulsoo::Eat(void)
{
	cout << "ö���� ������ũ�� �Դ´�" << endl;
}

int Chulsoo::Eat(int SteakNum)
{
	cout << "ö���� " << SteakNum << "�� ¥�� ������ũ�� �Դ´�" << endl;
	return SteakNum;
}

double Chulsoo::Eat(double SteakWeight)
{
	cout << "ö���� " << SteakWeight << "g ¥�� ������ũ�� �Դ´�" << endl;
	return SteakWeight;
}

int Chulsoo::Eat(int SteakNum1, int SteakNum2)
{
	cout << "ö���� " << SteakNum1 << "�� ¥�� ������ũ�� �԰�, ";
	cout << SteakNum2 << "�� ¥�� ������ũ�� �Դ´�" << endl;
	return SteakNum2;
}

double Chulsoo::Eat(int SteakWeight1, int SteakWeight2)
{
	cout << "ö���� " << SteakWeight1 << "g ¥�� ������ũ�� �԰�, ";
	cout << SteakWeight2 << "g ¥�� ������ũ�� �Դ´�" << endl;
	return SteakWeight2;
}