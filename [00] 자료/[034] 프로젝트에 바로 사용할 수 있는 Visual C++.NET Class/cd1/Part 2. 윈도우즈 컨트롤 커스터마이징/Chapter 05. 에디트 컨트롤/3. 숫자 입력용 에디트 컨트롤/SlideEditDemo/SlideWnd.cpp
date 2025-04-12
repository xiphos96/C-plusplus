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

// 슬라이드 윈도우를 그리는데 사용하는 상수
#define CONST_SLIDEWND_WIDTH	120			// 슬라이드 윈도우의 폭
#define CONST_SLIDEWND_HEIGHT	14			// 슬라이드 윈도우의 높이
#define CONST_SLIDE_EDGE		10			// 슬라이드 윈도우와 범위 라인 사이의 여백
#define CONST_SLIDE_Y			3			// 범위 라인의 수직 위치
#define CONST_SLIDE_CX			100			// 범위 라인의 폭
#define CONST_SLIDE_CY			2			// 범위 라인의 높이
#define CONST_SLIDE_WIDTH		6			// 현재 위치 표시자의 폭
#define CONST_SLIDE_HEIGHT		5			// 현재 위치 표시자의 높이


CSlideWnd::CSlideWnd()
{
	// 슬라이드 윈도우를 그리는데 사용하는 GDI 객체 생성
	m_LinePen.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_BTNTEXT));
	m_ShadowPen.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_BTNSHADOW));
	m_BkgndBrush.CreateSolidBrush(::GetSysColor(COLOR_BTNFACE));

	// 멤버 변수 초기화
	m_pParent	= NULL;

	m_nCurPos	= 0;
	m_nMax		= 0;
	m_nMin		= 0;

	m_hCursor	= ::LoadCursor(NULL, IDC_ARROW);
}

CSlideWnd::~CSlideWnd()
{
	// GDI 객체 소멸
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

// 슬라이드 윈도우를 생성하는 함수
BOOL CSlideWnd::PopupSlide(CWnd *pParent, CRect &rcWindow, int nMax, int nMin, int nPos)
{
	// 인자들을 멤버 변수에 저장한다
	m_pParent	= pParent;

	m_nMax		= nMax;
	m_nMin		= nMin;

	// 현재 위치는 0 ~ 100까지의 퍼센테이지 값으로 변경한다
	m_nCurPos	= int((nPos - m_nMin) * 100.0 / (m_nMax - m_nMin));

	// 슬라이드 에디트 컨트롤의 버튼 영역을 기반으로
	// 현재 위치에 따른 슬라이드 윈도우의 영역을 계산한다
	rcWindow.left	-= m_nCurPos + CONST_SLIDE_EDGE - rcWindow.Width() / 2;
	rcWindow.right	= rcWindow.left + CONST_SLIDEWND_WIDTH;
	rcWindow.top	= rcWindow.bottom + 2;
	rcWindow.bottom	= rcWindow.top + CONST_SLIDEWND_HEIGHT;

	// 팝업 윈도우로 생성하기 위해 윈도우 클래스를 등록한다
	UINT nStyle = CS_CLASSDC | CS_SAVEBITS | CS_HREDRAW | CS_VREDRAW;
	CString strClassName = AfxRegisterWndClass(nStyle, 0, 0, 0);

	// 팝업 윈도우로써 생성한다
	if(!CreateEx(0, strClassName, "SlideWnd", WS_VISIBLE | WS_POPUP, rcWindow, m_pParent, 0, NULL))
	{
		return FALSE;
	}

	// 클라이언트 영역의 크기를 저장한다
	GetClientRect(&m_rcClient);

	// 화면에 갱신한다
	ShowWindow(SW_SHOW);
	UpdateWindow();

	// 마우스의 이벤트를 캡춰한다
	SetCapture();
	// 포커스를 갖는다
	SetFocus();

	return TRUE;
}

void CSlideWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// 화면 출력을 부드럽게 하기 위해 더블 버퍼링을 사용한다
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);

	CBitmap MemBmp, *pOldBmp;

	MemBmp.CreateCompatibleBitmap(&dc, m_rcClient.Width(), m_rcClient.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);

	CBrush *pOldBrush = MemDC.SelectObject(&m_BkgndBrush);
	CPen *pOldPen = MemDC.SelectObject(&m_LinePen);

	// 배경과 테두리를 그린다
	MemDC.Rectangle(&m_rcClient);

	// 범위 라인을 그린다
	MemDC.MoveTo(CONST_SLIDE_EDGE, CONST_SLIDE_Y);
	MemDC.LineTo(CONST_SLIDE_EDGE + CONST_SLIDE_CX + 1, CONST_SLIDE_Y);

	// 범위 라인의 그림자를 그린다
	MemDC.SelectObject(&m_ShadowPen);
	MemDC.MoveTo(CONST_SLIDE_EDGE, CONST_SLIDE_Y + 1);
	MemDC.LineTo(CONST_SLIDE_EDGE + CONST_SLIDE_CX + 1, CONST_SLIDE_Y + 1);

	// 현재 위치 표시자를 그린다
	MemDC.SelectObject(&m_LinePen);
	MemDC.MoveTo(CONST_SLIDE_EDGE + m_nCurPos, CONST_SLIDE_Y + CONST_SLIDE_CY);
	MemDC.LineTo(CONST_SLIDE_EDGE + m_nCurPos - CONST_SLIDE_WIDTH / 2,
		CONST_SLIDE_Y + CONST_SLIDE_CY + CONST_SLIDE_HEIGHT);
	MemDC.LineTo(CONST_SLIDE_EDGE + m_nCurPos + CONST_SLIDE_WIDTH / 2,
		CONST_SLIDE_Y + CONST_SLIDE_CY + CONST_SLIDE_HEIGHT);
	MemDC.LineTo(CONST_SLIDE_EDGE + m_nCurPos, CONST_SLIDE_Y + CONST_SLIDE_CY);

	// 화면에 출력한다
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
	// 만약 마우스 좌측 버튼을 누른 상태로 마우스를 드래그하면
	if(nFlags & MK_LBUTTON)
	{
		// 마우스의 위치를 바탕으로 현재 위치를 계산한다
		m_nCurPos = point.x - CONST_SLIDE_EDGE;
		// 현재 위치를 보정한다
		if(m_nCurPos < 0)					m_nCurPos = 0;
		if(m_nCurPos > CONST_SLIDE_CX)		m_nCurPos = CONST_SLIDE_CX;

		// 값의 변경을 부모 윈도우에게 알린다
		OnPosChange();

		::SetCursor(m_hCursor);
	}
	
	CWnd::OnMouseMove(nFlags, point);
}

// 값의 변동이 발생할 경우 부모 윈도우에게 알리는 함수
void CSlideWnd::OnPosChange()
{
	// 새로운 값에 따른 슬라이드 윈도우를 다시 그린다
	Invalidate(FALSE);

	// 현재 위치에 따른 실제 값을 계산한다
	int nPos = ((m_nMax - m_nMin) * m_nCurPos + m_nMin) / 100;
	// 슬라이드 에디트 컨트롤에게 메시지로 알린다
	if(m_pParent)
		m_pParent->SendMessage(WM_SLIDE_POS_CHANGE, (WPARAM)nPos, (LPARAM)m_hWnd);
}

void CSlideWnd::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// 마우스의 위치를 바탕으로 현재 위치를 계산한다
	m_nCurPos = point.x - CONST_SLIDE_EDGE;
	// 현재 위치를 보정한다
	if(m_nCurPos < 0)					m_nCurPos = 0;
	if(m_nCurPos > CONST_SLIDE_CX)		m_nCurPos = CONST_SLIDE_CX;

	// 값 변경이 완료 되었음을 부모 윈도우에게 알린다
	OnEndSelect();
	
	CWnd::OnLButtonUp(nFlags, point);
}

void CSlideWnd::OnCaptureChanged(CWnd *pWnd) 
{
	// 만약 마우스 이벤트를 다른 윈도우가 가져갈 경우 값 변경을 완료한다
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

// 값 변경이 완료된 경우 부모 윈도우에게 알리는 함수
void CSlideWnd::OnEndSelect()
{
	if(!IsWindowVisible())		return;

	// 마우스 이벤트 캡춰를 정지한다
	ReleaseCapture();

	// 현재 위치에 따른 실제 값을 계산한다
	int nPos = ((m_nMax - m_nMin) * m_nCurPos + m_nMin) / 100;
	// 값 변경이 완료 되었음을 슬라이드 에디트 컨트롤에게 메시지로 알린다
	m_pParent->SendMessage(WM_SLIDE_END_SELECT, (WPARAM)nPos, (LPARAM)m_hWnd);

	// 슬라이드 윈도우를 소멸 시킨다
	DestroyWindow();
}

void CSlideWnd::OnKillFocus(CWnd* pNewWnd) 
{
	CWnd::OnKillFocus(pNewWnd);
	
	// 만약 슬라이드 윈도우가 포커스를 잃을 경우 값 변경을 완료한다
	OnEndSelect();
}

#if _MSC_VER <= 1200
	// VC++ 6.0에서의 코드
void CSlideWnd::OnActivateApp(BOOL bActive,  HTASK dwThreadID) 
{
	CWnd::OnActivateApp(bActive, dwThreadID);
#else
	// VC++.Net에서의 코드
void CSlideWnd::OnActivateApp(BOOL bActive, DWORD dwThreadID) 
{
	CWnd::OnActivateApp(bActive, dwThreadID);
#endif
	
	// 만약 다른 프로그램이 활성화될 경우 값 변경을 완료한다
	if(!bActive)	OnEndSelect();
}
