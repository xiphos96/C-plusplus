// SlidingDialog.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CSlidingDialogApp:
// �� Ŭ������ ������ ���ؼ��� SlidingDialog.cpp�� �����Ͻʽÿ�.
//

class CSlidingDialogApp : public CWinApp
{
public:
	CSlidingDialogApp();

// ������
	//{{AFX_VIRTUAL(CSlidingDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CSlidingDialogApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CSlidingDialogApp theApp;
