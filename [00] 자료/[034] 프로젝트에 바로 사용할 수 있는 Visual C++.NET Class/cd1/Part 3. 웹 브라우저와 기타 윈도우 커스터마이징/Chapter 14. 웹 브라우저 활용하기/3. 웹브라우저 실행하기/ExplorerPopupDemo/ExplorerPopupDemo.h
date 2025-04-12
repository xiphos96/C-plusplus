// ExplorerPopupDemo.h : PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 주 기호


// CExplorerPopupDemoApp:
// 이 클래스의 구현에 대해서는 ExplorerPopupDemo.cpp을 참조하십시오.
//

class CExplorerPopupDemoApp : public CWinApp
{
public:
	CExplorerPopupDemoApp();

// 재정의
	//{{AFX_VIRTUAL(CExplorerPopupDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// 구현

	//{{AFX_MSG(CExplorerPopupDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CExplorerPopupDemoApp theApp;
