// SlideEditDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CSlideEditDemoApp:
// �� Ŭ������ ������ ���ؼ��� SlideEditDemo.cpp�� �����Ͻʽÿ�.
//

class CSlideEditDemoApp : public CWinApp
{
public:
	CSlideEditDemoApp();

// ������
	//{{AFX_VIRTUAL(CSlideEditDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CSlideEditDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CSlideEditDemoApp theApp;
