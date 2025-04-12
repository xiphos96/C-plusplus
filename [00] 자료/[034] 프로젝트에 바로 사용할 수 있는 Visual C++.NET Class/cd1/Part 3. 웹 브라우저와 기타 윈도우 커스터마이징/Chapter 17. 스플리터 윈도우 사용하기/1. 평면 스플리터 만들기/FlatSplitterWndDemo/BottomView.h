#if !defined(AFX_BOTTOMVIEW_H__CC08D8CF_2B86_4976_83B1_1FC16238F255__INCLUDED_)
#define AFX_BOTTOMVIEW_H__CC08D8CF_2B86_4976_83B1_1FC16238F255__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BottomView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBottomView view

// 메인프레임의 우측 하단 뷰 클래스
class CBottomView : public CView
{
protected:
	CBottomView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CBottomView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBottomView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CBottomView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CBottomView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOTTOMVIEW_H__CC08D8CF_2B86_4976_83B1_1FC16238F255__INCLUDED_)
