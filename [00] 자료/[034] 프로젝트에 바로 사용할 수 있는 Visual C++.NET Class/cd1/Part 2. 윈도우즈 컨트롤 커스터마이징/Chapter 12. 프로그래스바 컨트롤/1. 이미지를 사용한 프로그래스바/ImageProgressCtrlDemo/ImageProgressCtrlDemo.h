// ImageProgressCtrlDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CImageProgressCtrlDemoApp:
// �� Ŭ������ ������ ���ؼ��� ImageProgressCtrlDemo.cpp�� �����Ͻʽÿ�.
//

class CImageProgressCtrlDemoApp : public CWinApp
{
public:
	CImageProgressCtrlDemoApp();

// ������
	//{{AFX_VIRTUAL(CImageProgressCtrlDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CImageProgressCtrlDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CImageProgressCtrlDemoApp theApp;
