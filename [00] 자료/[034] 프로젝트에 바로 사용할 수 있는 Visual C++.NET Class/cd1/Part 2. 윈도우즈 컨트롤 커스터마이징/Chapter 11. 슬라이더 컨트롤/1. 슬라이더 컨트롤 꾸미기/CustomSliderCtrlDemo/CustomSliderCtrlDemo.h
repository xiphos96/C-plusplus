// CustomSliderCtrlDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CCustomSliderCtrlDemoApp:
// �� Ŭ������ ������ ���ؼ��� CustomSliderCtrlDemo.cpp�� �����Ͻʽÿ�.
//

class CCustomSliderCtrlDemoApp : public CWinApp
{
public:
	CCustomSliderCtrlDemoApp();

// ������
	//{{AFX_VIRTUAL(CCustomSliderCtrlDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CCustomSliderCtrlDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CCustomSliderCtrlDemoApp theApp;
