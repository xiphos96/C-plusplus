// ControlStatusBarDemoDoc.cpp : CControlStatusBarDemoDoc Ŭ������ ����
//

#include "stdafx.h"
#include "ControlStatusBarDemo.h"

#include "ControlStatusBarDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CControlStatusBarDemoDoc

IMPLEMENT_DYNCREATE(CControlStatusBarDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CControlStatusBarDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CControlStatusBarDemoDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CControlStatusBarDemoDoc ����/�Ҹ�

CControlStatusBarDemoDoc::CControlStatusBarDemoDoc()
{
	//{{AFX_DATA_INIT(CControlStatusBarDemoDoc)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CControlStatusBarDemoDoc::~CControlStatusBarDemoDoc()
{
}

BOOL CControlStatusBarDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ �ٽ� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CControlStatusBarDemoDoc serialization

void CControlStatusBarDemoDoc::Serialize(CArchive& ar)
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


// CControlStatusBarDemoDoc ����

#ifdef _DEBUG
void CControlStatusBarDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CControlStatusBarDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CControlStatusBarDemoDoc ���
