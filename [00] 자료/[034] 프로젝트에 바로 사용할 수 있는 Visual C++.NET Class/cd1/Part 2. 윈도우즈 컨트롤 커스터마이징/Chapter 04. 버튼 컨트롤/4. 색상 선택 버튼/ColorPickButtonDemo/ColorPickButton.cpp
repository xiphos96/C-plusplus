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

// �׸� DLL�� ���õ� ���� �������� �ʱ�ȭ�Ѵ�
HMODULE		CColorPickButton::m_hThemeDLL	= NULL;
int			CColorPickButton::m_nCount		= 0;


CColorPickButton::CColorPickButton()
{
	// ���� �׸� DLL�� �ε����� �ʾҴٸ� �ε��Ѵ�
	if(m_hThemeDLL == NULL)
		m_hThemeDLL = ::LoadLibrary(_T("UxTheme.dll"));

	// ī��Ʈ�� 1 ������Ų��
	m_nCount++;

	// �� �������� �⺻ ���� �����Ѵ�
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
	// ī��Ʈ�� 1 ���� ��Ų��
	m_nCount--;

	// ���� ������ ���̻� ���� �׸� DLL�� �ε�Ǿ� �ִٸ� �����Ѵ�
	if(m_nCount == 0 && m_hThemeDLL)
	{
		::FreeLibrary(m_hThemeDLL);
		m_hThemeDLL = NULL;
	}

	// ���� �ȷ�Ʈ �����찡 ���� �ִٸ� �����Ѵ�
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
	// ���� ��ư�� ũ�⸦ �����Ѵ�
	GetClientRect(&m_rcClient);

	// ���� ��ư ũ�⿡�� ����, ���� �̸�, ȭ��ǥ�� ��� ��ġ�� ����Ѵ�
	CRect rcTemp = m_rcClient;
	rcTemp.DeflateRect(5, 5);

	m_rcColor = rcTemp;
	m_rcColor.right = m_rcColor.left + rcTemp.Height();

	m_rcArrow = rcTemp;
	m_rcArrow.left = m_rcArrow.right - 8;

	m_rcText = rcTemp;
	m_rcText.left = m_rcColor.right + 4;
	m_rcText.right = m_rcArrow.left - 2;
	
	// BS_OWNERDRAW �Ӽ��� �����Ѵ�
	ModifyStyle(0, BS_OWNERDRAW);

	// �⺻ �ؽ�Ʈ�� ��ư�� ĸ������ �����Ѵ�
	GetWindowText(m_strToolTip);

	// ���� ��Ʈ���� �����Ѵ�
	m_wndToolTip.Create(this, TTS_ALWAYSTIP);
	m_wndToolTip.Activate(FALSE);
	m_wndToolTip.AddTool(this, m_strToolTip, m_rcClient, 1);
	m_wndToolTip.Activate(TRUE);

	// ��ư �ؽ�Ʈ�� ���� �̸��� �����Ѵ�
	CColorPaletteWnd::FindColorName(m_clrSelect, m_strText);

	CButton::PreSubclassWindow();
}

BOOL CColorPickButton::PreTranslateMessage(MSG* pMsg) 
{
	// ���� ��Ʈ�ѿ��� ���콺 �̺�Ʈ�� �����Ѵ�
	m_wndToolTip.RelayEvent(pMsg);
	
	return CButton::PreTranslateMessage(pMsg);
}

void CColorPickButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// ������ DC �ڵ�� CDC ��ü�� �����Ѵ�
	CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

	// ���� ������ ��ư�� ����Ѵ�
	RedrawButton(pDC, m_clrSelect, m_bPopupWindow || lpDrawItemStruct->itemState & ODS_SELECTED,
		!(lpDrawItemStruct->itemState & ODS_DISABLED));
}

// ��ư ��� �Լ�
void CColorPickButton::RedrawButton(CDC *pDC, COLORREF clrColor, BOOL bPressed, BOOL bEnable)
{
	// �ε巯�� ȭ�� ����� ���� �޸� DC�� �����ϰ� ���� ���۸��� �����Ѵ�
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);
	CBitmap MemBmp, *pOldBmp;

	MemBmp.CreateCompatibleBitmap(pDC, m_rcClient.Width(), m_rcClient.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);

	MemDC.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(), pDC, 0, 0, SRCCOPY);

	CRect rcTemp, rcTemp2;
	BOOL bDrawn = FALSE;

	// ���� �׸��� ����ϰ� �ִٸ�
	if(IsAppThemed())
	{
		HTHEME	hTheme = NULL;

		// ��ư ���� �׸� �����͸� ����
		hTheme = OpenThemeData(m_hWnd, L"BUTTON");
		if(hTheme)
		{
			// ���� ��ư�� ���¿� ���� �Ӽ��� ã�´�
			int	iStateId = PBS_NORMAL;
			if(m_bHover)		iStateId = PBS_HOT;
			if(bPressed)		iStateId = PBS_PRESSED;
			if(!bEnable)		iStateId = PBS_DISABLED;

			// ���� �׸��� ��ư�� ���� ���� ������ ����� �׸���
			DrawThemeBackground(hTheme, MemDC.m_hDC, BP_PUSHBUTTON,
				iStateId, &m_rcClient, NULL);

			// ������ �׸� �����͸� �ݴ´�
			CloseThemeData(hTheme);

			bDrawn = TRUE;
		}
	}

	// ���� �׸��� ����ϰ� ���� �ʴٸ� 
	if(!bDrawn)
	{
		// ���� �������� ��ư�� ĥ�Ѵ�
		MemDC.FillSolidRect(&m_rcClient, m_clrBkgnd);
	}

	// ���� ���콺�� ������ �ְų� ��� ��ư�� �ƴϰų� ���� ������ ���¶��
	if(m_bHover || !m_bFlat || bPressed)
	{
		// ���� ������ ���¶�� 
		if(bPressed)
			// ������ ����� 3���� �׵θ��� �׸���
			MemDC.Draw3dRect(m_rcClient, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DHILIGHT));
		else
			// Ƣ��� ����� 3���� �׵θ��� �׸���
			MemDC.Draw3dRect(m_rcClient, ::GetSysColor(COLOR_3DHILIGHT), ::GetSysColor(COLOR_3DSHADOW));
	}

	// ���� ��� �ڽ��� �׵θ� �׸���
	rcTemp = m_rcColor;
	// ���� ���� ��ư�� ������ ���¶��
	// ���� ��� �ڽ��� �밢�� �Ʒ��� 1�ȼ��� �̵���Ų��
	if(bPressed)			rcTemp.OffsetRect(1, 1);
	MemDC.Rectangle(&rcTemp);

	// ���� ���� ����ϱ�
	rcTemp.DeflateRect(1, 1);
	MemDC.FillSolidRect(&rcTemp, (clrColor == CLR_DEFAULT ? m_clrDefault : clrColor));

	// �ؽ�Ʈ ��ġ�� �ӽ� �����Ѵ�
	rcTemp = m_rcText;

	// ���� ���� ��ư�� ������ ���¶��
	// �ؽ�Ʈ�� �밢�� �Ʒ��� 1�ȼ��� �̵���Ų��
	if(bPressed)		rcTemp.OffsetRect(1, 1);

	// �ؽ�Ʈ�� ����� �����ϰ� �����Ѵ�
	int nBkMode = MemDC.SetBkMode(TRANSPARENT);
	COLORREF clrText;

	// ���� ��ư�� ��Ȱ��ȭ�� ���¶�� ȸ������ �ؽ�Ʈ ������ �����Ѵ�
	clrText = MemDC.SetTextColor(bEnable ? m_clrText : RGB(200, 200, 200));

	// �θ� ���̾�α��� ��Ʈ�� ��ų� �ý����� ��Ʈ�� ����ؼ� �ؽ�Ʈ�� ����Ѵ�
	CFont *pFont = GetParent()->GetFont(), *pOldFont;
	if(pFont == NULL)
		pFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pOldFont = MemDC.SelectObject(pFont);

	MemDC.DrawText(m_strText, &rcTemp, DT_LEFT | DT_VCENTER | DT_SINGLELINE);

	MemDC.SelectObject(pOldFont);
	MemDC.SetBkMode(nBkMode);
	MemDC.SetTextColor(clrText);

	// ȭ��ǥ�� ������ ��� ��ġ�� �ӽ� �����Ѵ�
	rcTemp = m_rcArrow;

	// ���� ���� ��ư�� ������ ���¶��
	// ȭ��ǥ�� �����ڸ� �밢�� �Ʒ��� 1�ȼ��� �̵���Ų��
	if(bPressed)		rcTemp.OffsetRect(1, 1);

	// ������ ���
	rcTemp2			= rcTemp;
	rcTemp2.right	= rcTemp2.left + 3;
	MemDC.DrawEdge(&rcTemp2, EDGE_ETCHED, BF_LEFT);

	// ȭ��ǥ ��� ��ġ ���
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

	// ���� ��ư�� ��Ȱ��ȭ �Ǿ� �ִٸ� ȸ������ ȭ��ǥ ������ �����Ѵ�
	COLORREF clrArrow = bEnable ? RGB(0, 0, 0) : ::GetSysColor(COLOR_GRAYTEXT);
	// ȭ��ǥ ���� ���� �귯���� ���� �����Ѵ�
	CBrush brsArrow(clrArrow);
	CPen penArrow(PS_SOLID, 1, clrArrow);

	// �귯���� ���� �����Ѵ�
	CBrush* pOldBrush = MemDC.SelectObject(&brsArrow);
	CPen*   pOldPen   = MemDC.SelectObject(&penArrow);

	// ȭ��ǥ ����� �ٰ����� �׸���
	MemDC.SetPolyFillMode(WINDING);
	MemDC.Polygon(m_ptArrow, 3);

	// ���� �귯���� ���� �����Ѵ�
	MemDC.SelectObject(pOldBrush);
	MemDC.SelectObject(pOldPen);

	// �޸� DC�� ��µ� ��� ������ ȭ�鿡 ����Ѵ�
	pDC->BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(), &MemDC, 0, 0, SRCCOPY);

	// GDI ��ü���� �����Ѵ�
	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
	brsArrow.DeleteObject();
	penArrow.DeleteObject();
}

BOOL CColorPickButton::OnEraseBkgnd(CDC* pDC) 
{
	// �������� ���ֱ� ���� ����� ĥ���� �ʴ´�
	return TRUE;	
//	return CButton::OnEraseBkgnd(pDC);
}

void CColorPickButton::OnClicked() 
{
	// ���� �̹� �ȷ�Ʈ �����찡 ���̴� ���¶�� �׳� �����Ѵ�
	if(m_bPopupWindow)			return;

	// �ȷ�Ʈ �����찡 ��Ÿ�� �������� �����Ѵ�
	m_bPopupWindow = TRUE;

	// �θ� �����찡 �ٽ� �׷����� �ʵ��� �����Ѵ�
	CWnd* pParent = GetParent();
	if(pParent)		pParent->SetRedraw(FALSE);

	// �ȷ�Ʈ �����츦 �����ϰ� �ʱ�ȭ�Ѵ�
	m_pPaletteWnd = new CColorPaletteWnd;
	if(!m_pPaletteWnd->Init(m_clrSelect, this, m_rcClient.left, m_rcClient.bottom, ID_COLOR_PALETTE_WND))
	{
		// ���� �ȷ�Ʈ ������ ������ �����ϸ� �θ� �������� �ٽ� �׸��⸦ �����ϰ� �����Ѵ�
		if(pParent)			pParent->SetRedraw(TRUE);

		delete m_pPaletteWnd;
		m_pPaletteWnd	= NULL;
		m_bPopupWindow	= FALSE;

		return;
	}

	// ���� �θ� �����찡 �����Ѵٸ�
	if(pParent)
	{
		// �θ� �����츦 Ȱ��ȭ ���·� ����� �ٽ� �׸��⸦ �����Ѵ�
		pParent->SendMessage(WM_NCACTIVATE, TRUE, 0);
		pParent->SetRedraw(TRUE);

		// �θ� �����쿡�� �ȷ�Ʈ �����찡 ��µǾ����� �˸���
		pParent->SendMessage(CLR_DROPDOWN, (WPARAM)GetDlgCtrlID(), (LPARAM)m_clrSelect);
	}
}

void CColorPickButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ���콺�� ��ư ������ �̵� ���̸�,
	// �ý��ۿ��� ���콺�� ��ư ���԰� Ż�⿡ ���� �޽����� ������ ���� ��û
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
	// ���콺�� ��ư�� ���������Ƿ� ��ư �ٽ� �׸�
	m_bHover = TRUE;
	Invalidate(FALSE);

	return 0;
}

LRESULT CColorPickButton::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	// ���콺�� ��ư���� Ż�������Ƿ� ��ư �ٽ� �׸�
	m_bHover = FALSE;
	Invalidate(FALSE);

	return 0;
}

// �ȷ�Ʈ �����쿡�� ���콺 �̵��� ���� ���� ��ȭ �޽��� �ڵ鷯
LRESULT CColorPickButton::OnTrackColor(WPARAM wParam, LPARAM lParam)
{
	// ���� ���콺�� ��ġ�� ������ �̸��� ��´�
	CColorPaletteWnd::FindColorName(COLORREF(lParam), m_strText);

	// ��ư�� �ٽ� �׸���
	CDC *pDC = GetDC();
	RedrawButton(pDC, COLORREF(lParam), TRUE, IsWindowEnabled());
	ReleaseDC(pDC);

	// �θ� �����찡 �ִٸ� ���콺�� �ٸ� �������� �̵� ������ �˸���
	CWnd *pParent = GetParent();
	if(pParent)
		pParent->SendMessage(CLR_TRACKCOLOR, (WPARAM)GetDlgCtrlID(), lParam);

	return TRUE;
}

// �ȷ�Ʈ �����쿡�� ���� ���� �޽��� �ڵ鷯
LRESULT CColorPickButton::OnSelEndOK(WPARAM wParam, LPARAM lParam)
{
	// ���� ���õ� ������ ��� ������ �����Ѵ�
	m_clrSelect = (COLORREF)lParam;

	// �ȷ�Ʈ �����츦 �����Ѵ�
	if(m_pPaletteWnd)		delete m_pPaletteWnd;
	m_pPaletteWnd	= NULL;
	m_bPopupWindow	= FALSE;

	// ��ư�� �ٽ� �׸���
	CDC *pDC = GetDC();
	CColorPaletteWnd::FindColorName(m_clrSelect, m_strText);
	RedrawButton(pDC, m_clrSelect, FALSE, IsWindowEnabled());
	ReleaseDC(pDC);

	// �θ� �����쿡�� ������ ����Ǿ����� �˸���
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
	// �ȷ�Ʈ �����츦 �����Ѵ�
	if(m_pPaletteWnd)		delete m_pPaletteWnd;
	m_pPaletteWnd	= NULL;
	m_bPopupWindow	= FALSE;

	// ��ư�� �ٽ� �׸���
	CDC *pDC = GetDC();
	CColorPaletteWnd::FindColorName(m_clrSelect, m_strText);
	RedrawButton(pDC, m_clrSelect, FALSE, IsWindowEnabled());
	ReleaseDC(pDC);

	// �θ� �����쿡�� ������ ������� �ʾ����� �˸���
	CWnd *pParent = GetParent();
	if(pParent) 
	{
		pParent->SendMessage(CLR_CLOSEUP, (WPARAM)GetDlgCtrlID(), lParam);
		pParent->SendMessage(CLR_SELENDCANCEL, (WPARAM)GetDlgCtrlID(), lParam);
	}

	return TRUE;
}

// ��� ��ư���� �����ϴ� �Լ�
void CColorPickButton::SetFlat(BOOL bFlat)
{
	if(m_bFlat == bFlat)		return;

	m_bFlat = bFlat;

	// ���� ���� ��ư�� �������� ���� �׸�
	if(::IsWindow(m_hWnd))		Invalidate(FALSE);
}

// ��ư�� ������ �����ϴ� �Լ�
void CColorPickButton::SetToolTipText(LPCTSTR pTip)
{
	// ������ �����ϰ�
	m_strToolTip = pTip;

	// ���� ��Ʈ���� ��Ȱ��ȭ ��Ų ��
	m_wndToolTip.Activate(FALSE);
	// ������ �����ϰ�
	m_wndToolTip.UpdateTipText(m_strToolTip, this, 1);
	// ���� ��Ʈ���� �ٽ� Ȱ��ȭ ��Ų��
	m_wndToolTip.Activate(TRUE);
}

// ���� ������ �����ϴ� �Լ�
COLORREF CColorPickButton::GetColor()
{
	// ���� CLR_DEFAULT�� �⺻ ������ �����Ѵ�
	return (m_clrSelect == CLR_DEFAULT)	? m_clrDefault : m_clrSelect;
}

// ���� ������ �����ϴ� �Լ�
void CColorPickButton::SetColor(COLORREF clrColor)
{
	// ���ο� ������ �����Ѵ�
	m_clrSelect = clrColor;

	// ���ο� ���� ���� ���� �̸��� ��´�
	CColorPaletteWnd::FindColorName(m_clrSelect, m_strText);

	// ���� ���� �������� ȭ���� �ٽ� �׸���
	if(::IsWindow(m_hWnd))		Invalidate(FALSE);
}

// XP �׸� DLL�� �ִ� �Լ����� ȣ�����ִ� �Լ�

// ���� ���α׷��� �׸��� ����Ǿ� �ִ��� Ȯ���ϴ� �Լ�
BOOL CColorPickButton::IsAppThemed()
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef BOOL (__stdcall *LPISAPPTHEMED)();
	LPISAPPTHEMED lpIsAppThemed = (LPISAPPTHEMED)GetProcAddress(m_hThemeDLL, "IsAppThemed");

	if(lpIsAppThemed == NULL)	return FALSE;

	return (*lpIsAppThemed)();
}

// Ư�� �����쿡 ���� Ư�� Ŭ������ �׸� �����͸� �����ϴ� �Լ�
HTHEME CColorPickButton::OpenThemeData(HWND hwnd, LPCWSTR pszClassList)
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef HTHEME (__stdcall *LPOPENTHEMEDATA)(HWND hwnd, LPCWSTR pszClassList);
	LPOPENTHEMEDATA lpOpenThemeData = (LPOPENTHEMEDATA)GetProcAddress(m_hThemeDLL, "OpenThemeData");

	if(lpOpenThemeData == NULL)	return FALSE;

	return (*lpOpenThemeData)(hwnd, pszClassList);
}

// ������ �׸� �����͸� �ݴ� �Լ�
HRESULT CColorPickButton::CloseThemeData(HTHEME hTheme)
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef BOOL (__stdcall *LPCLOSETHEMEDATA)(HTHEME hTheme);
	LPCLOSETHEMEDATA lpCloseThemeData = (LPCLOSETHEMEDATA)GetProcAddress(m_hThemeDLL, "CloseThemeData");

	if(lpCloseThemeData == NULL)	return FALSE;

	return (*lpCloseThemeData)(hTheme);
}

// ������ �׸��� ����� �׸��� �Լ�
HRESULT CColorPickButton::DrawThemeBackground(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect)
{
	if(m_hThemeDLL == NULL)		return FALSE;

	typedef BOOL (__stdcall *LPDRAWTHEMEBACKGROUND)(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect);
	LPDRAWTHEMEBACKGROUND lpDrawThemeBackground = (LPDRAWTHEMEBACKGROUND)GetProcAddress(m_hThemeDLL, "DrawThemeBackground");

	if(lpDrawThemeBackground == NULL)	return FALSE;

	return (*lpDrawThemeBackground)(hTheme, hdc, iPartId, iStateId, pRect, pClipRect);
}
