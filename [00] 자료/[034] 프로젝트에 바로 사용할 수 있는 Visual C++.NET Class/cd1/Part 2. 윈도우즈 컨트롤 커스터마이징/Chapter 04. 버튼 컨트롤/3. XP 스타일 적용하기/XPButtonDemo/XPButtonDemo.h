// XPButtonDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CXPButtonDemoApp:
// �� Ŭ������ ������ ���ؼ��� XPButtonDemo.cpp�� �����Ͻʽÿ�.
//

class CXPButtonDemoApp : public CWinApp
{
public:
	CXPButtonDemoApp();

// ������
	//{{AFX_VIRTUAL(CXPButtonDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CXPButtonDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CXPButtonDemoApp theApp;
