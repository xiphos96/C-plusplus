//////////////////////////////////////////////////////////////
/// 
/// \file used_words_in_text.cpp
///
/// \brief
///  사용된 모든 단어 출력
///
/// 텍스트 파일을 검사하여 사용된 모든 단어를 중복없이 출력.
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
#include<vector>
#include<fstream>
#include<string>

template<typename char_t>
inline void used_words( 
					   std::basic_istream<char_t> &in, std::basic_ostream<char_t> &out)
{
	std::vector< std::basic_string<char_t> > inputs;
	std::copy(
		std::istream_iterator< std::basic_string<char_t> >(in),
		std::istream_iterator< std::basic_string<char_t> >(),
		std::back_inserter(inputs)
		);
	
	std::vector< std::basic_string<char_t> > uniques;
	
	std::sort( inputs.begin(), inputs.end());
	std::unique_copy( 
		inputs.begin(), inputs.end(), 
		std::back_inserter(uniques) );
	
	std::copy(
		uniques.begin(),
		uniques.end(),
		std::ostream_iterator< std::basic_string<char_t> >(
		out, "\n")
		);
}

int main()
{
	std::ifstream mybook("abc.txt");
	used_words(mybook, std::cout);
	mybook.close();
}