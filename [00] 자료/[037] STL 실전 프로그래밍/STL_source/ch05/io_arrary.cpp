//////////////////////////////////////////////////////////////
/// 
/// \file io_arrary.cpp
///
/// \brief
///  for_each�� ����� ���
///
/// �˰��� for_each�� ����Ͽ� �迭�� ����ϴ� ��
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

#include <iostream>
#include <algorithm>

void print(char a_n)
{
	std::cout << a_n ;
}

int main()
{
	char a[] = "abcdefghijk";
	std::for_each(a, a+ sizeof a/ sizeof(char),print);
}