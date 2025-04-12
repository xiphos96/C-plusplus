#if !defined(AFX_COLORSTATIC_H__C1DC1983_A465_420F_A89A_F442782DC43E__INCLUDED_)
#define AFX_COLORSTATIC_H__C1DC1983_A465_420F_A89A_F442782DC43E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorStatic window

// 컬러 출력 및 선택을 위해 사용되는 스태틱 컨트롤
class CColorStatic : public CStatic
{
// Construction
public:
	CColorStatic();

// Attributes
public:
	CRect		m_rcClient;					// 클라이언트 영역
	COLORREF	m_clrColor;					// 색상

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CColorStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CColorStatic)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORSTATIC_H__C1DC1983_A465_420F_A89A_F442782DC43E__INCLUDED_)
