// CustomPropertySheetDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CCustomPropertySheetDemoApp:
// �� Ŭ������ ������ ���ؼ��� CustomPropertySheetDemo.cpp�� �����Ͻʽÿ�.
//

class CCustomPropertySheetDemoApp : public CWinApp
{
public:
	CCustomPropertySheetDemoApp();

// ������
	//{{AFX_VIRTUAL(CCustomPropertySheetDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CCustomPropertySheetDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CCustomPropertySheetDemoApp theApp;
