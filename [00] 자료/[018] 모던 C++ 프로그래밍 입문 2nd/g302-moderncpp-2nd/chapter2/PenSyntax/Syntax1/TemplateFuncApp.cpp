#include <iostream>
using std::cout;
using std::endl;

template <typename T>
T max(T a, T b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	int i = 300;
	int j = 400;
	int k = max(i, j);
	cout << "�� ���� �� ū ���� " << k << "�Դϴ�." << endl;
	float x = 250.0f;
	float y = 250.57f;
	float z = max(x, y);
	cout << "�� �Ǽ� �� ū ���� " << z << "�Դϴ�." << endl;

	return 0;
}