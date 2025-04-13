//////////////////////////////////////////////////////////////
/// 
/// \file tokenizer.cpp
///
/// \brief
///  ������ ������ ���ڿ� ������ ��ūȭ
///
/// ������ ���� ��ü�� ���ڿ� ������ �߶� vector�� ��� ��ȯ
///
/// \�׽�Ʈȯ��
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
#include<fstream>

template<typename char_t>
std::vector< std::basic_string< char_t > > 
simple_tokenizer(std::basic_ifstream<char_t> &file, char_t del = '\n')
{
	std::vector < std::basic_string< char_t > > tokens;
	std::basic_string< char_t > temp;
	
	while( std::getline(file, temp, del) )
	{
		tokens.push_back(temp);
	}
	
	return tokens;
}

int main()
{
	std::ifstream infile("word.dat");
	
	std::cout << "##Start\n";
	std::vector< std::string > tokens = simple_tokenizer( infile, '/');
	for(size_t i(0); i< tokens.size(); i++)
	{
		std::cout << tokens[i] << "<-\n";
	}	
	std::cout << "##End\n";
}