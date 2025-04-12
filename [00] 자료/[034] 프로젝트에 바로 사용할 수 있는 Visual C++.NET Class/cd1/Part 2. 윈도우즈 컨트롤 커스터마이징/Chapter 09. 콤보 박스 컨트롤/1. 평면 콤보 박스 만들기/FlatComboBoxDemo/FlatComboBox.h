#if !defined(AFX_FLATCOMBOBOX_H__474EC413_9785_4D76_8D11_FDA35402CE98__INCLUDED_)
#define AFX_FLATCOMBOBOX_H__474EC413_9785_4D76_8D11_FDA35402CE98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlatComboBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFlatComboBox window

// ��� �޺� �ڽ� ��Ʈ�� Ŭ����
class CFlatComboBox : public CComboBox
{
// Construction
public:
	CFlatComboBox();

// Attributes
public:
	COLORREF m_clrBkgnd;					// ���� ������ �׸� ����
	COLORREF m_clrSelected;					// ���õ� ������ �׸� ����
	COLORREF m_clrText;						// �ؽ�Ʈ ����
	COLORREF m_clrTextDisabled;				// ��Ȱ��ȭ �ؽ�Ʈ ����

	COLORREF m_clrFace;						// �޺� �ڽ� �Ϲ� ����
	COLORREF m_clrHighlight;				// �޺� �ڽ� ���� ����
	COLORREF m_clrShadow;					// �޺� �ڽ� ��ο� ����

	BOOL	m_bHover;						// ���콺�� �޺� �ڽ� ���� �ִ��� ����
	BOOL	m_bPress;						// ���콺 ���� ��ư�� ���� �������� ����
	BOOL	m_bFocus;						// ��Ŀ���� ���� �ִ��� ����
	BOOL	m_bAutoComplete;				// �ڵ� �ϼ� ����� ��� ����
	BOOL	m_bDelBack;						// DELŰ�� Back Space Ű�� �Է� ����
	int		m_nDropArrowWidth;				// ��� �ٿ� ȭ��ǥ ��ư�� ��
	int		m_nAutoSel;						// �ڵ� �ϼ� ��ɿ� ���� ���õ� �׸� ��ȣ

	CRect	m_rcClient;						// Ŭ���̾�Ʈ ����

// Operations
public:
	// ��� �޺� �ڽ� �׵θ��� �׸��� �Լ�
	void DrawFlatCombo();
	// ���� �ѱ� �Է� ������� Ȯ���ϴ� �Լ�
	BOOL IsHangleMode();

	// �ڵ� �ϼ� ����� ����ϰ� �ִ��� �����ϴ� �Լ�
	BOOL IsEnableAutoComplete()				{ return m_bAutoComplete; }
	// �ڵ� �ϼ� ����� ������� �����ϴ� �Լ�
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
