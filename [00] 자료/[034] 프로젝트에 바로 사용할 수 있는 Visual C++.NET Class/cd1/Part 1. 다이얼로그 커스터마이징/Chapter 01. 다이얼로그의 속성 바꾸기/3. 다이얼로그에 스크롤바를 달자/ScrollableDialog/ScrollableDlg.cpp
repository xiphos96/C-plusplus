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
	// ���̾�α��� ũ�� ������ �����ϵ���,
	// WS_THICKFRAME �Ӽ��� �����Ѵ�.
    ModifyStyle(DS_MODALFRAME, WS_THICKFRAME);
	
	CDialog::PreSubclassWindow();
}

BOOL CScrollableDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// �ʱ� ���̾�α� ũ�⸦ ������ �д�
	GetClientRect(&m_rcOriginalClient);
	
	CRect rcSizeBoxArea;

	// ũ�� ���� �ڵ��� ��ġ�� ���̾�α��� ���� �ϴ����� �����Ѵ�.
	rcSizeBoxArea.SetRect(	m_rcOriginalClient.right - ::GetSystemMetrics(SM_CXHSCROLL),
							m_rcOriginalClient.bottom - ::GetSystemMetrics(SM_CYVSCROLL),
							m_rcOriginalClient.right,
							m_rcOriginalClient.bottom);

	// ũ�� ���� �ڵ� ����
	m_wndSizeBox.Create(WS_CHILD | WS_VISIBLE | SBS_SIZEGRIP, rcSizeBoxArea, this, AFX_IDW_SIZE_BOX);

	// ��ũ�� ��ġ�� ������ �ʱ�ȭ�Ѵ�.
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

	// ������ν� ������ �Ŀ��� �����ϵ��� �Ѵ�
	if(!::IsWindow(m_hWnd))					return;
	if(!::IsWindow(m_wndSizeBox.m_hWnd))	return;

	WINDOWPLACEMENT WndPlace;
	GetWindowPlacement(&WndPlace);

	CRect rcCurClient;
	GetClientRect(&rcCurClient);

	// ���� Ŭ���̾�Ʈ ũ�Ⱑ
	// ��ũ�ѹٰ� �ʿ��� ũ������ ����Ѵ�
	m_ScrollSize.cx = max(m_rcOriginalClient.Width()  - rcCurClient.Width(), 0);
	m_ScrollSize.cy = max(m_rcOriginalClient.Height() - rcCurClient.Height(), 0);

	// ��ũ�� ������ �����Ѵ�
	SetScrollRange(SB_HORZ, 0, m_ScrollSize.cx, TRUE);
	SetScrollRange(SB_VERT, 0, m_ScrollSize.cy, TRUE);

	// ũ�� ������ ���� ��ũ�� ��ġ�� �����Ѵ�
	int nNewX = min(m_ScrollPos.x, m_ScrollSize.cx);
	int nNewY = min(m_ScrollPos.y, m_ScrollSize.cy);

	// ������ ��ũ�� ��ġ�� ���� �����츦 ��ũ���Ѵ�
	ScrollWindow(m_ScrollPos.x - nNewX, m_ScrollPos.y - nNewY, NULL, NULL);
	m_ScrollPos.x = nNewX;
	m_ScrollPos.y = nNewY;

	// ��ũ�ѹٰ� ���ų� �ִ�ȭ �Ǿ� ���� ���� ��츸 ������ ���� �ڵ��� �����ش�
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

	// ��ũ�� �ɼǿ� ���� ���̾�α׸� ��ũ�� ��Ű��
	// ��ũ�� ��ġ�� �����Ѵ�
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

	// ��ũ�� �ɼǿ� ���� ���̾�α׸� ��ũ�� ��Ű��
	// ��ũ�� ��ġ�� �����Ѵ�
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
