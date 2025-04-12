// PictureDemoView.h : iCPictureDemoView 클래스의 인터페이스
//


#pragma once

#include "Picture.h"


class CPictureDemoView : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CPictureDemoView();
	DECLARE_DYNCREATE(CPictureDemoView)

// 특성
public:
	CPictureDemoDoc* GetDocument() const;

	CPicture	m_Picture;

// 작업
public:

// 재정의
	//{{AFX_VIRTUAL(CPictureDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// 구현
public:
	virtual ~CPictureDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 메시지 맵 함수를 생성했습니다.
protected:
	//{{AFX_MSG(CPictureDemoView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // PictureDemoView.cpp의 디버그 버전
inline CPictureDemoDoc* CPictureDemoView::GetDocument() const
   { return reinterpret_cast<CPictureDemoDoc*>(m_pDocument); }
#endif

