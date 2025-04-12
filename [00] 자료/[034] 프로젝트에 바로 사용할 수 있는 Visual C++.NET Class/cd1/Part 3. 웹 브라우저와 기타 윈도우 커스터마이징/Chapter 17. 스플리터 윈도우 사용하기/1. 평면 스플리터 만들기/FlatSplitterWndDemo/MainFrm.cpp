// MainFrm.cpp : CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "FlatSplitterWndDemo.h"

#include "MainFrm.h"
// 스플리터의 페인에 설정할 뷰 클래스 헤더 파일들
#include "FlatSplitterWndDemoDoc.h"
#include "FlatSplitterWndDemoView.h"
#include "LeftView.h"
#include "BottomView.h"

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


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// 메인프레임을 두 열로 분할한다
	if(!m_wndSplitter.CreateStatic(this, 1, 2))
	{
		TRACE0("Failed to CreateStatic Splitter\n");
		return FALSE;
	}

	// 좌측 페인에 CLeftView 뷰를 생성한다
	if(!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CLeftView), CSize(230, 0), pContext))
	{
		TRACE0("Failed to create left pane\n");
		return FALSE;
	}

	// 우측 페인을 두 행으로 분할한다
	if (!m_wndSplitterVert.CreateStatic(&m_wndSplitter, 2, 1, WS_CHILD | WS_VISIBLE, m_wndSplitter.IdFromRowCol(0, 1)))
	{
		TRACE0("Failed to vertical CreateStatic Splitter\n");
		return FALSE;
	}
	// 상단 페인에 CFlatSplitterWndDemoView 뷰를 생성한다
	if (!m_wndSplitterVert.CreateView(0, 0, RUNTIME_CLASS(CFlatSplitterWndDemoView), CSize(0, 200), pContext))
	{
		TRACE0("Failed to create top pane\n");
		return FALSE;
	}
	// 하단 페인에 CBottomView 뷰를 생성한다
	if (!m_wndSplitterVert.CreateView(1, 0, RUNTIME_CLASS(CBottomView), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create bottom pane\n");
		return FALSE;
	}

	return TRUE;
}
