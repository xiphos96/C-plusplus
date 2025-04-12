//================================================================
// ���� ���� 3
// �ǽ� ������ ������Ŵ
// 20������ �簢���� ����
//================================================================
#pragma once
#include "pclaf.h"
#include <array>
#include <memory>
class Rect;

const auto MAX_RECTS = 20;

class RectApp : public Application
{
public:
	RectApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// data fields, ���� ���� 3
	std::array<std::shared_ptr<Rect>, MAX_RECTS> rects;
	int rectCount = 0;
};