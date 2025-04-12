// RulerSplitterWndDemoView.cpp : CRulerSplitterWndDemoView Ŭ������ ����
//

#include "stdafx.h"
#include "RulerSplitterWndDemo.h"

#include "RulerSplitterWndDemoDoc.h"
#include "RulerSplitterWndDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRulerSplitterWndDemoView

IMPLEMENT_DYNCREATE(CRulerSplitterWndDemoView, CScrollView)

BEGIN_MESSAGE_MAP(CRulerSplitterWndDemoView, CScrollView)
	//{{AFX_MSG_MAP(CRulerSplitterWndDemoView)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRulerSplitterWndDemoView ����/�Ҹ�

CRulerSplitterWndDemoView::CRulerSplitterWndDemoView()
{
	//{{AFX_DATA_INIT(CRulerSplitterWndDemoView)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CRulerSplitterWndDemoView::~CRulerSplitterWndDemoView()
{
}

BOOL CRulerSplitterWndDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	// Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CRulerSplitterWndDemoView �׸���

void CRulerSplitterWndDemoView::OnDraw(CDC* pDC)
{
	CRulerSplitterWndDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CDC BmpDC;
	// ��Ʈ�� DC�� �����Ѵ�
	BmpDC.CreateCompatibleDC(pDC);
	// ���� ������ ��Ʈ���� ��Ʈ�� DC�� �����Ѵ�
	CBitmap *pOldBmp = BmpDC.SelectObject(&GetDocument()->m_Bitmap);

	// ��Ʈ���� ȭ�鿡 ����Ѵ�
	pDC->BitBlt(0, 0, m_ScrollHint.m_nCX, m_ScrollHint.m_nCY, &BmpDC, 0, 0, SRCCOPY);

	// ��Ʈ�� DC���� ���� ��Ʈ���� �����Ѵ�
	BmpDC.SelectObject(pOldBmp);
	// ��Ʈ�� DC�� �Ҹ��Ų��
	BmpDC.DeleteDC();
}


// CRulerSplitterWndDemoView �μ�

BOOL CRulerSplitterWndDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CRulerSplitterWndDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CRulerSplitterWndDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CRulerSplitterWndDemoView ����

#ifdef _DEBUG
void CRulerSplitterWndDemoView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CRulerSplitterWndDemoView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CRulerSplitterWndDemoDoc* CRulerSplitterWndDemoView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRulerSplitterWndDemoDoc)));
	return (CRulerSplitterWndDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CRulerSplitterWndDemoView �޽��� ó����

void CRulerSplitterWndDemoView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();

	// �䰡 �ʱ�ȭ�� �� ������ ��Ʈ�� ������ �д´�
	BITMAP bmpInfo;
	GetDocument()->m_Bitmap.GetBitmap(&bmpInfo);
	// ��Ʈ���� ũ�⸦ ��� ����ü ������ �����Ѵ�
	m_ScrollHint.m_nCX		= bmpInfo.bmWidth;
	m_ScrollHint.m_nCY		= bmpInfo.bmHeight;
	// �ʱ� ��ũ�� ��ġ�� (0, 0)���� �����Ѵ�
	m_ScrollHint.m_nScrollX = 0;
	m_ScrollHint.m_nScrollY = 0;
	// �ʱ� ���콺 ��ġ�� (-1, -1)���� �����Ѵ�
	m_ScrollHint.m_nCursorX	= -1;
	m_ScrollHint.m_nCursorY = -1;

	// ��Ʈ���� ũ�⸸ŭ ��ũ�� ����� �����Ѵ�
	SetScrollSizes(MM_TEXT, CSize(bmpInfo.bmWidth, bmpInfo.bmHeight), sizeDefault, sizeDefault);

	// ������ �信�� ���� ��ũ�� ���� �� ��ġ ������ �˸���
	GetDocument()->UpdateAllViews(this, UPDATE_HSCROLL, &m_ScrollHint);
	// ������ �信�� ���� ��ũ�� ���� �� ��ġ ������ �˸���
	GetDocument()->UpdateAllViews(this, UPDATE_VSCROLL, &m_ScrollHint);
}

// ���� ��ũ�ѽ� ȣ��Ǵ� �Լ�
void CRulerSplitterWndDemoView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// ��ũ�Ѻ��� ��ũ�� ó���� �����Ѵ�
	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);

	// ���� ���� ��ũ�� ��ġ�� ���� ��ũ�� ��ġ�� Ʋ���ٸ�
	if(m_ScrollHint.m_nScrollX != GetScrollPosition().x)
	{
		// ���� ��ũ�� ��ġ�� ����ü ��� ������ �����Ѵ�
		m_ScrollHint.m_nScrollX = GetScrollPosition().x;
		// ������ �信�� ��ũ�� �Ӽ� ������ �˸���
		GetDocument()->UpdateAllViews(this, UPDATE_HSCROLL, &m_ScrollHint);
	}
}

// ���� ��ũ�ѽ� ȣ��Ǵ� �Լ�
void CRulerSplitterWndDemoView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// ��ũ�Ѻ��� ��ũ�� ó���� �����Ѵ�
	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);

	// ���� ���� ��ũ�� ��ġ�� ���� ��ũ�� ��ġ�� Ʋ���ٸ�
	if(m_ScrollHint.m_nScrollY != GetScrollPosition().y)
	{
		// ���� ��ũ�� ��ġ�� ����ü ��� ������ �����Ѵ�
		m_ScrollHint.m_nScrollY = GetScrollPosition().y;
		// ������ �信�� ��ũ�� �Ӽ� ������ �˸���
		GetDocument()->UpdateAllViews(this, UPDATE_VSCROLL, &m_ScrollHint);
	}
}

// ���콺 �̵��� ȣ��Ǵ� �Լ�
void CRulerSplitterWndDemoView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ���ο� ���콺 ��ġ�� ����ü ��� ������ �����Ѵ�
	m_ScrollHint.m_nCursorX = point.x;
	m_ScrollHint.m_nCursorY = point.y;

	// ����/�����ڿ��� Ŀ���� ��ġ�� ����Ǿ����� �˸���
	GetDocument()->UpdateAllViews(this, UPDATA_CURSOR, &m_ScrollHint);
	
	CScrollView::OnMouseMove(nFlags, point);
}
