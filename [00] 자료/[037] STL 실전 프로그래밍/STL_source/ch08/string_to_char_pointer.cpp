//////////////////////////////////////////////////////////////
/// 
/// \file string_to_char_pointer.cpp
///
/// \brief
///  string�� char*��
///
/// string�� ����ִ� ���� �������� char *�� ����Ű�� �迭�� 
/// ����
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

#include<algorithm>
#include<string>

int main()
{
	std::string s("abcdefg");
	char *p = new char[ s.size() +1 ];
	
	std::copy(s.begin(), s.end(), p);
	p[s.size()] = char(0);
}