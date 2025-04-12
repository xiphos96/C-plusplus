// ScrollableDlg.cpp : implementation file
//

#include "stdafx.h"
#include "scrollabledialog.h"
#include "ScrollableDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScrollableDlg dialog


CScrollableDlg::CScrollableDlg(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CScrollableDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CScrollableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScrollableDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScrollableDlg, CDialog)
	//{{AFX_MSG_MAP(CScrollableDlg)
	ON_WM_SIZE()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScrollableDlg message handlers

void CScrollableDlg::PreSubclassWindow() 
{
	// 다이얼로그의 크기 조절이 가능하도록,
	// WS_THICKFRAME 속성을 설정한다.
    ModifyStyle(DS_MODALFRAME, WS_THICKFRAME);
	
	CDialog::PreSubclassWindow();
}

BOOL CScrollableDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// 초기 다이얼로그 크기를 저장해 둔다
	GetClientRect(&m_rcOriginalClient);
	
	CRect rcSizeBoxArea;

	// 크기 조절 핸들의 위치를 다이얼로그의 우측 하단으로 설정한다.
	rcSizeBoxArea.SetRect(	m_rcOriginalClient.right - ::GetSystemMetrics(SM_CXHSCROLL),
							m_rcOriginalClient.bottom - ::GetSystemMetrics(SM_CYVSCROLL),
							m_rcOriginalClient.right,
							m_rcOriginalClient.bottom);

	// 크기 조절 핸들 생성
	m_wndSizeBox.Create(WS_CHILD | WS_VISIBLE | SBS_SIZEGRIP, rcSizeBoxArea, this, AFX_IDW_SIZE_BOX);

	// 스크롤 위치와 범위를 초기화한다.
	m_ScrollPos.x = 0;
	m_ScrollPos.y = 0;
	m_ScrollSize.cx = 0;
	m_ScrollSize.cy = 0;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CScrollableDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

	// 윈도우로써 생성된 후에만 실행하도록 한다
	if(!::IsWindow(m_hWnd))					return;
	if(!::IsWindow(m_wndSizeBox.m_hWnd))	return;

	WINDOWPLACEMENT WndPlace;
	GetWindowPlacement(&WndPlace);

	CRect rcCurClient;
	GetClientRect(&rcCurClient);

	// 현재 클라이언트 크기가
	// 스크롤바가 필요한 크기인지 계산한다
	m_ScrollSize.cx = max(m_rcOriginalClient.Width()  - rcCurClient.Width(), 0);
	m_ScrollSize.cy = max(m_rcOriginalClient.Height() - rcCurClient.Height(), 0);

	// 스크롤 범위를 설정한다
	SetScrollRange(SB_HORZ, 0, m_ScrollSize.cx, TRUE);
	SetScrollRange(SB_VERT, 0, m_ScrollSize.cy, TRUE);

	// 크기 조절에 따른 스크롤 위치를 보정한다
	int nNewX = min(m_ScrollPos.x, m_ScrollSize.cx);
	int nNewY = min(m_ScrollPos.y, m_ScrollSize.cy);

	// 보정된 스크롤 위치에 따라 윈도우를 스크롤한다
	ScrollWindow(m_ScrollPos.x - nNewX, m_ScrollPos.y - nNewY, NULL, NULL);
	m_ScrollPos.x = nNewX;
	m_ScrollPos.y = nNewY;

	// 스크롤바가 없거나 최대화 되어 있지 않은 경우만 사이즈 조절 핸들을 보여준다
	if(m_ScrollSize.cx > 0 || m_ScrollSize.cy > 0 || WndPlace.showCmd == SW_MAXIMIZE)
		m_wndSizeBox.ShowWindow(SW_HIDE);
	else
	{
		GetClientRect(&rcCurClient);

		m_wndSizeBox.SetWindowPos(NULL, rcCurClient.right - ::GetSystemMetrics(SM_CXHSCROLL),
			rcCurClient.bottom - ::GetSystemMetrics(SM_CYVSCROLL), 0, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_SHOWWINDOW);
	}
}

void CScrollableDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CRect rcCurClient;
	GetClientRect(&rcCurClient);

	// 스크롤 옵션에 따라 다이얼로그를 스크롤 시키고
	// 스크롤 위치를 보정한다
	switch(nSBCode)
	{
	case SB_TOP :
		nPos = m_ScrollPos.x;
		break;
	case SB_BOTTOM :
		nPos = (m_ScrollSize.cx - m_ScrollPos.x) * -1;
		break;
	case SB_LINEUP :
		nPos = 1;
		break;
	case SB_LINEDOWN :
		nPos = -1;
		break;
	case SB_PAGEUP :
		nPos = rcCurClient.Width();
		break;
	case SB_PAGEDOWN :
		nPos = rcCurClient.Width() * -1;
		break;
	case SB_THUMBTRACK :
	case SB_THUMBPOSITION :
		nPos = m_ScrollPos.x - nPos;
		break;
	}
	
	m_ScrollPos.x -= nPos;
	if(m_ScrollPos.x < 0)
	{
		nPos += m_ScrollPos.x;
		m_ScrollPos.x = 0;
	}
	if(m_ScrollPos.x > m_ScrollSize.cx)
	{
		nPos += (m_ScrollPos.x - m_ScrollSize.cx);
		m_ScrollPos.x = m_ScrollSize.cx;
	}

	ScrollWindow(nPos, 0, NULL, NULL);
	SetScrollPos(SB_HORZ, m_ScrollPos.x, TRUE);

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CScrollableDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CRect rcCurClient;
	GetClientRect(&rcCurClient);

	// 스크롤 옵션에 따라 다이얼로그를 스크롤 시키고
	// 스크롤 위치를 보정한다
	switch(nSBCode)
	{
	case SB_TOP :
		nPos = m_ScrollPos.y;
		break;
	case SB_BOTTOM :
		nPos = (m_ScrollSize.cy - m_ScrollPos.y) * -1;
		break;
	case SB_LINEUP :
		nPos = 1;
		break;
	case SB_LINEDOWN :
		nPos = -1;
		break;
	case SB_PAGEUP :
		nPos = rcCurClient.Height();
		break;
	case SB_PAGEDOWN :
		nPos = rcCurClient.Height() * -1;
		break;
	case SB_THUMBTRACK :
	case SB_THUMBPOSITION :
		nPos = m_ScrollPos.y - nPos;
		break;
	}
	
	m_ScrollPos.y -= nPos;
	if(m_ScrollPos.y < 0)
	{
		nPos += m_ScrollPos.y;
		m_ScrollPos.y = 0;
	}
	if(m_ScrollPos.y > m_ScrollSize.cy)
	{
		nPos += (m_ScrollPos.y - m_ScrollSize.cy);
		m_ScrollPos.y = m_ScrollSize.cy;
	}

	ScrollWindow(0, nPos, NULL, NULL);
	SetScrollPos(SB_VERT, m_ScrollPos.y, TRUE);

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
