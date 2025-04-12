#include <iostream>
using namespace std;

class Chulsoo;

class Younghee
{
private:
	int age;
public:
	Younghee(int age) : age(age)
	{
		cout << "Younghee::Younghee(age) ������ �Ϸ�" << endl;
	}
	void introduce()
	{
		cout << "���� ���� : " << age << endl;
	}
	void whoIsOlder(const Chulsoo & chulsooObj);
};

class Chulsoo
{
private:
	int age;
public:
	Chulsoo(int age) : age(age)
	{
		cout << "Chulsoo::Chulsoo(age) ������ �Ϸ�" << endl;
	}
	void introduce()
	{
		cout << "ö�� ���� : " << age << endl;
	}
	friend void Younghee::whoIsOlder(const Chulsoo & chulsooObj);
};

void Younghee::whoIsOlder(const Chulsoo & chulsooObj)
{
	cout << "����� ö������ " << ((age > chulsooObj.age) ? "���̰� ����" : "���̰� ���ų� ����") << endl;
}

int main(void)
{
	Chulsoo chulsoo1(32);
	chulsoo1.introduce();
	Younghee younghee1(35);
	younghee1.introduce();

	younghee1.whoIsOlder(chulsoo1);

	return 0;
}