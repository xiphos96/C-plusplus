// ListSortDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CListSortDemoApp:
// �� Ŭ������ ������ ���ؼ��� ListSortDemo.cpp�� �����Ͻʽÿ�.
//

class CListSortDemoApp : public CWinApp
{
public:
	CListSortDemoApp();

// ������
	//{{AFX_VIRTUAL(CListSortDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CListSortDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CListSortDemoApp theApp;
