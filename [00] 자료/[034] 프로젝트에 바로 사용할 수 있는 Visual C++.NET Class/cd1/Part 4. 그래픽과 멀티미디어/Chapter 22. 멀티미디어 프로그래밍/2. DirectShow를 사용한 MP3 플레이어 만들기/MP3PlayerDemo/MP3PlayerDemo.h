// MP3PlayerDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CMP3PlayerDemoApp:
// �� Ŭ������ ������ ���ؼ��� MP3PlayerDemo.cpp�� �����Ͻʽÿ�.
//

class CMP3PlayerDemoApp : public CWinApp
{
public:
	CMP3PlayerDemoApp();

// ������
	//{{AFX_VIRTUAL(CMP3PlayerDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CMP3PlayerDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CMP3PlayerDemoApp theApp;
