// MoviePlayerDemo.h : PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 주 기호


// CMoviePlayerDemoApp:
// 이 클래스의 구현에 대해서는 MoviePlayerDemo.cpp을 참조하십시오.
//

class CMoviePlayerDemoApp : public CWinApp
{
public:
	CMoviePlayerDemoApp();

// 재정의
	//{{AFX_VIRTUAL(CMoviePlayerDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// 구현

	//{{AFX_MSG(CMoviePlayerDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CMoviePlayerDemoApp theApp;
