// FlatSplitterWndDemoDoc.cpp : CFlatSplitterWndDemoDoc Ŭ������ ����
//

#include "stdafx.h"
#include "FlatSplitterWndDemo.h"

#include "FlatSplitterWndDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFlatSplitterWndDemoDoc

IMPLEMENT_DYNCREATE(CFlatSplitterWndDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CFlatSplitterWndDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CFlatSplitterWndDemoDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CFlatSplitterWndDemoDoc ����/�Ҹ�

CFlatSplitterWndDemoDoc::CFlatSplitterWndDemoDoc()
{
	//{{AFX_DATA_INIT(CFlatSplitterWndDemoDoc)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CFlatSplitterWndDemoDoc::~CFlatSplitterWndDemoDoc()
{
}

BOOL CFlatSplitterWndDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ �ٽ� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CFlatSplitterWndDemoDoc serialization

void CFlatSplitterWndDemoDoc::Serialize(CArchive& ar)
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


// CFlatSplitterWndDemoDoc ����

#ifdef _DEBUG
void CFlatSplitterWndDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFlatSplitterWndDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFlatSplitterWndDemoDoc ���
