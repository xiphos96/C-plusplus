/* 7-1.c */

#include <stdio.h>

struct date {           
int year; 
int mon;
int day;
};

void print_date(struct date *d)
{
	printf("%d�� %d�� %d��", d->year, d->mon, d->day);
}

void main()
{
	struct date today;
	int year, month, day;
	
	today.year = 2009;
	today.mon = 1;
	today.day = 1;

	year = today.year + 2333;
	month = today.mon;
	day = today.day;

	printf("������ �ܱ� %d�� %d�� %d�� �Դϴ�.\n", year, month, day);
	printf("������ ���� ");
	print_date(&today);
	printf(" �Դϴ�.\n");
}