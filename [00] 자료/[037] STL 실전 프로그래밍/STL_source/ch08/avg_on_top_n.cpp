//////////////////////////////////////////////////////////////
/// 
/// \avg_on_top_n.cpp
///
/// \brief
///  최상위 n개의 데이터 추출
///
/// nth_element를 이용하여 최상위 n명에 해당하는 성적의 평균을
/// 계산
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
#include<numeric>

template<typename value_t, typename rst_t>
inline rst_t aver( const std::vector<value_t> &grades, size_t top_n )
{
	std::vector<value_t> tgrades(grades);
	typename std::vector<value_t>::iterator first, last, nth;
	
	first = tgrades.begin();
	last = tgrades.end();
	nth = tgrades.begin() + top_n;
	
	std::nth_element( first, nth, last, std::greater<value_t>() );
	
	typename std::vector<value_t>::value_type sum = 
		std::accumulate(first, nth, 0);
	
	return static_cast<rst_t>(sum) / static_cast<rst_t>(top_n);
}

int main()
{
	int g[]={ 10, 99, 83, 87, 73, 65, 39, 20 };
	std::vector< int > grades(g, g+sizeof g/ sizeof(int));
	
	std::cout << aver<int, double>(grades, 3) ;
}
