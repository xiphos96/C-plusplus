// Demonstrating the STL vector capacity and reserve functions
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
class U { 
public: 
  unsigned long id;
  U() : id(0) { }
  U(unsigned long x) : id(x) { }
};

int main() 
{
  cout << "Demonstrating STL vector capacity and reserve "
          "functions." << endl;

  int N = 10000; // size of vectors

  vector<U> vector1, vector2;

  cout << "Doing " << N << " insertions in vector1,\n"
       << "with no advance reservation.\n";
  int k;
  for (k = 0; k != N; ++k) {
    vector<U>::size_type cap = vector1.capacity();
    vector1.push_back(U(k));
    if (vector1.capacity() != cap)
      cout << "k: " << k << ", new capacity: " 
           << vector1.capacity() << endl;
  }

  vector2.reserve(N);
  cout << "\nNow doing the same thing with vector2,\n"
       << "after starting with reserve(" << N << ").\n";
  for (k = 0; k != N; ++k) {
    vector<U>::size_type cap = vector2.capacity();
    vector2.push_back(U(k));
    if (vector2.capacity() != cap)
      cout << "k: " << k << ", new capacity: " 
           << vector2.capacity() << "\n";
  }
  return 0;
}
