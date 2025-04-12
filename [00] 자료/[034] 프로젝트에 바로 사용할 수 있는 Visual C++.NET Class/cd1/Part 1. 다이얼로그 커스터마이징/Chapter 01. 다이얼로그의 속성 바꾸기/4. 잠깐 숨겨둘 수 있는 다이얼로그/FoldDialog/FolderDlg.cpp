// FolderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "folddialog.h"
#include "FolderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFolderDlg dialog


CFolderDlg::CFolderDlg(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CFolderDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	// 초기값을 설정한다
	m_hIcon = NULL;
	m_bIsFolded = FALSE;
}


void CFolderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFolderDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFolderDlg, CDialog)
	//{{AFX_MSG_MAP(CFolderDlg)
	ON_WM_PAINT()
	ON_WM_NCHITTEST()
	ON_WM_NCLBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFolderDlg message handlers

BOOL CFolderDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 초기에 아이콘이 설정되어 있지 않다면
	// 기본 프로그램 아이콘을 설정한다
	if(m_hIcon == NULL)
		SetFoldIcon(::LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME)));

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFolderDlg::OnPaint() 
{
	// 다이얼로그가 숨겨진 상태일 때, 아이콘이 설정된 상태일 때,
	// 아이콘을 출력한다
	if(m_bIsFolded && m_hIcon)
	{
		CPaintDC dc(this); // device context for painting

		dc.DrawIcon(0, 0, m_hIcon);
	}

	CDialog::OnPaint();
}

// 새로운 아이콘을 설정하는 함수
void CFolderDlg::SetFoldIcon(HICON hIcon)
{
	// 기존 아이콘이 존재한다면 제거한다
	if(m_hIcon)			::DestroyIcon(m_hIcon);

	// 새로운 아이콘을 설정한다
	m_hIcon = hIcon;

	if(m_hIcon == NULL)	return;

	int nIconCX = 0, nIconCY = 0;

	// 아이콘의 크기를 얻어온다
	ICONINFO IconInfo;

	if(::GetIconInfo(m_hIcon, &IconInfo))
	{
		BITMAP BmpInfo;

		if(::GetObject(IconInfo.hbmColor, sizeof(BITMAP), &BmpInfo))
		{
			nIconCX = BmpInfo.bmWidth;
			nIconCY = BmpInfo.bmHeight;
		}
	}

	// 아이콘의 크기를 얻을 수 없었다면 32*32 크기로 설정한다
	if(nIconCX == 0 || nIconCY == 0)
	{
		nIconCX = 32;
		nIconCY = 32;
	}

	// 기본 위치를 화면 우측/하단으로 설정한다.
	// 숨겨졌을 때 크기는, 아이콘의 크기에 테두리 두께를 두배 더한 크기이다
	CRect rcScreen;
	::SystemParametersInfo(SPI_GETWORKAREA, 0, &rcScreen, 0);

	m_rcLastFold.left	= rcScreen.right - nIconCX - ::GetSystemMetrics(SM_CXEDGE) * 2;
	m_rcLastFold.top	= rcScreen.bottom - nIconCY - ::GetSystemMetrics(SM_CYEDGE) * 2;
	m_rcLastFold.right	= rcScreen.right;
	m_rcLastFold.bottom = rcScreen.bottom;

}

// 다이얼로그의 모든 자식 윈도우들을 보이거나 감추기 위한 함수
BOOL CALLBACK EnumChildProc(HWND hChild, LPARAM lParam)
{
	::ShowWindow(hChild, lParam);
	return TRUE;
}

// 다이얼로그를 감추는 함수
void CFolderDlg::Fold()
{
	m_bIsFolded = TRUE;

	// 현재 윈도우 크기와 위치를 저장해 둔다
	GetWindowRect(&m_rcWindow);

	// 자식 윈도우들을 모두 감춘다
	::EnumChildWindows(m_hWnd, EnumChildProc, SW_HIDE);

	// 현재 스타일을 저장해 둔다
	m_dwStyle = GetStyle();
	ModifyStyle(WS_CAPTION, 0);

	// 애니메이션을 출력한다
	Animate(m_rcWindow, m_rcLastFold);

	// 다이얼로그 크기를 축소한다
	SetWindowPos(&wndTopMost, m_rcLastFold.left, m_rcLastFold.top,
		m_rcLastFold.Width(), m_rcLastFold.Height(), SWP_NOZORDER | SWP_SHOWWINDOW);

	// 다이얼로그를 다시 그린다
	Invalidate();
}

void CFolderDlg::Stretch()
{
	m_bIsFolded = FALSE;

	// 현재 윈도우 크기와 위치를 저장해 둔다
	GetWindowRect(&m_rcLastFold);

	// 원래 스타일로 돌려 놓는다
	ModifyStyle(0, m_dwStyle);

	// 애니메이션을 출력한다
	Animate(m_rcLastFold, m_rcWindow);

	// 다이얼로그 크기를 원래대로 확장한다
	SetWindowPos(&wndTop, m_rcWindow.left, m_rcWindow.top,
		m_rcWindow.Width(), m_rcWindow.Height(), SWP_NOZORDER | SWP_SHOWWINDOW);

	// 자식 윈도우들을 보이게 만든다
	::EnumChildWindows(m_hWnd, EnumChildProc, SW_SHOW);

	// 다이얼로그를 다시 그린다
	Invalidate();
}

// 축소/확장시 위치 이동에 대한 애니메이션 함수
void CFolderDlg::Animate(CRect &rcStart, CRect &rcEnd)
{
	CRect rcTerm, rcTemp;
	rcTerm.left		= (rcEnd.left - rcStart.left) / 20;
	rcTerm.right	= (rcEnd.right - rcStart.right) / 20;
	rcTerm.top		= (rcEnd.top - rcStart.top) / 20;
	rcTerm.bottom	= (rcEnd.bottom - rcStart.bottom) / 20;

	HDC hDC = ::GetDC(NULL);

	int nOldRop = ::SetROP2(hDC, R2_NOTXORPEN);

	HBRUSH hOldBrush;
	CBrush NullBrush;
	NullBrush.CreateStockObject(NULL_BRUSH);
	hOldBrush = (HBRUSH)::SelectObject(hDC, HBRUSH(NullBrush));

	HPEN hOldPen;
	CPen LinePen;
	LinePen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	hOldPen = (HPEN)::SelectObject(hDC, HPEN(LinePen));

	rcTemp = rcStart;

	for(int i = 0; i < 20; i++)
	{
		rcTemp.left		+= rcTerm.left;
		rcTemp.top		+= rcTerm.top;
		rcTemp.right	+= rcTerm.right;
		rcTemp.bottom	+= rcTerm.bottom;

		::Rectangle(hDC, rcTemp.left, rcTemp.top, rcTemp.right, rcTemp.bottom);

		::Sleep(10);

		::Rectangle(hDC, rcTemp.left, rcTemp.top, rcTemp.right, rcTemp.bottom);
	}

	::SetROP2(hDC, nOldRop);
	::SelectObject(hDC, hOldBrush);
	::SelectObject(hDC, hOldPen);
}

UINT CFolderDlg::OnNcHitTest(CPoint point) 
{
	UINT nArea = CDialog::OnNcHitTest(point);

	// 다이얼로그가 축소 되어 있을 때는,
	// 모든 마우스 조작이 캡션에서 이뤄지는 것처럼 처리한다
	if(m_bIsFolded && nArea == HTCLIENT)		nArea = HTCAPTION;

	return nArea;
}

void CFolderDlg::OnNcLButtonDblClk(UINT nHitTest, CPoint point) 
{
	// 다이얼로그를 더블 클릭하면 다시 확장 시킨다
	if(m_bIsFolded)		Stretch();
	
	CDialog::OnNcLButtonDblClk(nHitTest, point);
}
