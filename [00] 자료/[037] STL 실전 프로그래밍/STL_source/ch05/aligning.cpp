//////////////////////////////////////////////////////////////
/// 
/// \file aligning.cpp
///
/// \brief
///  형식 제어 입출력
///
/// 표준 조절자 setw 등을 이용하여 정렬 출력을 하는 예
///
/// \테스트환경
///  Gcc3.2.2, Comeau4.3.3, VC++6.0, VC++.NET 2003
///
/// \author 
///  Kim, Seungtai( stkim@yujinrobot.com )
/// 
/// \date
///  - 2004-08-10, Kim, Seungtai, Create
/// 
/// \see
///
//////////////////////////////////////////////////////////////

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct item{ char name[32]; int price; int num; };

void print_title(
				 const string &kind, const string &price, const string &number)
{
	cout << setw(15) << kind << 
		setw(10) << price << 
		setw(10) << number << endl;
}

void print_item(const item &item)
{
	cout << setw(15) << item.name << 
		setw(8) << item.price << "원" <<
		setw(8) << item.num << "개" << endl;
}

void print_total(int price)
{
	cout << setw(33) << price << "원" <<endl;
}

int main()
{    
	item items[3] = 
	{
		{"가나 초컬릿", 900, 1},{"파워 에이드", 900, 1},{"감자깡", 450, 2}
	};
	
	print_title("종류", "가격", "수량");
	int price(0);
	for(size_t i(0); i< sizeof items / sizeof (item); i++)
	{
		print_item(items[i]);
		price += items[i].num * items[i].price;
	}
	print_total(price);
}
