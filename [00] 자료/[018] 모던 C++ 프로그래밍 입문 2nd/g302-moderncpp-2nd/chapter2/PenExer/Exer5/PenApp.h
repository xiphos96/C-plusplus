// ���� ���� 2�� ������Ŵ
// �� ���� ���콺 Ŭ������ ���� ����
// Point ����ü�� �����ؼ� ���

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