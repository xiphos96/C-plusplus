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
	// ��ȯ���� char�� ������ ���� �Լ�
	cout << [=](int steakWeight)mutable->char{cout << "eatLambda() :: ö���� " << chulsoo.count++ << "��° " << steakWeight << "g ¥�� ������ũ�� �Դ´�" << endl; return steakWeight; }(67) << endl;
	// ��ȯ���� int�� ������ ���� �Լ�
	cout << [=](int steakWeight)mutable->int{cout << "eatLambda() :: ö���� " << chulsoo.count++ << "��° " << steakWeight << "g ¥�� ������ũ�� �Դ´�" << endl; return steakWeight; }(67) << endl;
	// ��ȯ���� �������� �ʾ�����, steakWeight�� ��ȯ�ϹǷ� int
	cout << [=](int steakWeight)mutable{cout << "eatLambda() :: ö���� " << chulsoo.count++ << "��° " << steakWeight << "g ¥�� ������ũ�� �Դ´�" << endl; return steakWeight; }(67) << endl;

	return 0;
}