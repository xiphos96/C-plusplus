//////////////////////////////////////////////////////////////
/// 
/// \file io_oct_dec_hex.cpp
///
/// \brief
///  8, 10, 16진수 입출력
///
/// 표준 조절자를 이용하여 8, 10, 16진수를 입출력하는 예
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

void print_v(int i)
{
	using namespace std;

	cout<< "\tDecimal: "<< setbase(10) << i << endl;
	cout<< "\tOctal: "<< setbase(8) << i << endl;
	cout<<"\tHexa-deciaml: "<< setbase(16)<< i << endl;
	cin >> resetiosflags( ios_base::basefield );
}

int main()
{
	using namespace std;
	
	int i;
	cout<< "Input Decimal: ";
	cin >> setbase(10) >> i;
	print_v(i);
	cin >> resetiosflags( ios_base::basefield );
	
	cout<< "Input Octal: " ;
	cin >> setbase(8) >> i;
	print_v(i);
	cin >> resetiosflags( ios_base::basefield );
	
	cout<<"Input Hexa-decimal: " ;
	cin >> setbase(16) >> i;
	print_v(i);
	cin >> resetiosflags( ios_base::basefield );
}