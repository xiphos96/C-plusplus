// CustomTabCtrlDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CCustomTabCtrlDemoApp:
// �� Ŭ������ ������ ���ؼ��� CustomTabCtrlDemo.cpp�� �����Ͻʽÿ�.
//

class CCustomTabCtrlDemoApp : public CWinApp
{
public:
	CCustomTabCtrlDemoApp();

// ������
	//{{AFX_VIRTUAL(CCustomTabCtrlDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CCustomTabCtrlDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CCustomTabCtrlDemoApp theApp;
