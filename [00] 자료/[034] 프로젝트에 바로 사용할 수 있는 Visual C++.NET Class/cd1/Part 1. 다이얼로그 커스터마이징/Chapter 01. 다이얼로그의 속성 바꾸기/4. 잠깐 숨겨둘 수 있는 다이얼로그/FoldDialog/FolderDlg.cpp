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

	// �ʱⰪ�� �����Ѵ�
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

	// �ʱ⿡ �������� �����Ǿ� ���� �ʴٸ�
	// �⺻ ���α׷� �������� �����Ѵ�
	if(m_hIcon == NULL)
		SetFoldIcon(::LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME)));

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFolderDlg::OnPaint() 
{
	// ���̾�αװ� ������ ������ ��, �������� ������ ������ ��,
	// �������� ����Ѵ�
	if(m_bIsFolded && m_hIcon)
	{
		CPaintDC dc(this); // device context for painting

		dc.DrawIcon(0, 0, m_hIcon);
	}

	CDialog::OnPaint();
}

// ���ο� �������� �����ϴ� �Լ�
void CFolderDlg::SetFoldIcon(HICON hIcon)
{
	// ���� �������� �����Ѵٸ� �����Ѵ�
	if(m_hIcon)			::DestroyIcon(m_hIcon);

	// ���ο� �������� �����Ѵ�
	m_hIcon = hIcon;

	if(m_hIcon == NULL)	return;

	int nIconCX = 0, nIconCY = 0;

	// �������� ũ�⸦ ���´�
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

	// �������� ũ�⸦ ���� �� �����ٸ� 32*32 ũ��� �����Ѵ�
	if(nIconCX == 0 || nIconCY == 0)
	{
		nIconCX = 32;
		nIconCY = 32;
	}

	// �⺻ ��ġ�� ȭ�� ����/�ϴ����� �����Ѵ�.
	// �������� �� ũ���, �������� ũ�⿡ �׵θ� �β��� �ι� ���� ũ���̴�
	CRect rcScreen;
	::SystemParametersInfo(SPI_GETWORKAREA, 0, &rcScreen, 0);

	m_rcLastFold.left	= rcScreen.right - nIconCX - ::GetSystemMetrics(SM_CXEDGE) * 2;
	m_rcLastFold.top	= rcScreen.bottom - nIconCY - ::GetSystemMetrics(SM_CYEDGE) * 2;
	m_rcLastFold.right	= rcScreen.right;
	m_rcLastFold.bottom = rcScreen.bottom;

}

// ���̾�α��� ��� �ڽ� ��������� ���̰ų� ���߱� ���� �Լ�
BOOL CALLBACK EnumChildProc(HWND hChild, LPARAM lParam)
{
	::ShowWindow(hChild, lParam);
	return TRUE;
}

// ���̾�α׸� ���ߴ� �Լ�
void CFolderDlg::Fold()
{
	m_bIsFolded = TRUE;

	// ���� ������ ũ��� ��ġ�� ������ �д�
	GetWindowRect(&m_rcWindow);

	// �ڽ� ��������� ��� �����
	::EnumChildWindows(m_hWnd, EnumChildProc, SW_HIDE);

	// ���� ��Ÿ���� ������ �д�
	m_dwStyle = GetStyle();
	ModifyStyle(WS_CAPTION, 0);

	// �ִϸ��̼��� ����Ѵ�
	Animate(m_rcWindow, m_rcLastFold);

	// ���̾�α� ũ�⸦ ����Ѵ�
	SetWindowPos(&wndTopMost, m_rcLastFold.left, m_rcLastFold.top,
		m_rcLastFold.Width(), m_rcLastFold.Height(), SWP_NOZORDER | SWP_SHOWWINDOW);

	// ���̾�α׸� �ٽ� �׸���
	Invalidate();
}

void CFolderDlg::Stretch()
{
	m_bIsFolded = FALSE;

	// ���� ������ ũ��� ��ġ�� ������ �д�
	GetWindowRect(&m_rcLastFold);

	// ���� ��Ÿ�Ϸ� ���� ���´�
	ModifyStyle(0, m_dwStyle);

	// �ִϸ��̼��� ����Ѵ�
	Animate(m_rcLastFold, m_rcWindow);

	// ���̾�α� ũ�⸦ ������� Ȯ���Ѵ�
	SetWindowPos(&wndTop, m_rcWindow.left, m_rcWindow.top,
		m_rcWindow.Width(), m_rcWindow.Height(), SWP_NOZORDER | SWP_SHOWWINDOW);

	// �ڽ� ��������� ���̰� �����
	::EnumChildWindows(m_hWnd, EnumChildProc, SW_SHOW);

	// ���̾�α׸� �ٽ� �׸���
	Invalidate();
}

// ���/Ȯ��� ��ġ �̵��� ���� �ִϸ��̼� �Լ�
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

	// ���̾�αװ� ��� �Ǿ� ���� ����,
	// ��� ���콺 ������ ĸ�ǿ��� �̷����� ��ó�� ó���Ѵ�
	if(m_bIsFolded && nArea == HTCLIENT)		nArea = HTCAPTION;

	return nArea;
}

void CFolderDlg::OnNcLButtonDblClk(UINT nHitTest, CPoint point) 
{
	// ���̾�α׸� ���� Ŭ���ϸ� �ٽ� Ȯ�� ��Ų��
	if(m_bIsFolded)		Stretch();
	
	CDialog::OnNcLButtonDblClk(nHitTest, point);
}
