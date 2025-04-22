//////////////////////////////////////////////////////////////
/// 
/// \file read_file_and_print.cpp
///
/// \brief
///  파일의 내용 출력
///
/// 파일의 내용을 문자열 단위로 읽어 모두 한꺼번에 출력하는 예
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
///  - test.txt
///
//////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

void print_str(const std::string &str)
{
	std::cout << str << std::endl ;
}

int main()
{
	using namespace std;
	
	ifstream file("test.txt");		
	if(!file) 
	{
		cerr << "Can't open file " << endl;
		exit(0);
	}
	
	vector< string > strlist;
	string temp;	
	while( file >> temp ) 
	{
		strlist.push_back(temp);
	}
	file.close();
	
	for_each(strlist.begin(), strlist.end(), print_str);
}

