// 7-1.cpp

#include <iostream.h>

class Date	// 사용자 타입 Date 작성
{
// 비공개 멤버 데이터
	int	m_year;	// 年
	int	m_month;	// 月
	int	m_day;	// 日

public:
	// 공개 멤버 함수
	void	setDate(int year, int month, int day);	// 날짜 설정
	int	getYear();		// 年 얻기
	int	getMonth();	// 月 얻기
	int	getDay();		// 日
	void	print();		// 날짜 출력
};		// 클래스 명세 끝

void
Date::setDate(int year, int month, int day)
{
m_year = year;
m_month = month;
m_day = day;
}

int
Date::getYear()
{
	return	m_year;
}

int
 Date::getMonth()
{
	return	m_month;
}

int
Date::getDay()
{
	return	m_day;
}

void
Date::print()
{
	cout << m_year << "년 " <<  m_month << "월 " << m_day << "일";
}

void main()
{
Date today;

today.setDate(2009, 1, 1);

int year = today.getYear();
int month = today.getMonth();
int day = today.getDay();

	cout	<< "오늘은 단기 " \
		<< year+2333 << "년 " \
 		<< month << "월 " \
		<< day << "일 입니다.\n";

	cout << "오늘은 서기 ";
		today.print();
	cout << " 입니다.\n";
}