//////////////////////////////////////////////////////////////
/// 
/// \file file_copy.cpp
///
/// \brief
///  파일 복사
///
/// 입출력 버퍼의 직접 연결을 통한 파일 복사의 예
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
#include<fstream>
#include<string>

int main(int argc, char *argv[])
{
	using namespace std;
	
	if(argc != 3) return 1;
	
	string file1(argv[1]), file2(argv[2]);
	ifstream in(file1.c_str(), ios_base::binary);
	ofstream out(file2.c_str(), ios_base::binary);
	out << in.rdbuf();
}
