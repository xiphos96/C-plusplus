// ScrollableDialog.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CScrollableDialogApp:
// �� Ŭ������ ������ ���ؼ��� ScrollableDialog.cpp�� �����Ͻʽÿ�.
//

class CScrollableDialogApp : public CWinApp
{
public:
	CScrollableDialogApp();

// ������
	//{{AFX_VIRTUAL(CScrollableDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CScrollableDialogApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CScrollableDialogApp theApp;
