//====================================================================
// �ǽ� ����
// ���콺 Ŭ������ ���� �� ������, �� 70, ���� 50�� û�� �簢���� �׸�
// ������ �簢�� ������ Ŭ���ϸ� �� ������ �簢���� �̵�
//====================================================================
#pragma once
#include "pclaf.h"
class Rect;

// Customized Application
class RectApp : public Application
{
public:
	RectApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// data field
	Rect* theRectPtr = nullptr;
};