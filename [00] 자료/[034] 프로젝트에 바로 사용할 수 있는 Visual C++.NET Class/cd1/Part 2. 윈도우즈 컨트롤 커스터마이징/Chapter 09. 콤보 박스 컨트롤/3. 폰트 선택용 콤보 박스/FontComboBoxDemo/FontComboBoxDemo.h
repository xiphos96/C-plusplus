// FontComboBoxDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CFontComboBoxDemoApp:
// �� Ŭ������ ������ ���ؼ��� FontComboBoxDemo.cpp�� �����Ͻʽÿ�.
//

class CFontComboBoxDemoApp : public CWinApp
{
public:
	CFontComboBoxDemoApp();

// ������
	//{{AFX_VIRTUAL(CFontComboBoxDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CFontComboBoxDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CFontComboBoxDemoApp theApp;
