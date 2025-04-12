// PictureDemoDoc.cpp : CPictureDemoDoc 클래스의 구현
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


// CPictureDemoDoc 생성/소멸

CPictureDemoDoc::CPictureDemoDoc()
{
	//{{AFX_DATA_INIT(CPictureDemoDoc)
	//}}AFX_DATA_INIT
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CPictureDemoDoc::~CPictureDemoDoc()
{
}

BOOL CPictureDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 다시 초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CPictureDemoDoc serialization

void CPictureDemoDoc::Serialize(CArchive& ar)
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


// CPictureDemoDoc 진단

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


// CPictureDemoDoc 명령
