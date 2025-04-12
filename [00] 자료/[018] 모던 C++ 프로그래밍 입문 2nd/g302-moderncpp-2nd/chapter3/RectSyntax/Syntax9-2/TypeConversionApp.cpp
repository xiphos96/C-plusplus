#include "Rect.h"

int main()
{
	// Rect type -> int type
	cout << "Rect to int conversion -----" << endl;
	Rect thatRectangle(40, 30, 80, 90);
	int i;
	// �ڵ� ��ȯ
	i = (++thatRectangle);
	cout << i << endl;
	// ���� ��ȯ
	int j = static_cast<int>(thatRectangle);
	cout << j << endl;
	// int type -> Rect type
	cout << "int to Rect conversion ------" << endl;
	Rect tempRectangle(50, 50, 100, 110);
	Rect theRectangle(40, 30, 80, 90);
	int m = 10000;
	// �ڵ� ��ȯ
	tempRectangle = m;
	cout << tempRectangle << endl;
	// ���� ��ȯ
	theRectangle = static_cast<Rect>(m);
	cout << theRectangle << endl;

	return 0;
}