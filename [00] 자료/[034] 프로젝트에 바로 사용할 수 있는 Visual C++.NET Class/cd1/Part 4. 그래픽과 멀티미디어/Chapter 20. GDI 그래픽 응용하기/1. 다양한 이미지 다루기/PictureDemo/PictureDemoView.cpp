// PictureDemoView.cpp : CPictureDemoView Ŭ������ ����
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPictureDemoView ����/�Ҹ�

CPictureDemoView::CPictureDemoView()
{
	//{{AFX_DATA_INIT(CPictureDemoView)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CPictureDemoView::~CPictureDemoView()
{
}

BOOL CPictureDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	// Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CPictureDemoView �׸���

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


// CPictureDemoView �μ�

BOOL CPictureDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CPictureDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CPictureDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CPictureDemoView ����

#ifdef _DEBUG
void CPictureDemoView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPictureDemoView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CPictureDemoDoc* CPictureDemoView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPictureDemoDoc)));
	return (CPictureDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CPictureDemoView �޽��� ó����
