//////////////////////////////////////////////////////////////
/// 
/// \file make_permutations.cpp
///
/// \brief
///  순열 생성
///
/// next_permutation을 이용하여 순열을 생성하는 예
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
#include<iostream>

template< typename value_t >
inline std::vector< std::vector< value_t > > 
events( const std::vector< value_t >  &c )
{
	std::vector< value_t > t( c );
	
	std::sort( t.begin(), t.end() );
	
	std::vector< std::vector< value_t > > r;
	r.push_back( t );
	while( std::next_permutation( t.begin(), t.end() ) )
	{
		r.push_back( t );
	}
	
	return r;
}

template< typename char_t , typename seq_t >
std::basic_ostream<char_t> &operator << ( std::basic_ostream<char_t> &out, const seq_t &s)
{
	std::copy( s.begin(), s.end(), std::ostream_iterator< char_t >( std::cout, " ") );
	return out;
}

void print_vv( const std::vector< char > &v )
{
	std::cout << v << std::endl;
}

int main()
{
	char a[] = { 'a', 'c', 'b' };
	std::vector< char > v( a, a+sizeof a/ sizeof( char) );
	std::vector < std::vector< char > > all = events( v );
	
	std::cout << all.size() << std::endl;
	std::for_each( all.begin(), all.end(), print_vv);
}