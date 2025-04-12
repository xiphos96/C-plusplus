//================================================================
// 응용 과제 4
// 응용 과제 3을 발전시킴
// 마우스 두 번 클릭으로 사각형들을 생성 후
// 오른쪽 버튼을 클릭하면 사각형들을 크기순으로 정렬
// vector에 사각형들을 직접 저장
//================================================================
#pragma once
#include "pclaf.h"
#include <vector>
class Rect;

const auto MAX_RECTS = 5;

class RectApp : public Application
{
public:
	RectApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void mouseRDown(int, int);		// 응용 과제 4
	void paint();
	// data fields, 응용 과제 4
	std::vector<Rect> theRects;		// 빈 벡터 생성
	int numRects = 0;
};