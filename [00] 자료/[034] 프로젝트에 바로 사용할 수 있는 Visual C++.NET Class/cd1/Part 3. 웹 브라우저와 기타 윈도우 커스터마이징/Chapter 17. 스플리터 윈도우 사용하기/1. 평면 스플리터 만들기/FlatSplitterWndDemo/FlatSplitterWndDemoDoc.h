// FlatSplitterWndDemoDoc.h : CFlatSplitterWndDemoDoc 클래스의 인터페이스
//


#pragma once

class CFlatSplitterWndDemoDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CFlatSplitterWndDemoDoc();
	DECLARE_DYNCREATE(CFlatSplitterWndDemoDoc)

// 특성
public:

// 작업
public:

// 재정의
	//{{AFX_VIRTUAL(CFlatSplitterWndDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// 구현
public:
	virtual ~CFlatSplitterWndDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 메시지 맵 함수를 생성했습니다.
protected:
	//{{AFX_MSG(CFlatSplitterWndDemoDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


