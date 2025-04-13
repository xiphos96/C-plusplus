//////////////////////////////////////////////////////////////
/// 
/// \file word_sorting.cpp
///
/// \brief
///  단어 정렬
///
/// 문장을 입력 받아 문장 내의 단어를 정렬하여 vector에 담아
/// 반환하는 예
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

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<iterator>

template< typename char_t >
std::vector< std::basic_string< char_t > >
sorted_words( const std::basic_string< char_t > &input )
{
	std::basic_stringstream< char_t > input_stream(input);
	
	std::vector< std::basic_string< char_t > > words;
	std::basic_string< char_t > word;
	while( input_stream >> word )
	{
		words.push_back(word);
	}
	
	std::sort(words.begin(),words.end() );
	
	return words;
}

int main()
{
	std::vector< std::string >
		rst = sorted_words(std::string("I am a boy"));
	
	for(size_t i(0) ; i< rst.size(); i++)
	{
		std::cout<< rst[i] << std::endl;
	}
}