// PictureDemo.h : PictureDemo 응용 프로그램에 대한 주 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // 주 기호


// CPictureDemoApp:
// 이 클래스의 구현에 대해서는 PictureDemo.cpp을 참조하십시오.
//

class CPictureDemoApp : public CWinApp
{
public:
	CPictureDemoApp();


// 재정의
	//{{AFX_VIRTUAL(CPictureDemoApp)
public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// 구현
	//{{AFX_MSG(CPictureDemoApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CPictureDemoApp theApp;
