//////////////////////////////////////////////////////////////
/// 
/// \file file_to_oct.cpp
///
/// \brief
///  파일 내용을 16진수로 출력
///
///  파일의 내용을 읽어 표준 조절자를 이용해서 16진수로 
///  정렬하여 출력하는 예
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
///  - bin.txt
///
//////////////////////////////////////////////////////////////

#include<string>
#include<fstream>
#include<iostream>
#include<iomanip>

template<typename char_t> 
class contents_t
{
	private:
		std::basic_ifstream<char_t> contents;
		
	public:
		
		explicit contents_t( 
			const std::basic_string<char_t> &filename )
		{
			contents.open( filename.c_str() );
		}
		
		contents_t()
		{
			contents.close();
		}
		
		bool print( 
			std::basic_ostream<char_t> &out, 
			char_t delim, size_t item_width )
		{
			char_t t;
			
			if( contents.get(t) )
			{
				out << std::setiosflags( std::ios_base::showbase)
					<< std::setw(item_width) 
					<< std::setbase(16) 
					<< std::setfill( char_t('0') )
					<< static_cast<unsigned int>(t) 
					<< delim;
				out << std::resetiosflags( std::ios_base::basefield )
					<< std::setfill( char_t(' ') );
				
				return true;
			}  		
			return false;
		}
		
		bool print_line(
			std::basic_ostream<char_t> &out, 
			char_t delim, size_t char_num, size_t item_width )
		{
			bool ret;
			for(size_t i(0); i<char_num && (ret=print(out, char_t(' '),	item_width)); i++);
			out << delim;
			
			return ret;
		}
};

int main()
{
	contents_t<char> contents( "bin.txt" );
	while( contents.print_line( std::cout, '\n', 5 , 4) );
}