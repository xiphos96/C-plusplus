// TransparentDialog.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CTransparentDialogApp:
// �� Ŭ������ ������ ���ؼ��� TransparentDialog.cpp�� �����Ͻʽÿ�.
//

class CTransparentDialogApp : public CWinApp
{
public:
	CTransparentDialogApp();

// ������
	//{{AFX_VIRTUAL(CTransparentDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CTransparentDialogApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CTransparentDialogApp theApp;
