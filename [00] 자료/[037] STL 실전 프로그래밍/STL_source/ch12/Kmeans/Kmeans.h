#pragma warning(disable:4786)

#if !defined(KMEANS_H)
#define KMEANS_H

#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<numeric>
#include<exception>
#include<map>
#include<valarray>
#include<sstream>
#include<functional>
#include<iostream>
#include<math.h>

template<typename value_t>
class kmeans
{
public:

	typedef value_t value_type;
	typedef std::valarray<value_type> vector_t;
	typedef std::multimap< size_t, vector_t > vectors_t;

public:

	kmeans( 
		const std::string &filename, 
		size_t nclusters, 
		size_t vsize, 
		size_t max_iterations,
		value_type e=0.1);

	void operator () ();

	std::vector<vector_t> centeriods() const 
	{ 
		std::vector<vector_t> c;
		for(typename vectors_t::const_iterator it=centers.begin(); it!=centers.end(); ++it)
			c.push_back(it->second);

		return c;
	}
		
private:

	void clustering();
	bool update();

private:

	vectors_t centers;
	vectors_t vectors;
	size_t num_of_clusters;
	size_t vector_size;
	size_t maximum_num_of_iterations;
	value_type epsilon;
};

template<typename value_t>
kmeans<value_t>::kmeans( 
	   const std::string &filename, 
	   size_t nclusters, 
	   size_t vsize, 
	   size_t max_iterations,
	   value_type e) 
		: 
		vector_size(vsize), 
		num_of_clusters(nclusters), 
		maximum_num_of_iterations(max_iterations), 
		epsilon(e)
{
	std::ifstream vector_file( filename.c_str() );

	if(vector_file)
	{
		std::vector< vector_t > temp;

		// Read Vectors
		std::string line;
		while( std::getline(vector_file, line) )
		{
			std::stringstream line_stream(line);

			vector_t vector(vector_size);

			for(size_t i(0); i<vector_size; ++i)
			{
				if( !(line_stream >> vector[i]) ) 
					throw std::logic_error("error");
			}

			vectors.insert( std::make_pair(0, vector) );
			temp.push_back(vector);
		}

		// Shuffling
		std::random_shuffle( temp.begin(), temp.end() );

		// Assign initail centers
		for(size_t i(0); i<num_of_clusters; ++i)
		{
			centers.insert( std::make_pair(i, temp[i]) );
		}
	}

	vector_file.close();
}

template< typename value_t >
value_t euclidean_distance(std::valarray<value_t> left, 
						   std::valarray<value_t> right )
{
	std::valarray<value_t> t1 = std::abs(left - right);
	std::valarray<value_t> t2 = std::pow( t1, value_t(2) );

	return value_t(::sqrt( double(t2.sum()) ));
}

template<typename value_t>
void kmeans<value_t>::clustering()
{
	vector_t distances(num_of_clusters);
	vectors_t temp_vectors;

	// For all vectors
	for(typename vectors_t::const_iterator it = vectors.begin(); it!=vectors.end(); ++it)
	{
		// Calculate the distance to center 
		size_t i(0);
		for( typename vectors_t::const_iterator cit = centers.begin(); cit!=centers.end(); ++cit, ++i )
		{
			distances[i] = euclidean_distance( cit->second, it->second );
		}
		
		// Assign nearest center
		temp_vectors.insert(
			std::make_pair(
				std::distance<typename vector_t::value_type*>( 
					&distances[0], 
					std::min_element( &distances[0], &distances[0] + distances.size() )
				),
				it->second
			)
		);
	}

	vectors = temp_vectors;
}

template<typename value_t>
bool kmeans<value_t>::update()
{
	bool ret = false;
	for(typename vectors_t::iterator it=centers.begin(); it!=centers.end(); ++it)
	{
		std::pair<typename vectors_t::const_iterator, typename vectors_t::const_iterator> 
			range = vectors.equal_range(it->first);

		size_t num_of_vectors = std::distance( range.first, range.second );

		vector_t temp(value_t(0), vector_size);

		for( typename vectors_t::const_iterator vit=range.first; vit!=range.second; ++vit)
		{
			temp += vit->second;
		}

		temp = temp / static_cast<value_type>(num_of_vectors);
		
		vector_t test = std::abs(temp - it->second);
		if( std::find_if( 
			&test[0], &test[0]+test.size(), 
			std::bind2nd(std::greater<value_type>(), epsilon) ) 
			== &test[0]+test.size() )
			ret = true;

		it->second = temp;
	}
	return ret;
}

template<typename value_t>
void kmeans<value_t>::operator () ()
{
	bool	ret = true;

	for( size_t i(0); ret && i<maximum_num_of_iterations; ++i )
	{
		clustering();
		ret = update();
	}
}
#endif
