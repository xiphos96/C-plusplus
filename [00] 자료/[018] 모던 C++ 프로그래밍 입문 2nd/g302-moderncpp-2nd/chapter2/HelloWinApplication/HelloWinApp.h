#pragma once
#include "pclaf.h"

class HelloWinApp : public Application
{
public:
	HelloWinApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
};