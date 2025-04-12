// ColorStatic.cpp : implementation file
//

#include "stdafx.h"
#include "colormessagebox.h"
#include "ColorStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorStatic

CColorStatic::CColorStatic()
{
	m_clrColor = RGB(255, 255, 255);
}

CColorStatic::~CColorStatic()
{
}


BEGIN_MESSAGE_MAP(CColorStatic, CStatic)
	//{{AFX_MSG_MAP(CColorStatic)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorStatic message handlers

BOOL CColorStatic::OnEraseBkgnd(CDC* pDC) 
{
	// 현재 설정된 색상으로 배경을 칠한다
	GetClientRect(&m_rcClient);

	pDC->FillSolidRect(&m_rcClient, m_clrColor);

	return TRUE;
}

void CColorStatic::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// 스태틱 컨트롤을 더블클릭하면 컬러 다이얼로그를 띄워 색상을 선택 받는다
	CColorDialog dlg;

	dlg.m_cc.rgbResult = m_clrColor;

	if(dlg.DoModal() == IDOK)
	{
		// 선택된 색상을 저장하고 배경을 다시 그린다
		m_clrColor = dlg.GetColor();

		Invalidate();
	}
	
	CStatic::OnLButtonDblClk(nFlags, point);
}
