// WarpTextDemo.h : PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 주 기호


// CWarpTextDemoApp:
// 이 클래스의 구현에 대해서는 WarpTextDemo.cpp을 참조하십시오.
//

class CWarpTextDemoApp : public CWinApp
{
public:
	CWarpTextDemoApp();

	GdiplusStartupInput		m_GDIPlusStartupInput;		// GDI+ 초기화 정보 구조체
	ULONG_PTR				m_GDIPlusToken;				// GDI+ 토큰

// 재정의
	//{{AFX_VIRTUAL(CWarpTextDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// 구현

	//{{AFX_MSG(CWarpTextDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CWarpTextDemoApp theApp;
