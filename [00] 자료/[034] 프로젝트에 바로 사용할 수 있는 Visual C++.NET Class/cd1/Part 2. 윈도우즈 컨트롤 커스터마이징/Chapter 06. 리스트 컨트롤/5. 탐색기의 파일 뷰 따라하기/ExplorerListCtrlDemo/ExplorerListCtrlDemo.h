// ExplorerListCtrlDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CExplorerListCtrlDemoApp:
// �� Ŭ������ ������ ���ؼ��� ExplorerListCtrlDemo.cpp�� �����Ͻʽÿ�.
//

class CExplorerListCtrlDemoApp : public CWinApp
{
public:
	CExplorerListCtrlDemoApp();

// ������
	//{{AFX_VIRTUAL(CExplorerListCtrlDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CExplorerListCtrlDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CExplorerListCtrlDemoApp theApp;
