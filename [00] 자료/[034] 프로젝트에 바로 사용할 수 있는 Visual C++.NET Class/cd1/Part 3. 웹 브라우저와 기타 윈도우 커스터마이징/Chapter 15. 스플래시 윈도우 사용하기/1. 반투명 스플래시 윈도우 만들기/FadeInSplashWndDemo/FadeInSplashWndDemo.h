// FadeInSplashWndDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CFadeInSplashWndDemoApp:
// �� Ŭ������ ������ ���ؼ��� FadeInSplashWndDemo.cpp�� �����Ͻʽÿ�.
//

class CFadeInSplashWndDemoApp : public CWinApp
{
public:
	CFadeInSplashWndDemoApp();

// ������
	//{{AFX_VIRTUAL(CFadeInSplashWndDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CFadeInSplashWndDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CFadeInSplashWndDemoApp theApp;
