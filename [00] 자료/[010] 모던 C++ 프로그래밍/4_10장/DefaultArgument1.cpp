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
	cout << "ö���� " << SteakNum << "�� ¥�� ������ũ�� �Դ´�" << endl;
	return SteakNum;
}