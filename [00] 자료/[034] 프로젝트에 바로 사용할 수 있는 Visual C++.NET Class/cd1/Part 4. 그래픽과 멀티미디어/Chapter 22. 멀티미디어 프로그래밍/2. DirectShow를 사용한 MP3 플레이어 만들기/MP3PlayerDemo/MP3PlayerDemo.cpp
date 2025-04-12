// MP3PlayerDemo.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "MP3PlayerDemo.h"
#include "MP3PlayerDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMP3PlayerDemoApp

BEGIN_MESSAGE_MAP(CMP3PlayerDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CMP3PlayerDemoApp)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMP3PlayerDemoApp ����

CMP3PlayerDemoApp::CMP3PlayerDemoApp()
{
	//{{AFX_DATA_INIT(CMP3PlayerDemoApp)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CMP3PlayerDemoApp ��ü�Դϴ�.

CMP3PlayerDemoApp theApp;


// CMP3PlayerDemoApp �ʱ�ȭ

BOOL CMP3PlayerDemoApp::InitInstance()
{
	// COM ���̺귯���� �ʱ�ȭ�Ѵ�
	CoInitialize(NULL);

	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControls()�� �ʿ��մϴ�. 
	// InitCommonControls()�� ������� ������ â�� ���� �� �����ϴ�.
	InitCommonControls();

	CWinApp::InitInstance();

	AfxEnableControlContainer();


	CMP3PlayerDemoDlg dlg;
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

int CMP3PlayerDemoApp::ExitInstance() 
{
	// COM ���̺귯���� �ݴ´�
	CoUninitialize();	
	
	return CWinApp::ExitInstance();
}
