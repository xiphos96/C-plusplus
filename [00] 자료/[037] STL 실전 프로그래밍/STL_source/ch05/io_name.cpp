//////////////////////////////////////////////////////////////
/// 
/// \file io_name.cpp
///
/// \brief
///  �̸� �����
///
/// cout, cin�� �̿��� �̸��� ������ϴ� ��
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

int main()
{
	using namespace std;
	string name;
	
	cout<< "Input your name:";
	cin >> name;
	cout<< "Your name is " << name;
}
