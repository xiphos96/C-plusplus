// DDTreeCtrlDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CDDTreeCtrlDemoApp:
// �� Ŭ������ ������ ���ؼ��� DDTreeCtrlDemo.cpp�� �����Ͻʽÿ�.
//

class CDDTreeCtrlDemoApp : public CWinApp
{
public:
	CDDTreeCtrlDemoApp();

// ������
	//{{AFX_VIRTUAL(CDDTreeCtrlDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CDDTreeCtrlDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CDDTreeCtrlDemoApp theApp;
