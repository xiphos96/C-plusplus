// ColorPickButtonDemo.h : PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 주 기호


// CColorPickButtonDemoApp:
// 이 클래스의 구현에 대해서는 ColorPickButtonDemo.cpp을 참조하십시오.
//

class CColorPickButtonDemoApp : public CWinApp
{
public:
	CColorPickButtonDemoApp();

// 재정의
	//{{AFX_VIRTUAL(CColorPickButtonDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// 구현

	//{{AFX_MSG(CColorPickButtonDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CColorPickButtonDemoApp theApp;
