/* 7-1.c */

#include <stdio.h>

struct date {           
int year; 
int mon;
int day;
};

void print_date(struct date *d)
{
	printf("%d년 %d월 %d일", d->year, d->mon, d->day);
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

	printf("오늘은 단기 %d년 %d월 %d일 입니다.\n", year, month, day);
	printf("오늘은 서기 ");
	print_date(&today);
	printf(" 입니다.\n");
}