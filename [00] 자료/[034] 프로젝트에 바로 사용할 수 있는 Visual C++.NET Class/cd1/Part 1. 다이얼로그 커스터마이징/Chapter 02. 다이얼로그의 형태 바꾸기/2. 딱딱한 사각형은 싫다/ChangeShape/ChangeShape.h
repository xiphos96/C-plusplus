// ChangeShape.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// �� ��ȣ


// CChangeShapeApp:
// �� Ŭ������ ������ ���ؼ��� ChangeShape.cpp�� �����Ͻʽÿ�.
//

class CChangeShapeApp : public CWinApp
{
public:
	CChangeShapeApp();

// ������
	//{{AFX_VIRTUAL(CChangeShapeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// ����

	//{{AFX_MSG(CChangeShapeApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CChangeShapeApp theApp;
