// MultiListBoxDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CMultiListBoxDemoApp:
// �� Ŭ������ ������ ���ؼ��� MultiListBoxDemo.cpp�� �����Ͻʽÿ�.
//

class CMultiListBoxDemoApp : public CWinApp
{
public:
	CMultiListBoxDemoApp();

// ������
	//{{AFX_VIRTUAL(CMultiListBoxDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CMultiListBoxDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CMultiListBoxDemoApp theApp;
