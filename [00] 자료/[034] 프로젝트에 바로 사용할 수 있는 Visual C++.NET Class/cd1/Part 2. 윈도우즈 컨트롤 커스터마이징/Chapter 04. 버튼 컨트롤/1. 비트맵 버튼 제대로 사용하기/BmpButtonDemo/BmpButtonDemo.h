// BmpButtonDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CBmpButtonDemoApp:
// �� Ŭ������ ������ ���ؼ��� BmpButtonDemo.cpp�� �����Ͻʽÿ�.
//

class CBmpButtonDemoApp : public CWinApp
{
public:
	CBmpButtonDemoApp();

// ������
	//{{AFX_VIRTUAL(CBmpButtonDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CBmpButtonDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CBmpButtonDemoApp theApp;
