// FontEffectDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CFontEffectDemoApp:
// �� Ŭ������ ������ ���ؼ��� FontEffectDemo.cpp�� �����Ͻʽÿ�.
//

class CFontEffectDemoApp : public CWinApp
{
public:
	CFontEffectDemoApp();

// ������
	//{{AFX_VIRTUAL(CFontEffectDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CFontEffectDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CFontEffectDemoApp theApp;
