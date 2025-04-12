// 1-1.cpp

#include <stdio.h>

void madd(double a[], double b[], double c[], int row, int col)
{
   int i, j;
   for (i=0; i<row; i++)
      for (j=0; j<col; j++)
       	   c[i*col+j]=a[i*col+j] + b[i*col+j];
 }

 void main()
 {
    int i;
    double a[2*2] = {  1, 2, 3, 4 }, b[2*2] = { 5, 6, 7, 8}, c[2*2];
    madd(a, b, c, 2, 2);
 	for (i=0; i<2*2; i++)
 		printf("%g\t", c[i]);
 }