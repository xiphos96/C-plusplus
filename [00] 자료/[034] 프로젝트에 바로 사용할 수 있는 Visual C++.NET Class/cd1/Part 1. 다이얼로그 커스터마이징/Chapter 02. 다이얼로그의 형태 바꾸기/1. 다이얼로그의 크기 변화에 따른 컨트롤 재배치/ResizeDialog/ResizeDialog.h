// ResizeDialog.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CResizeDialogApp:
// �� Ŭ������ ������ ���ؼ��� ResizeDialog.cpp�� �����Ͻʽÿ�.
//

class CResizeDialogApp : public CWinApp
{
public:
	CResizeDialogApp();

// ������
	//{{AFX_VIRTUAL(CResizeDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CResizeDialogApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CResizeDialogApp theApp;
