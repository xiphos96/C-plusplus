#include "Rect.h"
#include <list>

int main()
{
	// 사각형을 담을 list
	std::list<Rect> rectList;
	Rect aRect(10, 10, 130, 130);
	Rect bRect(20, 20, 100, 110);
	Rect cRect(30, 30, 70, 70);
	rectList.push_back(aRect);
	rectList.push_front(bRect);
	rectList.push_front(cRect);
	// 범위 기반 for문 - 순방향
	cout << "범위 기반 for - 순방향" << endl;
	for (auto& r : rectList)
		cout << r << endl;
	// 반복자로 접근 - 역방향
	cout << "반복자 - 역방향" << endl;
	std::list<Rect>::reverse_iterator it;
	for (it = rectList.rbegin(); it != rectList.rend(); ++it) {
		it->moveTo(150, 150);
		cout << *it << endl;
	}
	// 첫 번째 사각형에 접근
	cout << "첫 번째 사각형의 왼쪽 위 꼭짓점의 x 좌표" << endl;
	Rect& firstRect = rectList.front();
	cout << firstRect.getUpperLeftX() << endl;
	// 첫 번째 사각형 제거
	rectList.pop_front();
	// 마지막 사각형 제거
	rectList.pop_back();
	cout << "첫 번째와 마지막 사각형 제거" << endl;
	cout << "사각형의 개수" << endl;
	int rectCount = rectList.size();
	cout << rectCount << endl;
	// 사각형이 있다면 모두 제거
	cout << "사각형 모두 제거" << endl;
	if (!rectList.empty()) {
		rectList.clear();
		cout << "사각형의 개수" << endl;
		rectCount = rectList.size();
		cout << rectCount << endl;
	}

	return 0;
}