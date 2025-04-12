// 응용 과제 1을 발전시킴
// remove print member function and CoinMoney_add global function
// overload operator+ and operator== as member functions
#include <iostream>
using std::cout; using std::endl;
using std::ostream;

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
	// Exer: overloaded operator+ as a member function
	CoinMoney operator+(const CoinMoney& m2) const
	{
		return CoinMoney(c50 + m2.c50, c100 + m2.c100, c500 + m2.c500);
	}
	// Exer: overloaded operator== as a member function
	bool operator==(const CoinMoney& m2) const
	{
		return ((c50 == m2.c50) && (c100 == m2.c100) && (c500 == m2.c500));
	}

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
	CoinMoney m1{ 2, 0, 1 }, m2, m3;
	cout << "m1 = " << m1;
	m2 = m1;
	cout << "m2 = " << m2;
	if (m1 == m2)		// Exer
		cout << "m1 and m2 are equal" << endl;
	m2.set_c100(3);
	cout << "m2 is now " << m2;
	m3 = m1 + m2;		// Exer
	cout << "m3 = " << m3;

	return 0;
}