#include "RectApp.h"
#include "Rect.h"
#include <memory>
#include <algorithm>				// ���� ���� 4

// ���� ���� 4
int upperLeftX, upperLeftY, lowerRightX, lowerRightY;
bool firstClick = true;
bool sorting = false;

RectApp::RectApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

// ���� ���� 4, ���� �Լ�
bool operator<(const Rect& left, const Rect& right)
{
	int leftArea = (left.lowerRightX - left.upperLeftX) *
		(left.lowerRightY - left.upperLeftY);
	int rightArea = (right.lowerRightX - right.upperLeftX) *
		(right.lowerRightY - right.upperLeftY);
	if (leftArea < rightArea)
		return true;
	else
		return false;
}
// ���� ���� 4, ���� �Լ�
bool operator>(const Rect& left, const Rect& right)
{
	int leftArea = (left.lowerRightX - left.upperLeftX) *
		(left.lowerRightY - left.upperLeftY);
	int rightArea = (right.lowerRightX - right.upperLeftX) *
		(right.lowerRightY - right.upperLeftY);
	if (leftArea > rightArea)
		return true;
	else
		return false;
}

// ���� ���� 4
void RectApp::mouseDown(int x, int y)
{
	if (firstClick) {
		upperLeftX = x;
		upperLeftY = y;
		firstClick = false;
	}
	else {
		lowerRightX = x;
		lowerRightY = y;
		// �簢�� ��ü ���� �� ���Ϳ� ����
		if (numRects < MAX_RECTS) {
			theRects.push_back(*(std::make_shared<Rect>
						(upperLeftX, upperLeftY, lowerRightX, lowerRightY)));
			/*
			Rect* r = new Rect(upperLeftX, upperLeftY, lowerRightX, lowerRightY);
			theRects.push_back(*r);
			*/
			++numRects;
		}
		firstClick = true;
		clearAndUpdate();
	}
}

// ���� ���� 4
void RectApp::mouseRDown(int x, int y)
{
	sorting = true;
	clearAndUpdate();
}

// ���� ���� 4
void RectApp::paint()
{
	if (sorting) { // ������ ��ư�� Ŭ������ ���� ó��
		std::sort(theRects.begin(), theRects.end());					// ���� ����
//		std::sort(theRects.begin(), theRects.end(), operator>);		// ���� ����
		int i = 0;
		for(Rect& r : theRects) {
			r.draw(*this);
			// ������ �������� ���� ǥ��
			wout << setpos(r.upperLeftX, r.upperLeftY) << ++i;
		}
	}
	else {
		for (auto r : theRects)
			r.draw(*this);
	}
}

int mainLAF()
{
	RectApp theApp(TEXT("RECTANGLES"), 750, 500, 150, 150);
	theApp.run();

	return 0;
}