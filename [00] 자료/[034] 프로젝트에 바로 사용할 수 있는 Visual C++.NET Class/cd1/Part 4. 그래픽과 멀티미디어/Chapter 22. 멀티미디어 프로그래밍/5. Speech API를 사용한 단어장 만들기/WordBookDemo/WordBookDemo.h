// WordBookDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CWordBookDemoApp:
// �� Ŭ������ ������ ���ؼ��� WordBookDemo.cpp�� �����Ͻʽÿ�.
//

class CWordBookDemoApp : public CWinApp
{
public:
	CWordBookDemoApp();

// ������
	//{{AFX_VIRTUAL(CWordBookDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CWordBookDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CWordBookDemoApp theApp;
