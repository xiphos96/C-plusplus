// MultiMediaTimerDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CMultiMediaTimerDemoApp:
// �� Ŭ������ ������ ���ؼ��� MultiMediaTimerDemo.cpp�� �����Ͻʽÿ�.
//

class CMultiMediaTimerDemoApp : public CWinApp
{
public:
	CMultiMediaTimerDemoApp();

// ������
	//{{AFX_VIRTUAL(CMultiMediaTimerDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CMultiMediaTimerDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CMultiMediaTimerDemoApp theApp;
