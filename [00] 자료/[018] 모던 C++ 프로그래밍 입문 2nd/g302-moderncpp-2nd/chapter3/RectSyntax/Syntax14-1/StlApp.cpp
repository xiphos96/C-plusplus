#include "Rect.h"
#include <memory>
#include <vector>

int main()
{
	// 사각형을 담을 vector
	cout << "-- 사각형 벡터 --" << endl;
	std::vector<Rect> rectVector;
	Rect aRect(10, 10, 130, 130);
	Rect bRect(20, 20, 100, 110);
	Rect cRect(30, 30, 70, 70);
	rectVector.push_back(aRect);
	rectVector.push_back(bRect);
	rectVector.push_back(cRect);
	// 사각형의 개수
	cout << "사각형의 개수" << endl;
	int rectCount = rectVector.size();
	cout << rectCount << endl;
	// 반복자로 접근 - 순방향
	cout << "반복자 - 순방향" << endl;
	for (std::vector<Rect>::iterator it = rectVector.begin();
			it != rectVector.end(); ++it)
		cout << *it << endl;
	// 반복자로 접근 - 순방향(일부)
	cout << "반복자 - 순방향(일부)" << endl;
	std::vector<Rect>::iterator iter = rectVector.begin() + 2;
	for (std::vector<Rect>::iterator it = rectVector.begin();
			it != iter; ++it)
		cout << *it << endl;
	// 반복자로 접근 - 역방향
	cout << "반복자 - 역방향" << endl;
	for (std::vector<Rect>::reverse_iterator it = rectVector.rbegin();
			it != rectVector.rend(); ++it) {
		it->moveTo(150, 150);
		cout << *it << endl;
	}
	// 배열 방식으로 접근
	cout << "배열 방식으로 접근" << endl;
	for (int i = 0; i < rectCount; ++i) {
		rectVector[i].moveTo(300, 300);
		cout << rectVector[i] << endl;
	}
	// 첫 번째 사각형에 접근
	cout << "첫 번째 사각형의 왼쪽 위 꼭짓점의 x 좌표" << endl;
	Rect& firstRect = rectVector.front();
	cout << firstRect.getUpperLeftX() << endl;
	// 마지막 사각형에 접근
	cout << "마지막 사각형의 오른쪽 아래 꼭짓점의 x 좌표" << endl;
	Rect& lastRect = rectVector.back();
	cout << lastRect.getLowerRightX() << endl;
	// at을 사용해서 두 번째 사각형에 접근
	cout << "두 번째 사각형의 오른쪽 아래 꼭짓점의 y 좌표" << endl;
	Rect& secondRect = rectVector.at(1);
	cout << secondRect.getLowerRightY() << endl;
	// 마지막 사각형 제거
	cout << "마지막 사각형 제거" << endl;
	rectVector.pop_back();
	cout << "사각형의 개수" << endl;
	rectCount = rectVector.size();
	cout << rectCount << endl;
	// 사각형이 있다면 모두 제거
	cout << "사각형 모두 제거" << endl;
	if (!rectVector.empty()) {
		rectVector.clear();
		rectCount = rectVector.size();
		cout << "사각형의 개수" << endl;
		cout << rectCount << endl;
	}
	// 사각형 포인터를 담을 vector
	cout << "-- 사각형 포인터 벡터 --" << endl;
	typedef std::shared_ptr<Rect> RectPtr;
	std::vector<RectPtr> rectPtrVector;
	RectPtr aRectPtr(new Rect(510, 110, 630, 230));
	rectPtrVector.push_back(aRectPtr);
	rectPtrVector.push_back(std::make_shared<Rect>(520, 120, 600, 210));
	rectPtrVector.push_back(std::make_shared<Rect>(530, 130, 570, 170));
	// 반복자로 접근 - 순방향
	cout << "반복자 - 순방향" << endl;
	for (std::vector<RectPtr>::iterator it = rectPtrVector.begin();
			it != rectPtrVector.end(); ++it) {
		cout << *(*it) << endl;			// RectPtr& rp = *it; cout << *rp << endl;
		cout << "area : " << (*it)->area() << endl;
	}
	/*
	for (auto it = rectPtrVector.begin(); it != rectPtrVector.end(); ++it) {
		cout << *(*it) << endl;
		cout << "area : " << (*it)->area() << endl;
	}
	*/
	rectPtrVector.clear();

	return 0;
}