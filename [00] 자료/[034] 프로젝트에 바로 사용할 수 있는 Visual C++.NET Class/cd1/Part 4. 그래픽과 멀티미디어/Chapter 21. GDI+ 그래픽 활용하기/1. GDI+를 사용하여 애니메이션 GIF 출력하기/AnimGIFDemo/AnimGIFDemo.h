// AnimGIFDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CAnimGIFDemoApp:
// �� Ŭ������ ������ ���ؼ��� AnimGIFDemo.cpp�� �����Ͻʽÿ�.
//

class CAnimGIFDemoApp : public CWinApp
{
public:
	CAnimGIFDemoApp();

	GdiplusStartupInput		m_GDIPlusStartupInput;		// GDI+ �ʱ�ȭ ���� ����ü
	ULONG_PTR				m_GDIPlusToken;				// GDI+ ��ū

// ������
	//{{AFX_VIRTUAL(CAnimGIFDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CAnimGIFDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CAnimGIFDemoApp theApp;
