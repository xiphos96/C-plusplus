//////////////////////////////////////////////////////////////
/// 
/// \file minmax.cpp
///
/// \brief
///  최대 최소값 산출
///
/// 알고리즘 min, max를 이용하여 최대, 최소 값을 산출하는 예.
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
#include<iterator>
#include<string>

template< typename ForwardIterator >
inline ForwardIterator minmax(ForwardIterator first, 
							  ForwardIterator last, 
							  bool min=true)
{
	if(min)
		return std::min_element( first, last );
	else
		return std::max_element( first, last );
}


int main()
{
	int a[] = { 10, 9, 3, 9, 5, 3 };
	std::vector<int> v(a, a+sizeof a/ sizeof(int));	
	std::copy( v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::cout << "MAX: ";
	std::cout << *(minmax(v.begin(), v.end(), false)) << std::endl;
	std::cout << "MIN: ";
	std::cout << *(minmax(v.begin(), v.end())) << std::endl;
}