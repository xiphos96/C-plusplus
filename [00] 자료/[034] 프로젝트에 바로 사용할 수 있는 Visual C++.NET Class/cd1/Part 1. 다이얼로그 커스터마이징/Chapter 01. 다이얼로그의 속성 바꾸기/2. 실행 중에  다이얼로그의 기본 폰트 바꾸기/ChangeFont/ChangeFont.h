// ChangeFont.h : PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 주 기호


// CChangeFontApp:
// 이 클래스의 구현에 대해서는 ChangeFont.cpp을 참조하십시오.
//

class CChangeFontApp : public CWinApp
{
public:
	CChangeFontApp();

// 재정의
	//{{AFX_VIRTUAL(CChangeFontApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// 구현

	//{{AFX_MSG(CChangeFontApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CChangeFontApp theApp;
