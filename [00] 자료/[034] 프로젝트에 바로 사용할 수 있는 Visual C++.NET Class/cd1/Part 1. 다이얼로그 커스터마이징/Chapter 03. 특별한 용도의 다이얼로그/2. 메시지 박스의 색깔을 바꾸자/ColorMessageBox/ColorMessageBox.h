// ColorMessageBox.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CColorMessageBoxApp:
// �� Ŭ������ ������ ���ؼ��� ColorMessageBox.cpp�� �����Ͻʽÿ�.
//

class CColorMessageBoxApp : public CWinApp
{
public:
	CColorMessageBoxApp();

// ������
	//{{AFX_VIRTUAL(CColorMessageBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CColorMessageBoxApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CColorMessageBoxApp theApp;
