// ExplorerPrintDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CExplorerPrintDemoApp:
// �� Ŭ������ ������ ���ؼ��� ExplorerPrintDemo.cpp�� �����Ͻʽÿ�.
//

class CExplorerPrintDemoApp : public CWinApp
{
public:
	CExplorerPrintDemoApp();

// ������
	//{{AFX_VIRTUAL(CExplorerPrintDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CExplorerPrintDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CExplorerPrintDemoApp theApp;
