// ColorPickButtonDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CColorPickButtonDemoApp:
// �� Ŭ������ ������ ���ؼ��� ColorPickButtonDemo.cpp�� �����Ͻʽÿ�.
//

class CColorPickButtonDemoApp : public CWinApp
{
public:
	CColorPickButtonDemoApp();

// ������
	//{{AFX_VIRTUAL(CColorPickButtonDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CColorPickButtonDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CColorPickButtonDemoApp theApp;
