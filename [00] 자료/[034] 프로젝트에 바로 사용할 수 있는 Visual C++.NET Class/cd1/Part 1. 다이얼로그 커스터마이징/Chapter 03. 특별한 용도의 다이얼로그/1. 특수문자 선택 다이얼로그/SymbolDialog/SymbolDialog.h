// SymbolDialog.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CSymbolDialogApp:
// �� Ŭ������ ������ ���ؼ��� SymbolDialog.cpp�� �����Ͻʽÿ�.
//

class CSymbolDialogApp : public CWinApp
{
public:
	CSymbolDialogApp();

// ������
	//{{AFX_VIRTUAL(CSymbolDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CSymbolDialogApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CSymbolDialogApp theApp;
