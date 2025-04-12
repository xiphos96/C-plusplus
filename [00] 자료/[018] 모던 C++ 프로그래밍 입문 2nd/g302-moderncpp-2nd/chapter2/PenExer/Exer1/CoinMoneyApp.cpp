// 응용 과제 1을 발전시킴
// template function
#include <iostream>
#include <memory>
using std::cout; using std::endl;
using std::shared_ptr;

struct CoinMoney {
	int c50;
	int c100;
	int c500;
};

inline int CoinMoney_value(const CoinMoney& m)
{
	return (50 * m.c50 + 100 * m.c100 + 500 * m.c500);
}
// Exer: template
template <typename T>
T CoinMoney_add(const T m1, const T m2)
{
	T psum(new CoinMoney());
	psum->c50 = m1->c50 + m2->c50;
	psum->c100 = m1->c100 + m2->c100;
	psum->c500 = m1->c500 + m2->c500;
	return psum;
}

void CoinMoney_print(const CoinMoney& m)
{
	cout << "50원 " << m.c50 << "개, "
		<< "100원 " << m.c100 << "개, "
		<< "500원 " << m.c500 << "개, "
		<< "총 " << CoinMoney_value(m) << "원" << endl;
}

int main()
{
	// Exer: shared_ptr type(smart pointer)
	shared_ptr<CoinMoney> sp1(new CoinMoney());
	shared_ptr<CoinMoney> sp2(new CoinMoney());
	sp1->c50 = 1; sp1->c100 = 2; sp1->c500 = 3;
	sp2->c50 = 2; sp2->c100 = 3; sp2->c500 = 4;
	shared_ptr<CoinMoney> sp3 = CoinMoney_add(sp1, sp2);	
	cout << "두 동전다발의 합: ";
	CoinMoney_print(*sp3);
	// Exer: CoinMoney* type(C-pointer)
	CoinMoney* cp1(new CoinMoney());
	CoinMoney* cp2(new CoinMoney());
	cp1->c50 = 3; cp1->c100 = 4; cp1->c500 = 5;
	cp2->c50 = 4; cp2->c100 = 5; cp2->c500 = 6;
	CoinMoney* cp3 = CoinMoney_add(cp1, cp2);
	cout << "두 동전다발의 합: ";
	CoinMoney_print(*cp3);

	delete cp1;
	delete cp2;
	delete cp3;
	return 0;
}