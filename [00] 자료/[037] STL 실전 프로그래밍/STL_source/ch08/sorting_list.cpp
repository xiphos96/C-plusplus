//////////////////////////////////////////////////////////////
/// 
/// \file sorting_list.cpp
///
/// \brief
///  정렬
///
/// 시퀀스를 정렬하는 예.
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

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<functional>

template<typename sequence_t, bool r>
inline sequence_t &sort(sequence_t &c)
{
	if(r)
		std::sort(
		c.begin(), c.end(), std::greater<typename sequence_t::value_type>());
	else
		std::sort(c.begin(), c.end());
	
	return c;
}

int main()
{
	std::vector< std::string > v;
	
	v.push_back("stkim");
	v.push_back("jtkim");
	v.push_back("htkim");
	
	sort< std::vector< std::string >, true >(v);
	
	for(size_t i(0); i<v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
}