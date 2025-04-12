// 7-1.cpp

#include <iostream.h>

class Date	// ����� Ÿ�� Date �ۼ�
{
// ����� ��� ������
	int	m_year;	// Ҵ
	int	m_month;	// ��
	int	m_day;	// ��

public:
	// ���� ��� �Լ�
	void	setDate(int year, int month, int day);	// ��¥ ����
	int	getYear();		// Ҵ ���
	int	getMonth();	// �� ���
	int	getDay();		// ��
	void	print();		// ��¥ ���
};		// Ŭ���� �� ��

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
	cout << m_year << "�� " <<  m_month << "�� " << m_day << "��";
}

void main()
{
Date today;

today.setDate(2009, 1, 1);

int year = today.getYear();
int month = today.getMonth();
int day = today.getDay();

	cout	<< "������ �ܱ� " \
		<< year+2333 << "�� " \
 		<< month << "�� " \
		<< day << "�� �Դϴ�.\n";

	cout << "������ ���� ";
		today.print();
	cout << " �Դϴ�.\n";
}