//////////////////////////////////////////////////////////////
/// 
/// \file print_filesize.cpp
///
/// \brief
///  ���� ũ�� ���
///
/// tellg�� difference�� ���� �̿��ؼ� ���� ũ�⸦ ����ϴ� ��
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
///  - bin.txt
///
//////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>
#include<iterator>
#include<limits>

int main()
{
	using namespace std;           
	string filename("bin.txt");
	
	ifstream in1( filename.c_str(), ios_base::ate );    
	streampos end = in1.tellg();    
	cout << "Size: " << end << endl;
	in1.close();    
	
	ifstream in2( filename.c_str(), ios_base::binary );
	streamsize size =         
		distance(istreambuf_iterator<char>(in2),
		istreambuf_iterator<char>());    
	cout << "Size: " << size << endl;    
	in2.close();
}