// FlatSplitterWndDemoDoc.cpp : CFlatSplitterWndDemoDoc 클래스의 구현
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


// CFlatSplitterWndDemoDoc 생성/소멸

CFlatSplitterWndDemoDoc::CFlatSplitterWndDemoDoc()
{
	//{{AFX_DATA_INIT(CFlatSplitterWndDemoDoc)
	//}}AFX_DATA_INIT
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CFlatSplitterWndDemoDoc::~CFlatSplitterWndDemoDoc()
{
}

BOOL CFlatSplitterWndDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 다시 초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CFlatSplitterWndDemoDoc serialization

void CFlatSplitterWndDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// CFlatSplitterWndDemoDoc 진단

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


// CFlatSplitterWndDemoDoc 명령
