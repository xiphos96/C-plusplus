// HTMLCollectorDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CHTMLCollectorDemoApp:
// �� Ŭ������ ������ ���ؼ��� HTMLCollectorDemo.cpp�� �����Ͻʽÿ�.
//

class CHTMLCollectorDemoApp : public CWinApp
{
public:
	CHTMLCollectorDemoApp();

// ������
	//{{AFX_VIRTUAL(CHTMLCollectorDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CHTMLCollectorDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CHTMLCollectorDemoApp theApp;
