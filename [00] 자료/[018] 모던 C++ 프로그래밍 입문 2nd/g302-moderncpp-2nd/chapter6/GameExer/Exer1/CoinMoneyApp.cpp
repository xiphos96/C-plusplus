// 3장의 응용 과제 1을 발전시킴
// multimap
#include <iostream>
#include <map>					// Exer
#include <string>
using std::multimap; using std::pair;
using std::string;
using std::cout; using std::endl;
using std::ostream;

class CoinMoney
{
public:
	// default constructor - no arguments
	CoinMoney() : c50(0), c100(0), c500(0)
	{}
	// constructor with parameters
	CoinMoney(int c, int cc, int ccc)
		: c50(c), c100(cc), c500(ccc)
	{}
	// virtual destructor instead of default destructor
	virtual ~CoinMoney()
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
	// getters
	int get_c50() const { return c50; }
	int get_c100() const { return c100; }
	int get_c500() const { return c500; }
	// setters
	void set_c50(int c) { c50 = c; }
	void set_c100(int cc) { c100 = cc; }
	void set_c500(int ccc) { c500 = ccc; }
protected:
	int c50;
	int c100;
	int c500;
};

// global function
CoinMoney add(const CoinMoney& m1, const CoinMoney& m2)
{
	CoinMoney sum;
	sum.set_c50(m1.get_c50() + m2.get_c50());
	sum.set_c100(m1.get_c100() + m2.get_c100());
	sum.set_c500(m1.get_c500() + m2.get_c500());
	return sum;
}
// << operator overroding
ostream& operator<<(ostream& os, const CoinMoney& m)
{
	os << "50원 " << m.get_c50() << "개, "
		<< "100원 " << m.get_c100() << "개, "
		<< "500원 " << m.get_c500() << "개, "
		<< "총 " << m.get_value() << "원" << endl;
	return os;
}

int main()
{
	multimap<string, CoinMoney> coinMap;
	CoinMoney m1{ 1, 2, 3 };
	CoinMoney m2{ 3, 4, 5 };
	CoinMoney m3{ 3, 2, 1 };
	CoinMoney m4{ 2, 4, 3 };
	CoinMoney m5{ 4, 3, 2 };
	CoinMoney m6{ 3, 4, 3 };
	coinMap.insert({
		{ "doohun", m1 }, { "doohun", m2 }, { "doohun", m3 },
		{ "youngmi", m4 }, { "doohun", m5 }, { "youngmi", m6 }
	});
	// Exer
	cout << "컨테이너 내용:" << endl;
	for (const auto& e : coinMap)
		cout << e.first << ": " << e.second;
	cout << "한 원소 검색:" << endl;
	string name = "youngmi";
	multimap<string, CoinMoney>::iterator it;
	it = coinMap.find(name);
	if (it == coinMap.end())
		cout << name << "의 동전다발은 없습니다" << endl;
	else
		cout << (*it).first << ": " << (*it).second;
	cout << "모든 원소 검색:" << endl;
	pair<multimap<string, CoinMoney>::iterator,
		multimap<string, CoinMoney>::iterator> ret;
	ret = coinMap.equal_range(name);
	for (it = ret.first; it != ret.second; ++it)
		cout << (*it).first << ": " << (*it).second;

	return 0;
}