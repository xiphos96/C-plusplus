// 응용 과제 1을 발전시킴
// remove print member function
// list, smart pointer, accumulate, functor
#include <iostream>
#include <list>				// list
#include <numeric>			// accumulate
#include <memory>			// shared_ptr, make_shared
using std::cout; using std::endl;
using std::ostream;
using std::list; using std::accumulate;
using std::shared_ptr; using std::make_shared;

class CoinMoney
{
public:
	CoinMoney() : c50(0), c100(0), c500(0)
	{}

	CoinMoney(int c, int cc, int ccc)
		: c50(c), c100(cc), c500(ccc)
	{}

	virtual ~CoinMoney()
	{}

	int get_value() const
	{
		return (50 * c50 + 100 * c100 + 500 * c500);
	}

	int get_c50() const { return c50; }
	int get_c100() const { return c100; }
	int get_c500() const { return c500; }

	void set_c50(int c) { c50 = c; }
	void set_c100(int cc) { c100 = cc; }
	void set_c500(int ccc) { c500 = ccc; }
protected:
	int c50;
	int c100;
	int c500;
};

CoinMoney add(const CoinMoney& m1, const CoinMoney& m2)
{
	CoinMoney sum;
	sum.set_c50(m1.get_c50() + m2.get_c50());
	sum.set_c100(m1.get_c100() + m2.get_c100());
	sum.set_c500(m1.get_c500() + m2.get_c500());
	return sum;
}

ostream& operator<<(ostream& os, const CoinMoney& m)
{
	os << "50원 " << m.get_c50() << "개, "
		<< "100원 " << m.get_c100() << "개, "
		<< "500원 " << m.get_c500() << "개, "
		<< "총 " << m.get_value() << "원" << endl;
	return os;
}

// Exer: functor with two parameters
// int => accumulated value, pointer => element type of list
class CoinValueSum
{
public:
	int operator()(const int sum, const shared_ptr<CoinMoney>& p) {
		return (sum + p->get_value());
	}
};

int main()
{
	shared_ptr<CoinMoney> pm1(new CoinMoney(1, 2, 3));
	shared_ptr<CoinMoney> pm2 = make_shared<CoinMoney>(4, 2, 1);
	shared_ptr<CoinMoney> pm3(new CoinMoney(3, 2, 4));
	shared_ptr<CoinMoney> pm4 = make_shared<CoinMoney>(6, 3, 1);
	// Exer: let's use short type name
	typedef shared_ptr<CoinMoney> CMPtr;
	CMPtr pm5(new CoinMoney(3, 3, 4));
	CMPtr pm6 = make_shared<CoinMoney>(5, 2, 1);
	// uniform initializer
	list<CMPtr> coinList{ pm1, pm2, pm3, pm4, pm5, pm6 };
	// print each CoinMoney
	for (auto pm : coinList)			// auto => const CMPtr&
		cout << *pm;
	// Exer: accumulate CoinMoney values
	CoinValueSum functor;
	int sum = accumulate(coinList.begin(), coinList.end(), 0, functor);
	cout << "총: " << sum << "원" << endl;

	return 0;
}