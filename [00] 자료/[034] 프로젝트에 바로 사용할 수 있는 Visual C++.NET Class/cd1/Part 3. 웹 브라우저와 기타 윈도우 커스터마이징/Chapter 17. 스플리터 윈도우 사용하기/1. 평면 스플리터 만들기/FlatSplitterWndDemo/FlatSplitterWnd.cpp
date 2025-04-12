// FlatSplitterWnd.cpp : implementation file
//

#include "stdafx.h"
#include "flatsplitterwnddemo.h"
#include "FlatSplitterWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlatSplitterWnd

// 기본 평면 스플리터의 두께/테두리 상수를 정의한다
#define CONST_SPLITTER_THICK			8
#define CONST_SPLITTER_GAP				CONST_SPLITTER_THICK
#define CONST_SPLITTER_BORDER			1
#define CONST_SPLITTER_BORDER_SHARE		0

IMPLEMENT_DYNCREATE(CFlatSplitterWnd, CSplitterWnd)

CFlatSplitterWnd::CFlatSplitterWnd()
{
	// CSplitterWnd의 멤버 변수에 기본 값을 설정한다
	m_cxSplitter	= m_cySplitter		= CONST_SPLITTER_THICK;
	m_cxSplitterGap = m_cySplitterGap	= CONST_SPLITTER_GAP;
	m_cxBorder		= m_cyBorder		= CONST_SPLITTER_BORDER;
	m_cxBorderShare = m_cyBorderShare	= CONST_SPLITTER_BORDER_SHARE;
}

CFlatSplitterWnd::~CFlatSplitterWnd()
{
}

BEGIN_MESSAGE_MAP(CFlatSplitterWnd, CSplitterWnd)
	//{{AFX_MSG_MAP(CFlatSplitterWnd)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlatSplitterWnd message handlers

// 스플리터의 두께를 설정하는 함수
void CFlatSplitterWnd::SetSplitterThick(int nHorz, int nVert)
{
	if(nHorz < 2 || nVert < 2)		return;

	// 새로운 수직 스플리터 너비를 설정한다
	m_cxSplitter	= m_cxSplitterGap	= nHorz;
	// 새로운 수평 스플리터 높이를 설정한다
	m_cySplitter	= m_cySplitterGap	= nVert;

	// 스플리터 영역을 다시 계산한다
	RecalcLayout();

	// 스플리터를 다시 그린다
	Invalidate(FALSE);
}

// 스플리터 윈도우를 그리는 함수
void CFlatSplitterWnd::OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect)
{
	// 만약 테두리를 그리기 위해 호출되지 않았거나 pDC가 NULL일 경우 CSplitterWnd의 기본 함수를 실행한다
	if((nType != splitBorder) || (pDC == NULL))
	{
		CSplitterWnd::OnDrawSplitter(pDC, nType, rect);
		return;
	}

	// 1픽셀의 3차원 테두리를 출력한다
	pDC->Draw3dRect(rect, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DHILIGHT));
}
