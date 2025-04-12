// SectionLine.cpp : implementation file
//

#include "stdafx.h"
#include "sectionlinedemo.h"
#include "SectionLine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSectionLine

// 라인과 텍스트 사이의 여백
#define CONST_ITEM_GAP		6

CSectionLine::CSectionLine()
{
	// 멤버 변수들을 초기화 한다
	m_bHorz			= TRUE;

	m_clrText		= ::GetSysColor(COLOR_BTNTEXT);
	m_clrBkgnd		= ::GetSysColor(COLOR_BTNFACE);
	m_clrHighlight	= ::GetSysColor(COLOR_3DHIGHLIGHT);
	m_clrShadow		= ::GetSysColor(COLOR_3DSHADOW);
}

CSectionLine::~CSectionLine()
{
	m_VertFont.DeleteObject();
}


BEGIN_MESSAGE_MAP(CSectionLine, CStatic)
	//{{AFX_MSG_MAP(CSectionLine)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_ENABLE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_SETTEXT, OnSetText)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSectionLine message handlers

void CSectionLine::PreSubclassWindow() 
{
	// 테두리 속성을 없앤다
	ModifyStyle(WS_BORDER, 0);
	ModifyStyleEx(WS_EX_CLIENTEDGE | WS_EX_STATICEDGE, 0);

	// 현재 스태틱 컨트롤의 폰트를 얻는다
	LOGFONT LogFont;
	CFont *pFont = GetFont();
	// 폰트의 로그 폰트 정보를 얻는다
	pFont->GetLogFont(&LogFont);
	// 폰트를 90도 회전 시킨다
	LogFont.lfEscapement = 900;
	// 세로 텍스트 출력용 폰트를 생성한다
	m_VertFont.CreateFontIndirect(&LogFont);

	// 스태틱의 텍스트를 얻는다
	CString strText;
	GetWindowText(strText);

	// 텍스트에 따른 텍스트 영역과 구분선 영역을 계산한다
	RecalcSectionLine(strText);

	CStatic::PreSubclassWindow();
}

void CSectionLine::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// 스태틱 컨트롤 영역을 배경색으로 칠한다
	CRect rcClient;
	GetClientRect(&rcClient);
	dc.FillSolidRect(rcClient, m_clrBkgnd);

	// 스태틱의 텍스트를 얻는다
	CString strText;
	GetWindowText(strText);

	// 텍스트 배경을 투명하게 설정한다
	dc.SetBkMode(TRANSPARENT);

	CFont *pOldFont;

	// 수평/수직 모드에 따라 폰트를 설정한다
	if(m_bHorz)		pOldFont = dc.SelectObject(GetFont());
	else			pOldFont = dc.SelectObject(&m_VertFont);

	// 텍스트 색상을 설정한다
	COLORREF clrOldText = dc.SetTextColor(m_clrText);

	// 만약 활성화되지 않은 상태라면
	if(!IsWindowEnabled())
	{
		// 밝은 색상으로 텍스트 색상을 설정한다
		dc.SetTextColor(m_clrHighlight);
		// 수평/수직 모드에 따라 다른 함수로 텍스트를 출력한다
		if(m_bHorz)
			dc.DrawText(strText, m_rcText + CPoint(1, 1), DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
		else
			dc.TextOut(m_rcText.left, m_rcText.bottom, strText);
		// 어두운 색상을 텍스트 색상으로 설정한다
		dc.SetTextColor(m_clrShadow);
	}
	// 수평/수직 모드에 따라 다른 함수로 텍스트를 출력한다
	if(m_bHorz)
		dc.DrawText(strText, m_rcText, DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
	else
		dc.TextOut(m_rcText.left, m_rcText.bottom, strText);

	// 만약 왼쪽 구분선의 영역이 설정되어 있다면
	if(!m_rcLineLeft.IsRectEmpty())
		// 왼쪽 구분선을 출력한다
		dc.Draw3dRect(m_rcLineLeft, m_clrShadow, m_clrHighlight);
	// 만약 오른쪽 구분선의 영역이 설정되어 있다면
	if(!m_rcLineRight.IsRectEmpty())
		// 오른쪽 구분선을 출력한다
		dc.Draw3dRect(m_rcLineRight, m_clrShadow, m_clrHighlight);

	// 이전 텍스트 색상과 폰트를 반환한다
	dc.SetTextColor(clrOldText);
	dc.SelectObject(pOldFont);
}

BOOL CSectionLine::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

void CSectionLine::RecalcSectionLine(LPCTSTR pText)
{
	// 클라이언트 영역을 얻는다
	CRect rcClient, rcText;
	GetClientRect(&rcClient);

	// 클라이언트 영역의 폭이 높이보다 크다면 수평 모드로 설정한다
	if(rcClient.Width() > rcClient.Height())	m_bHorz = TRUE;
	else										m_bHorz = FALSE;

	// DC를 얻는다
	CDC *pDC = GetDC();
	CFont *pOldFont;
	
	// 수평/수직 모드에 따라 폰트를 설정한다
	if(m_bHorz)		pOldFont = pDC->SelectObject(GetFont());
	else			pOldFont = pDC->SelectObject(&m_VertFont);

	// 텍스트 출력에 필요한 영역을 계산한다
	rcText.SetRectEmpty();
	pDC->DrawText(pText, -1, &rcText, DT_LEFT | DT_CALCRECT);

	// 이전 폰트로 되돌린다
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	// 기본 영역을 클라이언트 영역으로 설정한다
	m_rcText = m_rcLineLeft = m_rcLineRight= rcClient;

	// 수평 모드라면
	if(m_bHorz)
	{
		// 구분선의 위, 아래 좌표를 계산한다
		m_rcLineLeft.top	= m_rcLineRight.top		= rcClient.Height() / 2 - 1;
		m_rcLineLeft.bottom	= m_rcLineRight.bottom	= m_rcLineRight.top + 2;
	}
	else
	{
		// 텍스트의 좌우측 좌표를 계산한다
		m_rcText.left	= (rcClient.Width() - rcText.Height()) / 2;
		m_rcText.right	= m_rcText.left + rcText.Height();
		// 구분선의 좌우측 좌표를 계산한다
		m_rcLineLeft.left	= m_rcLineRight.left	= rcClient.Width() / 2 - 1;
		m_rcLineLeft.right	= m_rcLineRight.right	= m_rcLineRight.left + 2;
	}

	// 스태틱 컨트롤의 정렬 속성을 얻는다
	DWORD	nAlign = GetStyle() & SS_TYPEMASK;

	// 정렬 속성에 따라 좌표를 계산한다
	switch(nAlign)
	{
	case SS_LEFT :
		// 왼쪽 정렬이라면
		if(m_bHorz)
		{
			m_rcText.right			= rcText.right;
			m_rcLineLeft.SetRectEmpty();
			m_rcLineRight.left		= rcText.right + CONST_ITEM_GAP;
		}
		else
		{
			m_rcText.top			= rcClient.Height() - rcText.Width();
			m_rcLineLeft.SetRectEmpty();
			m_rcLineRight.bottom	= m_rcText.top - CONST_ITEM_GAP;
		}
		break;
	case SS_CENTER :
		// 가운데 정렬이라면
		if(m_bHorz)
		{
			m_rcText.left			= (rcClient.Width() - rcText.Width()) / 2;
			m_rcText.right			= m_rcText.left + rcText.Width();
			m_rcLineLeft.right		= m_rcText.left - CONST_ITEM_GAP;
			m_rcLineRight.left		= m_rcText.right + CONST_ITEM_GAP;
		}
		else
		{
			m_rcText.top			= (rcClient.Height() - rcText.Width()) / 2;
			m_rcText.bottom			= m_rcText.top + rcText.Width();
			m_rcLineLeft.top		= m_rcText.bottom + CONST_ITEM_GAP;
			m_rcLineRight.bottom	= m_rcText.top - CONST_ITEM_GAP; 
		}
		break;
	case SS_RIGHT :
		// 오른쪽 정렬이라면
		if(m_bHorz)
		{
			m_rcText.left			= rcClient.Width() - rcText.Width();
			m_rcLineLeft.right		= m_rcText.left - CONST_ITEM_GAP;
			m_rcLineRight.SetRectEmpty();
		}
		else
		{
			m_rcText.bottom			= rcText.right;
			m_rcLineLeft.top		= m_rcText.bottom + CONST_ITEM_GAP;
			m_rcLineRight.SetRectEmpty();
		}
		break;
	}
}

LONG CSectionLine::OnSetText(WPARAM wParam, LPARAM lParam)
{
	// 기본 텍스트 설정을 실행한다
	Default();

	// 새로운 텍스트에 따른 영역을 계산한다
	RecalcSectionLine(LPCTSTR(lParam));
	// 화면을 다시 그린다
	Invalidate();

	return TRUE;
}

void CSectionLine::OnEnable(BOOL bEnable) 
{
	CStatic::OnEnable(bEnable);

	// 화면을 다시 그린다
	Invalidate();
}

void CSectionLine::OnSize(UINT nType, int cx, int cy) 
{
	CStatic::OnSize(nType, cx, cy);
	
	// 스태틱 컨트롤의 텍스트를 얻는다
	CString strText;
	GetWindowText(strText);

	// 새로운 텍스트에 따른 영역을 계산한다
	RecalcSectionLine(strText);
	// 화면을 다시 그린다
	Invalidate();
}
