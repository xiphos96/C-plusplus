//////////////////////////////////////////////////////////////
/// 
/// \file mean_vector.cpp
///
/// \brief
///  평균 벡터 산출
///
/// valarray를 이용하여 평균 벡터를 산출
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
#include<valarray>
#include<iostream>
#include<iterator>
#include<iomanip>
#include<numeric>

template<typename char_t, typename value_t>
std::basic_ostream<char_t> &operator << (std::basic_ostream<char_t> &out, 
										const std::valarray<value_t> &v)
{	
	for(size_t j(0); j< v.size(); ++j)
	{
		out << std::setw( 6 ) << std::setprecision(3) << v[j]; 
	}
	return out;
}

template<typename value_t, int vector_size>
class find_center
{
private:
	std::vector< std::valarray<value_t> > vectors;
	
public:
	
	bool add_vector( const std::valarray<value_t> &v )
	{
		if(v.size() != vector_size) return false;
		
		vectors.push_back( v );
		
		return true;
	}
	
	std::valarray<value_t> operator()() const
	{
		std::valarray<value_t> v(vector_size);
		std::valarray<value_t> size_of_v(vector_size);
		
		std::fill( &v[0], &v[vector_size], value_t(0) );
		std::fill( &size_of_v[0], &size_of_v[vector_size], 
			value_t(vectors.size()) );
		
		return
			std::accumulate( 
			vectors.begin(), vectors.end(), v ) / size_of_v;		
	}
	
	template<typename char_t>
		void print(std::basic_ostream<char_t> &out)
	{		
		for(size_t i(0); i< vectors.size(); ++i)
		{
			out << vectors[i] << std::endl;
		}
	}
};

int main()
{
	double v1[5] = { 10, -3, 7, 17, 6 };
	double v2[5] = { 3, 2, 3, -8, -70 };
	double v3[5] = { 5, 10, 2, 4, 8 };
	double v4[5] = { -8, -9, 6, 7, 6 };
	
	find_center< double, 5 > center;
	
	center.add_vector( std::valarray<double>( &v1[0], 5) );
	center.add_vector( std::valarray<double>( &v2[0], 5) );
	center.add_vector( std::valarray<double>( &v3[0], 5) );
	center.add_vector( std::valarray<double>( &v4[0], 5) );
	
	std::cout << "Vectors are: " << std::endl;
	center.print( std::cout );
	
	std::cout << "Center: " << std::endl << center() << std::endl;
}