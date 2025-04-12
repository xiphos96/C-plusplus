// RulerSquareView.cpp : implementation file
//

#include "stdafx.h"
#include "rulersplitterwnddemo.h"
#include "RulerSquareView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRulerSquareView

IMPLEMENT_DYNCREATE(CRulerSquareView, CView)

CRulerSquareView::CRulerSquareView()
{
}

CRulerSquareView::~CRulerSquareView()
{
}


BEGIN_MESSAGE_MAP(CRulerSquareView, CView)
	//{{AFX_MSG_MAP(CRulerSquareView)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRulerSquareView drawing

void CRulerSquareView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();

	// Ŭ���̾�Ʈ ������ ��´�
	CRect rcClient;
	GetClientRect(&rcClient);

	CDC MemDC;
	CBitmap MemBmp, *pOldBmp;

	// �޸� DC�� �����Ѵ�
	MemDC.CreateCompatibleDC(pDC);
	// ��Ʈ���� �����Ѵ�
	MemBmp.CreateCompatibleBitmap(pDC, rcClient.Width(), rcClient.Height());
	// �޸� DC�� ��Ʈ���� �����Ѵ�
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// �޸� DC�� �Ͼ������ ĥ�Ѵ�
	MemDC.FillSolidRect(&rcClient, RGB(255, 255, 255));

	int i;

	// ���伥������ ���� �ٴڿ��� 5�ȼ� ���� ���� ������ �׸���
	for(i = rcClient.left + 1; i < rcClient.right; i += 2)
	{
		MemDC.SetPixel(i, rcClient.bottom - 5, RGB(0, 0, 0));
	}
	// ���伥������ ���� �����ʿ��� 5�ȼ� ������ ���� ������ �׸���
	for(i = rcClient.top + 1; i < rcClient.bottom; i += 2)
	{
		MemDC.SetPixel(rcClient.right - 5, i, RGB(0, 0, 0));
	}

	// �޸� DC�� ������ ȭ�鿡 ����Ѵ�
	pDC->BitBlt(0, 0, rcClient.Width(), rcClient.Height(), &MemDC, 0, 0, SRCCOPY);

	// �޸� DC�� ���� ��Ʈ���� �����Ѵ�
	MemDC.SelectObject(pOldBmp);
	// �޸� DC�� �Ҹ��Ų��
	MemDC.DeleteDC();
	// ��Ʈ���� �Ҹ��Ų��
	MemBmp.DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CRulerSquareView diagnostics

#ifdef _DEBUG
void CRulerSquareView::AssertValid() const
{
	CView::AssertValid();
}

void CRulerSquareView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRulerSquareView message handlers

BOOL CRulerSquareView::OnEraseBkgnd(CDC* pDC) 
{
	// ����� ������ �ʰ� �����Ѵ�
	return TRUE;
}
