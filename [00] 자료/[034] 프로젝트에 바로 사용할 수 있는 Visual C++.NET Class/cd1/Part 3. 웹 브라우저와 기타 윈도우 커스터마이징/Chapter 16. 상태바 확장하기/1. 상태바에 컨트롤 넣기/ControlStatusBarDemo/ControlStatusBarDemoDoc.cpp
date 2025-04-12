// ControlStatusBarDemoDoc.cpp : CControlStatusBarDemoDoc 클래스의 구현
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


// CControlStatusBarDemoDoc 생성/소멸

CControlStatusBarDemoDoc::CControlStatusBarDemoDoc()
{
	//{{AFX_DATA_INIT(CControlStatusBarDemoDoc)
	//}}AFX_DATA_INIT
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CControlStatusBarDemoDoc::~CControlStatusBarDemoDoc()
{
}

BOOL CControlStatusBarDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 다시 초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CControlStatusBarDemoDoc serialization

void CControlStatusBarDemoDoc::Serialize(CArchive& ar)
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


// CControlStatusBarDemoDoc 진단

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


// CControlStatusBarDemoDoc 명령
