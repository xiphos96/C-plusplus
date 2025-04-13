//////////////////////////////////////////////////////////////
/// 
/// \file merge_list.cpp
///
/// \brief
///  두 개의 리스트를 합치는 예
///
/// 두 개의 vector에 담긴 데이터를 하나의 vector로 알고리즘
/// merge를 이용하여 합치는 예.
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
#include<vector>
#include<string>
#include<iostream>
#include<iterator>

template<typename char_t>
std::vector< std::basic_string< char_t > > 
inline merge_list(
				  const std::vector< std::basic_string< char_t > > &a,
				  const std::vector< std::basic_string< char_t > > &b)
{
	std::vector< std::basic_string< char_t > > t;
	t.reserve( a.size() + b.size() );
	std::merge( 
		a.begin(), a.end(), 
		b.begin(), b.end(), 
		std::inserter( t, t.begin() ) );
	
	std::vector< std::basic_string< char_t > > r;
	r.reserve( t.size() );
	std::unique_copy( 
		t.begin(), t.end(), 
		std::inserter( r, r.begin() ) );
	
	return r;
}


int main()
{
	std::vector< std::string > a;
	
	a.push_back("stkim");
	a.push_back("jhkim");
	a.push_back("skok");
	a.push_back("hnwoo");
	a.push_back("thkwon");
	
	std::sort( a.begin(), a.end() );
	
	std::vector< std::string > b;
	
	b.push_back("slee");
	b.push_back("yjlee");
	b.push_back("skok");
	b.push_back("shkim");
	b.push_back("wwwoo");
	
	std::sort( b.begin(), b.end() );
	
	std::vector< std::string > n = merge_list( a, b );
	
	std::copy(
		n.begin(), n.end(),
		std::ostream_iterator< std::string >( std::cout, "\n" )
		);
}