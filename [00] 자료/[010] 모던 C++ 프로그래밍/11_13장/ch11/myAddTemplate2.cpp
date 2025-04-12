#include <iostream>
 
using namespace std;
 
template <typename T>
T const add(T const& a, T const& b)
{
    return a+b;
}
 
int main()
{
    int i = 5;
    double j = 10.2;
     
    cout << i << " + " << j << " = " << add(i, j) << endl;
     
    return 0;
}

