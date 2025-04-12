// 응용 과제 1을 발전시킴
// string
#include <iostream>
#include <string>		// Exer
using std::string;
using std::cout; using std::endl;

struct CoinMoney {
	int c50;
	int c100;
	int c500;
	string owner;		// Exer
};

inline int CoinMoney_value(const CoinMoney& m)
{
	return (50 * m.c50 + 100 * m.c100 + 500 * m.c500);
}
// Exer
CoinMoney CoinMoney_add(const CoinMoney& m1, const CoinMoney& m2)
{
	CoinMoney sum;
	sum.c50 = m1.c50 + m2.c50;
	sum.c100 = m1.c100 + m2.c100;
	sum.c500 = m1.c500 + m2.c500;
	if (m1.owner == m2.owner)
		sum.owner = m1.owner;
	else
		sum.owner = m1.owner + " & " + m2.owner;
	return sum;
}

void CoinMoney_print(const CoinMoney& m)
{
	cout << m.owner << ": "				// Exer
		<< "50원 " << m.c50 << "개, "
		<< "100원 " << m.c100 << "개, "
		<< "500원 " << m.c500 << "개, "
		<< "총 " << CoinMoney_value(m) << "원" << endl;
}

auto main(void) -> int
{
	CoinMoney m1, m2, m3;
	m1.c50 = 1;
	m1.c100 = 2;
	m1.c500 = 3;
	m1.owner = "doohun";		// Exer
	cout << "m1 = ";
	CoinMoney_print(m1);
	// Exer
	m2.c50 = 2;
	m2.c100 = 1;
	m2.c500 = 4;
	m2.owner = "youngmi";
	cout << "m2 = ";
	CoinMoney_print(m2);
	m3 = CoinMoney_add(m1, m2);
	cout << "m1 + m2 = ";		// Exer
	CoinMoney_print(m3);

	return 0;
}