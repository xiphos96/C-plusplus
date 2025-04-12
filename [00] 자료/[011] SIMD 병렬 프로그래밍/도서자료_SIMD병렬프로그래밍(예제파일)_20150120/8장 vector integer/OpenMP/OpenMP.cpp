// OpenMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <omp.h>

int main(int argc, char* argv[])
{
	omp_set_num_threads(2);

#pragma omp parallel
	{
		printf("Hello World! %d\n", omp_get_thread_num());
	}
		
	return 0;
}

