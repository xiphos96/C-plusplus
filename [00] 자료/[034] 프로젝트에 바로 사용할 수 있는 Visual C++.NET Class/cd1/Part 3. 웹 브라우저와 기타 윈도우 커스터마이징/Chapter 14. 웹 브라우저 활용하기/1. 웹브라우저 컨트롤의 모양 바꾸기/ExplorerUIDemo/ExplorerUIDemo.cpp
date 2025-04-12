// ExplorerUIDemo.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "ExplorerUIDemo.h"
#include "ExplorerUIDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����� ���� ��Ʈ�� ����Ʈ ������ ���� ��� ����
#include "CustomControlSite.h"

// CExplorerUIDemoApp

BEGIN_MESSAGE_MAP(CExplorerUIDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CExplorerUIDemoApp)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CExplorerUIDemoApp ����

CExplorerUIDemoApp::CExplorerUIDemoApp()
{
	//{{AFX_DATA_INIT(CExplorerUIDemoApp)
	//}}AFX_DATA_INIT
}

CExplorerUIDemoApp::~CExplorerUIDemoApp()
{
}

// ������ CExplorerUIDemoApp ��ü�Դϴ�.

CExplorerUIDemoApp theApp;


// CExplorerUIDemoApp �ʱ�ȭ

BOOL CExplorerUIDemoApp::InitInstance()
{
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControls()�� �ʿ��մϴ�. 
	// InitCommonControls()�� ������� ������ â�� ���� �� �����ϴ�.
	InitCommonControls();

	CWinApp::InitInstance();

	// ����� ���� ActiveX ��Ʈ�� �����̳� �޴����� �����Ѵ�
	CCustomOccManager *pManager = new CCustomOccManager;
	// �� ���α׷��� ActiveX ��Ʈ�� �����̳� �޴�����
	// ������ ������ ����� ���� ActiveX ��Ʈ�� �����̳� �޴����� �����Ѵ�
	AfxEnableControlContainer(pManager);

	CExplorerUIDemoDlg dlg;
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
