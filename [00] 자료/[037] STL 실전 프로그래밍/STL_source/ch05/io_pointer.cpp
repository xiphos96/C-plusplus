//////////////////////////////////////////////////////////////
/// 
/// \file io_pointer.cpp
///
/// \brief
///  포인터의 입출력
///
/// 포인터의 값을 형식지정 입출력 연산으로 출력하는 예
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

#include <iostream>

int main ()
{
	using namespace std;
	char *p = "abc";
	void *vp=p;
	cout<< *p << ":" << vp << endl;
	cin >> vp;
	p = static_cast<char *>(vp);
	cout<< "result: "<< p;
}
