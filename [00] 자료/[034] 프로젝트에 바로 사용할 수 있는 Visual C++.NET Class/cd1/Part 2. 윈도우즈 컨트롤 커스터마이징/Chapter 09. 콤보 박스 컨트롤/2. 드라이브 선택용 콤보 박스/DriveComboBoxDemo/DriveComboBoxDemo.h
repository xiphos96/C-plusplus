// DriveComboBoxDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CDriveComboBoxDemoApp:
// �� Ŭ������ ������ ���ؼ��� DriveComboBoxDemo.cpp�� �����Ͻʽÿ�.
//

class CDriveComboBoxDemoApp : public CWinApp
{
public:
	CDriveComboBoxDemoApp();

// ������
	//{{AFX_VIRTUAL(CDriveComboBoxDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CDriveComboBoxDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CDriveComboBoxDemoApp theApp;
