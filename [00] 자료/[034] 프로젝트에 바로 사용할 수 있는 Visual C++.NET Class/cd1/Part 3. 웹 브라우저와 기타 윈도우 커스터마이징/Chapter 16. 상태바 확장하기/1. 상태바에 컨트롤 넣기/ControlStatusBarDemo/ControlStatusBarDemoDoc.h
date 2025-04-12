// ControlStatusBarDemoDoc.h : CControlStatusBarDemoDoc 클래스의 인터페이스
//


#pragma once

class CControlStatusBarDemoDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CControlStatusBarDemoDoc();
	DECLARE_DYNCREATE(CControlStatusBarDemoDoc)

// 특성
public:

// 작업
public:

// 재정의
	//{{AFX_VIRTUAL(CControlStatusBarDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// 구현
public:
	virtual ~CControlStatusBarDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 메시지 맵 함수를 생성했습니다.
protected:
	//{{AFX_MSG(CControlStatusBarDemoDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


