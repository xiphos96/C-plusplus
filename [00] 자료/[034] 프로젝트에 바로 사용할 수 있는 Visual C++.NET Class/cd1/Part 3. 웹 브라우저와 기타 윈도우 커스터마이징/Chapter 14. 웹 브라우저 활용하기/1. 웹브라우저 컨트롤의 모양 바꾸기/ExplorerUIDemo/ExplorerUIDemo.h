// ExplorerUIDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CExplorerUIDemoApp:
// �� Ŭ������ ������ ���ؼ��� ExplorerUIDemo.cpp�� �����Ͻʽÿ�.
//

class CExplorerUIDemoApp : public CWinApp
{
public:
	CExplorerUIDemoApp();
	virtual ~CExplorerUIDemoApp();

// ������
	//{{AFX_VIRTUAL(CExplorerUIDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CExplorerUIDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CExplorerUIDemoApp theApp;
