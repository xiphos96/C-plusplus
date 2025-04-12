// Illustrating the generic inner_product algorithm
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
using namespace std;

int main()
{
  cout << "Illustrating the generic inner_product algorithm." 
       << endl;
  const int N = 5;
  int x1[N], x2[N];
  for (int i = 0; i < N; ++i) {
    x1[i] = i + 1;
    x2[i] = i + 2;
  }
  
  // Compute inner product of 1, 2, ..., N and 2, 3, ..., N+1:
  int result = inner_product(&x1[0], &x1[N], &x2[0], 0);
  
  cout << "Inner product as normally defined: " 
       << result << endl;

  // Again compute "inner product," with roles of + and *
  // reversed:
  result = inner_product(&x1[0], &x1[N], &x2[0], 1,
                         multiplies<int>(), plus<int>());

  cout << "Inner product with roles of + and * reversed: " 
       << result << endl;
  return 0;
}
