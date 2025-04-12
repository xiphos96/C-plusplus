// FadeInSplashWndDemo.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "FadeInSplashWndDemo.h"
#include "FadeInSplashWndDemoDlg.h"

// ������ ���÷��� ������ Ŭ���� ���
#include "FadeInSplashWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFadeInSplashWndDemoApp

BEGIN_MESSAGE_MAP(CFadeInSplashWndDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CFadeInSplashWndDemoApp)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CFadeInSplashWndDemoApp ����

CFadeInSplashWndDemoApp::CFadeInSplashWndDemoApp()
{
	//{{AFX_DATA_INIT(CFadeInSplashWndDemoApp)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CFadeInSplashWndDemoApp ��ü�Դϴ�.

CFadeInSplashWndDemoApp theApp;


// CFadeInSplashWndDemoApp �ʱ�ȭ

BOOL CFadeInSplashWndDemoApp::InitInstance()
{
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControls()�� �ʿ��մϴ�. 
	// InitCommonControls()�� ������� ������ â�� ���� �� �����ϴ�.
	InitCommonControls();

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ���� ���ڸ� ���´�
	CCommandLineInfo CmdInfo;
	ParseCommandLine(CmdInfo);

	// ���÷��ð� ��� �����ϵ��� �����Ѵ�
	CFadeInSplashWnd::EnableSplashScreen(CmdInfo.m_bShowSplash);

	CFadeInSplashWndDemoDlg dlg;
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

BOOL CFadeInSplashWndDemoApp::PreTranslateMessage(MSG* pMsg) 
{
	// ���ø����̼��� �޽����� ���÷��� �����쿡�� �����Ѵ�
	if(CFadeInSplashWnd::PreTranslateAppMessage(pMsg))
		return TRUE;
	
	return CWinApp::PreTranslateMessage(pMsg);
}
