// LinkStaticDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CLinkStaticDemoApp:
// �� Ŭ������ ������ ���ؼ��� LinkStaticDemo.cpp�� �����Ͻʽÿ�.
//

class CLinkStaticDemoApp : public CWinApp
{
public:
	CLinkStaticDemoApp();

// ������
	//{{AFX_VIRTUAL(CLinkStaticDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CLinkStaticDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CLinkStaticDemoApp theApp;
