// MSNNotifyDialog.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CMSNNotifyDialogApp:
// �� Ŭ������ ������ ���ؼ��� MSNNotifyDialog.cpp�� �����Ͻʽÿ�.
//

class CMSNNotifyDialogApp : public CWinApp
{
public:
	CMSNNotifyDialogApp();

// ������
	//{{AFX_VIRTUAL(CMSNNotifyDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CMSNNotifyDialogApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CMSNNotifyDialogApp theApp;
