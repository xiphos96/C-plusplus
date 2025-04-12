// SlideWnd.cpp : implementation file
//

#include "stdafx.h"
#include "slideeditdemo.h"
#include "SlideWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSlideWnd

// �����̵� �����츦 �׸��µ� ����ϴ� ���
#define CONST_SLIDEWND_WIDTH	120			// �����̵� �������� ��
#define CONST_SLIDEWND_HEIGHT	14			// �����̵� �������� ����
#define CONST_SLIDE_EDGE		10			// �����̵� ������� ���� ���� ������ ����
#define CONST_SLIDE_Y			3			// ���� ������ ���� ��ġ
#define CONST_SLIDE_CX			100			// ���� ������ ��
#define CONST_SLIDE_CY			2			// ���� ������ ����
#define CONST_SLIDE_WIDTH		6			// ���� ��ġ ǥ������ ��
#define CONST_SLIDE_HEIGHT		5			// ���� ��ġ ǥ������ ����


CSlideWnd::CSlideWnd()
{
	// �����̵� �����츦 �׸��µ� ����ϴ� GDI ��ü ����
	m_LinePen.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_BTNTEXT));
	m_ShadowPen.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_BTNSHADOW));
	m_BkgndBrush.CreateSolidBrush(::GetSysColor(COLOR_BTNFACE));

	// ��� ���� �ʱ�ȭ
	m_pParent	= NULL;

	m_nCurPos	= 0;
	m_nMax		= 0;
	m_nMin		= 0;

	m_hCursor	= ::LoadCursor(NULL, IDC_ARROW);
}

CSlideWnd::~CSlideWnd()
{
	// GDI ��ü �Ҹ�
	m_LinePen.DeleteObject();
	m_ShadowPen.DeleteObject();
	m_BkgndBrush.DeleteObject();

	::DeleteObject(m_hCursor);
}


BEGIN_MESSAGE_MAP(CSlideWnd, CWnd)
	//{{AFX_MSG_MAP(CSlideWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_KILLFOCUS()
	ON_WM_ACTIVATEAPP()
	ON_WM_CAPTURECHANGED()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CSlideWnd message handlers

// �����̵� �����츦 �����ϴ� �Լ�
BOOL CSlideWnd::PopupSlide(CWnd *pParent, CRect &rcWindow, int nMax, int nMin, int nPos)
{
	// ���ڵ��� ��� ������ �����Ѵ�
	m_pParent	= pParent;

	m_nMax		= nMax;
	m_nMin		= nMin;

	// ���� ��ġ�� 0 ~ 100������ �ۼ������� ������ �����Ѵ�
	m_nCurPos	= int((nPos - m_nMin) * 100.0 / (m_nMax - m_nMin));

	// �����̵� ����Ʈ ��Ʈ���� ��ư ������ �������
	// ���� ��ġ�� ���� �����̵� �������� ������ ����Ѵ�
	rcWindow.left	-= m_nCurPos + CONST_SLIDE_EDGE - rcWindow.Width() / 2;
	rcWindow.right	= rcWindow.left + CONST_SLIDEWND_WIDTH;
	rcWindow.top	= rcWindow.bottom + 2;
	rcWindow.bottom	= rcWindow.top + CONST_SLIDEWND_HEIGHT;

	// �˾� ������� �����ϱ� ���� ������ Ŭ������ ����Ѵ�
	UINT nStyle = CS_CLASSDC | CS_SAVEBITS | CS_HREDRAW | CS_VREDRAW;
	CString strClassName = AfxRegisterWndClass(nStyle, 0, 0, 0);

	// �˾� ������ν� �����Ѵ�
	if(!CreateEx(0, strClassName, "SlideWnd", WS_VISIBLE | WS_POPUP, rcWindow, m_pParent, 0, NULL))
	{
		return FALSE;
	}

	// Ŭ���̾�Ʈ ������ ũ�⸦ �����Ѵ�
	GetClientRect(&m_rcClient);

	// ȭ�鿡 �����Ѵ�
	ShowWindow(SW_SHOW);
	UpdateWindow();

	// ���콺�� �̺�Ʈ�� ĸ���Ѵ�
	SetCapture();
	// ��Ŀ���� ���´�
	SetFocus();

	return TRUE;
}

void CSlideWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// ȭ�� ����� �ε巴�� �ϱ� ���� ���� ���۸��� ����Ѵ�
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);

	CBitmap MemBmp, *pOldBmp;

	MemBmp.CreateCompatibleBitmap(&dc, m_rcClient.Width(), m_rcClient.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);

	CBrush *pOldBrush = MemDC.SelectObject(&m_BkgndBrush);
	CPen *pOldPen = MemDC.SelectObject(&m_LinePen);

	// ���� �׵θ��� �׸���
	MemDC.Rectangle(&m_rcClient);

	// ���� ������ �׸���
	MemDC.MoveTo(CONST_SLIDE_EDGE, CONST_SLIDE_Y);
	MemDC.LineTo(CONST_SLIDE_EDGE + CONST_SLIDE_CX + 1, CONST_SLIDE_Y);

	// ���� ������ �׸��ڸ� �׸���
	MemDC.SelectObject(&m_ShadowPen);
	MemDC.MoveTo(CONST_SLIDE_EDGE, CONST_SLIDE_Y + 1);
	MemDC.LineTo(CONST_SLIDE_EDGE + CONST_SLIDE_CX + 1, CONST_SLIDE_Y + 1);

	// ���� ��ġ ǥ���ڸ� �׸���
	MemDC.SelectObject(&m_LinePen);
	MemDC.MoveTo(CONST_SLIDE_EDGE + m_nCurPos, CONST_SLIDE_Y + CONST_SLIDE_CY);
	MemDC.LineTo(CONST_SLIDE_EDGE + m_nCurPos - CONST_SLIDE_WIDTH / 2,
		CONST_SLIDE_Y + CONST_SLIDE_CY + CONST_SLIDE_HEIGHT);
	MemDC.LineTo(CONST_SLIDE_EDGE + m_nCurPos + CONST_SLIDE_WIDTH / 2,
		CONST_SLIDE_Y + CONST_SLIDE_CY + CONST_SLIDE_HEIGHT);
	MemDC.LineTo(CONST_SLIDE_EDGE + m_nCurPos, CONST_SLIDE_Y + CONST_SLIDE_CY);

	// ȭ�鿡 ����Ѵ�
	dc.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(), &MemDC, 0, 0, SRCCOPY);

	MemDC.SelectObject(pOldBmp);
	MemDC.SelectObject(pOldBrush);
	MemDC.SelectObject(pOldPen);
	MemDC.DeleteDC();

	MemBmp.DeleteObject();
}

BOOL CSlideWnd::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
//	return CWnd::OnEraseBkgnd(pDC);
}

void CSlideWnd::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ���� ���콺 ���� ��ư�� ���� ���·� ���콺�� �巡���ϸ�
	if(nFlags & MK_LBUTTON)
	{
		// ���콺�� ��ġ�� �������� ���� ��ġ�� ����Ѵ�
		m_nCurPos = point.x - CONST_SLIDE_EDGE;
		// ���� ��ġ�� �����Ѵ�
		if(m_nCurPos < 0)					m_nCurPos = 0;
		if(m_nCurPos > CONST_SLIDE_CX)		m_nCurPos = CONST_SLIDE_CX;

		// ���� ������ �θ� �����쿡�� �˸���
		OnPosChange();

		::SetCursor(m_hCursor);
	}
	
	CWnd::OnMouseMove(nFlags, point);
}

// ���� ������ �߻��� ��� �θ� �����쿡�� �˸��� �Լ�
void CSlideWnd::OnPosChange()
{
	// ���ο� ���� ���� �����̵� �����츦 �ٽ� �׸���
	Invalidate(FALSE);

	// ���� ��ġ�� ���� ���� ���� ����Ѵ�
	int nPos = ((m_nMax - m_nMin) * m_nCurPos + m_nMin) / 100;
	// �����̵� ����Ʈ ��Ʈ�ѿ��� �޽����� �˸���
	if(m_pParent)
		m_pParent->SendMessage(WM_SLIDE_POS_CHANGE, (WPARAM)nPos, (LPARAM)m_hWnd);
}

void CSlideWnd::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// ���콺�� ��ġ�� �������� ���� ��ġ�� ����Ѵ�
	m_nCurPos = point.x - CONST_SLIDE_EDGE;
	// ���� ��ġ�� �����Ѵ�
	if(m_nCurPos < 0)					m_nCurPos = 0;
	if(m_nCurPos > CONST_SLIDE_CX)		m_nCurPos = CONST_SLIDE_CX;

	// �� ������ �Ϸ� �Ǿ����� �θ� �����쿡�� �˸���
	OnEndSelect();
	
	CWnd::OnLButtonUp(nFlags, point);
}

void CSlideWnd::OnCaptureChanged(CWnd *pWnd) 
{
	// ���� ���콺 �̺�Ʈ�� �ٸ� �����찡 ������ ��� �� ������ �Ϸ��Ѵ�
	BOOL bEnd = FALSE;

	if(pWnd)
	{
		if(pWnd->m_hWnd != m_hWnd)	bEnd = TRUE;
	}
	else
		bEnd = TRUE;

	if(bEnd)		OnEndSelect();

	CWnd::OnCaptureChanged(pWnd);
}

// �� ������ �Ϸ�� ��� �θ� �����쿡�� �˸��� �Լ�
void CSlideWnd::OnEndSelect()
{
	if(!IsWindowVisible())		return;

	// ���콺 �̺�Ʈ ĸ�縦 �����Ѵ�
	ReleaseCapture();

	// ���� ��ġ�� ���� ���� ���� ����Ѵ�
	int nPos = ((m_nMax - m_nMin) * m_nCurPos + m_nMin) / 100;
	// �� ������ �Ϸ� �Ǿ����� �����̵� ����Ʈ ��Ʈ�ѿ��� �޽����� �˸���
	m_pParent->SendMessage(WM_SLIDE_END_SELECT, (WPARAM)nPos, (LPARAM)m_hWnd);

	// �����̵� �����츦 �Ҹ� ��Ų��
	DestroyWindow();
}

void CSlideWnd::OnKillFocus(CWnd* pNewWnd) 
{
	CWnd::OnKillFocus(pNewWnd);
	
	// ���� �����̵� �����찡 ��Ŀ���� ���� ��� �� ������ �Ϸ��Ѵ�
	OnEndSelect();
}

#if _MSC_VER <= 1200
	// VC++ 6.0������ �ڵ�
void CSlideWnd::OnActivateApp(BOOL bActive,  HTASK dwThreadID) 
{
	CWnd::OnActivateApp(bActive, dwThreadID);
#else
	// VC++.Net������ �ڵ�
void CSlideWnd::OnActivateApp(BOOL bActive, DWORD dwThreadID) 
{
	CWnd::OnActivateApp(bActive, dwThreadID);
#endif
	
	// ���� �ٸ� ���α׷��� Ȱ��ȭ�� ��� �� ������ �Ϸ��Ѵ�
	if(!bActive)	OnEndSelect();
}
