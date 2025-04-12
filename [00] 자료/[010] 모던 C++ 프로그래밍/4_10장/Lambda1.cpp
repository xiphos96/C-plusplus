#include <iostream>
using namespace std;

class Chulsoo
{
public:
	void eat(int steakWeight);
	inline void eatInline(int steakWeight)
	{
		cout << "eatInline() :: ö���� " << steakWeight << "g ¥�� ������ũ�� �Դ´�" << endl;
	}
};

int main(void)
{
	Chulsoo chulsoo;
	chulsoo.eat(1000);
	chulsoo.eatInline(1000);
	[](int steakWeight){cout << "eatLambda() :: ö���� " << steakWeight << "g ¥�� ������ũ�� �Դ´�" << endl; }(1000);
	return 0;
}

void Chulsoo::eat(int steakWeight)
{
	cout << "eat() :: ö���� " << steakWeight << "g ¥�� ������ũ�� �Դ´�" << endl;
}