// ExplorerListCtrlDemo.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "ExplorerListCtrlDemo.h"
#include "ExplorerListCtrlDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExplorerListCtrlDemoApp

BEGIN_MESSAGE_MAP(CExplorerListCtrlDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CExplorerListCtrlDemoApp)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CExplorerListCtrlDemoApp ����

CExplorerListCtrlDemoApp::CExplorerListCtrlDemoApp()
{
	//{{AFX_DATA_INIT(CExplorerListCtrlDemoApp)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CExplorerListCtrlDemoApp ��ü�Դϴ�.

CExplorerListCtrlDemoApp theApp;


// CExplorerListCtrlDemoApp �ʱ�ȭ

BOOL CExplorerListCtrlDemoApp::InitInstance()
{
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControls()�� �ʿ��մϴ�. 
	// InitCommonControls()�� ������� ������ â�� ���� �� �����ϴ�.
	InitCommonControls();

	CWinApp::InitInstance();

	AfxEnableControlContainer();


	CExplorerListCtrlDemoDlg dlg;
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
