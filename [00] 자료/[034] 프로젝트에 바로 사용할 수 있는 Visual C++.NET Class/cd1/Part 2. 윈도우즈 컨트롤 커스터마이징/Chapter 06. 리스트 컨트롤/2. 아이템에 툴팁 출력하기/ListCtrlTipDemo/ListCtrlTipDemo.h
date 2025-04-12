// ListCtrlTipDemo.h : PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 주 기호


// CListCtrlTipDemoApp:
// 이 클래스의 구현에 대해서는 ListCtrlTipDemo.cpp을 참조하십시오.
//

class CListCtrlTipDemoApp : public CWinApp
{
public:
	CListCtrlTipDemoApp();

// 재정의
	//{{AFX_VIRTUAL(CListCtrlTipDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// 구현

	//{{AFX_MSG(CListCtrlTipDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CListCtrlTipDemoApp theApp;
