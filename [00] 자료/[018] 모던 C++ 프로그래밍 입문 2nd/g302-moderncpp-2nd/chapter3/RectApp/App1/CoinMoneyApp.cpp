//=========================================================
// 응용 과제 1
// 1장의 응용 과제 1을 발전시킴
// class
//=========================================================
#include <iostream>
using std::cout; using std::endl;
using std::ostream;

class CoinMoney
{
public:
	// default constructor - no parameters
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
// operator<< overloading
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
	CoinMoney m1(1, 2, 3);		// initialized by constructor with parameters
	CoinMoney m2, m3;			// initialized by default constructor
	cout << "m1 = ";				// print values using print member function
	m1.print();					
	cout << "m2 = " << m2;		// print values using operator<<
//	m2.c50 = 3;					// error! protected members!
	m2.set_c50(1);
	m2.set_c100(2);
	m2.set_c500(3);
	cout << "m1은 " << m1.get_value() << "원" << endl;
	m2 = m1;						// default operator=
	cout << "m2 = " << m2;
	m3 = add(m1, m2);			// use add function to add members
	cout << "m3 = " << m3;

	return 0;
}