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

// �⺻ ��� ���ø����� �β�/�׵θ� ����� �����Ѵ�
#define CONST_SPLITTER_THICK			8
#define CONST_SPLITTER_GAP				CONST_SPLITTER_THICK
#define CONST_SPLITTER_BORDER			1
#define CONST_SPLITTER_BORDER_SHARE		0

IMPLEMENT_DYNCREATE(CFlatSplitterWnd, CSplitterWnd)

CFlatSplitterWnd::CFlatSplitterWnd()
{
	// CSplitterWnd�� ��� ������ �⺻ ���� �����Ѵ�
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

// ���ø����� �β��� �����ϴ� �Լ�
void CFlatSplitterWnd::SetSplitterThick(int nHorz, int nVert)
{
	if(nHorz < 2 || nVert < 2)		return;

	// ���ο� ���� ���ø��� �ʺ� �����Ѵ�
	m_cxSplitter	= m_cxSplitterGap	= nHorz;
	// ���ο� ���� ���ø��� ���̸� �����Ѵ�
	m_cySplitter	= m_cySplitterGap	= nVert;

	// ���ø��� ������ �ٽ� ����Ѵ�
	RecalcLayout();

	// ���ø��͸� �ٽ� �׸���
	Invalidate(FALSE);
}

// ���ø��� �����츦 �׸��� �Լ�
void CFlatSplitterWnd::OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect)
{
	// ���� �׵θ��� �׸��� ���� ȣ����� �ʾҰų� pDC�� NULL�� ��� CSplitterWnd�� �⺻ �Լ��� �����Ѵ�
	if((nType != splitBorder) || (pDC == NULL))
	{
		CSplitterWnd::OnDrawSplitter(pDC, nType, rect);
		return;
	}

	// 1�ȼ��� 3���� �׵θ��� ����Ѵ�
	pDC->Draw3dRect(rect, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DHILIGHT));
}
