// AutoTabCtrlDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CAutoTabCtrlDemoApp:
// �� Ŭ������ ������ ���ؼ��� AutoTabCtrlDemo.cpp�� �����Ͻʽÿ�.
//

class CAutoTabCtrlDemoApp : public CWinApp
{
public:
	CAutoTabCtrlDemoApp();

// ������
	//{{AFX_VIRTUAL(CAutoTabCtrlDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CAutoTabCtrlDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CAutoTabCtrlDemoApp theApp;
