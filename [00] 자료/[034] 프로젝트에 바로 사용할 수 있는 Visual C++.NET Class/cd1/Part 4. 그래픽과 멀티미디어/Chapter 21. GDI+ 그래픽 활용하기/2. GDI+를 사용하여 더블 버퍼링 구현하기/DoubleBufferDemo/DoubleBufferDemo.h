// DoubleBufferDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CDoubleBufferDemoApp:
// �� Ŭ������ ������ ���ؼ��� DoubleBufferDemo.cpp�� �����Ͻʽÿ�.
//

class CDoubleBufferDemoApp : public CWinApp
{
public:
	CDoubleBufferDemoApp();

	GdiplusStartupInput		m_GDIPlusStartupInput;		// GDI+ �ʱ�ȭ ���� ����ü
	ULONG_PTR				m_GDIPlusToken;				// GDI+ ��ū

// ������
	//{{AFX_VIRTUAL(CDoubleBufferDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CDoubleBufferDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CDoubleBufferDemoApp theApp;
