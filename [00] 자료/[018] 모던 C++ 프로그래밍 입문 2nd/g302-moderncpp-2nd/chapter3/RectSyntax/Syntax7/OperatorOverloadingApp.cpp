#include "Rect.h"

int main()
{
	// operator> 연산자 - 멤버 함수
	cout << "operator> 연산자" << endl;
	Rect thisRectangle(30, 40, 70, 80);
	Rect thatRectangle(100, 90, 110, 120);
	if (thisRectangle > thatRectangle)
		cout << thisRectangle << endl;
	// operator< 연산자 - 전역 함수
	cout << "operator< 연산자" << endl;
	Rect hisRectangle(30, 40, 70, 80);
	Rect herRectangle(100, 90, 130, 150);
	if (hisRectangle < herRectangle)
		cout << hisRectangle << endl;
	// operator++ 전위 연산자 - 멤버 함수
	cout << "operator++ 전위 연산자" << endl;
	Rect aRectangle(30, 40, 70, 80);
	cout << aRectangle << endl;
	cout << ++aRectangle << endl;
	cout << ++(++aRectangle) << endl;
	// operator-- 연산자 - 전역 함수
	cout << "operator-- 연산자" << endl;
	Rect theRectangle(30, 40, 70, 80);
	cout << theRectangle << endl;
	cout << --theRectangle << endl;
	cout << --(--theRectangle) << endl;
	// operator++ 후위 연산자 - 멤버 함수
	cout << "operator++ 후위 연산자" << endl;
	Rect myRectangle(30, 40, 70, 80);
	cout << myRectangle << endl;
	cout << myRectangle++ << endl;
	cout << myRectangle++ << endl;

	return 0;
}