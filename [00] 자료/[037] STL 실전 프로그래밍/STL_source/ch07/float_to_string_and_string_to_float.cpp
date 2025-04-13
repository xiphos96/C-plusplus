//////////////////////////////////////////////////////////////
/// 
/// \file float_to_string_and_string_to_float.cpp
///
/// \brief
///  stringstream ���� �̿��� �Ǽ��� ���ڿ��� ��ȯ.
///
/// stringstream�� �������� ����� ������ >>�� <<�� �̿��Ͽ�
/// string�� �Ǽ��� ������ ���ڿ� ��ȯ�� �����ϴ� ��
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

#include<string>
#include<iostream>
#include<sstream>

template< typename float_t, typename char_t >
struct ftos
{
	std::basic_string<char_t> 
		operator () ( float_t f ) const
	{
		std::basic_ostringstream<char_t> temp;
		
		temp << f ;
		
		return temp.str();
	}
};

template< typename float_t, typename char_t >
struct stof
{
	float_t 
		operator () ( 
		const std::basic_string<char_t> &str ) const
	{
		std::basic_istringstream<char_t> temp(str);
		
		float_t rst;
		
		temp >> rst ;
		
		return rst;
	}
};

int main()
{
	float f(0.001f);
	std::string fstr = ftos<float, char>()(f);
	float rstf = stof<float, char>()(fstr);
	std::cout << fstr << "==" << rstf << std::endl;
}
