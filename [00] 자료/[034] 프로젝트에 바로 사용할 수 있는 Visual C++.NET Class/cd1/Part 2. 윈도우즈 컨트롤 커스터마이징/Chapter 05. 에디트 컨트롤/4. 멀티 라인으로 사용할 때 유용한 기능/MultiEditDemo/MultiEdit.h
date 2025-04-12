#if !defined(AFX_MULTIEDIT_H__6C9B8844_CD01_4D77_B4EE_845A62D95C92__INCLUDED_)
#define AFX_MULTIEDIT_H__6C9B8844_CD01_4D77_B4EE_845A62D95C92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MultiEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMultiEdit window

// 탭 사용/현재 라인 표시/포커스에 따른 배경색 출력 기능을 갖는 에디트 컨트롤 클래스
class CMultiEdit : public CEdit
{
// Construction
public:
	CMultiEdit();

// Attributes
public:
	CRect		m_rcClient;					// 클라이언트 영역
	BOOL		m_bFocus;					// 현재 포커스를 갖고 있는지 여부
	int			m_nLineHeight;				// 한 라인의 높이
	int			m_nLastLine;				// 마지막 캐럿을 갖고 있던 라인 번호

	COLORREF	m_clrBkgndNormal;			// 포커스를 갖고 있지 않을 때의 배경색
	COLORREF	m_clrBkgndHot;				// 포커스를 갖고 있을 때의 배경색
	CBrush		m_brsBkgndNormal;			// 포커스를 갖고 있지 않을 때의 배경색 브러쉬
	CBrush		m_brsBkgndHot;				// 포커스를 갖고 있을 때의 배경색 브러쉬

// Operations
public:
	// 현재 캐럿이 위치한 라인 번호를 리턴하는 함수
	int GetLineNo();
	// 특정 라인의 사각 영역을 계산/리턴하는 함수
	void GetLineRect(int nLine, CRect &rcRect);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiEdit)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMultiEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMultiEdit)
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnEnVscroll();
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
public:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIEDIT_H__6C9B8844_CD01_4D77_B4EE_845A62D95C92__INCLUDED_)
