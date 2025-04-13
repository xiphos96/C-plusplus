//////////////////////////////////////////////////////////////
/// 
/// \file filtering_student_record.cpp
///
/// \brief
///  �ùٸ� �����Ϳ� �ùٸ��� ���� ������ ����
///
/// ����½� ������ ���� �ùٸ� �����Ϳ� �ùٸ��� ���� �����͸�
/// ��� ����ϴ� ��
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

#include<fstream>
#include<string>
#include<sstream>

int main()
{
	using namespace std;
	
	ifstream file("students.txt");
	ofstream filtered_file("students_filtered.txt");
	ofstream error_file("error_file.txt");
	
	string line;
	while( getline(file, line) )
	{
		string name;
		int grade(-1);
		stringstream temp(line);
		
		if( (temp >> name >> grade) && grade >= 1 && grade <= 4 )
		{
			filtered_file << name << "\t" << grade << endl;
		}
		else
		{
			error_file << name << endl;
		}
	}
	
	file.close();
	filtered_file.close();
	error_file.close();
}