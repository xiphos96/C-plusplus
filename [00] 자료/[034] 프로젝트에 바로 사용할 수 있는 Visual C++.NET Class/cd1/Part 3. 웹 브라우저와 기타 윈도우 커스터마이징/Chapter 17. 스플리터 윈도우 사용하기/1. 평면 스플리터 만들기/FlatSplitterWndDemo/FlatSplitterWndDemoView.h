// FlatSplitterWndDemoView.h : iCFlatSplitterWndDemoView 클래스의 인터페이스
//


#pragma once


// 메인프레임의 우측 상단 뷰 클래스
class CFlatSplitterWndDemoView : public CView
{
protected: // serialization에서만 만들어집니다.
	CFlatSplitterWndDemoView();
	DECLARE_DYNCREATE(CFlatSplitterWndDemoView)

// 특성
public:
	CFlatSplitterWndDemoDoc* GetDocument() const;

// 작업
public:

// 재정의
	//{{AFX_VIRTUAL(CFlatSplitterWndDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// 구현
public:
	virtual ~CFlatSplitterWndDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 메시지 맵 함수를 생성했습니다.
protected:
	//{{AFX_MSG(CFlatSplitterWndDemoView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // FlatSplitterWndDemoView.cpp의 디버그 버전
inline CFlatSplitterWndDemoDoc* CFlatSplitterWndDemoView::GetDocument() const
   { return reinterpret_cast<CFlatSplitterWndDemoDoc*>(m_pDocument); }
#endif

