//////////////////////////////////////////////////////////////
/// 
/// \file string_to_capital_string.cpp
///
/// \brief
///  대문자 변환
///
/// 문자열의 문자를 모두 대문자로 변환. ASCII 문자 집합에 대해서만
/// 올바르게 동작한다.
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
#include<iostream>

// Work for only ASCII character set
char to_capital(char c)
{
	if( c >= 'a' )	return c - ('a' -'A');
	return c;
}

template<typename char_t>
inline std::basic_string<char_t> 
to_capital_string( const std::basic_string<char_t> &str )
{
	std::basic_string<char_t> tstr;
	
	tstr.resize(str.size());
	
	std::transform(
		str.begin(), str.end(), tstr.begin(), to_capital);
	
	return tstr;
}

int main()
{
	std::cout<< to_capital_string(std::string("StYle")) << std::endl;
}
