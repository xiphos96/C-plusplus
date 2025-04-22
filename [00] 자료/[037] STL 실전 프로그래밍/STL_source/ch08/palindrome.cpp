//////////////////////////////////////////////////////////////
/// 
/// \file palindrome.cpp
///
/// \brief
///  회문 검사
///
/// 알고리즘 equal을 이용하여 회문을 검사하는 예.
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

template<typename char_t>
inline bool is_palindrome( const std::basic_string<char_t> &word)
{
	return std::equal(word.begin(), word.end(), word.rbegin());
}


int main()
{
	std::cout<< is_palindrome(std::string("abcdcba")) << std::endl;
	std::cout<< is_palindrome(std::string("abcdecba")) << std::endl;
}