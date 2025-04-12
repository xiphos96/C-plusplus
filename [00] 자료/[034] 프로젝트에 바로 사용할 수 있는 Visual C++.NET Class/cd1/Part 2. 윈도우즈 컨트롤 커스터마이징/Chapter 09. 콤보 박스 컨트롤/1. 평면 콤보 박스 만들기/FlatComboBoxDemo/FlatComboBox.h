#if !defined(AFX_FLATCOMBOBOX_H__474EC413_9785_4D76_8D11_FDA35402CE98__INCLUDED_)
#define AFX_FLATCOMBOBOX_H__474EC413_9785_4D76_8D11_FDA35402CE98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlatComboBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFlatComboBox window

// 평면 콤보 박스 컨트롤 클래스
class CFlatComboBox : public CComboBox
{
// Construction
public:
	CFlatComboBox();

// Attributes
public:
	COLORREF m_clrBkgnd;					// 보통 상태의 항목 배경색
	COLORREF m_clrSelected;					// 선택된 상태의 항목 배경색
	COLORREF m_clrText;						// 텍스트 색상
	COLORREF m_clrTextDisabled;				// 비활성화 텍스트 색상

	COLORREF m_clrFace;						// 콤보 박스 일반 색상
	COLORREF m_clrHighlight;				// 콤보 박스 밝은 색상
	COLORREF m_clrShadow;					// 콤보 박스 어두운 색상

	BOOL	m_bHover;						// 마우스가 콤보 박스 위에 있는지 여부
	BOOL	m_bPress;						// 마우스 좌측 버튼이 눌린 상태인지 여부
	BOOL	m_bFocus;						// 포커스를 갖고 있는지 여부
	BOOL	m_bAutoComplete;				// 자동 완성 기능의 사용 여부
	BOOL	m_bDelBack;						// DEL키나 Back Space 키의 입력 여부
	int		m_nDropArrowWidth;				// 드롭 다운 화살표 버튼의 폭
	int		m_nAutoSel;						// 자동 완성 기능에 의해 선택된 항목 번호

	CRect	m_rcClient;						// 클라이언트 영역

// Operations
public:
	// 평면 콤보 박스 테두리를 그리는 함수
	void DrawFlatCombo();
	// 현재 한글 입력 모드인지 확인하는 함수
	BOOL IsHangleMode();

	// 자동 완성 기능을 사용하고 있는지 리턴하는 함수
	BOOL IsEnableAutoComplete()				{ return m_bAutoComplete; }
	// 자동 완성 기능을 사용할지 설정하는 함수
	BOOL EnableAutoComplete(BOOL bEnable)	{ return m_bAutoComplete = bEnable; }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlatComboBox)
	public:
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFlatComboBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFlatComboBox)
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnEditupdate();
	afx_msg void OnCBNKillFocus();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnCloseup();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLATCOMBOBOX_H__474EC413_9785_4D76_8D11_FDA35402CE98__INCLUDED_)
