// CaptureWindowDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CCaptureWindowDemoApp:
// �� Ŭ������ ������ ���ؼ��� CaptureWindowDemo.cpp�� �����Ͻʽÿ�.
//

class CCaptureWindowDemoApp : public CWinApp
{
public:
	CCaptureWindowDemoApp();

// ������
	//{{AFX_VIRTUAL(CCaptureWindowDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CCaptureWindowDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CCaptureWindowDemoApp theApp;
