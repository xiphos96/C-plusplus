// ImageProgressCtrlDemo.h : PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 주 기호


// CImageProgressCtrlDemoApp:
// 이 클래스의 구현에 대해서는 ImageProgressCtrlDemo.cpp을 참조하십시오.
//

class CImageProgressCtrlDemoApp : public CWinApp
{
public:
	CImageProgressCtrlDemoApp();

// 재정의
	//{{AFX_VIRTUAL(CImageProgressCtrlDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// 구현

	//{{AFX_MSG(CImageProgressCtrlDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CImageProgressCtrlDemoApp theApp;
