// BitmapDialog.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CBitmapDialogApp:
// �� Ŭ������ ������ ���ؼ��� BitmapDialog.cpp�� �����Ͻʽÿ�.
//

class CBitmapDialogApp : public CWinApp
{
public:
	CBitmapDialogApp();

// ������
	//{{AFX_VIRTUAL(CBitmapDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CBitmapDialogApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CBitmapDialogApp theApp;
