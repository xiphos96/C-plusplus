//==================================================================
// �ǽ� ����
// pclaf�� �̿��ؼ� ���콺 Ŭ������ �����쿡 ���� �׸�
//==================================================================
#pragma once
#include "pclaf.h"

// Customized Application
class PenApp : public Application
{
public:
	PenApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// �� ��ġ�� ���� ������ �ʵ�
	int oldx = 0;
	int oldy = 0;
	int newx = 0;
	int newy = 0;
};