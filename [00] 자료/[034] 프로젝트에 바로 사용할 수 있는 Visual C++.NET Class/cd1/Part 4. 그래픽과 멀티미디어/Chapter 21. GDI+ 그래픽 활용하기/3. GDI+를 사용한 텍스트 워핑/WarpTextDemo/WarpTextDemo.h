// WarpTextDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CWarpTextDemoApp:
// �� Ŭ������ ������ ���ؼ��� WarpTextDemo.cpp�� �����Ͻʽÿ�.
//

class CWarpTextDemoApp : public CWinApp
{
public:
	CWarpTextDemoApp();

	GdiplusStartupInput		m_GDIPlusStartupInput;		// GDI+ �ʱ�ȭ ���� ����ü
	ULONG_PTR				m_GDIPlusToken;				// GDI+ ��ū

// ������
	//{{AFX_VIRTUAL(CWarpTextDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CWarpTextDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CWarpTextDemoApp theApp;
