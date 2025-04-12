//=========================================================
// ���� ���� 1-1
// 1���� ���� ���� 1�� ������Ŵ
// C ������ ����
//=========================================================
#include <iostream>
using std::cout; using std::endl;

struct CoinMoney {
	int c50;
	int c100;
	int c500;
};

inline int CoinMoney_value(const CoinMoney& m)
{
	return (50 * m.c50 + 100 * m.c100 + 500 * m.c500);
}
// ���� ���� 1-1, C ������
CoinMoney* CoinMoney_add(const CoinMoney* m1, const CoinMoney* m2)
{
	CoinMoney* psum(new CoinMoney());		// CoinMoney* psum = new CoinMoney();
	psum->c50 = m1->c50 + m2->c50;
	psum->c100 = m1->c100 + m2->c100;
	psum->c500 = m1->c500 + m2->c500;
	return psum;
}

void CoinMoney_print(const CoinMoney& m)
{
	cout << "50�� " << m.c50 << "��, "
		<< "100�� " << m.c100 << "��, "
		<< "500�� " << m.c500 << "��, "
		<< "�� " << CoinMoney_value(m) << "��" << endl;
}

int main()
{
	CoinMoney* pm1 = new CoinMoney();		// C ������
	CoinMoney* pm2 = new CoinMoney();
	pm1->c50 = 1;
	pm1->c100 = 2;
	pm1->c500 = 3;
	cout << "m1 = ";	
	CoinMoney_print(*pm1);
	*pm2 = *pm1;
	cout << "m2 = ";
	CoinMoney_print(*pm2);
	auto value = CoinMoney_value(*pm1);
	cout << "m1�� �� " << value << endl;
	// auto -> CoinMoney*
	auto pm3 = CoinMoney_add(pm1, pm2);
	cout << "m3 = ";
	CoinMoney_print(*pm3);
	// ���� ���� 1-1
	delete pm1;
	delete pm2;
	delete pm3;
	return 0;
}