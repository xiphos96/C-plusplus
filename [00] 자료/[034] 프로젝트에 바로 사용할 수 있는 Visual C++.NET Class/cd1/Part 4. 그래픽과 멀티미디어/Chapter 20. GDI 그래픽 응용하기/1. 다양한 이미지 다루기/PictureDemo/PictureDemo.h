// PictureDemo.h : PictureDemo ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // �� ��ȣ


// CPictureDemoApp:
// �� Ŭ������ ������ ���ؼ��� PictureDemo.cpp�� �����Ͻʽÿ�.
//

class CPictureDemoApp : public CWinApp
{
public:
	CPictureDemoApp();


// ������
	//{{AFX_VIRTUAL(CPictureDemoApp)
public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����
	//{{AFX_MSG(CPictureDemoApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CPictureDemoApp theApp;
