// CamCastDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CCamCastDemoApp:
// �� Ŭ������ ������ ���ؼ��� CamCastDemo.cpp�� �����Ͻʽÿ�.
//

class CCamCastDemoApp : public CWinApp
{
public:
	CCamCastDemoApp();

// ������
	//{{AFX_VIRTUAL(CCamCastDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CCamCastDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CCamCastDemoApp theApp;
