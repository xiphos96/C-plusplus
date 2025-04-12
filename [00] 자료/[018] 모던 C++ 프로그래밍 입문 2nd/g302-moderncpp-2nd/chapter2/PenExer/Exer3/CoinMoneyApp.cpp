// 응용 과제 1을 발전시킴
// smart pointer array
#include <iostream>
#include <memory>
using std::cout; using std::endl;
using std::shared_ptr;
using std::make_shared;			// Exer

struct CoinMoney {
	int c50;
	int c100;
	int c500;
};

inline int CoinMoney_value(const CoinMoney& m)
{
	return (50 * m.c50 + 100 * m.c100 + 500 * m.c500);
}

shared_ptr<CoinMoney> CoinMoney_add(const shared_ptr<CoinMoney> m1,
									const shared_ptr<CoinMoney> m2)
{
	shared_ptr<CoinMoney> psum(new CoinMoney());
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
	// Exer
	shared_ptr<CoinMoney> pm[3];
	for (size_t k = 0; k < 3; ++k) {
		pm[k] = make_shared<CoinMoney>();
		pm[k]->c50 = k + 1;
		pm[k]->c100 = k + 2;
		pm[k]->c500 = k + 3;
	}
	for (auto p : pm)
		CoinMoney_print(*p);

	return 0;
}