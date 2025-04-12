// 응용 과제 1을 발전시킴
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
		<< "50원 " << m.c50 << "개, "
		<< "100원 " << m.c100 << "개, "
		<< "500원 " << m.c500 << "개, "
		<< "총 " << CoinMoney_value(m) << "원" << endl;
}
// Exer
void CoinMoney_increment(CoinMoney& m)
{
	cout << "lvalue 레퍼런스 파라미터" << endl;
	++m.c50; ++m.c100; ++m.c500;
	cout << "increment 효과를 main에 전달" << endl;
}
// Exer
void CoinMoney_increment(CoinMoney&& m)
{
	cout << "rvalue 레퍼런스 파라미터" << endl;
	++m.c50; ++m.c100; ++m.c500;
	cout << "increment 효과는 무!" << endl;
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