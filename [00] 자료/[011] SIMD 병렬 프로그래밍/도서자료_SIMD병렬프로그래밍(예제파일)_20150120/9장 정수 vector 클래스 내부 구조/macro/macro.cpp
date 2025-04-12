// macro.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _mm_add(int a, int b){return a+b;};
int _mm_sub(int a, int b){return a-b;};
int _mm_mul(int a, int b){return a*b;};
int _mm_div(int a, int b){return a/b;};

#define VECTOR_FUNC(op) \
int vect_##op (int a, int b)\
{				\
return _mm_##op(a, b);	\
}

VECTOR_FUNC(add)		//generates vect_add(a,b)
VECTOR_FUNC(sub)		//generates vect_sub(a,b)
VECTOR_FUNC(mul)		//generates vect_mul(a,b)	
VECTOR_FUNC(div)		//generates vect_div(a,b)

int main(int argc, char* argv[])
{
	int r = vect_add(1,2);
	printf("vect_add : %d\n",r);
	r = vect_sub(1,2);
	printf("vect_sub : %d\n",r);
	r = vect_mul(1,2);
	printf("vect_mul : %d\n",r);
	r = vect_div(1,2);
	printf("vect_div : %d\n",r);
	return 0;
}

