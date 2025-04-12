#include "Rect.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class RotateRect
{
public:
	void operator()(Rect& r)
	{
		int width = r.getLowerRightX() - r.getUpperLeftX();
		int height = r.getLowerRightY() - r.getUpperLeftY();
		r.setLowerRightX(r.getUpperLeftX() + height);
		r.setLowerRightY(r.getUpperLeftY() + width);
	}
};

void rectRotate(Rect& r)
{
	int width = r.getLowerRightX() - r.getUpperLeftX();
	int height = r.getLowerRightY() - r.getUpperLeftY();
	r.setLowerRightX(r.getUpperLeftX() + height);
	r.setLowerRightY(r.getUpperLeftY() + width);
}

int main()
{
	vector<Rect> rectVector;
	Rect aRect(0, 0, 70, 90);
	Rect bRect(0, 0, 130, 150);
	Rect cRect(0, 0, 50, 60);
	rectVector.push_back(aRect);
	rectVector.push_back(bRect);
	rectVector.push_back(cRect);
	// �� �簢���� ȸ��
	// 1. for�� ���
	cout << "For ---------------------" << endl;
	for (Rect& r : rectVector) {
		int width = r.getLowerRightX() - r.getUpperLeftX();
		int height = r.getLowerRightY() - r.getUpperLeftY();
		r.setLowerRightX(r.getUpperLeftX() + height);
		r.setLowerRightY(r.getUpperLeftY() + width);
	}
	for (const Rect& r : rectVector) {
		cout << "lowerRightX = " << r.getLowerRightX()
			<< ", lowerRightY = " << r.getLowerRightY() << endl;
	}
	// 2. �Լ� ��ü ���
	cout << "Functor -----------------" << endl;
	RotateRect rotateRect;
	// for_each(rectVector.begin(), rectVector.end(), RotateRect());
	for_each(rectVector.begin(), rectVector.end(), rotateRect);
	for (const Rect& r : rectVector) {
		cout << "lowerRightX = " << r.getLowerRightX()
			<< ", lowerRightY = " << r.getLowerRightY() << endl;
	}
	// 3. �Լ� ������ ���
	cout << "Function Pointer --------" << endl;
	for_each(rectVector.begin(), rectVector.end(), rectRotate);
	for (const Rect& r : rectVector) {
		cout << "lowerRightX = " << r.getLowerRightX()
			<< ", lowerRightY = " << r.getLowerRightY() << endl;
	}

	return 0;
}