// PictureDemoView.cpp : CPictureDemoView 클래스의 구현
//

#include "stdafx.h"
#include "PictureDemo.h"

#include "PictureDemoDoc.h"
#include "PictureDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPictureDemoView

IMPLEMENT_DYNCREATE(CPictureDemoView, CScrollView)

BEGIN_MESSAGE_MAP(CPictureDemoView, CScrollView)
	//{{AFX_MSG_MAP(CPictureDemoView)
	//}}AFX_MSG_MAP
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPictureDemoView 생성/소멸

CPictureDemoView::CPictureDemoView()
{
	//{{AFX_DATA_INIT(CPictureDemoView)
	//}}AFX_DATA_INIT
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPictureDemoView::~CPictureDemoView()
{
}

BOOL CPictureDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	// Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CPictureDemoView 그리기

void CPictureDemoView::OnDraw(CDC* pDC)
{
	CPictureDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	m_Picture.Draw(pDC);
}

void CPictureDemoView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal(0, 0);
	CString strFileName = GetDocument()->GetPathName();

	if(!strFileName.IsEmpty())
	{
		if(m_Picture.Load(strFileName))
		{
			sizeTotal.cx = m_Picture.GetWidth();
			sizeTotal.cy = m_Picture.GetHeight();
		}
	}
	else
	{
		if(m_Picture.Load(IDR_JPEG_RESOURCE, "JPEG"))
		{
			sizeTotal.cx = m_Picture.GetWidth();
			sizeTotal.cy = m_Picture.GetHeight();
		}
	}

	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CPictureDemoView 인쇄

BOOL CPictureDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPictureDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPictureDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPictureDemoView 진단

#ifdef _DEBUG
void CPictureDemoView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPictureDemoView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CPictureDemoDoc* CPictureDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPictureDemoDoc)));
	return (CPictureDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CPictureDemoView 메시지 처리기
