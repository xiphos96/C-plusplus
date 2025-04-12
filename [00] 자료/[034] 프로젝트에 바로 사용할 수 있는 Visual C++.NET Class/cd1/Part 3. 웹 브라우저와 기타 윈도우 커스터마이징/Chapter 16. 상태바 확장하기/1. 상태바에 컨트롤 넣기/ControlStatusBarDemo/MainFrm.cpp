// MainFrm.cpp : CMainFrame Ŭ������ ����
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

	// ���¹ٸ� �����Ѵ�
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

	// ���¹��� 3�� ��ġ�� ����ƽ�� �߰��Ѵ�
	m_wndStatusBar.InsertControlPane("Static", CONTROL_STATIC, ID_STATUS_STATIC, 4, 200);
	// ���¹��� 4�� ��ġ�� ����Ʈ �ڽ��� �߰��Ѵ�
	m_wndStatusBar.InsertControlPane("Edit", CONTROL_EDIT, ID_STATUS_EDIT, 5, 60);
	// ���¹��� 5�� ��ġ�� ��ư�� �߰��Ѵ�
	m_wndStatusBar.InsertControlPane("Ÿ��Ʋ �ٲٱ�", CONTROL_BUTTON, ID_STATUS_BUTTON, 6, 150);
	// ���¹��� 6�� ��ġ�� üũ�ڽ��� �߰��Ѵ�
	m_wndStatusBar.InsertControlPane("Check", CONTROL_CHECK, ID_STATUS_CHECK, 7, 60);
	// ���¹��� 7�� ��ġ�� ���α׷����ٸ� �߰��Ѵ�
	m_wndStatusBar.InsertControlPane("Progress", CONTROL_PROGRESS, ID_STATUS_PROGRESS, 8, 100);

	// ���¹��� ���̸� �����Ѵ�
	m_wndStatusBar.GetStatusBarCtrl().SetMinHeight(25);

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

