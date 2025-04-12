// RulerSplitterWnd.cpp : implementation file
//

#include "stdafx.h"
#include "rulersplitterwnddemo.h"
#include "RulerSplitterWnd.h"

#include "RulerSquareView.h"
#include "RulerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRulerSplitterWnd

// 줄자의 두께를 정하는 상수
#define CONST_RULER_THICK		15

CRulerSplitterWnd::CRulerSplitterWnd()
{
	// 스플리터의 두께를 1로 설정한다
	m_cxSplitter	= m_cySplitter		= 1;
	// 뷰와 뷰 사이의 간격을 1로 설정한다
	m_cxSplitterGap = m_cySplitterGap	= 1;
	// 뷰의 테두리를 0으로 설정한다
	m_cxBorder		= m_cyBorder		= 0;
	// 뷰의 공유 공간을 0으로 설정한다
	m_cxBorderShare = m_cyBorderShare	= 0;
}

CRulerSplitterWnd::~CRulerSplitterWnd()
{
}


BEGIN_MESSAGE_MAP(CRulerSplitterWnd, CSplitterWnd)
	//{{AFX_MSG_MAP(CRulerSplitterWnd)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CRulerSplitterWnd message handlers

// 수평/수직자 구현을 위한 프레임 분할 함수
BOOL CRulerSplitterWnd::CreateRulerSplitter(CWnd *pFrame, CRuntimeClass *pView, CCreateContext* pContext)
{
	// 프레임을 2행 2열로 분할한다
	if(!CreateStatic(pFrame, 2, 2))
	{
		TRACE("Failed to create splitter wnd\n");
		return FALSE;
	}

	// 좌상단에 CRulerSquareView 뷰를 생성한다
	if(!CreateView(0, 0, RUNTIME_CLASS(CRulerSquareView), CSize(CONST_RULER_THICK, CONST_RULER_THICK), pContext))
	{
		TRACE("Failed to create square\n");
		return FALSE;
	}
	// 우상단에 CRulerView 수평자 뷰를 생성한다
	if(!CreateView(0, 1, RUNTIME_CLASS(CRulerView), CSize(0, CONST_RULER_THICK), pContext))
	{
		TRACE("Failed to create top ruler\n");
		return FALSE;
	}
	// 좌하단에 CRulerView 수직자 뷰를 생성한다
	if(!CreateView(1, 0, RUNTIME_CLASS(CRulerView), CSize(CONST_RULER_THICK, 0), pContext))
	{
		TRACE("Failed to create left ruler\n");
		return FALSE;
	}
	// 우하단에 CRulerSplitterWndDemoView 메인 뷰를 생성한다 
	if(!CreateView(1, 1, pView, CSize(0,0), pContext))
	{
		TRACE("Failed to create main view\n");
		return FALSE;
	}

	// 상단과 좌측의 페인들의 두께를 수평/수직자 두께로 설정한다
	SetColumnInfo(0, CONST_RULER_THICK, 0);
	SetRowInfo(0, CONST_RULER_THICK, 0);

	// 우상단 뷰에게 수평자 임을 설정한다
	((CRulerView*)GetPane(0, 1))->SetDirection(TRUE);
	// 좌하단 뷰에게 수직자 임을 설정한다
	((CRulerView*)GetPane(1, 0))->SetDirection(FALSE);

	return TRUE;
}

// 스플리터의 이동을 막기 위한 마우스 히트 테스트 함수
int CRulerSplitterWnd::HitTest(CPoint pt) const
{
	// 스플리터를 이동할 수 없도록 0을 리턴한다
	return 0;
}

// 스플리터 윈도우를 그리는 함수
void CRulerSplitterWnd::OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect)
{
	// 만약 테두리를 그리기 위해 호출되지 않았거나 pDC가 NULL일 경우 CSplitterWnd의 기본 함수를 실행한다
	if((nType != splitBorder) || (pDC == NULL))
	{
		CSplitterWnd::OnDrawSplitter(pDC, nType, rect);
		return;
	}

	// 좌측 뷰들이라면
	if(rect.left == 0)
	{
		// 오른쪽 변에 선을 출력한다
		pDC->MoveTo(rect.right, rect.top);
		pDC->LineTo(rect.right, rect.bottom);
	}
	// 상단 뷰들이라면
	if(rect.top == 0)
	{
		// 아래쪽 변에 선을 출력한다
		pDC->MoveTo(rect.left, rect.bottom);
		pDC->LineTo(rect.right, rect.bottom);
	}
}
