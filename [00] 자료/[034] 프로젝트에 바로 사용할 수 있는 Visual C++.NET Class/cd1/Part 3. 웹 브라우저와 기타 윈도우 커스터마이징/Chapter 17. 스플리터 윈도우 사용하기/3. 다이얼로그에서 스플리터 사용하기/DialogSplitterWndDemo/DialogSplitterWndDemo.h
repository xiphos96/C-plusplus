// DialogSplitterWndDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CDialogSplitterWndDemoApp:
// �� Ŭ������ ������ ���ؼ��� DialogSplitterWndDemo.cpp�� �����Ͻʽÿ�.
//

class CDialogSplitterWndDemoApp : public CWinApp
{
public:
	CDialogSplitterWndDemoApp();

// ������
	//{{AFX_VIRTUAL(CDialogSplitterWndDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CDialogSplitterWndDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CDialogSplitterWndDemoApp theApp;
