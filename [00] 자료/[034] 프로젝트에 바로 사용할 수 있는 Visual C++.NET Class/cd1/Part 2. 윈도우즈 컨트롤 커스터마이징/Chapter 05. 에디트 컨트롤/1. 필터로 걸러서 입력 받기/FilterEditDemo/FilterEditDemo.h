// FilterEditDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"		// �� ��ȣ


// CFilterEditDemoApp:
// �� Ŭ������ ������ ���ؼ��� FilterEditDemo.cpp�� �����Ͻʽÿ�.
//

class CFilterEditDemoApp : public CWinApp
{
public:
	CFilterEditDemoApp();

// ������
	public:
	virtual BOOL InitInstance();

// ����

	DECLARE_MESSAGE_MAP()
};

extern CFilterEditDemoApp theApp;
