// FlatHeaderCtrlDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CFlatHeaderCtrlDemoApp:
// �� Ŭ������ ������ ���ؼ��� FlatHeaderCtrlDemo.cpp�� �����Ͻʽÿ�.
//

class CFlatHeaderCtrlDemoApp : public CWinApp
{
public:
	CFlatHeaderCtrlDemoApp();

// ������
	//{{AFX_VIRTUAL(CFlatHeaderCtrlDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CFlatHeaderCtrlDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CFlatHeaderCtrlDemoApp theApp;
