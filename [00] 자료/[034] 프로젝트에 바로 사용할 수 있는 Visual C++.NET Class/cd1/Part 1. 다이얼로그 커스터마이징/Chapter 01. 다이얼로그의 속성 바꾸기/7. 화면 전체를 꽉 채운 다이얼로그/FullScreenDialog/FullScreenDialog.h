// FullScreenDialog.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CFullScreenDialogApp:
// �� Ŭ������ ������ ���ؼ��� FullScreenDialog.cpp�� �����Ͻʽÿ�.
//

class CFullScreenDialogApp : public CWinApp
{
public:
	CFullScreenDialogApp();

// ������
	//{{AFX_VIRTUAL(CFullScreenDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CFullScreenDialogApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CFullScreenDialogApp theApp;
