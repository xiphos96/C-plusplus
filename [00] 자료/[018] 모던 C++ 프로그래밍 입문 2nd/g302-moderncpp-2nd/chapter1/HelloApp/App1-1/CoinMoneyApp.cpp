//=========================================================
// 응용 과제 1-1
// 실습 과제를 발전시킴
// 동전 다발 처리 - C 버전
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
	printf("50원 %d개, 100원 %d개, 500원 %d개, 총 %d원\n",
		m.c50, m.c100, m.c500, CoinMoney_value(m));
}

int main()
{
	struct CoinMoney m1, m2, m3;	// 3개의 CoinMoney 변수
	int value;
	m1.c50 = 1;						// m1 초기화
	m1.c100 = 2;
	m1.c500 = 3;
	printf("m1 = ");
	CoinMoney_print(m1);			// m1의 구성 요소와 총금액 출력
	m2 = m1;						// 구조체끼리 배정, 구조체 필드 각각을 배정함
	printf("m2 = ");
	CoinMoney_print(m2);			// m2의 구성 요소와 총금액 출력
	value = CoinMoney_value(m1);	// m1의 총금액 계산
	printf("m1은 ");
	printf("총 %d원\n", value);		// m1의 총금액 출력
	m3 = CoinMoney_add(m1, m2);		// m1과 m2를 더해서 m3에 배정
	printf("m3 = ");
	CoinMoney_print(m3);			// m3의 구성 요소와 총금액 출력

	return 0;
}