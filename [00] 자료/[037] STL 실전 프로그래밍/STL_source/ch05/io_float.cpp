//////////////////////////////////////////////////////////////
/// 
/// \file io_float.cpp
///
/// \brief
///  �Ǽ��� �����
///
/// ǥ�� �����ڸ� ����Ͽ� �Ǽ��� ��� ������ �����ϴ� ��
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
#include<iomanip>

int main()
{
	using namespace std;    
	
	float f=1234.56789f;
	cout<< scientific << setprecision(4) << f << endl;
	cout<< resetiosflags(ios_base::floatfield);
	cout<< setprecision(6);
}