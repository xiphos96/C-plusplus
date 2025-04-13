//////////////////////////////////////////////////////////////
/// 
/// \file aligning.cpp
///
/// \brief
///  ���� ���� �����
///
/// ǥ�� ������ setw ���� �̿��Ͽ� ���� ����� �ϴ� ��
///
/// \�׽�Ʈȯ��
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
		setw(8) << item.price << "��" <<
		setw(8) << item.num << "��" << endl;
}

void print_total(int price)
{
	cout << setw(33) << price << "��" <<endl;
}

int main()
{    
	item items[3] = 
	{
		{"���� ���ø�", 900, 1},{"�Ŀ� ���̵�", 900, 1},{"���ڱ�", 450, 2}
	};
	
	print_title("����", "����", "����");
	int price(0);
	for(size_t i(0); i< sizeof items / sizeof (item); i++)
	{
		print_item(items[i]);
		price += items[i].num * items[i].price;
	}
	print_total(price);
}
