//==================================================================
// ���� ���� 2
// �ǽ� ������ ������Ŵ
// ������ ���콺 Ŭ������ ���� ���� �׸�
// ���� ������ hello ���ڿ� ���
//==================================================================
#pragma once
#include "pclaf.h"

class PenApp : public Application
{
public:
	PenApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	// ���� ���� 2
	void mouseRDown(int, int);
	void paint();
	// data fields for pen locations
	int oldx = 0;
	int oldy = 0;
	int newx = 0;
	int newy = 0;
};