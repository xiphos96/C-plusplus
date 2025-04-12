#include <iostream>
using namespace std;

class Chulsoo
{
private:
	int age;
	static int chulsooPrivateCounter;
protected:
	static int chulsooProtectedCounter;
public:
	static int chulsooPublicCounter;
	Chulsoo(int age) : age(age)
	{
		chulsooPrivateCounter++;
		chulsooProtectedCounter++;
		chulsooPublicCounter++;
		cout << "Chulsoo::Chulsoo(age) �����ڷ� ��������� " << 
			chulsooPrivateCounter << "(Priavte) ��° ��ü ���� �Ϸ�" << endl;
		cout << "Chulsoo::Chulsoo(age) �����ڷ� ��������� " <<
			chulsooProtectedCounter << "(Protected)��° ��ü ���� �Ϸ�" << endl;
		cout << "Chulsoo::Chulsoo(age) �����ڷ� ��������� " <<
			chulsooPublicCounter << "(Public)��° ��ü ���� �Ϸ�" << endl;
	}
};
int Chulsoo::chulsooPrivateCounter = 0;
int Chulsoo::chulsooProtectedCounter = 0;
int Chulsoo::chulsooPublicCounter = 0;

class Younghee
{
private:
	int age;
public:
	Younghee(int age) : age(age)
	{
		//Chulsoo::chulsooPrivateIntroduceCounter++;
		//Chulsoo::chulsooProtectedIntroduceCounter++;
		Chulsoo::chulsooPublicCounter++;
		cout << "Younghee::Younghee(age) �����ڷ� ��������� " <<
			Chulsoo::chulsooPublicCounter << "��° ��ü ���� �Ϸ�" << endl;
	}
};

int main(void)
{
	Chulsoo chulsoo1(32);
	Chulsoo chulsoo2(32);
	Younghee younghee1(32);
	Younghee younghee2(32);
	return 0;
}