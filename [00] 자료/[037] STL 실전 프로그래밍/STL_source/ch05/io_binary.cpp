//////////////////////////////////////////////////////////////
/// 
/// \file io_binary.cpp
///
/// \brief
///  2진수의 입출력
///
/// bitset 사용해 2진수를 입출력하는 예
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
#include<bitset>

void print_v(int i)
{
	using namespace std;

	cout<< "\tDecimal: "<< setbase(10) << i << endl;
	cout<< "\tOctal: "<< setbase(8) << i << endl;
	cout<< "\tHexa-deciaml: "<< setbase(16) << i << endl;
	cin >> resetiosflags( ios_base::basefield );
}

int main(int argc, char *argv[])
{
	using namespace std;

	bitset<8> bin;

	cout<< "Input Binary: " ;
	cin >> bin;
	print_v(bin.to_ulong());

	int j;
	
	cout<< "Input Decimal: " ;
	cin >> j;
	bitset<8> bin2(j);
	cout << "\tBinary: "<< bin ;
}
