// ListCtrlTipDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CListCtrlTipDemoApp:
// �� Ŭ������ ������ ���ؼ��� ListCtrlTipDemo.cpp�� �����Ͻʽÿ�.
//

class CListCtrlTipDemoApp : public CWinApp
{
public:
	CListCtrlTipDemoApp();

// ������
	//{{AFX_VIRTUAL(CListCtrlTipDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CListCtrlTipDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CListCtrlTipDemoApp theApp;
