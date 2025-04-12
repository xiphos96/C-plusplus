// RulerSplitterWndDemo.h : RulerSplitterWndDemo 응용 프로그램에 대한 주 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // 주 기호


// CRulerSplitterWndDemoApp:
// 이 클래스의 구현에 대해서는 RulerSplitterWndDemo.cpp을 참조하십시오.
//

class CRulerSplitterWndDemoApp : public CWinApp
{
public:
	CRulerSplitterWndDemoApp();


// 재정의
	//{{AFX_VIRTUAL(CRulerSplitterWndDemoApp)
public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// 구현
	//{{AFX_MSG(CRulerSplitterWndDemoApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CRulerSplitterWndDemoApp theApp;
