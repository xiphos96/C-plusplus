// ControlStatusBarDemo.h : ControlStatusBarDemo ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // �� ��ȣ


// CControlStatusBarDemoApp:
// �� Ŭ������ ������ ���ؼ��� ControlStatusBarDemo.cpp�� �����Ͻʽÿ�.
//

class CControlStatusBarDemoApp : public CWinApp
{
public:
	CControlStatusBarDemoApp();


// ������
	//{{AFX_VIRTUAL(CControlStatusBarDemoApp)
public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����
	//{{AFX_MSG(CControlStatusBarDemoApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CControlStatusBarDemoApp theApp;
