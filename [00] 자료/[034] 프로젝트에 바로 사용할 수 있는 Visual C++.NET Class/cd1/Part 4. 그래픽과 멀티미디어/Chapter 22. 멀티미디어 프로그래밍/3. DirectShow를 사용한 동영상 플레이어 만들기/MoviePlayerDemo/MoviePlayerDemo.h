// MoviePlayerDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CMoviePlayerDemoApp:
// �� Ŭ������ ������ ���ؼ��� MoviePlayerDemo.cpp�� �����Ͻʽÿ�.
//

class CMoviePlayerDemoApp : public CWinApp
{
public:
	CMoviePlayerDemoApp();

// ������
	//{{AFX_VIRTUAL(CMoviePlayerDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CMoviePlayerDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CMoviePlayerDemoApp theApp;
