#include <iostream>
using namespace std;

class Chulsoo
{
public:
	int count; // ö���� ������ũ�� �Դ� Ƚ��
};

int main(void)
{
	Chulsoo chulsoo;
	chulsoo.count = 1; 
	for (int i = 0; i < 10; i++)
	{
		[&]{cout << "eatLambda() :: ö���� " << chulsoo.count++ << "��° g ¥�� ������ũ�� �Դ´�" << endl; }();
	}
	return 0;
}