//////////////////////////////////////////////////////////////
/// 
/// \file initailizations.cpp
///
/// \brief
///  �پ��� �ʱ�ȭ�� ��
///
/// �����̳� vector, list�� �迭 ���� �ʱ�ȭ�� ��. 
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

#include<algorithm>
#include<iostream>
#include<vector>
#include<iomanip>
#include<list>
#include<string>

template<typename value_t>
struct print
{
	void operator()(value_t v)
	{
		std::cout<< std::setw(4) << v;
	}
};

int main()
{
	int a[10];
	std::fill(a, a+sizeof a/ sizeof(a[0]), 10);
	std::for_each(a, a+sizeof a/ sizeof(a[0]), print<int>());
	std::cout << std::endl;
	
	std::vector<int> v(10);
	std::fill(v.begin(), v.end(), 7);
	std::for_each(v.begin(), v.end(), print<int>());
	std::cout << std::endl;
	
	std::list<std::string> l(10);
	std::fill(l.begin(), l.end(), "st");
	std::for_each(l.begin(), l.end(), print<std::string>());
	std::cout << std::endl;
}