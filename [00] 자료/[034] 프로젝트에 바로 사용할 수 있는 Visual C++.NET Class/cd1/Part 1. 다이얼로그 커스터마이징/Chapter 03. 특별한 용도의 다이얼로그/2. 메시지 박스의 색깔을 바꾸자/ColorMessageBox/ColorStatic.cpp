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
	// ���� ������ �������� ����� ĥ�Ѵ�
	GetClientRect(&m_rcClient);

	pDC->FillSolidRect(&m_rcClient, m_clrColor);

	return TRUE;
}

void CColorStatic::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// ����ƽ ��Ʈ���� ����Ŭ���ϸ� �÷� ���̾�α׸� ��� ������ ���� �޴´�
	CColorDialog dlg;

	dlg.m_cc.rgbResult = m_clrColor;

	if(dlg.DoModal() == IDOK)
	{
		// ���õ� ������ �����ϰ� ����� �ٽ� �׸���
		m_clrColor = dlg.GetColor();

		Invalidate();
	}
	
	CStatic::OnLButtonDblClk(nFlags, point);
}
