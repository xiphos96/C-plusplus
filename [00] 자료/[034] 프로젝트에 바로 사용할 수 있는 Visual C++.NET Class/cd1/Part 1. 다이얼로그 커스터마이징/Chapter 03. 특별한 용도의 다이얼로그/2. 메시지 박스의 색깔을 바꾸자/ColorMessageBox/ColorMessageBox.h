// ColorMessageBox.h : PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 주 기호


// CColorMessageBoxApp:
// 이 클래스의 구현에 대해서는 ColorMessageBox.cpp을 참조하십시오.
//

class CColorMessageBoxApp : public CWinApp
{
public:
	CColorMessageBoxApp();

// 재정의
	//{{AFX_VIRTUAL(CColorMessageBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// 구현

	//{{AFX_MSG(CColorMessageBoxApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CColorMessageBoxApp theApp;
