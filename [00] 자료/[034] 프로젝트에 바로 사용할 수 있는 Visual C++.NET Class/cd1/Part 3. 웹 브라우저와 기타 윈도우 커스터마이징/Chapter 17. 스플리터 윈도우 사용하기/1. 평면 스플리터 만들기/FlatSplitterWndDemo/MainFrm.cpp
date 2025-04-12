// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "FlatSplitterWndDemo.h"

#include "MainFrm.h"
// ���ø����� ���ο� ������ �� Ŭ���� ��� ���ϵ�
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
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	//{{AFX_DATA_INIT(CMainFrame)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
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
		TRACE0("���� ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("���� ǥ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}
	// TODO: ���� ������ ��ŷ�� �� ���� �Ϸ��� �� �� ���� �����Ͻʽÿ�.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	// Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return TRUE;
}


// CMainFrame ����

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


// CMainFrame �޽��� ó����


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// ������������ �� ���� �����Ѵ�
	if(!m_wndSplitter.CreateStatic(this, 1, 2))
	{
		TRACE0("Failed to CreateStatic Splitter\n");
		return FALSE;
	}

	// ���� ���ο� CLeftView �並 �����Ѵ�
	if(!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CLeftView), CSize(230, 0), pContext))
	{
		TRACE0("Failed to create left pane\n");
		return FALSE;
	}

	// ���� ������ �� ������ �����Ѵ�
	if (!m_wndSplitterVert.CreateStatic(&m_wndSplitter, 2, 1, WS_CHILD | WS_VISIBLE, m_wndSplitter.IdFromRowCol(0, 1)))
	{
		TRACE0("Failed to vertical CreateStatic Splitter\n");
		return FALSE;
	}
	// ��� ���ο� CFlatSplitterWndDemoView �並 �����Ѵ�
	if (!m_wndSplitterVert.CreateView(0, 0, RUNTIME_CLASS(CFlatSplitterWndDemoView), CSize(0, 200), pContext))
	{
		TRACE0("Failed to create top pane\n");
		return FALSE;
	}
	// �ϴ� ���ο� CBottomView �並 �����Ѵ�
	if (!m_wndSplitterVert.CreateView(1, 0, RUNTIME_CLASS(CBottomView), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create bottom pane\n");
		return FALSE;
	}

	return TRUE;
}
