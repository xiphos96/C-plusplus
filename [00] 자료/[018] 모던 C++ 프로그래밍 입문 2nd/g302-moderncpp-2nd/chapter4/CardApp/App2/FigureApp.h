//================================================================
// ���� ���� 2
// �ǽ� ������ ������Ŵ
// ���� ���콺 ��ư���� ������ ī����� �����ϰ�
// ������ ���콺 ��ư���� Ŭ������ �������� �ϰ�
// �������� 40�� ������ �׸�
// ������ ������ ���� ����
//================================================================
#pragma once
#include "pclaf.h"
#include "Card.h"
#include <vector>

class FigureApp : public Application
{
public:
	FigureApp(const TCHAR*);
	FigureApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void mouseRDown(int, int);
	void paint();
	// data field
	std::vector<FigurePtr> figures;
};