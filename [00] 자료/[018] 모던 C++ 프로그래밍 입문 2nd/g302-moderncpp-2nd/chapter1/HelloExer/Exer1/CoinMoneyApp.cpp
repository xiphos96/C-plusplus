// 응용 과제 1을 발전시킴
#include <iostream>
using std::cout; using std::endl;
using std::cin;				// Exer

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

void CoinMoney_print(const CoinMoney& m)
{
	cout << "50원 " << m.c50 << "개, "
		<< "100원 " << m.c100 << "개, "
		<< "500원 " << m.c500 << "개, "
		<< "총 " << CoinMoney_value(m) << "원" << endl;
}

auto main(void) -> int
{
	CoinMoney m1, m2, m3;
	// Exer
	cout << "동전다발을 입력하세요." << endl;
	cout << "50원짜리 동전: ";
	cin >> m1.c50;
	cout << "100원짜리 동전: ";
	cin >> m1.c100;
	cout << "500원짜리 동전: ";
	cin >> m1.c500;
	cout << "m1 = ";
	CoinMoney_print(m1);
	m2 = m1;
	cout << "m2 = ";
	CoinMoney_print(m2);
	auto value = CoinMoney_value(m1);
	cout << "m1은 총 " << value << endl;
	m3 = CoinMoney_add(m1, m2);
	cout << "m3 = ";
	CoinMoney_print(m3);

	return 0;
}