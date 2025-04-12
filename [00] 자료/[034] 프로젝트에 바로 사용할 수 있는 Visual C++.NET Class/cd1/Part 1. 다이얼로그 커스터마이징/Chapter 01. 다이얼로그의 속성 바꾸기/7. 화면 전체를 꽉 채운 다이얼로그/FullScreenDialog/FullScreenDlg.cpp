// FullScreenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "fullscreendialog.h"
#include "FullScreenDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFullScreenDlg dialog


CFullScreenDlg::CFullScreenDlg(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CFullScreenDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFullScreenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFullScreenDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFullScreenDlg, CDialog)
	//{{AFX_MSG_MAP(CFullScreenDlg)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFullScreenDlg message handlers

BOOL CFullScreenDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 전체 화면에 적합하도록 윈도우 스타일을 조절한다
	ModifyStyle(WS_THICKFRAME | WS_BORDER | WS_CAPTION, WS_SYSMENU);
	
	// 초기 다이얼로그 크기를 저장한다
	GetClientRect(&m_rcClient);

	// 초기 작업 영역 크기를 읽어 저장한다
	if(::SystemParametersInfo(SPI_GETWORKAREA, 0, &m_rcWorkArea, 0))
	{
		// 작업 영역 크기를 전체 영역으로 설정한다
		::SystemParametersInfo(SPI_SETWORKAREA, 0, NULL, 0);
	}

	// 작업 표시줄의 포인터를 획득한다
	CWnd* pTaskBar = CWnd::FindWindow("Shell_TrayWnd", "");
	if(pTaskBar)
	{
		// 현재 보이는 상태인지 저장한다
		m_bIsVisibleTaskBar = pTaskBar->IsWindowVisible();
		// 작업 표시줄을 감춘다
		pTaskBar->ShowWindow(SW_HIDE);
	}

	// 전체 화면 크기를 구한다
	int nScreenCX = ::GetSystemMetrics(SM_CXSCREEN);
	int nScreenCY = ::GetSystemMetrics(SM_CYSCREEN);

	// 다이얼로그 크기를 전체 화면 크기로 조정한다
	SetWindowPos(&wndTopMost, 0, 0, nScreenCX, nScreenCY, SWP_SHOWWINDOW);

	// 다이얼로그의 컨트롤들을 중앙으로 이동시킨다
	ScrollWindow((nScreenCX - m_rcClient.Width()) / 2, (nScreenCY - m_rcClient.Height()) / 2);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFullScreenDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// 원래 작업 영역 크기로 환원 시킨다
	::SystemParametersInfo(SPI_SETWORKAREA, 0, &m_rcWorkArea, 0);

	// 작업 표시줄의 포인터를 획득한다
	CWnd* pTaskBar = CWnd::FindWindow("Shell_TrayWnd", "");
	if(pTaskBar)
		// 작업 표시줄을 초기 상태로 되돌린다
		pTaskBar->ShowWindow(m_bIsVisibleTaskBar ? SW_SHOW : SW_HIDE);
}
