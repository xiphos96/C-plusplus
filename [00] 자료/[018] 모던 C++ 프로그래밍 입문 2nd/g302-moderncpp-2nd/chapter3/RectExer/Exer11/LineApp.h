// ���� ���� 4�� ������Ŵ
// Line Ŭ���� �𵨸�
#pragma once
#include "pclaf.h"
#include <vector>
class Line;

class LineApp : public Application
{
public:
	// constructor
	LineApp(const TCHAR*, int, int, int, int);
	// operations
	void mouseDown(int, int);
	void paint();
	// data field: line vector
	std::vector<Line> lineVector;
};