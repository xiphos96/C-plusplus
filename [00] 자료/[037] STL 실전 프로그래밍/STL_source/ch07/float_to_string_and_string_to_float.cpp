//////////////////////////////////////////////////////////////
/// 
/// \file float_to_string_and_string_to_float.cpp
///
/// \brief
///  stringstream 등을 이용한 실수와 문자열의 변환.
///
/// stringstream의 형식지정 입출력 연산자 >>와 <<를 이용하여
/// string과 실수형 사이의 문자열 변환을 수행하는 예
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
