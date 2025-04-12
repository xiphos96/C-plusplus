//=========================================================
// ���� ���� 1-1
// �ǽ� ������ ������Ŵ
// ���� �ٹ� ó�� - C ����
//=========================================================
#include <stdio.h>

// structure for CoinMoney - three int members
struct CoinMoney {
	int c50;
	int c100;
	int c500;
};

int CoinMoney_value(struct CoinMoney m)
{
	return (50 * m.c50 + 100 * m.c100 + 500 * m.c500);
}

struct CoinMoney CoinMoney_add(struct CoinMoney m1, struct CoinMoney m2)
{
	struct CoinMoney sum;
	sum.c50 = m1.c50 + m2.c50;
	sum.c100 = m1.c100 + m2.c100;
	sum.c500 = m1.c500 + m2.c500;
	return sum;
}

void CoinMoney_print(struct CoinMoney m)
{
	printf("50�� %d��, 100�� %d��, 500�� %d��, �� %d��\n",
		m.c50, m.c100, m.c500, CoinMoney_value(m));
}

int main()
{
	struct CoinMoney m1, m2, m3;	// 3���� CoinMoney ����
	int value;
	m1.c50 = 1;						// m1 �ʱ�ȭ
	m1.c100 = 2;
	m1.c500 = 3;
	printf("m1 = ");
	CoinMoney_print(m1);			// m1�� ���� ��ҿ� �ѱݾ� ���
	m2 = m1;						// ����ü���� ����, ����ü �ʵ� ������ ������
	printf("m2 = ");
	CoinMoney_print(m2);			// m2�� ���� ��ҿ� �ѱݾ� ���
	value = CoinMoney_value(m1);	// m1�� �ѱݾ� ���
	printf("m1�� ");
	printf("�� %d��\n", value);		// m1�� �ѱݾ� ���
	m3 = CoinMoney_add(m1, m2);		// m1�� m2�� ���ؼ� m3�� ����
	printf("m3 = ");
	CoinMoney_print(m3);			// m3�� ���� ��ҿ� �ѱݾ� ���

	return 0;
}