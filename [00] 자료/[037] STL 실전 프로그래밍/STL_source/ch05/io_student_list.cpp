//////////////////////////////////////////////////////////////
/// 
/// \file io_student_list.cpp
///
/// \brief
///  ����� ����
///
/// ifstream, getline, stringstream ���� �̿��Ͽ� �������
/// �����ϴ� ��
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
///  - student_list.txt
///
//////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream> 
#include<string>
#include<sstream>

void print_info(const std::string &filename)
{	
	using namespace std;
	
	ifstream in_file( filename.c_str() );		
	
	cout << "-Students-" << endl;
	
	string line;
	while( getline(in_file, line) )
	{
		stringstream line_stream(line);
		
		string name;
		getline(line_stream, name,'/');
		
		string grade;
		getline(line_stream, grade,'/');
		
		string major;
		getline(line_stream, major);
		
		cout << name << '\t';
		cout << major << '\t';	
		cout << grade << endl;	
	}	
	cout << "-End of File-" << endl;
	
	in_file.close();
}

int main()
{
	print_info("student_list.txt");
}
