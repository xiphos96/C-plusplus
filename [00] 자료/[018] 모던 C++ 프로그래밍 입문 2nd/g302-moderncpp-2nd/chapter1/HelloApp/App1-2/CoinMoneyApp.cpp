//=========================================================
// 응용 과제 1-2
// 응용 과제 1-1을 발전시킴
// 동전 다발 처리 - C++ 버전
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
	printf("50원 %d개, 100원 %d개, 500원 %d개, 총 %d원\n",
		m.c50, m.c100, m.c500, CoinMoney_value(m));
	*/
	// stream io
	cout << "50원 " << m.c50 << "개, "
		<< "100원 " << m.c100 << "개, "
		<< "500원 " << m.c500 << "개, "
		<< "총 " << CoinMoney_value(m) << "원" << endl;
}

auto main() -> int				// 다른 함수 스타일
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
//	printf("m1은 ");
//	printf("총 %d원\n", value);
	cout << "m1은 총 " << value << "원" << endl;
	m3 = CoinMoney_add(m1, m2);
//	printf("m3 = ");
	cout << "m3 = ";
	CoinMoney_print(m3);

	return 0;
}