//////////////////////////////////////////////////////////////
/// 
/// \file rotated_image.cpp
///
/// \brief
///  영상을 한 픽셀씩 이동하는 예
///
/// 이차원 vector에 담겨있는 영상을 알고리즘 rotate를 이용해
/// 한 픽셀 단위로 이동시키는 예.
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

#include<algorithm>
#include<vector>
#include<iostream>
#include<iomanip>

template< typename pixel_t >
class image_t
{
private:
	
	std::vector< std::vector < pixel_t > > data;
	
public:
	
	explicit image_t( std::vector< std::vector < pixel_t > > &d )
	{
		data = d;
	}
	
	const std::vector< std::vector < pixel_t > > &get_data()
	{
		return data;
	}
	
	void next_rotated()
	{
		for( size_t w(0); w< data.size(); w++ )
		{
			std::rotate( 
				data[w].begin(), data[w].begin()+1, data[w].end() );
		}
	}
	
	void show( std::ostream &out)
	{
		for( size_t w(0); w< data.size(); w++ )
		{
			for( size_t h(0); h<data[w].size(); h++ )
			{
				out << std::setw(2) << data[w][h] ;
			}
			out << std::endl;
		}
	}
};



int main()
{
	char a[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	std::vector< char > line(a, a+sizeof a/ sizeof a[0]);
	std::vector< std::vector< char > > data(5, line);
	
	image_t<char> img(data);
	std::cout << "Before" << std::endl;
	img.show(std::cout);
	
	for(size_t i(0); i< 10; ++i)
	{
		std::cout << i << "th rotated" << std::endl;
		img.next_rotated();
		img.show(std::cout);
	}
	
}