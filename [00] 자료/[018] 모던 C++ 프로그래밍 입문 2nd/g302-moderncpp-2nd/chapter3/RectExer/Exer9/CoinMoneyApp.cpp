// 응용 과제 1을 발전시킴
// template class
#include <iostream>
#include <vector>
using std::cout; using std::endl;
using std::vector;

class KoreanCoinMoney
{
public:
	// ctor
	KoreanCoinMoney(int c, int cc, int ccc)
		: c50(c), c100(cc), c500(ccc)
	{}
	// member functions
	int get_value() const
	{
		return (50 * c50 + 100 * c100 + 500 * c500);
	}
	void print() const
	{
		cout << "50원 " << c50 << "개, "
			<< "100원 " << c100 << "개, "
			<< "500원 " << c500 << "개, "
			<< "총 " << get_value() << "원" << endl;
	}
	// member variables
	int c50;
	int c100;
	int c500;
};

class USCoinMoney
{
public:
	// ctor
	USCoinMoney(int c, int cc, int ccc)
		: nickels(c), dimes(cc), quarters(ccc)
	{}
	// member functions
	double get_value() const
	{
		return (5 * nickels + 10 * dimes + 25 * quarters) / 100.0;
	}
	void print() const
	{
		cout << "nickels " << nickels << "개, "
			<< "dimes " << dimes << "개, "
			<< "quarters " << quarters << "개, "
			<< "총 " << "$" << get_value() << endl;
	}
	// member variables
	int nickels;
	int dimes;
	int quarters;
};

template <typename CoinType>
class CoinContainer
{
public:
	void addCoin(const CoinType& c) {
		coinVect.push_back(c);
	}
	CoinType topCoin() {
		CoinType c = coinVect.back();
		coinVect.pop_back();
		return c;
	}
	void print() const {
		for (auto c : coinVect)
			c.print();
	}
private:
	vector<CoinType> coinVect;
};

int main()
{
	// KoreanCoinMoney Container
	KoreanCoinMoney km1(4, 5, 6); KoreanCoinMoney km2(3, 3, 4);
	KoreanCoinMoney km3(4, 5, 6); KoreanCoinMoney km4(5, 4, 6);
	CoinContainer<KoreanCoinMoney> kContainer;
	kContainer.addCoin(km1); kContainer.addCoin(km2);
	kContainer.addCoin(km3); kContainer.addCoin(km4);
	cout << "KoreanCoinMoney Container:" << endl;
	kContainer.print();
	// take the last coin out of container
	cout << "the last coin is" << endl;
	auto c = kContainer.topCoin();
	c.print();
	cout << "KoreanCoinMoney Container now becomes" << endl;
	kContainer.print();
	// USCoinMoney Container
	USCoinMoney um1(4, 5, 6); USCoinMoney um2(5, 4, 6);
	USCoinMoney um3(7, 4, 6); USCoinMoney um4(4, 3, 8);
	CoinContainer<USCoinMoney> uContainer;
	uContainer.addCoin(um1); uContainer.addCoin(um2);
	uContainer.addCoin(um3); uContainer.addCoin(um4);
	cout << "USCoinMoney Container:" << endl;
	uContainer.print();

	return 0;
}