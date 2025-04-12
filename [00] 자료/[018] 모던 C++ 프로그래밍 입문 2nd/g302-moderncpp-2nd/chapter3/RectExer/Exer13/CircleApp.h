// ���� ���� 4�� ������Ŵ
// Circle Ŭ���� �𵨸�, smart pointer
#pragma once
#include "pclaf.h"
#include <memory>
#include <vector>
class Circle;

typedef std::shared_ptr<Circle> CirclePtr;

class CircleApp : public Application
{
public:
	// constructor
	CircleApp(const TCHAR*, int, int, int, int);
	// operations
	void mouseDown(int, int);
	void paint();
	// data field: circle pointer vector
	std::vector<CirclePtr> circlePtrVector;
};