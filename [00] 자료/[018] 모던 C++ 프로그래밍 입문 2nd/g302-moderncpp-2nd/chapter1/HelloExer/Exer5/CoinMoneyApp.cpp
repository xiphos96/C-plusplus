// ���� ���� 1�� ������Ŵ
// rvalue reference, default param, uniform initialization
#include <iostream>
#include <string>
using std::cout; using std::endl;
using std::string;

struct CoinMoney {
	int c50;
	int c100;
	int c500;
};

inline int CoinMoney_value(const CoinMoney& m)
{
	return (50 * m.c50 + 100 * m.c100 + 500 * m.c500);
}

CoinMoney CoinMoney_add(const CoinMoney& m1, const CoinMoney& m2)
{
	CoinMoney sum;
	sum.c50 = m1.c50 + m2.c50;
	sum.c100 = m1.c100 + m2.c100;
	sum.c500 = m1.c500 + m2.c500;
	return sum;
}
// Exer
void CoinMoney_print(const CoinMoney& m, string str = "doohun")
{
	cout << str << ": "
		<< "50�� " << m.c50 << "��, "
		<< "100�� " << m.c100 << "��, "
		<< "500�� " << m.c500 << "��, "
		<< "�� " << CoinMoney_value(m) << "��" << endl;
}
// Exer
void CoinMoney_increment(CoinMoney& m)
{
	cout << "lvalue ���۷��� �Ķ����" << endl;
	++m.c50; ++m.c100; ++m.c500;
	cout << "increment ȿ���� main�� ����" << endl;
}
// Exer
void CoinMoney_increment(CoinMoney&& m)
{
	cout << "rvalue ���۷��� �Ķ����" << endl;
	++m.c50; ++m.c100; ++m.c500;
	cout << "increment ȿ���� ��!" << endl;
}

auto main(void) -> int
{
	CoinMoney m;
	m.c50 = 1;
	m.c100 = 2;
	m.c500 = 3;
	cout << "m = ";
	CoinMoney_print(m);
	// Exer: lvalue reference call
	CoinMoney_increment(m);
	cout << "m = ";
	CoinMoney_print(m, "youngmi");
	// Exer: rvalue reference call, uniform initialization
	CoinMoney_increment({ 1, 2, 3 });

	return 0;
}