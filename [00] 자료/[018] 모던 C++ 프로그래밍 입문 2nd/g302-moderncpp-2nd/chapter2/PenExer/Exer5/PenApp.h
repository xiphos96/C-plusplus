// 응용 과제 2를 발전시킴
// 두 번의 마우스 클릭으로 선을 정의
// Point 구조체를 정의해서 사용

#pragma once
#include "pclaf.h"

// Exer
struct Pt
{
	int x = 0;
	int y = 0;
};

class PenApp : public Application
{
public:
	PenApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// Exer: data fields
	Pt startPoint, endPoint;
};