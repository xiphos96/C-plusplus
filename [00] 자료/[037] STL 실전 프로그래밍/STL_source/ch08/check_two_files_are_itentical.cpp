//////////////////////////////////////////////////////////////
/// 
/// \file check_two_files_are_itentical.cpp
///
/// \brief
///  match와 distance를 이용하여 파일의 동일성 체크
///
/// match와 distance를 이용하여 두 파일이 완전히 동일한지 
/// 여부를 확인하는 예
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
///  - abc.txt
///  - abc2.txt
///
//////////////////////////////////////////////////////////////

#include<algorithm>
#include<fstream>
#include<string>
#include<exception>
#include<iterator>
#include<iostream>

template<typename char_t>
inline bool match(const std::basic_string<char_t> &fname1, 
				  const std::basic_string<char_t> &fname2)
{
	typedef std::istreambuf_iterator<char_t> ister;
	
	std::basic_ifstream<char_t> 
		file1(fname1.c_str()), file2(fname2.c_str());
	
	if( !file1 || !file2 ) 
		throw std::logic_error("Invalid filename");
	
	bool is_match(false);
	
	if( std::distance(ister(file1), ister()) 
		== std::distance(ister(file2), ister()))
	{
		if( std::mismatch(ister(file1), ister(), ister(file2)) 
			== std::make_pair(ister(), ister()))
		{
			is_match = true;
		}
	}
	
	file1.close();
	file2.close();
	
	return is_match;
}

int main()
{
	std::cout << match(std::string("abc.txt"),std::string("abc2.txt")) << std::endl;
}
