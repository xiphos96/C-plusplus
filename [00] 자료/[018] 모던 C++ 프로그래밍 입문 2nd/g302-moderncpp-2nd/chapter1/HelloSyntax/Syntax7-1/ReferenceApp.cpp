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
	cout << "���� �Է�: ";
	cin >> number;
	square = cube = number;
	squareCube(square, cube);
	cout << number << "�� ������ " << square << endl;
	cout << "�������� " << cube << "�Դϴ�" << endl;

	return 0;
}