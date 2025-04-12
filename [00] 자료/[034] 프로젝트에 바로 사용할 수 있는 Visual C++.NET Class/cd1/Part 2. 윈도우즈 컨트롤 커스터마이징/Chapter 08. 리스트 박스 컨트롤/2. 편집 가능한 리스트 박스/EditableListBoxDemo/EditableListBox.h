#if !defined(AFX_EDITABLELISTBOX_H__82D1059A_4397_4AB4_9867_3EFF9EBC449A__INCLUDED_)
#define AFX_EDITABLELISTBOX_H__82D1059A_4397_4AB4_9867_3EFF9EBC449A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditableListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditableListBox window

// 텍스트 편집 리스트 박스 컨트롤 클래스
class CEditableListBox : public CListBox
{
// Construction
public:
	CEditableListBox();

// Attributes
public:
	CEdit			m_Edit;					// 텍스트 편집용 에디트 컨트롤
	int				m_nTrackItem;			// 현재 마우스가 위치한 항목 번호
	int				m_nEditItem;			// 현재 편집 중인 항목 번호

	CBrush			m_NullBrush;			// 배경 출력용 브러쉬
	CPen			m_ShadowPen;			// 리스트 박스 테두리용 펜
	CPen			m_FocusPen;				// 선택 항목 테두리용 펜

	COLORREF		m_clrText;				// 텍스트 색상
	COLORREF		m_clrHighlight;			// 마우스가 위치한 항목의 배경색
	COLORREF		m_clrBkgnd;				// 일반 배경색
	COLORREF		m_clrSelected;			// 선택된 항목의 배경색

// Operations
public:
	void EndEdit();							// 텍스트 편집을 종료하는 함수

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditableListBox)
	public:
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEditableListBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CEditableListBox)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcPaint();
	afx_msg void OnDblclk();
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg void OnKillFocusEdit();
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITABLELISTBOX_H__82D1059A_4397_4AB4_9867_3EFF9EBC449A__INCLUDED_)
