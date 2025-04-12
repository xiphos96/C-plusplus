//=========================================================
// ���� ���� 1-2
// ���� ���� 1-1�� ������Ŵ
// ���� �ٹ� ó�� - C++ ����
//=========================================================
//#include <cstdio>
#include <iostream>			// <iostream>
using std::cout; using std::endl;

struct CoinMoney {
	int c50;
	int c100;
	int c500;
};
// inline, const CoinMoney&
inline int CoinMoney_value(const CoinMoney& m)
{
	return (50 * m.c50 + 100 * m.c100 + 500 * m.c500);
}
// struct CoinMoney->CoinMoney
CoinMoney CoinMoney_add(const CoinMoney& m1, const CoinMoney& m2)
{
	CoinMoney sum;
	sum.c50 = m1.c50 + m2.c50;
	sum.c100 = m1.c100 + m2.c100;
	sum.c500 = m1.c500 + m2.c500;
	return sum;
}

void CoinMoney_print(const CoinMoney& m)
{
	/*
	printf("50�� %d��, 100�� %d��, 500�� %d��, �� %d��\n",
		m.c50, m.c100, m.c500, CoinMoney_value(m));
	*/
	// stream io
	cout << "50�� " << m.c50 << "��, "
		<< "100�� " << m.c100 << "��, "
		<< "500�� " << m.c500 << "��, "
		<< "�� " << CoinMoney_value(m) << "��" << endl;
}

auto main() -> int				// �ٸ� �Լ� ��Ÿ��
{
	CoinMoney m1, m2, m3;
//	int value;
	m1.c50 = 1;
	m1.c100 = 2;
	m1.c500 = 3;
//	printf("m1 = ");
	cout << "m1 = ";				// stream io
	CoinMoney_print(m1);
	m2 = m1;
//	printf("m2 = ");
	cout << "m2 = ";
	CoinMoney_print(m2);
	auto value = CoinMoney_value(m1);	// auto
//	printf("m1�� ");
//	printf("�� %d��\n", value);
	cout << "m1�� �� " << value << "��" << endl;
	m3 = CoinMoney_add(m1, m2);
//	printf("m3 = ");
	cout << "m3 = ";
	CoinMoney_print(m3);

	return 0;
}