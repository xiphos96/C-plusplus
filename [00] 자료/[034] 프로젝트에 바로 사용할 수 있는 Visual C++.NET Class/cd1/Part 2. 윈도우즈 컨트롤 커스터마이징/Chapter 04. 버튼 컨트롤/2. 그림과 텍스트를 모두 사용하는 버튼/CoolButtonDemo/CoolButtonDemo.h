// CoolButtonDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CCoolButtonDemoApp:
// �� Ŭ������ ������ ���ؼ��� CoolButtonDemo.cpp�� �����Ͻʽÿ�.
//

class CCoolButtonDemoApp : public CWinApp
{
public:
	CCoolButtonDemoApp();

// ������
	//{{AFX_VIRTUAL(CCoolButtonDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CCoolButtonDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CCoolButtonDemoApp theApp;
