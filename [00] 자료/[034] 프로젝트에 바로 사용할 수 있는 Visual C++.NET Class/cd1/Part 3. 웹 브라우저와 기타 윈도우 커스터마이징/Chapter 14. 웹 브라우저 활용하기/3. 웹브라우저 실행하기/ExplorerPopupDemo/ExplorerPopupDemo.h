// ExplorerPopupDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CExplorerPopupDemoApp:
// �� Ŭ������ ������ ���ؼ��� ExplorerPopupDemo.cpp�� �����Ͻʽÿ�.
//

class CExplorerPopupDemoApp : public CWinApp
{
public:
	CExplorerPopupDemoApp();

// ������
	//{{AFX_VIRTUAL(CExplorerPopupDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CExplorerPopupDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CExplorerPopupDemoApp theApp;
