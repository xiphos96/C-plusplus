// MoviePlayerDemo.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "MoviePlayerDemo.h"
#include "MoviePlayerDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMoviePlayerDemoApp

BEGIN_MESSAGE_MAP(CMoviePlayerDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CMoviePlayerDemoApp)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMoviePlayerDemoApp ����

CMoviePlayerDemoApp::CMoviePlayerDemoApp()
{
	//{{AFX_DATA_INIT(CMoviePlayerDemoApp)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CMoviePlayerDemoApp ��ü�Դϴ�.

CMoviePlayerDemoApp theApp;


// CMoviePlayerDemoApp �ʱ�ȭ

BOOL CMoviePlayerDemoApp::InitInstance()
{
	// COM ���̺귯���� �ʱ�ȭ�Ѵ�
	CoInitialize(NULL);

	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControls()�� �ʿ��մϴ�. 
	// InitCommonControls()�� ������� ������ â�� ���� �� �����ϴ�.
	InitCommonControls();

	CWinApp::InitInstance();

	AfxEnableControlContainer();


	CMoviePlayerDemoDlg dlg;
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

int CMoviePlayerDemoApp::ExitInstance() 
{
	// COM ���̺귯���� �ݴ´�
	CoUninitialize();	
	
	return CWinApp::ExitInstance();
}
