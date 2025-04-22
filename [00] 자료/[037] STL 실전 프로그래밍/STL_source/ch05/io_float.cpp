//////////////////////////////////////////////////////////////
/// 
/// \file io_float.cpp
///
/// \brief
///  실수의 입출력
///
/// 표준 조절자를 사용하여 실수의 출력 형식을 조절하는 예
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
#include<iomanip>

int main()
{
	using namespace std;    
	
	float f=1234.56789f;
	cout<< scientific << setprecision(4) << f << endl;
	cout<< resetiosflags(ios_base::floatfield);
	cout<< setprecision(6);
}