// RulerSplitterWndDemoDoc.cpp : CRulerSplitterWndDemoDoc 클래스의 구현
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


// CRulerSplitterWndDemoDoc 생성/소멸

CRulerSplitterWndDemoDoc::CRulerSplitterWndDemoDoc()
{
	//{{AFX_DATA_INIT(CRulerSplitterWndDemoDoc)
	//}}AFX_DATA_INIT
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CRulerSplitterWndDemoDoc::~CRulerSplitterWndDemoDoc()
{
	// 문서가 소멸할 때 비트맵 객체도 함께 소멸시킨다
	if(m_Bitmap.m_hObject)		m_Bitmap.DeleteObject();
}

BOOL CRulerSplitterWndDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// 새문서 생성시 흰색 비트맵을 생성하기 위한 코드
	CDC dc, BmpDC;
	// 화면 DC를 얻는다
	dc.Attach(::GetDC(NULL));
	// 화면 DC와 호환되는 비트맵 DC를 생성한다
	BmpDC.CreateCompatibleDC(&dc);

	// 만약 이미 비트맵 객체가 있다면 소멸시킨다
	if(m_Bitmap.m_hObject)		m_Bitmap.DeleteObject();
	// 화면 DC와 호환되는 1000*1000 크기의 비트맵을 생성한다
	m_Bitmap.CreateCompatibleBitmap(&dc, 1000, 1000);

	// 비트맵을 비트맵 DC에 설정한다
	CBitmap *pOldBmp = BmpDC.SelectObject(&m_Bitmap);
	// 비트맵을 하얀색으로 칠한다
	BmpDC.FillSolidRect(0, 0, 1000, 1000, RGB(255, 255, 255));
	// 비트맵 DC에 이전 비트맵을 설정한다
	BmpDC.SelectObject(pOldBmp);

	// 비트맵 DC를 제거한다
	BmpDC.DeleteDC();
	// 화면 DC를 반환한다
	::ReleaseDC(NULL, dc.Detach());

	return TRUE;
}




// CRulerSplitterWndDemoDoc serialization

void CRulerSplitterWndDemoDoc::Serialize(CArchive& ar)
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


// CRulerSplitterWndDemoDoc 진단

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


// CRulerSplitterWndDemoDoc 명령

BOOL CRulerSplitterWndDemoDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// 파일로부터 비트맵을 생성한다
	HBITMAP hBitmap = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			LPCTSTR(lpszPathName), IMAGE_BITMAP,
			0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	// 비트맵 생성에 실패하면 리턴
	if(hBitmap == NULL)			return FALSE;

	// 이미 비트맵 객체가 있다면 소멸시킨다
	if(m_Bitmap.m_hObject)		m_Bitmap.DeleteObject();

	// 비트맵 객체에 비트맵 핸들을 설정한다
	m_Bitmap.Attach(hBitmap);

	return TRUE;
}
