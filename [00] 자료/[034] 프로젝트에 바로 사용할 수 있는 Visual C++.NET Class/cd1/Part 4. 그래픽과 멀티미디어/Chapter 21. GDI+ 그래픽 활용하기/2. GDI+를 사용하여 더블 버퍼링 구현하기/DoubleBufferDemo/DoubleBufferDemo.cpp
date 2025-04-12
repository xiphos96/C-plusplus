// DoubleBufferDemo.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "DoubleBufferDemo.h"
#include "DoubleBufferDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDoubleBufferDemoApp

BEGIN_MESSAGE_MAP(CDoubleBufferDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CDoubleBufferDemoApp)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CDoubleBufferDemoApp ����

CDoubleBufferDemoApp::CDoubleBufferDemoApp()
{
	//{{AFX_DATA_INIT(CDoubleBufferDemoApp)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CDoubleBufferDemoApp ��ü�Դϴ�.

CDoubleBufferDemoApp theApp;


// CDoubleBufferDemoApp �ʱ�ȭ

BOOL CDoubleBufferDemoApp::InitInstance()
{
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControls()�� �ʿ��մϴ�. 
	// InitCommonControls()�� ������� ������ â�� ���� �� �����ϴ�.
	InitCommonControls();

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// GDI+ ���̺귯�� �ʱ�ȭ
	GdiplusStartup(&m_GDIPlusToken, &m_GDIPlusStartupInput, NULL);

	CDoubleBufferDemoDlg dlg;
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

int CDoubleBufferDemoApp::ExitInstance() 
{
	// GDI+ ���̺귯�� ����
	GdiplusShutdown(m_GDIPlusToken);
	
	return CWinApp::ExitInstance();
}
