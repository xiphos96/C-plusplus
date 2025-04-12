// MainFrm.cpp : CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "ControlStatusBarDemo.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	//{{AFX_DATA_INIT(CMainFrame)
	//}}AFX_DATA_INIT
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	// 상태바를 생성한다
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	// TODO: 도구 모음을 도킹할 수 없게 하려면 이 세 줄을 삭제하십시오.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	// 상태바의 3번 위치에 스태틱을 추가한다
	m_wndStatusBar.InsertControlPane("Static", CONTROL_STATIC, ID_STATUS_STATIC, 4, 200);
	// 상태바의 4번 위치에 에디트 박스를 추가한다
	m_wndStatusBar.InsertControlPane("Edit", CONTROL_EDIT, ID_STATUS_EDIT, 5, 60);
	// 상태바의 5번 위치에 버튼을 추가한다
	m_wndStatusBar.InsertControlPane("타이틀 바꾸기", CONTROL_BUTTON, ID_STATUS_BUTTON, 6, 150);
	// 상태바의 6번 위치에 체크박스를 추가한다
	m_wndStatusBar.InsertControlPane("Check", CONTROL_CHECK, ID_STATUS_CHECK, 7, 60);
	// 상태바의 7번 위치에 프로그래스바를 추가한다
	m_wndStatusBar.InsertControlPane("Progress", CONTROL_PROGRESS, ID_STATUS_PROGRESS, 8, 100);

	// 상태바의 높이를 조정한다
	m_wndStatusBar.GetStatusBarCtrl().SetMinHeight(25);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	// Window 클래스 또는 스타일을 수정합니다.

	return TRUE;
}


// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame 메시지 처리기

