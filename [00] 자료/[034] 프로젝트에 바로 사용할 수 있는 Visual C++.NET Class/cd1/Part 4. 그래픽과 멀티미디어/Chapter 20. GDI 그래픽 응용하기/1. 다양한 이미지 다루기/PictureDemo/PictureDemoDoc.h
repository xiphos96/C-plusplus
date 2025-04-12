// PictureDemoDoc.h : CPictureDemoDoc 클래스의 인터페이스
//


#pragma once

class CPictureDemoDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CPictureDemoDoc();
	DECLARE_DYNCREATE(CPictureDemoDoc)

// 특성
public:

// 작업
public:

// 재정의
	//{{AFX_VIRTUAL(CPictureDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// 구현
public:
	virtual ~CPictureDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 메시지 맵 함수를 생성했습니다.
protected:
	//{{AFX_MSG(CPictureDemoDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


