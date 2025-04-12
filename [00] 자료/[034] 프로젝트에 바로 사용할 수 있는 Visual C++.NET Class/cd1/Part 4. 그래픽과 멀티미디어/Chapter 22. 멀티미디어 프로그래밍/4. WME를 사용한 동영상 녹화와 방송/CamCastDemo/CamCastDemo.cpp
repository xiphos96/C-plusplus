// CamCastDemo.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "CamCastDemo.h"
#include "CamCastDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCamCastDemoApp

BEGIN_MESSAGE_MAP(CCamCastDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CCamCastDemoApp)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCamCastDemoApp ����

CCamCastDemoApp::CCamCastDemoApp()
{
	//{{AFX_DATA_INIT(CCamCastDemoApp)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CCamCastDemoApp ��ü�Դϴ�.

CCamCastDemoApp theApp;


// CCamCastDemoApp �ʱ�ȭ

BOOL CCamCastDemoApp::InitInstance()
{
	// COM ���̺귯���� �ʱ�ȭ�Ѵ�
	CoInitialize(NULL);

	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControls()�� �ʿ��մϴ�. 
	// InitCommonControls()�� ������� ������ â�� ���� �� �����ϴ�.
	InitCommonControls();

	CWinApp::InitInstance();

	AfxEnableControlContainer();


	CCamCastDemoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ���⿡ ��ȭ ���ڰ� Ȯ���� ���� �������� ��� ó����
		// �ڵ带 ��ġ�մϴ�.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ���⿡ ��ȭ ���ڰ� ��Ҹ� ���� �������� ��� ó����
		// �ڵ带 ��ġ�մϴ�.
	}

	// ��ȭ ���ڰ� �������Ƿ� ���� ���α׷��� �޽��� ������ �������� �ʰ�
	// ���� ���α׷��� ���� �� �ֵ��� FALSE�� ��ȯ�մϴ�.
	return FALSE;
}

int CCamCastDemoApp::ExitInstance() 
{
	// COM ���̺귯���� �ݴ´�
	CoUninitialize();	
	
	return CWinApp::ExitInstance();
}
