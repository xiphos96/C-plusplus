// FlatSplitterWndDemo.h : FlatSplitterWndDemo 응용 프로그램에 대한 주 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // 주 기호


// CFlatSplitterWndDemoApp:
// 이 클래스의 구현에 대해서는 FlatSplitterWndDemo.cpp을 참조하십시오.
//

class CFlatSplitterWndDemoApp : public CWinApp
{
public:
	CFlatSplitterWndDemoApp();


// 재정의
	//{{AFX_VIRTUAL(CFlatSplitterWndDemoApp)
public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// 구현
	//{{AFX_MSG(CFlatSplitterWndDemoApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CFlatSplitterWndDemoApp theApp;
