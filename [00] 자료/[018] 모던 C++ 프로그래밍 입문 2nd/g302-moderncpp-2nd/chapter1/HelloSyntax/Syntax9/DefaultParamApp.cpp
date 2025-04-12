#include <iostream>
using std::cout;
using std::endl;

int boxVolume(int length, int width = 1, int height = 1)
{
	return length * width * height;
}

int main()
{
	cout << boxVolume(5, 6, 3) << endl;
	cout << boxVolume(5, 6) << endl;
	cout << boxVolume(5) << endl;

	return 0;
}