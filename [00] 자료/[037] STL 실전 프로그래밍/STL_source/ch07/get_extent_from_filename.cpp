//////////////////////////////////////////////////////////////
/// 
/// \file get_extent_from_filename.cpp
///
/// \brief
///  확장자 추출
///
/// 주어진 파일명에서 확장자를 추출하는 예
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
#include<utility>
#include<iostream>

template<typename char_t>
std::pair<std::basic_string<char_t>, std::basic_string<char_t> >
get_extent(std::basic_string<char_t> filename, char_t del)
{
	typename std::basic_string<char_t>::size_type pos = filename.find(del);
	
	if(pos == std::basic_string<char_t>::npos)
	{
		return 
			std::make_pair<
			std::basic_string<char_t>, std::basic_string<char_t> >
			(
			std::basic_string<char_t>(
			filename.begin(), filename.end()),
			std::basic_string<char_t>()
			);
	}
	else
	{
		return 
			std::make_pair< 
			std::basic_string<char_t>, std::basic_string<char_t> >
			(
			std::basic_string<char_t>(
			filename.begin(), filename.begin()+pos),
			std::basic_string<char_t>(
			filename.begin()+pos+1, filename.end())
			);
	}
}							

int main()
{
	std::pair< std::string, std::string> rst
		= get_extent( std::string("abc.dat"), char('.'));
	
	std::cout<< "filename: " << rst.first << std::endl;
	std::cout<< "extent: " << rst.second << std::endl;
}