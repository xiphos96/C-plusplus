#if !defined(AFX_RULERSQUAREVIEW_H__70A3A9B7_CB1E_42B9_9037_FC2A42D7B456__INCLUDED_)
#define AFX_RULERSQUAREVIEW_H__70A3A9B7_CB1E_42B9_9037_FC2A42D7B456__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RulerSquareView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRulerSquareView view

// 화면 좌상단의 여백 출력용 뷰 클래스
class CRulerSquareView : public CView
{
protected:
	CRulerSquareView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CRulerSquareView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRulerSquareView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CRulerSquareView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CRulerSquareView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULERSQUAREVIEW_H__70A3A9B7_CB1E_42B9_9037_FC2A42D7B456__INCLUDED_)
