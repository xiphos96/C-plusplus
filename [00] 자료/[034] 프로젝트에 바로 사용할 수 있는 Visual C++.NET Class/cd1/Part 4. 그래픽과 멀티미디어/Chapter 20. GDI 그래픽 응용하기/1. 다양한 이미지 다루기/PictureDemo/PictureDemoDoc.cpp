// PictureDemoDoc.cpp : CPictureDemoDoc Ŭ������ ����
//

#include "stdafx.h"
#include "PictureDemo.h"

#include "PictureDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPictureDemoDoc

IMPLEMENT_DYNCREATE(CPictureDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CPictureDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CPictureDemoDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CPictureDemoDoc ����/�Ҹ�

CPictureDemoDoc::CPictureDemoDoc()
{
	//{{AFX_DATA_INIT(CPictureDemoDoc)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CPictureDemoDoc::~CPictureDemoDoc()
{
}

BOOL CPictureDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ �ٽ� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CPictureDemoDoc serialization

void CPictureDemoDoc::Serialize(CArchive& ar)
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


// CPictureDemoDoc ����

#ifdef _DEBUG
void CPictureDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPictureDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPictureDemoDoc ���
