// FoldDialog.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CFoldDialogApp:
// �� Ŭ������ ������ ���ؼ��� FoldDialog.cpp�� �����Ͻʽÿ�.
//

class CFoldDialogApp : public CWinApp
{
public:
	CFoldDialogApp();

// ������
	//{{AFX_VIRTUAL(CFoldDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CFoldDialogApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CFoldDialogApp theApp;
