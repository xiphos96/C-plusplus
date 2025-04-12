// BottomView.cpp : implementation file
//

#include "stdafx.h"
#include "flatsplitterwnddemo.h"
#include "BottomView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBottomView

IMPLEMENT_DYNCREATE(CBottomView, CView)

CBottomView::CBottomView()
{
}

CBottomView::~CBottomView()
{
}


BEGIN_MESSAGE_MAP(CBottomView, CView)
	//{{AFX_MSG_MAP(CBottomView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBottomView drawing

void CBottomView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CBottomView diagnostics

#ifdef _DEBUG
void CBottomView::AssertValid() const
{
	CView::AssertValid();
}

void CBottomView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBottomView message handlers
