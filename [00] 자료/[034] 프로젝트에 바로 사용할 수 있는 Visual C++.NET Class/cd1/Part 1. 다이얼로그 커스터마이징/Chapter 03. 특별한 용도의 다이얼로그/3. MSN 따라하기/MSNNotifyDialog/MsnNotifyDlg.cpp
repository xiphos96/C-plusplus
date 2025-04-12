// MsnNotifyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "msnnotifydialog.h"
#include "MsnNotifyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMsnNotifyDlg dialog

// �� ����� ���콺 Ŀ�� ID
#define IDC_HAND            MAKEINTRESOURCE(32649)


CMsnNotifyDlg::CMsnNotifyDlg(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CMsnNotifyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	// �ո�� ���콺 Ŀ�� �ε�
	m_hCursor	= ::LoadCursor(NULL, MAKEINTRESOURCE(IDC_HAND));

	// ��Ʈ ����
	HDC hDC = ::GetDC(NULL);
	m_MessageFont.CreateFont(-MulDiv(9, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_NORMAL,
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "����");
	m_HotFont.CreateFont(-MulDiv(9, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_BOLD,
		0, TRUE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "����");
	::ReleaseDC(NULL, hDC);

	// ���� ���� �ʱ�ȭ
	m_clrText		= RGB(0, 0, 0);

 	m_nTimeUp		= 20;
	m_nTimeShow		= 3000;
	m_nTimeDown		= 20;

	m_nTimerID		= 0;

	m_bHover		= FALSE;
}

CMsnNotifyDlg::~CMsnNotifyDlg()
{
	// �ո�� ���콺 Ŀ�� �Ҹ�
	::DeleteObject(m_hCursor);
	// ��� �̹��� �Ҹ�
	if(m_bmpBkgnd.m_hObject)		m_bmpBkgnd.DeleteObject();
	// ��Ʈ �Ҹ�
	if(m_MessageFont.m_hObject)		m_MessageFont.DeleteObject();
	if(m_HotFont.m_hObject)			m_HotFont.DeleteObject();
}

void CMsnNotifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMsnNotifyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMsnNotifyDlg, CDialog)
	//{{AFX_MSG_MAP(CMsnNotifyDlg)
	ON_WM_SETCURSOR()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsnNotifyDlg message handlers

BOOL CMsnNotifyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// ���̾�α� ������ ���� ��� �̹����� �����Ǿ� ���� ������
	if(m_rcMessage.IsRectEmpty())
	{
		// ���� ���̾�α� ũ�⸦ �޽��� ��� �������� �ϰ�
		// �̿� ���� �������� �����Ѵ�
		GetClientRect(&m_rcMessage);
		m_bmpInfo.bmWidth	= m_rcMessage.Width();
		m_bmpInfo.bmHeight	= m_rcMessage.Height();

		InitPosition();
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

// ���콺�� �˸� â�� ���� ��� ���콺 Ŀ���� �������ִ� �Լ�
BOOL CMsnNotifyDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	::SetCursor(m_hCursor);
	return TRUE;
}

void CMsnNotifyDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// ������ ��Ʈ�� �������� �޽����� ���
	dc.SetTextColor(m_clrText);
	dc.SetBkMode(TRANSPARENT); 

	CFont *pOldFont;

	// ���콺�� �˸� â ���� �ִ��� ���ο� ���� ��Ʈ ����
	if(m_bHover)	pOldFont = dc.SelectObject(&m_HotFont);
	else			pOldFont = dc.SelectObject(&m_MessageFont);

	dc.DrawText(m_strMessage, m_rcMessage,
		DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_WORDBREAK | DT_END_ELLIPSIS | DT_EXPANDTABS);
	dc.SelectObject(pOldFont);
}

BOOL CMsnNotifyDlg::OnEraseBkgnd(CDC* pDC) 
{
	// �˸� â�� ��濡 ��� �̹��� ���
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	CBitmap *pOldBmp = MemDC.SelectObject(&m_bmpBkgnd);

	pDC->BitBlt(0, 0, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);

	MemDC.SelectObject(pOldBmp);

	return TRUE;
}

void CMsnNotifyDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ���콺�� �˸� â ������ �̵� ���̸�,
	// �ý��ۿ��� ���콺�� �˸� â ���԰� Ż�⿡ ���� �޽����� ������ ���� ��û
	TRACKMOUSEEVENT MouseEvent;
	MouseEvent.cbSize		= sizeof(TRACKMOUSEEVENT);
	MouseEvent.dwFlags		= TME_LEAVE | TME_HOVER;
	MouseEvent.hwndTrack	= m_hWnd;
	MouseEvent.dwHoverTime	= 1;

	::TrackMouseEvent(&MouseEvent);
	
	CDialog::OnMouseMove(nFlags, point);
}

LRESULT CMsnNotifyDlg::OnMouseHover(WPARAM wParam, LPARAM lParam)
{
	// ���콺�� �˸� â�� ���������Ƿ� ȭ�� �ٽ� �׸�
	m_bHover = TRUE;
	Invalidate();

	return 0;
}

LRESULT CMsnNotifyDlg::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	// ���콺�� �˸� â���� Ż�������Ƿ� ȭ�� �ٽ� �׸�
	m_bHover = FALSE;
	Invalidate();

	return 0;
}

void CMsnNotifyDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// ���콺 ���� ��ư Ŭ��(��Ȯ���� ���� ��ư ����)��
	// �θ� �����쿡�� �޽��� ����
	if(GetParent())
	{
		GetParent()->PostMessage(WM_NOTIFY_CLICKED, 0, 0);
	}
	
	CDialog::OnLButtonUp(nFlags, point);
}

void CMsnNotifyDlg::OnTimer(UINT nIDEvent) 
{
	CRect rcWindow;

	GetWindowRect(&rcWindow);

	switch(nIDEvent)
	{
	case CONST_TIMER_UP:
		// �˸� â�� ��Ÿ���� ���̶��
		// �˸� â�� ��ġ�� �ű��
		rcWindow.OffsetRect(m_szTerm);
		// �˸� â�� �̵��� �� ��ġ���� �Դٸ�
		if(rcWindow.left == m_ptEnd.x && rcWindow.top == m_ptEnd.y)
		{
			// ��Ÿ���� Ÿ�̸Ӹ� ���߰�, �����ֱ� ���� Ÿ�̸Ӹ� ����
			KillTimer(nIDEvent);
			m_nTimerID = SetTimer(CONST_TIMER_SHOW, m_nTimeShow, NULL);
		}
		break;
	case CONST_TIMER_SHOW:
		// �˸� â�� �����ִ� �ð��� �����ٸ�
		// �����ֱ� ���� Ÿ�̸Ӹ� ���߰�, ������� Ÿ�̸Ӹ� ����
		KillTimer(nIDEvent);
		m_nTimerID = SetTimer(CONST_TIMER_DOWN, m_nTimeDown, NULL);
		break;
	case CONST_TIMER_DOWN:
		// �˸� â�� ������� ���̶��
		// �˸� â�� ��ġ�� �ű��
		rcWindow.OffsetRect(-1 * m_szTerm.cx, -1 * m_szTerm.cy);
		// �˸� â�� ���� ���� ��ġ���� �Դٸ�
		if(rcWindow.left == m_ptStart.x && rcWindow.top == m_ptStart.y)
		{
			// ������� Ÿ�̸� ����
			KillTimer(nIDEvent);
		}
		break;
	}

	// �˸� â ��ġ �ű�
	SetWindowPos(NULL, rcWindow.left, rcWindow.top,
		m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, SWP_NOZORDER | SWP_NOACTIVATE | SWP_SHOWWINDOW);
	
	CDialog::OnTimer(nIDEvent);
}

// ��� �̹��� ���� �Լ�
void CMsnNotifyDlg::SetBitmap(UINT nBitmap)
{
	if(m_bmpBkgnd.m_hObject)		m_bmpBkgnd.DeleteObject();
	m_bmpBkgnd.LoadBitmap(nBitmap);
	m_bmpBkgnd.GetBitmap(&m_bmpInfo);

	// �޽��� �ؽ�Ʈ ��� ������ ��� �̹��� ũ��� ����
	m_rcMessage.SetRect(0, 0, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight);

	// ��� �̹����� ���� ���� ����
	InitPosition();
}

// ��� �̹��� ���� �Լ�
void CMsnNotifyDlg::SetBitmap(LPCTSTR pFileName)
{
	if(m_bmpBkgnd.m_hObject)		m_bmpBkgnd.DeleteObject();

	// ��� ��Ʈ���� ���Ͽ��� ����
	HBITMAP hBitmap = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			LPCTSTR(pFileName), IMAGE_BITMAP,
			0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	m_bmpBkgnd.Attach(hBitmap);
	m_bmpBkgnd.GetBitmap(&m_bmpInfo);

	// �޽��� �ؽ�Ʈ ��� ������ ��� �̹��� ũ��� ����
	m_rcMessage.SetRect(0, 0, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight);

	// ��� �̹����� ���� ���� ����
	InitPosition();
}

// ��� �̹����� ���� ���� ���� �Լ�
void CMsnNotifyDlg::InitPosition()
{
	// �۾�ǥ������ ������ �۾� ���� ȹ��
	CRect rcWorkArea;
	::SystemParametersInfo(SPI_GETWORKAREA, 0, &rcWorkArea, 0);

	// ȭ�� ũ�� ȹ��
	int nScreenWidth	= ::GetSystemMetrics(SM_CXSCREEN);
	int nScreenHeight	= ::GetSystemMetrics(SM_CYSCREEN);

	if(rcWorkArea.left > 0)
	{
		// �۾� ǥ������ ���ʿ� �ִٸ�, �˸� â�� ���ʿ��� ��Ÿ������ ��ġ ����
		m_ptStart.x = rcWorkArea.left - m_bmpInfo.bmWidth;
		m_ptStart.y = rcWorkArea.bottom - m_bmpInfo.bmHeight;
		m_ptEnd.x = rcWorkArea.left;
		m_ptEnd.y = m_ptStart.y;
		m_szTerm.cx = CONST_INCREMENT;
		m_szTerm.cy = 0;
	}
	if(rcWorkArea.right < nScreenWidth)
	{
		// �۾� ǥ������ �����ʿ� �ִٸ�, �˸� â�� �����ʿ��� ��Ÿ������ ��ġ ����
		m_ptStart.x = rcWorkArea.right;
		m_ptStart.y = rcWorkArea.bottom - m_bmpInfo.bmHeight;
		m_ptEnd.x = rcWorkArea.right - m_bmpInfo.bmWidth;
		m_ptEnd.y = m_ptStart.y;
		m_szTerm.cx = -CONST_INCREMENT;
		m_szTerm.cy = 0;
	}
	if(rcWorkArea.top > 0)
	{
		// �۾� ǥ������ ���ʿ� �ִٸ�, �˸� â�� ���ʿ��� ��Ÿ������ ��ġ ����
		m_ptStart.x = rcWorkArea.right - m_bmpInfo.bmWidth;
		m_ptStart.y = rcWorkArea.top - m_bmpInfo.bmHeight;
		m_ptEnd.x = m_ptStart.x;
		m_ptEnd.y = rcWorkArea.top;
		m_szTerm.cx = 0;
		m_szTerm.cy = CONST_INCREMENT;
	}
	if(rcWorkArea.bottom < nScreenHeight)
	{
		// �۾� ǥ������ �Ʒ��ʿ� �ִٸ�, �˸� â�� �Ʒ��ʿ��� ��Ÿ������ ��ġ ����
		m_ptStart.x = rcWorkArea.right - m_bmpInfo.bmWidth;
		m_ptStart.y = rcWorkArea.bottom;
		m_ptEnd.x = m_ptStart.x;
		m_ptEnd.y = rcWorkArea.bottom - m_bmpInfo.bmHeight;
		m_szTerm.cx = 0;
		m_szTerm.cy = -CONST_INCREMENT;
	}

	// �˸� â�� ���̰� �ִ� ���¶�� 
	if(::IsWindow(m_hWnd))
	{
		// �˸� â�� ��ġ/ũ�� ������
		SetWindowPos(NULL, 0, 0, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, SWP_NOZORDER | SWP_NOMOVE);
	}
}

// �޽��� �ؽ�Ʈ ��¿� ��Ʈ ���� �Լ�
void CMsnNotifyDlg::SetTextFont(LPCTSTR pFontName, int nPoint)
{
	// ���� ��Ʈ�� �Ҹ�
	if(m_MessageFont.m_hObject)		m_MessageFont.DeleteObject();
	if(m_HotFont.m_hObject)			m_HotFont.DeleteObject();

	// ���ο� ��Ʈ �̸��� ũ��� ��Ʈ �� ����
	HDC hDC = ::GetDC(NULL);
	m_MessageFont.CreateFont(-MulDiv(nPoint, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_NORMAL,
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, pFontName);
	m_HotFont.CreateFont(-MulDiv(nPoint, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_BOLD,
		0, TRUE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, pFontName);
	::ReleaseDC(NULL, hDC);
}

// �˸� â ��� �Լ�
void CMsnNotifyDlg::Show()
{
	// ���� ���� ���� Ÿ�̸Ӱ� �ִٸ� ����
	if(m_nTimerID)		KillTimer(m_nTimerID);

	// �˸� â�� ȭ�鿡 ���
	SetWindowPos(NULL, m_ptStart.x, m_ptStart.y,
		m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, SWP_NOZORDER | SWP_NOACTIVATE | SWP_SHOWWINDOW);

	// �˸� â�� ��Ÿ���� Ÿ�̸� ����
	m_nTimerID = SetTimer(CONST_TIMER_UP, m_nTimeUp, NULL);
}

// �˸� â ���ߴ� �Լ�
void CMsnNotifyDlg::Hide()
{
	// ���� ���� ���� Ÿ�̸Ӱ� �ִٸ� ����
	if(m_nTimerID)		KillTimer(m_nTimerID);

	// �˸� â�� ������� Ÿ�̸� ����
	m_nTimerID = SetTimer(CONST_TIMER_DOWN, m_nTimeDown, NULL);
}
