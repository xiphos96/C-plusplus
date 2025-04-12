// RulerSplitterWndDemoView.h : iCRulerSplitterWndDemoView 클래스의 인터페이스
//


#pragma once

// 수평/수직자 구현 스플리터 윈도우 클래스 헤더
#include "RulerSplitterWnd.h"

class CRulerSplitterWndDemoView : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CRulerSplitterWndDemoView();
	DECLARE_DYNCREATE(CRulerSplitterWndDemoView)

// 특성
public:
	CRulerSplitterWndDemoDoc* GetDocument() const;

	// 수평/수직자에게 메인 뷰의 스크롤과 커서 위치를 알리기 위한 구조체 변수
	CScrollHint			m_ScrollHint;

// 작업
public:

// 재정의
	//{{AFX_VIRTUAL(CRulerSplitterWndDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현
public:
	virtual ~CRulerSplitterWndDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 메시지 맵 함수를 생성했습니다.
protected:
	//{{AFX_MSG(CRulerSplitterWndDemoView)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // RulerSplitterWndDemoView.cpp의 디버그 버전
inline CRulerSplitterWndDemoDoc* CRulerSplitterWndDemoView::GetDocument() const
   { return reinterpret_cast<CRulerSplitterWndDemoDoc*>(m_pDocument); }
#endif

