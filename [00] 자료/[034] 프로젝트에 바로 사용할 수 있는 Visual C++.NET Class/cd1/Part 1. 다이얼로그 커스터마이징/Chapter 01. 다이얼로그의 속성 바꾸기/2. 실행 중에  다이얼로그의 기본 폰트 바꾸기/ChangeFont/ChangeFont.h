// ChangeFont.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CChangeFontApp:
// �� Ŭ������ ������ ���ؼ��� ChangeFont.cpp�� �����Ͻʽÿ�.
//

class CChangeFontApp : public CWinApp
{
public:
	CChangeFontApp();

// ������
	//{{AFX_VIRTUAL(CChangeFontApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CChangeFontApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CChangeFontApp theApp;
