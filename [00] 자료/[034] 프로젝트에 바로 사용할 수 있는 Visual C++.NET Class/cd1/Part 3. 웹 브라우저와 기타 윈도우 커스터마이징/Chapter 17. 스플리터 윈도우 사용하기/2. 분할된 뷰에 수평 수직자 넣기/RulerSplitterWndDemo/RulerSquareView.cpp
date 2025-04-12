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

	// 클라이언트 영역을 얻는다
	CRect rcClient;
	GetClientRect(&rcClient);

	CDC MemDC;
	CBitmap MemBmp, *pOldBmp;

	// 메모리 DC를 생성한다
	MemDC.CreateCompatibleDC(pDC);
	// 비트맵을 생성한다
	MemBmp.CreateCompatibleBitmap(pDC, rcClient.Width(), rcClient.Height());
	// 메모리 DC에 비트맵을 설정한다
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// 메모리 DC를 하얀색으로 칠한다
	MemDC.FillSolidRect(&rcClient, RGB(255, 255, 255));

	int i;

	// 포토샵에서와 같이 바닥에서 5픽셀 위에 수평 점선을 그린다
	for(i = rcClient.left + 1; i < rcClient.right; i += 2)
	{
		MemDC.SetPixel(i, rcClient.bottom - 5, RGB(0, 0, 0));
	}
	// 포토샵에서와 같이 오른쪽에서 5픽셀 좌측에 수직 점선을 그린다
	for(i = rcClient.top + 1; i < rcClient.bottom; i += 2)
	{
		MemDC.SetPixel(rcClient.right - 5, i, RGB(0, 0, 0));
	}

	// 메모리 DC의 내용을 화면에 출력한다
	pDC->BitBlt(0, 0, rcClient.Width(), rcClient.Height(), &MemDC, 0, 0, SRCCOPY);

	// 메모리 DC에 이전 비트맵을 설정한다
	MemDC.SelectObject(pOldBmp);
	// 메모리 DC를 소멸시킨다
	MemDC.DeleteDC();
	// 비트매을 소멸시킨다
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
	// 배경을 지우지 않고 리턴한다
	return TRUE;
}
