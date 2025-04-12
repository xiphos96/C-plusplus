// RulerSplitterWndDemoDoc.h : CRulerSplitterWndDemoDoc 클래스의 인터페이스
//


#pragma once

class CRulerSplitterWndDemoDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CRulerSplitterWndDemoDoc();
	DECLARE_DYNCREATE(CRulerSplitterWndDemoDoc)

// 특성
public:
	// 현재 편집 중인 문서의 비트맵 객체
	CBitmap		m_Bitmap;

// 작업
public:

// 재정의
	//{{AFX_VIRTUAL(CRulerSplitterWndDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// 구현
public:
	virtual ~CRulerSplitterWndDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 메시지 맵 함수를 생성했습니다.
protected:
	//{{AFX_MSG(CRulerSplitterWndDemoDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


