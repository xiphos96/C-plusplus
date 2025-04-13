//////////////////////////////////////////////////////////////
/// 
/// \file reverse_image.cpp
///
/// \brief
///  영상 뒤집기
///
/// 알고리즘 reverse를 이용하여 이차원 vector에 담겨있는
/// 원소의 순서를 뒤집는 예.
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

template<typename pixel_t>
inline std::vector< std::vector< pixel_t > > 
reverse_image( const std::vector< std::vector<pixel_t> > &image)
{
	std::vector< std::vector<pixel_t> > rimage;
	
	rimage.reserve( image.size() );
	
	for(typename std::vector< std::vector<pixel_t> >::const_iterator 
		it = image.begin(); it!=image.end(); it++)
	{
		std::vector<pixel_t> line;
		std::reverse_copy(
			(*it).begin(), (*it).end(), std::back_inserter(line)
			);
		rimage.push_back(line);
	}
	
	return rimage;
}

int main()
{
	std::vector< std::vector< unsigned short > > 
		image( 5, std::vector<unsigned short>(5) );
	
	{for(size_t i(0); i<5; ++i)
		for(size_t j(0); j<5; ++j) image[i][j] = j;}
	
	{
		std::cout << "Original" << std::endl;
		for(size_t i(0); i<5; ++i)
		{
			std::cout<<"\t";
			for(size_t j(0); j<5; ++j) std::cout << image[i][j];
			std::cout<<std::endl;
		}
	}
	
	std::vector< std::vector< unsigned short > > rimage;
	
	rimage = reverse_image(image);
	
	{
		std::cout << "Reverse" << std::endl;
		for(size_t i(0); i<5; ++i)
		{
			std::cout<<"\t";
			for(size_t j(0); j<5; ++j) std::cout << rimage[i][j];
			std::cout<<std::endl;
		}
	}
}