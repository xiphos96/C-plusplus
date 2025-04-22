//////////////////////////////////////////////////////////////
/// 
/// \file space_to_underscore.cpp
///
/// \brief
///  공백문자를 '_'로
///
/// relace_copy_if를 이용해 문자열을 검색하여 만일 공백문자가 
/// 있다면 해당 문자를 '_'로 변경하는 예.
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
#include<string>
#include<functional>
#include<iostream>

template<typename char_t>
inline std::basic_string<char_t> 
space_to_under_score( const std::basic_string<char_t> &str)
{
	std::basic_string<char_t> tstr;
	
	tstr.resize(str.size());
	
	std::replace_copy_if(
		str.begin(), str.end(), 
		tstr.begin(), 
		std::bind2nd(std::equal_to<char_t>(), char_t(' ')), 
		char_t('_'));
	
	return tstr;
}


int main()
{
	std::cout
		<< space_to_under_score(std::string("My hair style")) 
		<< std::endl;
}
