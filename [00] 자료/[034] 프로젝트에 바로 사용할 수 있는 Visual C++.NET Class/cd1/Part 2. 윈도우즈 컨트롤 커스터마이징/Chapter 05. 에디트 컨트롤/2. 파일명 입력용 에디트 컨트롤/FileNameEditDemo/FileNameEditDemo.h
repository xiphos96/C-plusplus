// FileNameEditDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CFileNameEditDemoApp:
// �� Ŭ������ ������ ���ؼ��� FileNameEditDemo.cpp�� �����Ͻʽÿ�.
//

class CFileNameEditDemoApp : public CWinApp
{
public:
	CFileNameEditDemoApp();

// ������
	//{{AFX_VIRTUAL(CFileNameEditDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CFileNameEditDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CFileNameEditDemoApp theApp;
