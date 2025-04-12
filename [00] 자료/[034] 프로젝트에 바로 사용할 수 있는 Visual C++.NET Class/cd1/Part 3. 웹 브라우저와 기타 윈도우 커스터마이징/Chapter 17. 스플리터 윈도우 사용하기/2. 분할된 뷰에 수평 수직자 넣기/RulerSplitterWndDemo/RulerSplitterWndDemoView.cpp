// RulerSplitterWndDemoView.cpp : CRulerSplitterWndDemoView 클래스의 구현
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

// CRulerSplitterWndDemoView 생성/소멸

CRulerSplitterWndDemoView::CRulerSplitterWndDemoView()
{
	//{{AFX_DATA_INIT(CRulerSplitterWndDemoView)
	//}}AFX_DATA_INIT
	// TODO: 여기에 생성 코드를 추가합니다.

}

CRulerSplitterWndDemoView::~CRulerSplitterWndDemoView()
{
}

BOOL CRulerSplitterWndDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	// Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CRulerSplitterWndDemoView 그리기

void CRulerSplitterWndDemoView::OnDraw(CDC* pDC)
{
	CRulerSplitterWndDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CDC BmpDC;
	// 비트맵 DC를 생성한다
	BmpDC.CreateCompatibleDC(pDC);
	// 현재 문서의 비트맵을 비트맵 DC에 설정한다
	CBitmap *pOldBmp = BmpDC.SelectObject(&GetDocument()->m_Bitmap);

	// 비트맵을 화면에 출력한다
	pDC->BitBlt(0, 0, m_ScrollHint.m_nCX, m_ScrollHint.m_nCY, &BmpDC, 0, 0, SRCCOPY);

	// 비트맵 DC에게 이전 비트맵을 설정한다
	BmpDC.SelectObject(pOldBmp);
	// 비트맵 DC를 소멸시킨다
	BmpDC.DeleteDC();
}


// CRulerSplitterWndDemoView 인쇄

BOOL CRulerSplitterWndDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CRulerSplitterWndDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CRulerSplitterWndDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CRulerSplitterWndDemoView 진단

#ifdef _DEBUG
void CRulerSplitterWndDemoView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CRulerSplitterWndDemoView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CRulerSplitterWndDemoDoc* CRulerSplitterWndDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRulerSplitterWndDemoDoc)));
	return (CRulerSplitterWndDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CRulerSplitterWndDemoView 메시지 처리기

void CRulerSplitterWndDemoView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();

	// 뷰가 초기화될 때 문서의 비트맵 정보를 읽는다
	BITMAP bmpInfo;
	GetDocument()->m_Bitmap.GetBitmap(&bmpInfo);
	// 비트맵의 크기를 멤버 구조체 변수에 저장한다
	m_ScrollHint.m_nCX		= bmpInfo.bmWidth;
	m_ScrollHint.m_nCY		= bmpInfo.bmHeight;
	// 초기 스크롤 위치를 (0, 0)으로 설정한다
	m_ScrollHint.m_nScrollX = 0;
	m_ScrollHint.m_nScrollY = 0;
	// 초기 마우스 위치를 (-1, -1)으로 설정한다
	m_ScrollHint.m_nCursorX	= -1;
	m_ScrollHint.m_nCursorY = -1;

	// 비트맵의 크기만큼 스크롤 사이즈를 설정한다
	SetScrollSizes(MM_TEXT, CSize(bmpInfo.bmWidth, bmpInfo.bmHeight), sizeDefault, sizeDefault);

	// 수평자 뷰에게 수평 스크롤 범위 및 위치 변경을 알린다
	GetDocument()->UpdateAllViews(this, UPDATE_HSCROLL, &m_ScrollHint);
	// 수직자 뷰에게 수직 스크롤 범위 및 위치 변경을 알린다
	GetDocument()->UpdateAllViews(this, UPDATE_VSCROLL, &m_ScrollHint);
}

// 수평 스크롤시 호출되는 함수
void CRulerSplitterWndDemoView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// 스크롤뷰의 스크롤 처리를 실행한다
	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);

	// 만약 이전 스크롤 위치와 현재 스크롤 위치가 틀리다면
	if(m_ScrollHint.m_nScrollX != GetScrollPosition().x)
	{
		// 수평 스크롤 위치를 구조체 멤버 변수에 저장한다
		m_ScrollHint.m_nScrollX = GetScrollPosition().x;
		// 수평자 뷰에게 스크롤 속성 변경을 알린다
		GetDocument()->UpdateAllViews(this, UPDATE_HSCROLL, &m_ScrollHint);
	}
}

// 수직 스크롤시 호출되는 함수
void CRulerSplitterWndDemoView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// 스크롤뷰의 스크롤 처리를 실행한다
	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);

	// 만약 이전 스크롤 위치와 현재 스크롤 위치가 틀리다면
	if(m_ScrollHint.m_nScrollY != GetScrollPosition().y)
	{
		// 수직 스크롤 위치를 구조체 멤버 변수에 저장한다
		m_ScrollHint.m_nScrollY = GetScrollPosition().y;
		// 수직자 뷰에게 스크롤 속성 변경을 알린다
		GetDocument()->UpdateAllViews(this, UPDATE_VSCROLL, &m_ScrollHint);
	}
}

// 마우스 이동시 호출되는 함수
void CRulerSplitterWndDemoView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// 새로운 마우스 위치를 구조체 멤버 변수에 저장한다
	m_ScrollHint.m_nCursorX = point.x;
	m_ScrollHint.m_nCursorY = point.y;

	// 수직/수평자에게 커서의 위치가 변경되었음을 알린다
	GetDocument()->UpdateAllViews(this, UPDATA_CURSOR, &m_ScrollHint);
	
	CScrollView::OnMouseMove(nFlags, point);
}
