//////////////////////////////////////////////////////////////
/// 
/// \file if_cond_true_then_write.cpp
///
/// \brief
///  ������ ���� �����
///
/// fstream�� �̿��Ͽ� �Է°� ����� ���ÿ� �����ϴ� ��
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
#include<fstream>
#include<string>

template<typename t>
void if_cond_is_true_write_rst(
							   std::string filename, 
							   std::streampos cond_pos, t cond, 
							   std::streampos target_pos, t rst)
{
	using namespace std;
	
	fstream file(filename.c_str(), ios_base::in | ios_base::out);
	
	file.seekg(cond_pos);
	
	t real;
	file.read(&real, sizeof real);
	
	if(real == cond)
	{
		file.seekg(target_pos);
		file.write(&rst, sizeof rst);
	}
}


int main(int argc, char *argv[])
{	
	if_cond_is_true_write_rst("cond.txt", 10, 'J', 0, '-');
	
	return 0;
}