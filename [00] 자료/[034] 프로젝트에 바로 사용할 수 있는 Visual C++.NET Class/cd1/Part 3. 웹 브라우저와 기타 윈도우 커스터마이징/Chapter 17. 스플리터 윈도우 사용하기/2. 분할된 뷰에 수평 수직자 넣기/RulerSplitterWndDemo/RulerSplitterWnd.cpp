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

// ������ �β��� ���ϴ� ���
#define CONST_RULER_THICK		15

CRulerSplitterWnd::CRulerSplitterWnd()
{
	// ���ø����� �β��� 1�� �����Ѵ�
	m_cxSplitter	= m_cySplitter		= 1;
	// ��� �� ������ ������ 1�� �����Ѵ�
	m_cxSplitterGap = m_cySplitterGap	= 1;
	// ���� �׵θ��� 0���� �����Ѵ�
	m_cxBorder		= m_cyBorder		= 0;
	// ���� ���� ������ 0���� �����Ѵ�
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

// ����/������ ������ ���� ������ ���� �Լ�
BOOL CRulerSplitterWnd::CreateRulerSplitter(CWnd *pFrame, CRuntimeClass *pView, CCreateContext* pContext)
{
	// �������� 2�� 2���� �����Ѵ�
	if(!CreateStatic(pFrame, 2, 2))
	{
		TRACE("Failed to create splitter wnd\n");
		return FALSE;
	}

	// �»�ܿ� CRulerSquareView �並 �����Ѵ�
	if(!CreateView(0, 0, RUNTIME_CLASS(CRulerSquareView), CSize(CONST_RULER_THICK, CONST_RULER_THICK), pContext))
	{
		TRACE("Failed to create square\n");
		return FALSE;
	}
	// ���ܿ� CRulerView ������ �並 �����Ѵ�
	if(!CreateView(0, 1, RUNTIME_CLASS(CRulerView), CSize(0, CONST_RULER_THICK), pContext))
	{
		TRACE("Failed to create top ruler\n");
		return FALSE;
	}
	// ���ϴܿ� CRulerView ������ �並 �����Ѵ�
	if(!CreateView(1, 0, RUNTIME_CLASS(CRulerView), CSize(CONST_RULER_THICK, 0), pContext))
	{
		TRACE("Failed to create left ruler\n");
		return FALSE;
	}
	// ���ϴܿ� CRulerSplitterWndDemoView ���� �並 �����Ѵ� 
	if(!CreateView(1, 1, pView, CSize(0,0), pContext))
	{
		TRACE("Failed to create main view\n");
		return FALSE;
	}

	// ��ܰ� ������ ���ε��� �β��� ����/������ �β��� �����Ѵ�
	SetColumnInfo(0, CONST_RULER_THICK, 0);
	SetRowInfo(0, CONST_RULER_THICK, 0);

	// ���� �信�� ������ ���� �����Ѵ�
	((CRulerView*)GetPane(0, 1))->SetDirection(TRUE);
	// ���ϴ� �信�� ������ ���� �����Ѵ�
	((CRulerView*)GetPane(1, 0))->SetDirection(FALSE);

	return TRUE;
}

// ���ø����� �̵��� ���� ���� ���콺 ��Ʈ �׽�Ʈ �Լ�
int CRulerSplitterWnd::HitTest(CPoint pt) const
{
	// ���ø��͸� �̵��� �� ������ 0�� �����Ѵ�
	return 0;
}

// ���ø��� �����츦 �׸��� �Լ�
void CRulerSplitterWnd::OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect)
{
	// ���� �׵θ��� �׸��� ���� ȣ����� �ʾҰų� pDC�� NULL�� ��� CSplitterWnd�� �⺻ �Լ��� �����Ѵ�
	if((nType != splitBorder) || (pDC == NULL))
	{
		CSplitterWnd::OnDrawSplitter(pDC, nType, rect);
		return;
	}

	// ���� ����̶��
	if(rect.left == 0)
	{
		// ������ ���� ���� ����Ѵ�
		pDC->MoveTo(rect.right, rect.top);
		pDC->LineTo(rect.right, rect.bottom);
	}
	// ��� ����̶��
	if(rect.top == 0)
	{
		// �Ʒ��� ���� ���� ����Ѵ�
		pDC->MoveTo(rect.left, rect.bottom);
		pDC->LineTo(rect.right, rect.bottom);
	}
}
