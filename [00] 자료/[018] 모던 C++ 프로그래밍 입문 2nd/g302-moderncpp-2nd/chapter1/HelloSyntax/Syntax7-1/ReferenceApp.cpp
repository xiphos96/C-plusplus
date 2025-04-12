#include <iostream>
using namespace std;

void squareCube(int& s, int& c)
{
	s = s * s;
	int temp = c * c;
	c = temp * c;
}

int main()
{
	int number, square, cube;
	cout << "정수 입력: ";
	cin >> number;
	square = cube = number;
	squareCube(square, cube);
	cout << number << "의 제곱은 " << square << endl;
	cout << "세제곱은 " << cube << "입니다" << endl;

	return 0;
}