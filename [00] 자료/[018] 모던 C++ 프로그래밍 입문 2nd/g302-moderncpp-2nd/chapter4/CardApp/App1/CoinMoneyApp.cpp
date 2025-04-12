//=========================================================
// 응용 과제 1
// 3장의 응용 과제 1을 발전시킴
// inheritance
//=========================================================
#include <iostream>
#include <string>		// 응용 과제 1
#include <memory>
using std::string; using std::shared_ptr;
using std::static_pointer_cast;
using std::cout; using std::endl;
using std::ostream;

class CoinMoney
{
public:
	CoinMoney() : c50(0), c100(0), c500(0)
	{ cout << "CoinMoney default ctor" << endl; }

	CoinMoney(int c, int cc, int ccc)
		: c50(c), c100(cc), c500(ccc)
	{ cout << "CoinMoney ctor" << endl; }

	virtual ~CoinMoney()
	{ cout << "CoinMoney dtor" << endl; }

	virtual int get_value() const
	{ return (50 * c50 + 100 * c100 + 500 * c500); }

	int get_c50() const { return c50; }
	int get_c100() const { return c100; }
	int get_c500() const { return c500; }
	void set_c50(int c) { c50 = c; }
	void set_c100(int cc) { c100 = cc; }
	void set_c500(int ccc) { c500 = ccc; }
protected:
	int c50, c100, c500;
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
// 응용 과제 1
class MyCoinMoney : public CoinMoney
{
public:
	MyCoinMoney(int nc, int c, int cc, int ccc, string name)
		: CoinMoney(c, cc, ccc),  c10(nc), owner(name)
	{ cout << "MyCoinMoney ctor" << endl; }
	// same as default dtor
	~MyCoinMoney()
	{ cout << "MyCoinMoney dtor" << endl; }

	virtual int get_value() const
	{ return (10 * c10 + 50 * c50 + 100 * c100 + 500 * c500); }
	// friend declaration for operator<<
	friend ostream& operator<<(ostream&, const MyCoinMoney&);
private:
	int c10;
	string owner;
};
// operator<< overloading
ostream& operator<<(ostream& os, const MyCoinMoney& m)
{
	os << m.owner << ": "
		<< "10원 " << m.c10 << "개, "
		<< "50원 " << m.c50 << "개, "
		<< "100원 " << m.c100 << "개, "
		<< "500원 " << m.c500 << "개, "
		<< "총 " << m.get_value() << "원" << endl;
	return os;
}

int main()
{
//	MyCoinMoney m1;					// error!!, no default ctor
	MyCoinMoney m2{ 1, 2, 3, 4, "doohun" };	// uniform initializer
	cout << "m2 = " << m2;
	// up-casting
	shared_ptr<CoinMoney> pm3(new MyCoinMoney(4, 3, 2, 1, "youngmi"));
	cout << "m3 = " << *pm3;
	// down-casting
	shared_ptr<MyCoinMoney> pm = static_pointer_cast<MyCoinMoney>(pm3);
	cout << "m3 = " << *pm;

	return 0;
}