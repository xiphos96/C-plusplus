// RulerSplitterWndDemoDoc.cpp : CRulerSplitterWndDemoDoc Ŭ������ ����
//

#include "stdafx.h"
#include "RulerSplitterWndDemo.h"

#include "RulerSplitterWndDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRulerSplitterWndDemoDoc

IMPLEMENT_DYNCREATE(CRulerSplitterWndDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CRulerSplitterWndDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CRulerSplitterWndDemoDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CRulerSplitterWndDemoDoc ����/�Ҹ�

CRulerSplitterWndDemoDoc::CRulerSplitterWndDemoDoc()
{
	//{{AFX_DATA_INIT(CRulerSplitterWndDemoDoc)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CRulerSplitterWndDemoDoc::~CRulerSplitterWndDemoDoc()
{
	// ������ �Ҹ��� �� ��Ʈ�� ��ü�� �Բ� �Ҹ��Ų��
	if(m_Bitmap.m_hObject)		m_Bitmap.DeleteObject();
}

BOOL CRulerSplitterWndDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// ������ ������ ��� ��Ʈ���� �����ϱ� ���� �ڵ�
	CDC dc, BmpDC;
	// ȭ�� DC�� ��´�
	dc.Attach(::GetDC(NULL));
	// ȭ�� DC�� ȣȯ�Ǵ� ��Ʈ�� DC�� �����Ѵ�
	BmpDC.CreateCompatibleDC(&dc);

	// ���� �̹� ��Ʈ�� ��ü�� �ִٸ� �Ҹ��Ų��
	if(m_Bitmap.m_hObject)		m_Bitmap.DeleteObject();
	// ȭ�� DC�� ȣȯ�Ǵ� 1000*1000 ũ���� ��Ʈ���� �����Ѵ�
	m_Bitmap.CreateCompatibleBitmap(&dc, 1000, 1000);

	// ��Ʈ���� ��Ʈ�� DC�� �����Ѵ�
	CBitmap *pOldBmp = BmpDC.SelectObject(&m_Bitmap);
	// ��Ʈ���� �Ͼ������ ĥ�Ѵ�
	BmpDC.FillSolidRect(0, 0, 1000, 1000, RGB(255, 255, 255));
	// ��Ʈ�� DC�� ���� ��Ʈ���� �����Ѵ�
	BmpDC.SelectObject(pOldBmp);

	// ��Ʈ�� DC�� �����Ѵ�
	BmpDC.DeleteDC();
	// ȭ�� DC�� ��ȯ�Ѵ�
	::ReleaseDC(NULL, dc.Detach());

	return TRUE;
}




// CRulerSplitterWndDemoDoc serialization

void CRulerSplitterWndDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}


// CRulerSplitterWndDemoDoc ����

#ifdef _DEBUG
void CRulerSplitterWndDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRulerSplitterWndDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRulerSplitterWndDemoDoc ���

BOOL CRulerSplitterWndDemoDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// ���Ϸκ��� ��Ʈ���� �����Ѵ�
	HBITMAP hBitmap = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			LPCTSTR(lpszPathName), IMAGE_BITMAP,
			0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	// ��Ʈ�� ������ �����ϸ� ����
	if(hBitmap == NULL)			return FALSE;

	// �̹� ��Ʈ�� ��ü�� �ִٸ� �Ҹ��Ų��
	if(m_Bitmap.m_hObject)		m_Bitmap.DeleteObject();

	// ��Ʈ�� ��ü�� ��Ʈ�� �ڵ��� �����Ѵ�
	m_Bitmap.Attach(hBitmap);

	return TRUE;
}
