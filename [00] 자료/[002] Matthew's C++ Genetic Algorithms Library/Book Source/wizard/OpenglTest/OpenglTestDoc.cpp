// OpenglTestDoc.cpp : implementation of the COpenglTestDoc class
//

#include "stdafx.h"
#include "OpenglTest.h"

#include "OpenglTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenglTestDoc

IMPLEMENT_DYNCREATE(COpenglTestDoc, CDocument)

BEGIN_MESSAGE_MAP(COpenglTestDoc, CDocument)
	//{{AFX_MSG_MAP(COpenglTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenglTestDoc construction/destruction

COpenglTestDoc::COpenglTestDoc()
{
	// TODO: add one-time construction code here

}

COpenglTestDoc::~COpenglTestDoc()
{
}

BOOL COpenglTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// COpenglTestDoc serialization

void COpenglTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// COpenglTestDoc diagnostics

#ifdef _DEBUG
void COpenglTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COpenglTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenglTestDoc commands
