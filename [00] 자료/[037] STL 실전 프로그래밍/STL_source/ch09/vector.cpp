//////////////////////////////////////////////////////////////
/// 
/// \file vector.cpp
///
/// \brief
///  벡터 연산
///
/// valarray를 이용해 +, -, 내적 등의 벡터 연산을 지원하는 예
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

#include<numeric>
#include<valarray>
#include<iostream>
#include<vector>

namespace vector
{
	template<typename value_t>
		inline std::valarray<value_t> sum( 
		const std::valarray<value_t> &a, 
		const std::valarray<value_t> &b )
	{
		if( a.size() != b.size() ) 
			throw std::logic_error("Illegal size");
		return a+b;
	}
	
	template<typename value_t>
		inline std::valarray<value_t> difference( 
		const std::valarray<value_t> &a, 
		const std::valarray<value_t> &b )
	{
		if( a.size() != b.size() ) 
			throw std::logic_error("Illegal size");
		return a-b;
	}
	
	template<typename value_t>
		inline value_t inner_product( 
		const std::valarray<value_t> &a, 
		const std::valarray<value_t> &b )
	{
		if( a.size() != b.size() ) 
			throw std::logic_error("Illegal size");
		
		std::vector<value_t> ta( a.size() ), tb( b.size() );
		
		for( size_t i(0); i< a.size(); ++i ) ta[i] = a[i];
		for( size_t j(0); j< b.size(); ++j ) tb[j] = b[j];
		
		return 
			std::inner_product( 
			ta.begin(), ta.end(), tb.begin(), value_t(0) );
	}
}

template< typename value_t, typename char_t >
std::basic_ostream<char_t> &operator << ( 
										 std::basic_ostream<char_t> &out, const std::valarray<value_t> &v)
{
	for(size_t i(0); i<v.size(); ++i)
	{
		out << v[i] << " ";
	}
	return out;
}

int main()
{
	int a1[] = { 10, 3, 4 };
	int a2[] = { 5, 9, 4 };
	
	std::valarray<int> a(a1, sizeof a1/ sizeof a1[0]);
	std::valarray<int> b(a2, sizeof a2/ sizeof a2[0]);
	std::valarray<int> r;
	
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "sum: " << vector::sum(a, b) << std::endl;
	std::cout << "difference: " << vector::difference(a, b) << std::endl;
	std::cout << "inner_product: " << vector::inner_product(a, b) << std::endl;
}