//////////////////////////////////////////////////////////////
/// 
/// \file median_filtering.cpp
///
/// \brief
///  중앙 필터링의 예
///
/// 정렬을 이용하여 영상을 중앙 필터링 하는 예
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

#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<iterator>
#include<iomanip>

template< typename pixel_t, int mask_w = 3, int mask_h = 3 >
class median_filter
{
public:

	typedef std::vector< std::vector< pixel_t > > data_t;

private:

	data_t data;

public:
	
	explicit median_filter( const data_t &d ): data(d) {}

	data_t operator () () const
	{
		data_t median_data(data);
		std::vector< pixel_t > mask;

		mask.reserve( mask_w*mask_h );

		for(int h(0); h< data.size(); ++h)
		{
			for(int w(0); w< data[h].size(); ++w)
			{				
				mask.clear();

				// Fill mask
				for(int mh(h-mask_h/2); mh<= h+mask_h/2; ++mh)
				{
					for( int mw(w-mask_w/2); mw<= w+mask_w/2; ++mw)
					{
						if( mh>=0 && mw>=0 && mh<data.size() && mw<data[h].size())
						{
							mask.push_back(data[mh][mw]);
						}
					}
				}
				
				// Sort
				std::sort(mask.begin(), mask.end());

				// Set median value
				median_data[h][w] = mask[ (mask.size()-1)/2 ];
			}
		}
		
		return median_data;
	}
};

template<typename char_t>
std::basic_ostream<char_t> &operator << (std::basic_ostream<char_t> &out,
										 const std::vector< std::vector< unsigned char > > &img)
{
	for(size_t i(0); i< img.size(); ++i)
	{
		for(size_t j(0); j<img[i].size(); ++j)
		{
			out << std::setw(4) << int(img[i][j]);
		}
		out << std::endl;
	}
	return out;
}

int main()
{
	std::vector< std::vector< unsigned char > > img(5, std::vector< unsigned char >(5));
	
	img[0][0] = 13;	img[0][1] = 2;	img[0][2] = 4;	img[0][3] = 99;	img[0][4] = 123; 
	img[1][0] = 38;	img[1][1] = 44;	img[1][2] = 89; img[1][3] = 255;img[1][4] = 122;
	img[2][0] = 190;img[2][1] = 37; img[2][2] = 234;img[2][3] = 87; img[2][4] = 213;
	img[3][0] = 122;img[3][1] = 2;  img[3][2] = 3;  img[3][3] = 1;  img[3][4] = 12;
	img[4][0] = 12; img[4][1] = 4;  img[4][2] = 11; img[4][3] = 21; img[4][4] = 12; 

	std::cout << "Original Image:" << std::endl;
	std::cout << img << std::endl;

	median_filter<unsigned char> median_img(img);

	std::cout << "Median Image:" << std::endl;
	std::cout << median_img() << std::endl;
}
