// EditableListBoxDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CEditableListBoxDemoApp:
// �� Ŭ������ ������ ���ؼ��� EditableListBoxDemo.cpp�� �����Ͻʽÿ�.
//

class CEditableListBoxDemoApp : public CWinApp
{
public:
	CEditableListBoxDemoApp();

// ������
	//{{AFX_VIRTUAL(CEditableListBoxDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CEditableListBoxDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CEditableListBoxDemoApp theApp;
