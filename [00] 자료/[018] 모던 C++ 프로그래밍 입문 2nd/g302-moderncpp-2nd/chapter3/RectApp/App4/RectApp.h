//================================================================
// ���� ���� 4
// ���� ���� 3�� ������Ŵ
// ���콺 �� �� Ŭ������ �簢������ ���� ��
// ������ ��ư�� Ŭ���ϸ� �簢������ ũ������� ����
// vector�� �簢������ ���� ����
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
	void mouseRDown(int, int);		// ���� ���� 4
	void paint();
	// data fields, ���� ���� 4
	std::vector<Rect> theRects;		// �� ���� ����
	int numRects = 0;
};