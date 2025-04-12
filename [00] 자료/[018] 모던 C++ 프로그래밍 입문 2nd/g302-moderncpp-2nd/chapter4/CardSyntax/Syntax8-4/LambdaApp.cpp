#include "Rect.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class FindAreaRect
{
public:
	bool operator()(Rect& r) {
		return (r.area() >= compareArea ? true : false);
	}

	int compareArea = 0;
};

int main()
{
	vector<Rect> rectVector;
	Rect aRect(30, 40, 70, 70);			// area = 1200
	Rect bRect(100, 90, 130, 150);		// area = 1800
	Rect cRect(20, 30, 50, 50);			// area = 600
	Rect dRect(100, 100, 150, 150);		// area = 2500
	rectVector.push_back(aRect);
	rectVector.push_back(bRect);
	rectVector.push_back(cRect);
	rectVector.push_back(dRect);
	vector<Rect>::iterator findRect;
	// ������ 1500 �̻��� ù ��° �簢�� ã��
	// Functor
	FindAreaRect findAreaRect;
	findAreaRect.compareArea = 1500;
	findRect = find_if(rectVector.begin(), rectVector.end(), findAreaRect);
	if (findRect != rectVector.end()) {
		cout << "������ 1500 ���� ū ù �簢���� " << *findRect << endl;
	}
	else {
		cout << "������ 1500���� ū �簢�� ����" << endl;
	}
	// ������ 2000 �̻��� ù ��° �簢�� ã��
	// Lambda
	findRect = find_if(rectVector.begin(), rectVector.end(),
		[compareArea = 2000](auto r)
		{ return (r.area() >= compareArea ? true : false); });
	if (findRect != rectVector.end()) {
		cout << "������ 2000 ���� ū ù �簢���� " << *findRect << endl;
	}
	else {
		cout << "������ 2000���� ū �簢�� ����" << endl;
	}

	return 0;
}