// FlatSplitterWndDemoView.cpp : CFlatSplitterWndDemoView Ŭ������ ����
//

#include "stdafx.h"
#include "FlatSplitterWndDemo.h"

#include "FlatSplitterWndDemoDoc.h"
#include "FlatSplitterWndDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFlatSplitterWndDemoView

IMPLEMENT_DYNCREATE(CFlatSplitterWndDemoView, CView)

BEGIN_MESSAGE_MAP(CFlatSplitterWndDemoView, CView)
	//{{AFX_MSG_MAP(CFlatSplitterWndDemoView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CFlatSplitterWndDemoView ����/�Ҹ�

CFlatSplitterWndDemoView::CFlatSplitterWndDemoView()
{
	//{{AFX_DATA_INIT(CFlatSplitterWndDemoView)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CFlatSplitterWndDemoView::~CFlatSplitterWndDemoView()
{
}

BOOL CFlatSplitterWndDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	// Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CFlatSplitterWndDemoView �׸���

void CFlatSplitterWndDemoView::OnDraw(CDC* /*pDC*/)
{
	CFlatSplitterWndDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CFlatSplitterWndDemoView �μ�

BOOL CFlatSplitterWndDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CFlatSplitterWndDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CFlatSplitterWndDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CFlatSplitterWndDemoView ����

#ifdef _DEBUG
void CFlatSplitterWndDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CFlatSplitterWndDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFlatSplitterWndDemoDoc* CFlatSplitterWndDemoView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFlatSplitterWndDemoDoc)));
	return (CFlatSplitterWndDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CFlatSplitterWndDemoView �޽��� ó����
