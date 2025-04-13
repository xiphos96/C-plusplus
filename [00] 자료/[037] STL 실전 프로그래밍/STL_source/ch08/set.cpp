//////////////////////////////////////////////////////////////
/// 
/// \file set.cpp
///
/// \brief
///  집합 연산
///
/// 교집합, 합집합, 차집합, 배타집합 등의 집합 연산 제공
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

namespace set
{
	template<typename value_t >
		inline std::vector< value_t > union_( 
		const std::vector< value_t > &a, 
		const std::vector< value_t > &b)
	{	
		std::vector< value_t > r;
		r.reserve( a.size() + b.size() );
		std::set_union( 
			a.begin(), a.end(), 	b.begin(), b.end(), 
			std::inserter( r, r.begin() ) );
		
		return r;
	}
	template<typename value_t>
		inline std::vector< value_t > intersection( 
		const std::vector< value_t > &a, 
		const std::vector< value_t > &b)
	{
		std::vector< value_t > r;
		r.reserve( a.size() + b.size() );
		std::set_intersection( 
			a.begin(), a.end(), 
			b.begin(), b.end(), 
			std::inserter( r, r.begin() ) );
		
		return r;
	}	
	template<typename value_t>
		inline std::vector< value_t > difference( 
		const std::vector< value_t > &a, 
		const std::vector< value_t > &b)
	{
		std::vector< value_t > r;
		r.reserve( a.size() + b.size() );
		std::set_difference( 
			a.begin(), a.end(), 
			b.begin(), b.end(), 
			std::inserter( r, r.begin() ) );
		
		return r;
	}	
	template<typename value_t>
		inline std::vector< value_t > symmetric_difference( 
		const std::vector< value_t > &a, 
		const std::vector< value_t > &b)
	{
		std::vector< value_t > r;
		r.reserve( a.size() + b.size() );
		std::set_symmetric_difference( 
			a.begin(), a.end(), 
			b.begin(), b.end(), 
			std::inserter( r, r.begin() ) );
		
		return r;
	}
}


int main()
{
	std::vector< int > a, b, r;	
	a.push_back( 1 );	a.push_back( 3 );
	a.push_back( 4 );	a.push_back( 2 );	
	b.push_back( 1 );	b.push_back( 5 );
	b.push_back( 7 );	b.push_back( 9 );	
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	
	
	std::cout << "--A--" << std::endl;
	std::copy( a.begin(), a.end(), std::ostream_iterator< int >( std::cout, " " ) );
	std::cout << std::endl;
	
	std::cout << "--B--" << std::endl;
	std::copy( b.begin(), b.end(), std::ostream_iterator< int >( std::cout, " " ) );
	std::cout << std::endl;
	
	std::cout << "--Union--" << std::endl;
	r = set::union_( a, b );	
	std::copy( r.begin(), r.end(), std::ostream_iterator< int >( std::cout, " " ) );
	std::cout << std::endl;
	
	std::cout << "--Intersection--" << std::endl;
	r = set::intersection( a, b );
	std::copy( r.begin(), r.end(), std::ostream_iterator< int >( std::cout, " " ) );
	std::cout << std::endl;
	
	std::cout << "--Difference--" << std::endl;
	r = set::difference( a, b );	
	std::copy( r.begin(), r.end(), std::ostream_iterator< int >( std::cout, " " ) );
	std::cout << std::endl;
	
	std::cout << "--Symmetric Difference--" << std::endl;
	r = set::symmetric_difference( a, b );	
	std::copy( r.begin(), r.end(), std::ostream_iterator< int >( std::cout, " " ) );
	std::cout << std::endl;
}