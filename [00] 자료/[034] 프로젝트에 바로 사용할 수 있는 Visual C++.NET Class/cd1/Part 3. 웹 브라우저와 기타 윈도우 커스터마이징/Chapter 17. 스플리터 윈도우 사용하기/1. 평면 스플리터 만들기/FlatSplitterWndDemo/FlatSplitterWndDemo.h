// FlatSplitterWndDemo.h : FlatSplitterWndDemo ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // �� ��ȣ


// CFlatSplitterWndDemoApp:
// �� Ŭ������ ������ ���ؼ��� FlatSplitterWndDemo.cpp�� �����Ͻʽÿ�.
//

class CFlatSplitterWndDemoApp : public CWinApp
{
public:
	CFlatSplitterWndDemoApp();


// ������
	//{{AFX_VIRTUAL(CFlatSplitterWndDemoApp)
public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����
	//{{AFX_MSG(CFlatSplitterWndDemoApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CFlatSplitterWndDemoApp theApp;
