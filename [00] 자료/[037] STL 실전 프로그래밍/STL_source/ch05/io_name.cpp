//////////////////////////////////////////////////////////////
/// 
/// \file io_name.cpp
///
/// \brief
///  이름 입출력
///
/// cout, cin을 이용해 이름을 입출력하는 예
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

int main()
{
	using namespace std;
	string name;
	
	cout<< "Input your name:";
	cin >> name;
	cout<< "Your name is " << name;
}
