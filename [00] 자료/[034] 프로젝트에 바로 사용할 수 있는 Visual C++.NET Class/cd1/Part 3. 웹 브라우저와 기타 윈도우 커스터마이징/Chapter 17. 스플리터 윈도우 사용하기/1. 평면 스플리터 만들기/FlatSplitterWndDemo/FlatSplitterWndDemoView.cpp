// FlatSplitterWndDemoView.cpp : CFlatSplitterWndDemoView 클래스의 구현
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CFlatSplitterWndDemoView 생성/소멸

CFlatSplitterWndDemoView::CFlatSplitterWndDemoView()
{
	//{{AFX_DATA_INIT(CFlatSplitterWndDemoView)
	//}}AFX_DATA_INIT
	// TODO: 여기에 생성 코드를 추가합니다.

}

CFlatSplitterWndDemoView::~CFlatSplitterWndDemoView()
{
}

BOOL CFlatSplitterWndDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	// Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CFlatSplitterWndDemoView 그리기

void CFlatSplitterWndDemoView::OnDraw(CDC* /*pDC*/)
{
	CFlatSplitterWndDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CFlatSplitterWndDemoView 인쇄

BOOL CFlatSplitterWndDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CFlatSplitterWndDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CFlatSplitterWndDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CFlatSplitterWndDemoView 진단

#ifdef _DEBUG
void CFlatSplitterWndDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CFlatSplitterWndDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFlatSplitterWndDemoDoc* CFlatSplitterWndDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFlatSplitterWndDemoDoc)));
	return (CFlatSplitterWndDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CFlatSplitterWndDemoView 메시지 처리기
