// DialogTabCtrlDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CDialogTabCtrlDemoApp:
// �� Ŭ������ ������ ���ؼ��� DialogTabCtrlDemo.cpp�� �����Ͻʽÿ�.
//

class CDialogTabCtrlDemoApp : public CWinApp
{
public:
	CDialogTabCtrlDemoApp();

// ������
	//{{AFX_VIRTUAL(CDialogTabCtrlDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CDialogTabCtrlDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CDialogTabCtrlDemoApp theApp;
