// MultiEdit.cpp : implementation file
//

#include "stdafx.h"
#include "multieditdemo.h"
#include "MultiEdit.h"
#include ".\multiedit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiEdit

CMultiEdit::CMultiEdit()
{
	// 포커스를 갖고 있지 않을 때의 배경색
	m_clrBkgndNormal	= RGB(220, 220, 220);
	// 포커스를 갖고 있을 때의 배경색
	m_clrBkgndHot		= ::GetSysColor(COLOR_WINDOW);

	// 포커스를 갖고 있지 않을 때의 배경색 브러쉬
	m_brsBkgndNormal.CreateSolidBrush(m_clrBkgndNormal);
	// 포커스를 갖고 있을 때의 배경색 브러쉬
	m_brsBkgndHot.CreateSolidBrush(m_clrBkgndHot);
}

CMultiEdit::~CMultiEdit()
{
	// 브러쉬 객체 소멸
	m_brsBkgndNormal.DeleteObject();
	m_brsBkgndHot.DeleteObject();
}


BEGIN_MESSAGE_MAP(CMultiEdit, CEdit)
	//{{AFX_MSG_MAP(CMultiEdit)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_CONTROL_REFLECT(EN_VSCROLL, OnEnVscroll)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiEdit message handlers

void CMultiEdit::PreSubclassWindow() 
{
	// 멀티라인 속성과 엔터키 입력 속성, 세로 스크롤바 속성을 설정한다
	ModifyStyle(WS_VSCROLL, ES_MULTILINE | ES_WANTRETURN, SWP_FRAMECHANGED);

	// 현재 윈도우의 폰트를 사용해서 글자의 높이를 구한다
	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(GetFont());

	CSize szText = pDC->GetTextExtent("A", 1);
	m_nLineHeight = szText.cy;

	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	// 멤버 변수들을 초기화한다
	m_nLastLine = -1;
	m_bFocus = FALSE;

	GetClientRect(&m_rcClient);

	CEdit::PreSubclassWindow();
}

BOOL CMultiEdit::PreTranslateMessage(MSG* pMsg) 
{
	// 만약 TAB 키가 눌러지면
	// 포커스 이동을 하지 않고 TAB 문자를 입력한다
	if((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == VK_TAB))
	{
		ReplaceSel("\t", TRUE);

		Invalidate(FALSE);

		return TRUE;
	}
	
	return CEdit::PreTranslateMessage(pMsg);
}

// 현재 캐럿이 위치한 라인 번호를 리턴하는 함수
int CMultiEdit::GetLineNo()
{
	// 현재 설정된 블럭을 얻는다
	int nStart, nEnd;
	GetSel(nStart, nEnd);

	// 만약 블럭이 설정되어 있다면
	if(nStart != nEnd)
	{
		CPoint ptEnd, ptCaret;

		// 블럭의 끝 위치에 대한 좌표를 얻는다
		ptEnd = PosFromChar(nEnd);
		// 현재 캐럿의 좌표를 얻는다
		ptCaret = GetCaretPos();

		// 블럭의 끝위치를 얻을 수 없는 경우 - 에디트 컨트롤의 제일 끝 위치에 있는 경우
		// 블럭의 끝 위치를 캐럿 시작 위치로 설정한다
		if(ptEnd.x < 0 && ptEnd.y < 0)	nStart = nEnd;
		// 블럭의 끝 좌표와 캐럿의 좌표가 같을 경우
		// 블럭의 끝 위치를 캐럿 시작 위치로 설정한다
		if(ptEnd.y == ptCaret.y)		nStart = nEnd;
	}

	// 블럭(캐럿)의 시작 위치로부터 라인 번호를 획득하여 리턴한다
	return LineFromChar(nStart);
}

// 특정 라인의 사각 영역을 계산/리턴하는 함수
void CMultiEdit::GetLineRect(int nLine, CRect &rcRect)
{
	// 해당 라인의 첫 문자 위치를 구한다
	int nPos = LineIndex(nLine);

	// 첫 문자의 좌표를 구한다
	CPoint ptLine = PosFromChar(nPos);

	// 만약 좌표가 모두 -1이라면
	// 에디트 컨트롤의 제일 마지막이므로, 현재 캐럿의 좌표를 구한다
	if(ptLine.x < 0 && ptLine.y < 0)
		ptLine = GetCaretPos();

	// 현재 편집 영역을 구한다
	GetRect(&rcRect);
	// y 좌표에 해당하는 top과 bottom만 현재 라인의 위치로 갱신한다
	rcRect.top		= ptLine.y;
	rcRect.bottom	= ptLine.y + m_nLineHeight;
}

void CMultiEdit::OnPaint() 
{
	// 기본적인 에디트 컨트롤의 그리기
	CEdit::OnPaint();
	
	CRect rcLine, rcRect;

	// 현재 캐럿이 있는 라인의 사각 영역을 구한다
	GetRect(&rcRect);
	GetLineRect(m_nLastLine, rcLine);

	// 만약 현재 에디트 컨트롤이 포커스를 갖고 있지 않거나,
	// 현재 보이는 영역 밖에 존재한다면 리턴
	if(!m_bFocus || rcRect.top > rcLine.bottom || rcRect.bottom < rcLine.top)
		return;

	// 캐럿을 화면에서 감춘다
	HideCaret();

	// 반전 효과를 만들기 위해 메모리 버퍼를 생성한다
	CDC *pDC = GetDC();
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	// 현재 라인 영역만큼 메모리 비트맵을 생성한다
	CBitmap LineBmp, *pOldBmp;
	LineBmp.CreateCompatibleBitmap(pDC, rcLine.Width(), rcLine.Height());
	pOldBmp = MemDC.SelectObject(&LineBmp);

	// 비트맵을 파란색으로 칠한다
	rcRect = rcLine;
	rcRect.OffsetRect(-rcLine.left, -rcLine.top);
	MemDC.FillSolidRect(&rcRect, RGB(0, 0, 255));

	// 화면에 반전 시켜 출력한다
	pDC->BitBlt(rcLine.left, rcLine.top, rcLine.Width(), rcLine.Height(),
		&MemDC, 0, 0, SRCINVERT);

	// GDI 객체 반환
	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();
	LineBmp.DeleteObject();

	// 캐럿을 다시 화면에 출력한다
	ShowCaret();
}

void CMultiEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);

	// 키보드가 눌려지면 현재 라인을 반전 시키기 위해 에디트 컨트롤을 다시 그린다
	m_nLastLine = GetLineNo();
	Invalidate(FALSE);
}

void CMultiEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CEdit::OnChar(nChar, nRepCnt, nFlags);

	// 문자가 입력되면 현재 라인을 반전 시키기 위해 에디트 컨트롤을 다시 그린다
	m_nLastLine = GetLineNo();
	Invalidate(FALSE);
}

void CMultiEdit::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CEdit::OnLButtonDown(nFlags, point);

	// 마우스 좌측 버튼이 눌려지면 현재 라인을 반전 시키기 위해 에디트 컨트롤을 다시 그린다
	m_nLastLine = GetLineNo();
	Invalidate(FALSE);
}

void CMultiEdit::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CEdit::OnLButtonUp(nFlags, point);

	// 마우스 좌측 버튼이 떼어지면 현재 라인을 반전 시키기 위해 에디트 컨트롤을 다시 그린다
	m_nLastLine = GetLineNo();
	Invalidate(FALSE);
}

void CMultiEdit::OnMouseMove(UINT nFlags, CPoint point) 
{
	// 만약 마우스 좌측 버튼을 누른 채로 드래깅하는 중이며
	// 현재 포커스를 갖고 있다면
	if(nFlags & MK_LBUTTON && m_bFocus)
	{
		// 현재 라인을 반전 시키기 위해 에디트 컨트롤을 다시 그린다

		m_nLastLine = GetLineNo();
		Invalidate(FALSE);
	}
	
	CEdit::OnMouseMove(nFlags, point);
}

void CMultiEdit::OnEnVscroll()
{
	// 현재 커서가 위치한 라인 번호를 얻는다
	m_nLastLine = GetLineNo();

	// 세로 스크롤바를 보여줘야할지 판단한다
	BOOL bShowVScrollBar = FALSE;
	
	int nFirstLine = GetFirstVisibleLine();

	// 만약 첫번째 보여지는 라인 번호가 0보다 크다면 세로 스크롤바를 보여줘야 한다
	if(nFirstLine > 0)		bShowVScrollBar = TRUE;
	else
	{
		// 에디트 컨트롤의 총 라인 개수를 얻는다
		int nLastLine = GetLineCount();

		// 총 라인 개수가 에디트 컨트롤에서 한번에 보여줄 수 있는 라인 개수보다 많다면 스크롤바를 보여줘야 한다
		if((m_rcClient.Height() / m_nLineHeight) < nLastLine)
			bShowVScrollBar = TRUE;
	}

	// 스크롤바를 보여줘야할지 여부에 따라 스크롤바 속성을 설정하고
	// 에디트 컨트롤의 프레임 영역을 재계산하고 재출력하도록 인자를 설정한다
	if(bShowVScrollBar)		ModifyStyle(0, WS_VSCROLL, SWP_FRAMECHANGED | SWP_DRAWFRAME);
	else					ModifyStyle(WS_VSCROLL, 0, SWP_FRAMECHANGED | SWP_DRAWFRAME);

	// 클라이언트 영역을 다시 얻는다
	GetClientRect(&m_rcClient);
}

void CMultiEdit::OnSetFocus(CWnd* pOldWnd) 
{
	CEdit::OnSetFocus(pOldWnd);

	// 에디트 컨트롤이 포커스를 받으면 화면을 다시 그린다
	m_bFocus = TRUE;
	Invalidate(TRUE);
}

void CMultiEdit::OnKillFocus(CWnd* pNewWnd) 
{
	CEdit::OnKillFocus(pNewWnd);

	// 에디트 컨트롤이 포커스를 잃으면 화면을 다시 그린다
	m_bFocus = FALSE;
	Invalidate(TRUE);
}

HBRUSH CMultiEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// 현재 포커스 여부에 따라 배경을 칠할 브러쉬를 각각 리턴한다
	// 이 브러쉬는 현재까지 입력된 데이터의 영역에 대해 출력된다
	if(m_bFocus)		return m_brsBkgndHot;
	else				return m_brsBkgndNormal;
}

BOOL CMultiEdit::OnEraseBkgnd(CDC* pDC) 
{
	BOOL bRet = CEdit::OnEraseBkgnd(pDC);

	// 현재 포커스 여부에 따라 배경을 칠한다
	// 여기서 칠하는 배경은 데이터 영역 이외에 효과가 있다
	if(m_bFocus)	pDC->FillSolidRect(&m_rcClient, m_clrBkgndHot);
	else			pDC->FillSolidRect(&m_rcClient, m_clrBkgndNormal);

	return bRet;
}
