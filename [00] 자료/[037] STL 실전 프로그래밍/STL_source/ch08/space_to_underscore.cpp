//////////////////////////////////////////////////////////////
/// 
/// \file space_to_underscore.cpp
///
/// \brief
///  ���鹮�ڸ� '_'��
///
/// relace_copy_if�� �̿��� ���ڿ��� �˻��Ͽ� ���� ���鹮�ڰ� 
/// �ִٸ� �ش� ���ڸ� '_'�� �����ϴ� ��.
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
#include<functional>
#include<iostream>

template<typename char_t>
inline std::basic_string<char_t> 
space_to_under_score( const std::basic_string<char_t> &str)
{
	std::basic_string<char_t> tstr;
	
	tstr.resize(str.size());
	
	std::replace_copy_if(
		str.begin(), str.end(), 
		tstr.begin(), 
		std::bind2nd(std::equal_to<char_t>(), char_t(' ')), 
		char_t('_'));
	
	return tstr;
}


int main()
{
	std::cout
		<< space_to_under_score(std::string("My hair style")) 
		<< std::endl;
}
