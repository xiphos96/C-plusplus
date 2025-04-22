#include "Kmeans.h"
#include<iostream>
#include<iterator>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>

std::string vector_to_string( kmeans<double>::vector_t &vector )
{
	std::ostringstream stream;

	std::copy( 
		&vector[0], &vector[0]+vector.size(), 
		std::ostream_iterator<double>( stream, " " )
		);
	stream << std::endl;
	
	return stream.str();
}

int main()
{
	kmeans<double> cluster("vectors.dat", 2, 2, 1000) ;

	cluster();

	std::vector< kmeans<double>::vector_t > centers = cluster.centeriods();
	
	std::cout << "Result" << std::endl;

	std::transform(
		centers.begin(), centers.end(), 
		std::ostream_iterator<std::string>(std::cout),
		vector_to_string
		);
}
