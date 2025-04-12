#include <iostream>
using namespace std;

inline int SQ(int x)
{
	return x * x;
}

int main()
{
	cout << SQ(8) << '\n';
	cout << SQ(9 + 5) << '\n';

	return 0;
}