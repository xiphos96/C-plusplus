// ConsistenceDialog.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CConsistenceDialogApp:
// �� Ŭ������ ������ ���ؼ��� ConsistenceDialog.cpp�� �����Ͻʽÿ�.
//

class CConsistenceDialogApp : public CWinApp
{
public:
	CConsistenceDialogApp();

// ������
	//{{AFX_VIRTUAL(CConsistenceDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CConsistenceDialogApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CConsistenceDialogApp theApp;
