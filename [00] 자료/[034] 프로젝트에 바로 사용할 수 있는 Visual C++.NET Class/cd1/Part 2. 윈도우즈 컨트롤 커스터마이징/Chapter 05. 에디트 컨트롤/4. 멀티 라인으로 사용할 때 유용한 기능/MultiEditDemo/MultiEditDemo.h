// MultiEditDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CMultiEditDemoApp:
// �� Ŭ������ ������ ���ؼ��� MultiEditDemo.cpp�� �����Ͻʽÿ�.
//

class CMultiEditDemoApp : public CWinApp
{
public:
	CMultiEditDemoApp();

// ������
	//{{AFX_VIRTUAL(CMultiEditDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CMultiEditDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CMultiEditDemoApp theApp;
