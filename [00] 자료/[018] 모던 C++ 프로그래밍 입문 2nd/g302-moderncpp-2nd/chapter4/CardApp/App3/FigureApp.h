//================================================================
// ���� ���� 3
// ���� ���� 2�� ������Ŵ
// ������ 10������ ���� �� ������ ���� Ŭ���ϸ�
// ���õ� ������ �ʷϻ����� ����
// std::array ���
//================================================================
#pragma once
#include "pclaf.h"
#include "Card.h"
#include <array>

const int MAX_FIGURES = 10;

class FigureApp : public Application
{
public:
	FigureApp(const TCHAR*);
	FigureApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void mouseRDown(int, int);
	// ���� ���� 3
	void doubleClick(int, int);
	void paint();
	// data fields, ���� ���� 3
	int numFigures = 0;
	std::array<FigurePtr, MAX_FIGURES> figures;
};