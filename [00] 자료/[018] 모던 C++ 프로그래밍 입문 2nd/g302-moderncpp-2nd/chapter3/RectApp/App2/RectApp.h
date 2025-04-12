//================================================================
// 응용 과제 2
// 실습 과제를 발전시킴
// namespace, unique_ptr
//================================================================
#pragma once
#include "pclaf.h"
#include "Rect.h"
#include <memory>
using namespace RectSpace;

class RectApp : public Application
{
public:
	RectApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// data field
	std::unique_ptr<Rect> smartRectangle = nullptr;
};