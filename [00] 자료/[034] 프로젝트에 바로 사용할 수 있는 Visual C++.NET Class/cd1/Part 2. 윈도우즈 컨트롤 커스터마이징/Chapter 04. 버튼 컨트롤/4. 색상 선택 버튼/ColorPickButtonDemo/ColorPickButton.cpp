// ColorPickButton.cpp : implementation file
//

#include "stdafx.h"
#include "colorpickbuttondemo.h"
#include "ColorPickButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorPickButton

// 테마 DLL과 관련된 정적 변수들을 초기화한다
HMODULE		CColorPickButton::m_hThemeDLL	= NULL;
int			CColorPickButton::m_nCount		= 0;


CColorPickButton::CColorPickButton()
{
	// 아직 테마 DLL이 로딩되지 않았다면 로드한다
	if(m_hThemeDLL == NULL)
		m_hThemeDLL = ::LoadLibrary(_T("UxTheme.dll"));

	// 카운트를 1 증가시킨다
	m_nCount++;

	// 각 변수들의 기본 값을 설정한다
	m_bFlat			= TRUE;
	m_bHover		= FALSE;

	m_clrSelect		= CLR_DEFAULT;
	m_clrDefault	= ::GetSysColor(COLOR_BTNTEXT);

	m_clrBkgnd		= ::GetSysColor(COLOR_BTNFACE);
	m_clrText		= RGB(0, 0, 0);

	m_bPopupWindow	= FALSE;
	m_pPaletteWnd	= NULL;
}

CColorPickButton::~CColorPickButton()
{
	// 카운트를 1 감소 시킨다
	m_nCount--;

	// 만약 참조가 더이상 없고 테마 DLL이 로드되어 있다면 해제한다
	if(m_nCount == 0 && m_hThemeDLL)
	{
		::FreeLibrary(m_hThemeDLL);
		m_hThemeDLL = NULL;
	}

	// 만약 팔레트 윈도우가 남아 있다면 제거한다
	if(m_pPaletteWnd)		delete m_pPaletteWnd;
}


BEGIN_MESSAGE_MAP(CColorPickButton, CButton)
	//{{AFX_MSG_MAP(CColorPickButton)
	ON_CONTROL_REFLECT(BN_CLICKED, OnClicked)
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)
    ON_MESSAGE(CLR_TRACKCOLOR, OnTrackColor)
    ON_MESSAGE(CLR_SELENDOK, OnSelEndOK)
    ON_MESSAGE(CLR_SELENDCANCEL, OnSelEndCancel)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorPickButton message handlers

void CColorPickButton::PreSubclassWindow() 
{
	// 현재 버튼의 크기를 저장한다
	GetClientRect(&m_rcClient);

	// 현재 버튼 크기에서 색상, 색상 이름, 화살표의 출력 위치를 계산한다
	CRect rcTemp = m_rcClient;
	rcTemp.DeflateRect(5, 5);

	m_rcColor = rcTemp;
	m_rcColor.right = m_rcColor.left + rcTemp.Height();

	m_rcArrow = rcTemp;
	m_rcArrow.left = m_rcArrow.right - 8;

	m_rcText = rcTemp;
	m_rcText.left = m_rcColor.right + 4;
	m_rcText.right = m_rcArrow.left - 2;
	
	// BS_OWNERDRAW 속성을 설정한다
	ModifyStyle(0, BS_OWNERDRAW);

	// 기본 텍스트를 버튼의 캡션으로 설정한다
	GetWindowText(m_strToolTip);

	// 툴팁 컨트롤을 생성한다
	m_wndToolTip.Create(this, TTS_ALWAYSTIP);
	m_wndToolTip.Activate(FALSE);
	m_wndToolTip.AddTool(this, m_strToolTip, m_rcClient, 1);
	m_wndToolTip.Activate(TRUE);

	// 버튼 텍스트로 색상 이름을 설정한다
	CColorPaletteWnd::FindColorName(m_clrSelect, m_strText);

	CButton::PreSubclassWindow();
}

BOOL CColorPickButton::PreTranslateMessage(MSG* pMsg) 
{
	// 툴팁 컨트롤에게 마우스 이벤트를 전달한다
	m_wndToolTip.RelayEvent(pMsg);
	
	return CButton::PreTranslateMessage(pMsg);
}

void CColorPickButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// 인자의 DC 핸들로 CDC 객체를 생성한다
	CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

	// 현재 상태의 버튼을 출력한다
	RedrawButton(pDC, m_clrSelect, m_bPopupWindow || lpDrawItemStruct->itemState & ODS_SELECTED,
		!(lpDrawItemStruct->itemState & ODS_DISABLED));
}

// 버튼 출력 함수
void CColorPickButton::RedrawButton(CDC *pDC, COLORREF clrColor, BOOL bPressed, BOOL bEnable)
{
	// 부드러운 화면 출력을 위해 메모리 DC를 생성하고 더블 버퍼링을 구현한다
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);
	CBitmap MemBmp, *pOldBmp;

	MemBmp.CreateCompatibleBitmap(pDC, m_rcClient.Width(), m_rcClient.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);

	MemDC.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(), pDC, 0, 0, SRCCOPY);

	CRect rcTemp, rcTemp2;
	BOOL bDrawn = FALSE;

	// 만일 테마를 사용하고 있다면
	if(IsAppThemed())
	{
		HTHEME	hTheme = NULL;

		// 버튼 관련 테마 데이터를 연다
		hTheme = OpenThemeData(m_hWnd, L"BUTTON");
		if(hTheme)
		{
			// 현재 버튼의 상태에 따른 속성을 찾는다
			int	iStateId = PBS_NORMAL;
			if(m_bHover)		iStateId = PBS_HOT;
			if(bPressed)		iStateId = PBS_PRESSED;
			if(!bEnable)		iStateId = PBS_DISABLED;

			// 현재 테마로 버튼에 대한 현재 상태의 배경을 그린다
			DrawThemeBackground(hTheme, MemDC.m_hDC, BP_PUSHBUTTON,
				iStateId, &m_rcClient, NULL);

			// 열려진 테마 데이터를 닫는다
			CloseThemeData(hTheme);

			bDrawn = TRUE;
		}
	}

	// 만일 테마를 사용하고 있지 않다면 
	if(!bDrawn)
	{
		// 현재 배경색으로 버튼을 칠한다
		MemDC.FillSolidRect(&m_rcClient, m_clrBkgnd);
	}

	// 만약 마우스가 진입해 있거나 평면 버튼이 아니거나 현재 눌려진 상태라면
	if(m_bHover || !m_bFlat || bPressed)
	{
		// 현재 눌려진 상태라면 
		if(bPressed)
			// 눌려진 모양의 3차원 테두리를 그린다
			MemDC.Draw3dRect(m_rcClient, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DHILIGHT));
		else
			// 튀어나온 모양의 3차원 테두리를 그린다
			MemDC.Draw3dRect(m_rcClient, ::GetSysColor(COLOR_3DHILIGHT), ::GetSysColor(COLOR_3DSHADOW));
	}

	// 색상 출력 박스의 테두리 그리기
	rcTemp = m_rcColor;
	// 만약 현재 버튼이 눌려진 상태라면
	// 색상 출력 박스를 대각선 아래로 1픽셀씩 이동시킨다
	if(bPressed)			rcTemp.OffsetRect(1, 1);
	MemDC.Rectangle(&rcTemp);

	// 현재 색상 출력하기
	rcTemp.DeflateRect(1, 1);
	MemDC.FillSolidRect(&rcTemp, (clrColor == CLR_DEFAULT ? m_clrDefault : clrColor));

	// 텍스트 위치를 임시 저장한다
	rcTemp = m_rcText;

	// 만약 현재 버튼이 눌려진 상태라면
	// 텍스트를 대각선 아래로 1픽셀씩 이동시킨다
	if(bPressed)		rcTemp.OffsetRect(1, 1);

	// 텍스트의 배경을 투명하게 설정한다
	int nBkMode = MemDC.SetBkMode(TRANSPARENT);
	COLORREF clrText;

	// 만약 버튼이 비활성화된 상태라면 회색으로 텍스트 색상을 설정한다
	clrText = MemDC.SetTextColor(bEnable ? m_clrText : RGB(200, 200, 200));

	// 부모 다이얼로그의 폰트를 얻거나 시스템의 폰트를 사용해서 텍스트를 출력한다
	CFont *pFont = GetParent()->GetFont(), *pOldFont;
	if(pFont == NULL)
		pFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pOldFont = MemDC.SelectObject(pFont);

	MemDC.DrawText(m_strText, &rcTemp, DT_LEFT | DT_VCENTER | DT_SINGLELINE);

	MemDC.SelectObject(pOldFont);
	MemDC.SetBkMode(nBkMode);
	MemDC.SetTextColor(clrText);

	// 화살표와 구분자 출력 위치를 임시 저장한다
	rcTemp = m_rcArrow;

	// 만약 현재 버튼이 눌려진 상태라면
	// 화살표와 구분자를 대각선 아래로 1픽셀씩 이동시킨다
	if(bPressed)		rcTemp.OffsetRect(1, 1);

	// 구분자 출력
	rcTemp2			= rcTemp;
	rcTemp2.right	= rcTemp2.left + 3;
	MemDC.DrawEdge(&rcTemp2, EDGE_ETCHED, BF_LEFT);

	// 화살표 출력 위치 계산
	rcTemp2.left	= rcTemp2.right + 1;
	rcTemp2.right	= rcTemp.right;
	rcTemp2.top		= (rcTemp2.bottom + rcTemp2.top) / 2 - 1;
	rcTemp2.bottom	= rcTemp2.top + 2;

	m_ptArrow[0].x = rcTemp2.left;
	m_ptArrow[0].y = rcTemp2.top;
	m_ptArrow[1].x = rcTemp2.right;
	m_ptArrow[1].y = rcTemp2.top;
	m_ptArrow[2].x = (rcTemp2.left + rcTemp2.right) / 2;
	m_ptArrow[2].y = rcTemp2.bottom;

	// 만약 버튼이 비활성화 되어 있다면 회색으로 화살표 색상을 변경한다
	COLORREF clrArrow = bEnable ? RGB(0, 0, 0) : ::GetSysColor(COLOR_GRAYTEXT);
	// 화살표 색상에 따른 브러쉬와 펜을 생성한다
	CBrush brsArrow(clrArrow);
	CPen penArrow(PS_SOLID, 1, clrArrow);

	// 브러쉬와 펜을 설정한다
	CBrush* pOldBrush = MemDC.SelectObject(&brsArrow);
	CPen*   pOldPen   = MemDC.SelectObject(&penArrow);

	// 화살표 모양의 다각형을 그린다
	MemDC.SetPolyFillMode(WINDING);
	MemDC.Polygon(m_ptArrow, 3);

	// 이전 브러쉬와 펜을 복원한다
	MemDC.SelectObject(pOldBrush);
	MemDC.SelectObject(pOldPen);

	// 메모리 DC에 출력된 모든 내용을 화면에 출력한다
	pDC->BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(), &MemDC, 0, 0, SRCCOPY);

	// GDI 객체들을 해제한다
	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
	brsArrow.DeleteObject();
	penArrow.DeleteObject();
}

BOOL CColorPickButton::OnEraseBkgnd(CDC* pDC) 
{
	// 깜빡임을 없애기 위해 배경은 칠하지 않는다
	return TRUE;	
//	return CButton::OnEraseBkgnd(pDC);
}

void CColorPickButton::OnClicked() 
{
	// 만약 이미 팔레트 윈도우가 보이는 상태라면 그냥 리턴한다
	if(m_bPopupWindow)			return;

	// 팔레트 윈도우가 나타난 상태임을 설정한다
	m_bPopupWindow = TRUE;

	// 부모 윈도우가 다시 그려지지 않도록 설정한다
	CWnd* pParent = GetParent();
	if(pParent)		pParent->SetRedraw(FALSE);

	// 팔레트 윈도우를 생성하고 초기화한다
	m_pPaletteWnd = new CColorPaletteWnd;
	if(!m_pPaletteWnd->Init(m_clrSelect, this, m_rcClient.left, m_rcClient.bottom, ID_COLOR_PALETTE_WND))
	{
		// 만약 팔레트 윈도우 생성에 실패하면 부모 윈도우의 다시 그리기를 설정하고 리턴한다
		if(pParent)			pParent->SetRedraw(TRUE);

		delete m_pPaletteWnd;
		m_pPaletteWnd	= NULL;
		m_bPopupWindow	= FALSE;

		return;
	}

	// 만약 부모 윈도우가 존재한다면
	if(pParent)
	{
		// 부모 윈도우를 활성화 상태로 만들고 다시 그리기를 설정한다
		pParent->SendMessage(WM_NCACTIVATE, TRUE, 0);
		pParent->SetRedraw(TRUE);

		// 부모 윈도우에게 팔레트 윈도우가 출력되었음을 알린다
		pParent->SendMessage(CLR_DROPDOWN, (WPARAM)GetDlgCtrlID(), (LPARAM)m_clrSelect);
	}
}

void CColorPickButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// 마우스가 버튼 위에서 이동 중이면,
	// 시스템에게 마우스의 버튼 진입과 탈출에 대한 메시지를 보내줄 것을 요청
	TRACKMOUSEEVENT MouseEvent;
	MouseEvent.cbSize		= sizeof(TRACKMOUSEEVENT);
	MouseEvent.dwFlags		= TME_LEAVE | TME_HOVER;
	MouseEvent.hwndTrack	= m_hWnd;
	MouseEvent.dwHoverTime	= 1;

	::TrackMouseEvent(&MouseEvent);
	
	CButton::OnMouseMove(nFlags, point);
}

LRESULT CColorPickButton::OnMouseHover(WPARAM wParam, LPARAM lParam)
{
	// 마우스가 버튼에 진입했으므로 버튼 다시 그림
	m_bHover = TRUE;
	Invalidate(FALSE);

	return 0;
}

LRESULT CColorPickButton::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	// 마우스가 버튼에서 탈출했으므로 버튼 다시 그림
	m_bHover = FALSE;
	Invalidate(FALSE);

	return 0;
}

// 팔레트 윈도우에서 마우스 이동에 따른 색상 변화 메시지 핸들러
LRESULT CColorPickButton::OnTrackColor(WPARAM wParam, LPARAM lParam)
{
	// 현재 마우스가 위치한 색상의 이름을 얻는다
	CColorPaletteWnd::FindColorName(COLORREF(lParam), m_strText);

	// 버튼을 다시 그린다
	CDC *pDC = GetDC();
	RedrawButton(pDC, COLORREF(lParam), TRUE, IsWindowEnabled());
	ReleaseDC(pDC);

	// 부모 윈도우가 있다면 마우스가 다른 색상으로 이동 중임을 알린다
	CWnd *pParent = GetParent();
	if(pParent)
		pParent->SendMessage(CLR_TRACKCOLOR, (WPARAM)GetDlgCtrlID(), lParam);

	return TRUE;
}

// 팔레트 윈도우에서 색상 선택 메시지 핸들러
LRESULT CColorPickButton::OnSelEndOK(WPARAM wParam, LPARAM lParam)
{
	// 새로 선택된 색상을 멤버 변수에 저장한다
	m_clrSelect = (COLORREF)lParam;

	// 팔레트 윈도우를 제거한다
	if(m_pPaletteWnd)		delete m_pPaletteWnd;
	m_pPaletteWnd	= NULL;
	m_bPopupWindow	= FALSE;

	// 버튼을 다시 그린다
	CDC *pDC = GetDC();
	CColorPaletteWnd::FindColorName(m_clrSelect, m_strText);
	RedrawButton(pDC, m_clrSelect, FALSE, IsWindowEnabled());
	ReleaseDC(pDC);

	// 부모 윈도우에게 색상이 변경되었음을 알린다
	CWnd *pParent = GetParent();
	if(pParent) 
	{
		pParent->SendMessage(CLR_CLOSEUP, (WPARAM)GetDlgCtrlID(), lParam);
		pParent->SendMessage(CLR_SELENDOK, (WPARAM)GetDlgCtrlID(), lParam);
	}

	return TRUE;
}

LRESULT CColorPickButton::OnSelEndCancel(WPARAM wParam, LPARAM lParam)
{
	// 팔레트 윈도우를 제거한다
	if(m_pPaletteWnd)		delete m_pPaletteWnd;
	m_pPaletteWnd	= NULL;
	m_bPopupWindow	= FALSE;

	// 버튼을 다시 그린다
	CDC *pDC = GetDC();
	CColorPaletteWnd::FindColorName(m_clrSelect, m_strText);
	RedrawButton(pDC, m_clrSelect, FALSE, IsWindowEnabled());
	ReleaseDC(pDC);

	// 부모 윈도우에게 색상이 변경되지 않았음을 알린다
	CWnd *pParent = GetParent();
	if(pParent) 
	{
		pParent->SendMessage(CLR_CLOSEUP, (WPARAM)GetDlgCtrlID(), lParam);
		pParent->SendMessage(CLR_SELENDCANCEL, (WPARAM)GetDlgCtrlID(), lParam);
	}

	return TRUE;
}

// 평면 버튼인지 설정하는 함수
void CColorPickButton::SetFlat(BOOL bFlat)
{
	if(m_bFlat == bFlat)		return;

	m_bFlat = bFlat;

	// 만약 현재 버튼이 윈도우라면 새로 그림
	if(::IsWindow(m_hWnd))		Invalidate(FALSE);
}

// 버튼의 툴팁을 설정하는 함수
void CColorPickButton::SetToolTipText(LPCTSTR pTip)
{
	// 툴팁을 저장하고
	m_strToolTip = pTip;

	// 툴팁 컨트롤을 비활성화 시킨 후
	m_wndToolTip.Activate(FALSE);
	// 툴팁을 갱신하고
	m_wndToolTip.UpdateTipText(m_strToolTip, this, 1);
	// 툴팁 컨트롤을 다시 활성화 시킨다
	m_wndToolTip.Activate(TRUE);
}

// 현재 색상을 리턴하는 함수
COLORREF CColorPickButton::GetColor()
{
	// 만약 CLR_DEFAULT면 기본 색상을 리턴한다
	return (m_clrSelect == CLR_DEFAULT)	? m_clrDefault : m_clrSelect;
}

// 현재 색상을 설정하는 함수
void CColorPickButton::SetColor(COLORREF clrColor)
{
	// 새로운 색상을 저장한다
	m_clrSelect = clrColor;

	// 새로운 색상에 대한 색상 이름을 얻는다
	CColorPaletteWnd::FindColorName(m_clrSelect, m_strText);

	// 만약 현재 윈도우라면 화면을 다시 그린다
	if(::IsWindow(m_hWnd))		Invalidate(FALSE);
}

// XP 테마 DLL에 있는 함수들을 호출해주는 함수

// 현재 프로그램에 테마가 적용되어 있는지 확인하는 함수
BOOL CColorPickButton::IsAppThemed()
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef BOOL (__stdcall *LPISAPPTHEMED)();
	LPISAPPTHEMED lpIsAppThemed = (LPISAPPTHEMED)GetProcAddress(m_hThemeDLL, "IsAppThemed");

	if(lpIsAppThemed == NULL)	return FALSE;

	return (*lpIsAppThemed)();
}

// 특정 윈도우에 대한 특정 클래스의 테마 데이터를 오픈하는 함수
HTHEME CColorPickButton::OpenThemeData(HWND hwnd, LPCWSTR pszClassList)
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef HTHEME (__stdcall *LPOPENTHEMEDATA)(HWND hwnd, LPCWSTR pszClassList);
	LPOPENTHEMEDATA lpOpenThemeData = (LPOPENTHEMEDATA)GetProcAddress(m_hThemeDLL, "OpenThemeData");

	if(lpOpenThemeData == NULL)	return FALSE;

	return (*lpOpenThemeData)(hwnd, pszClassList);
}

// 열려진 테마 데이터를 닫는 함수
HRESULT CColorPickButton::CloseThemeData(HTHEME hTheme)
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef BOOL (__stdcall *LPCLOSETHEMEDATA)(HTHEME hTheme);
	LPCLOSETHEMEDATA lpCloseThemeData = (LPCLOSETHEMEDATA)GetProcAddress(m_hThemeDLL, "CloseThemeData");

	if(lpCloseThemeData == NULL)	return FALSE;

	return (*lpCloseThemeData)(hTheme);
}

// 열려진 테마로 배경을 그리는 함수
HRESULT CColorPickButton::DrawThemeBackground(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect)
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef BOOL (__stdcall *LPDRAWTHEMEBACKGROUND)(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect);
	LPDRAWTHEMEBACKGROUND lpDrawThemeBackground = (LPDRAWTHEMEBACKGROUND)GetProcAddress(m_hThemeDLL, "DrawThemeBackground");

	if(lpDrawThemeBackground == NULL)	return FALSE;

	return (*lpDrawThemeBackground)(hTheme, hdc, iPartId, iStateId, pRect, pClipRect);
}
