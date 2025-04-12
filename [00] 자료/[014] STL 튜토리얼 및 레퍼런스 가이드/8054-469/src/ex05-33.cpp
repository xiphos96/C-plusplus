// Illustrating the generic adjacent_difference algorithm
#include <iostream>
#include <cassert>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
  cout << "Illustrating the generic "
       << "adjacent_difference algorithm." << endl;
  const int N = 20;
  int x1[N], x2[N];
  int i;
  for (i = 0; i < N; ++i)
    x1[i] = i;

  // Compute the partial sums of 0, 1, 2, 3, ..., N - 1,
  // putting the result in x2:
  partial_sum(&x1[0], &x1[N], &x2[0]);

  // Compute the adjacent differences of elements in x2,
  // placing the result back in x2:
  adjacent_difference(&x2[0], &x2[N], &x2[0]);

  // The result is the original 0, 1, 2, 3, ..., N - 1:
  for (i = 0; i < N; ++i)
      assert (x2[i] == i);
  cout << " --- Ok." << endl;
  return 0;
}
