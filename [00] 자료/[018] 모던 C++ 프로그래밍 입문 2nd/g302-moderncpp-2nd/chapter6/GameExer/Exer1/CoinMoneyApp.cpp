// 3���� ���� ���� 1�� ������Ŵ
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
		cout << "50�� " << c50 << "��, "
			<< "100�� " << c100 << "��, "
			<< "500�� " << c500 << "��, "
			<< "�� " << get_value() << "��" << endl;
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
	os << "50�� " << m.get_c50() << "��, "
		<< "100�� " << m.get_c100() << "��, "
		<< "500�� " << m.get_c500() << "��, "
		<< "�� " << m.get_value() << "��" << endl;
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
	cout << "�����̳� ����:" << endl;
	for (const auto& e : coinMap)
		cout << e.first << ": " << e.second;
	cout << "�� ���� �˻�:" << endl;
	string name = "youngmi";
	multimap<string, CoinMoney>::iterator it;
	it = coinMap.find(name);
	if (it == coinMap.end())
		cout << name << "�� �����ٹ��� �����ϴ�" << endl;
	else
		cout << (*it).first << ": " << (*it).second;
	cout << "��� ���� �˻�:" << endl;
	pair<multimap<string, CoinMoney>::iterator,
		multimap<string, CoinMoney>::iterator> ret;
	ret = coinMap.equal_range(name);
	for (it = ret.first; it != ret.second; ++it)
		cout << (*it).first << ": " << (*it).second;

	return 0;
}