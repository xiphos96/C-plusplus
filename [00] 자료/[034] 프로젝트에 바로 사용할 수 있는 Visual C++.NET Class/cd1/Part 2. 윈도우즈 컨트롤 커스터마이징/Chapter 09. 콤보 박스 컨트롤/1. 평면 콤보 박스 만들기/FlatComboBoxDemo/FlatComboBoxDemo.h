// FlatComboBoxDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CFlatComboBoxDemoApp:
// �� Ŭ������ ������ ���ؼ��� FlatComboBoxDemo.cpp�� �����Ͻʽÿ�.
//

class CFlatComboBoxDemoApp : public CWinApp
{
public:
	CFlatComboBoxDemoApp();

// ������
	//{{AFX_VIRTUAL(CFlatComboBoxDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CFlatComboBoxDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CFlatComboBoxDemoApp theApp;
