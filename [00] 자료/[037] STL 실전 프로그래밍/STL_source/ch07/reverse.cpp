//////////////////////////////////////////////////////////////
/// 
/// \file reverse.cpp
///
/// \brief
///  문자열을 뒤집는 예
///
/// 주어진 문자열을 알고리즘 reverse를 이용해 뒤집는 예
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

#include<string>
#include<algorithm>
#include<iostream>

std::string reverse(const std::string &input)
{
	std::string temp(input);

	std::reverse(temp.begin(), temp.end());

	return temp;
}

int main()
{
	std::cout<< reverse("abcdefg") << std::endl;
}