// ControlStatusBarDemoView.h : iCControlStatusBarDemoView 클래스의 인터페이스
//


#pragma once


class CControlStatusBarDemoView : public CView
{
protected: // serialization에서만 만들어집니다.
	CControlStatusBarDemoView();
	DECLARE_DYNCREATE(CControlStatusBarDemoView)

// 특성
public:
	CControlStatusBarDemoDoc* GetDocument() const;

// 작업
public:

// 재정의
	//{{AFX_VIRTUAL(CControlStatusBarDemoView)
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
	virtual ~CControlStatusBarDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 메시지 맵 함수를 생성했습니다.
protected:
	//{{AFX_MSG(CControlStatusBarDemoView)
	//}}AFX_MSG
	afx_msg void OnStatusButton();
	afx_msg void OnStatusCheck();
	afx_msg void OnUpdateStatic(CCmdUI* pCmdUI);
	afx_msg void OnUpdateProgress(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ControlStatusBarDemoView.cpp의 디버그 버전
inline CControlStatusBarDemoDoc* CControlStatusBarDemoView::GetDocument() const
   { return reinterpret_cast<CControlStatusBarDemoDoc*>(m_pDocument); }
#endif

