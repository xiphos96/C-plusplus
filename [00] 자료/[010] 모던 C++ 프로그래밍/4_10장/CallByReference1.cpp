#include <iostream>
using namespace std;

int main(void)
{
	int value1 = 1, value2 = 11;
	int &refvalue1 = value1;
	refvalue1 = 22;
	refvalue1 = value2;
	value2 = refvalue1;

	cout << "value1 = " << value1 << endl;
	cout << "value2 = " << value2 << endl;
	cout << "refvalue1 = " << refvalue1 << endl;
}