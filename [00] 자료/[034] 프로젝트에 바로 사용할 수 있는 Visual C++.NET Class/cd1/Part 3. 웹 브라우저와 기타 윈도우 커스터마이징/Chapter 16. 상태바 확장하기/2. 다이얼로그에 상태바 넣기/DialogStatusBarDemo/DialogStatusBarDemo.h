// DialogStatusBarDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CDialogStatusBarDemoApp:
// �� Ŭ������ ������ ���ؼ��� DialogStatusBarDemo.cpp�� �����Ͻʽÿ�.
//

class CDialogStatusBarDemoApp : public CWinApp
{
public:
	CDialogStatusBarDemoApp();

// ������
	//{{AFX_VIRTUAL(CDialogStatusBarDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CDialogStatusBarDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CDialogStatusBarDemoApp theApp;
