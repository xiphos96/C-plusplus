// ControlStatusBarDemo.h : ControlStatusBarDemo 응용 프로그램에 대한 주 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // 주 기호


// CControlStatusBarDemoApp:
// 이 클래스의 구현에 대해서는 ControlStatusBarDemo.cpp을 참조하십시오.
//

class CControlStatusBarDemoApp : public CWinApp
{
public:
	CControlStatusBarDemoApp();


// 재정의
	//{{AFX_VIRTUAL(CControlStatusBarDemoApp)
public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// 구현
	//{{AFX_MSG(CControlStatusBarDemoApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CControlStatusBarDemoApp theApp;
