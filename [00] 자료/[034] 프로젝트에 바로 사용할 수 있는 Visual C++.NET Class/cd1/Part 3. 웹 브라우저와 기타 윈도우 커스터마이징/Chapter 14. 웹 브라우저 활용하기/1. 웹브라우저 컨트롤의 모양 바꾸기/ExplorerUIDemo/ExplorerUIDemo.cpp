// ExplorerUIDemo.cpp : 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "ExplorerUIDemo.h"
#include "ExplorerUIDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 사용자 정의 컨트롤 사이트 설정을 위한 헤더 파일
#include "CustomControlSite.h"

// CExplorerUIDemoApp

BEGIN_MESSAGE_MAP(CExplorerUIDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CExplorerUIDemoApp)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CExplorerUIDemoApp 생성

CExplorerUIDemoApp::CExplorerUIDemoApp()
{
	//{{AFX_DATA_INIT(CExplorerUIDemoApp)
	//}}AFX_DATA_INIT
}

CExplorerUIDemoApp::~CExplorerUIDemoApp()
{
}

// 유일한 CExplorerUIDemoApp 개체입니다.

CExplorerUIDemoApp theApp;


// CExplorerUIDemoApp 초기화

BOOL CExplorerUIDemoApp::InitInstance()
{
	// 응용 프로그램 매니페스트가 ComCtl32.dll 버전 6 이상을 사용하여 비주얼 스타일을
	// 사용하도록 지정하는 경우, Windows XP 상에서 반드시 InitCommonControls()가 필요합니다. 
	// InitCommonControls()를 사용하지 않으면 창을 만들 수 없습니다.
	InitCommonControls();

	CWinApp::InitInstance();

	// 사용자 정의 ActiveX 컨트롤 컨테이너 메니저를 생성한다
	CCustomOccManager *pManager = new CCustomOccManager;
	// 본 프로그램의 ActiveX 컨트롤 컨테이너 메니저로
	// 위에서 생성한 사용자 정의 ActiveX 컨트롤 컨테이너 메니저를 설정한다
	AfxEnableControlContainer(pManager);

	CExplorerUIDemoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 여기에 대화 상자가 확인을 눌러 없어지는 경우 처리할
		// 코드를 배치합니다.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 여기에 대화 상자가 취소를 눌러 없어지는 경우 처리할
		// 코드를 배치합니다.
	}

	// 대화 상자가 닫혔으므로 응용 프로그램의 메시지 펌프를 시작하지 않고
	// 응용 프로그램을 끝낼 수 있도록 FALSE를 반환합니다.
	return FALSE;
}
