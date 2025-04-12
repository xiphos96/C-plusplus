#include <iostream>
using std::cout;
using std::endl;

int& max(int& a, int& b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	int i = 20, j = 10;
	int& k = max(i, j);
	cout << k << endl;

	return 0;
}