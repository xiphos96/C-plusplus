#include "Rect.h"

int main()
{
	// operator> ������ - ��� �Լ�
	cout << "operator> ������" << endl;
	Rect thisRectangle(30, 40, 70, 80);
	Rect thatRectangle(100, 90, 110, 120);
	if (thisRectangle > thatRectangle)
		cout << thisRectangle << endl;
	// operator< ������ - ���� �Լ�
	cout << "operator< ������" << endl;
	Rect hisRectangle(30, 40, 70, 80);
	Rect herRectangle(100, 90, 130, 150);
	if (hisRectangle < herRectangle)
		cout << hisRectangle << endl;
	// operator++ ���� ������ - ��� �Լ�
	cout << "operator++ ���� ������" << endl;
	Rect aRectangle(30, 40, 70, 80);
	cout << aRectangle << endl;
	cout << ++aRectangle << endl;
	cout << ++(++aRectangle) << endl;
	// operator-- ������ - ���� �Լ�
	cout << "operator-- ������" << endl;
	Rect theRectangle(30, 40, 70, 80);
	cout << theRectangle << endl;
	cout << --theRectangle << endl;
	cout << --(--theRectangle) << endl;
	// operator++ ���� ������ - ��� �Լ�
	cout << "operator++ ���� ������" << endl;
	Rect myRectangle(30, 40, 70, 80);
	cout << myRectangle << endl;
	cout << myRectangle++ << endl;
	cout << myRectangle++ << endl;

	return 0;
}