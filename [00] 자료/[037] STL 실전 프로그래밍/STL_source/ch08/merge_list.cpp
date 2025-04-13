//////////////////////////////////////////////////////////////
/// 
/// \file merge_list.cpp
///
/// \brief
///  �� ���� ����Ʈ�� ��ġ�� ��
///
/// �� ���� vector�� ��� �����͸� �ϳ��� vector�� �˰���
/// merge�� �̿��Ͽ� ��ġ�� ��.
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