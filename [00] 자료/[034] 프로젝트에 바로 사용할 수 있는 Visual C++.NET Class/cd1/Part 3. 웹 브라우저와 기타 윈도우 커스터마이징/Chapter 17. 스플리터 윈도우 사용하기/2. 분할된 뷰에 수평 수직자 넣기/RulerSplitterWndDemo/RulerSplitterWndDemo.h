// RulerSplitterWndDemo.h : RulerSplitterWndDemo ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // �� ��ȣ


// CRulerSplitterWndDemoApp:
// �� Ŭ������ ������ ���ؼ��� RulerSplitterWndDemo.cpp�� �����Ͻʽÿ�.
//

class CRulerSplitterWndDemoApp : public CWinApp
{
public:
	CRulerSplitterWndDemoApp();


// ������
	//{{AFX_VIRTUAL(CRulerSplitterWndDemoApp)
public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����
	//{{AFX_MSG(CRulerSplitterWndDemoApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CRulerSplitterWndDemoApp theApp;
