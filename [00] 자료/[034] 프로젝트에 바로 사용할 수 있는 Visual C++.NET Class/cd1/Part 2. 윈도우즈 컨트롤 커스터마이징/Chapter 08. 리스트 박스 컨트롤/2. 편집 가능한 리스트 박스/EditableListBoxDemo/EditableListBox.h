#if !defined(AFX_EDITABLELISTBOX_H__82D1059A_4397_4AB4_9867_3EFF9EBC449A__INCLUDED_)
#define AFX_EDITABLELISTBOX_H__82D1059A_4397_4AB4_9867_3EFF9EBC449A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditableListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditableListBox window

// �ؽ�Ʈ ���� ����Ʈ �ڽ� ��Ʈ�� Ŭ����
class CEditableListBox : public CListBox
{
// Construction
public:
	CEditableListBox();

// Attributes
public:
	CEdit			m_Edit;					// �ؽ�Ʈ ������ ����Ʈ ��Ʈ��
	int				m_nTrackItem;			// ���� ���콺�� ��ġ�� �׸� ��ȣ
	int				m_nEditItem;			// ���� ���� ���� �׸� ��ȣ

	CBrush			m_NullBrush;			// ��� ��¿� �귯��
	CPen			m_ShadowPen;			// ����Ʈ �ڽ� �׵θ��� ��
	CPen			m_FocusPen;				// ���� �׸� �׵θ��� ��

	COLORREF		m_clrText;				// �ؽ�Ʈ ����
	COLORREF		m_clrHighlight;			// ���콺�� ��ġ�� �׸��� ����
	COLORREF		m_clrBkgnd;				// �Ϲ� ����
	COLORREF		m_clrSelected;			// ���õ� �׸��� ����

// Operations
public:
	void EndEdit();							// �ؽ�Ʈ ������ �����ϴ� �Լ�

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
