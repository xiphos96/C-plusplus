// SectionLineDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CSectionLineDemoApp:
// �� Ŭ������ ������ ���ؼ��� SectionLineDemo.cpp�� �����Ͻʽÿ�.
//

class CSectionLineDemoApp : public CWinApp
{
public:
	CSectionLineDemoApp();

// ������
	//{{AFX_VIRTUAL(CSectionLineDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CSectionLineDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CSectionLineDemoApp theApp;
