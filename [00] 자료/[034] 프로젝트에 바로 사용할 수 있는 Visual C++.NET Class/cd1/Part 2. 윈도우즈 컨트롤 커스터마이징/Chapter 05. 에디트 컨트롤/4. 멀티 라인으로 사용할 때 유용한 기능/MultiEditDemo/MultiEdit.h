#if !defined(AFX_MULTIEDIT_H__6C9B8844_CD01_4D77_B4EE_845A62D95C92__INCLUDED_)
#define AFX_MULTIEDIT_H__6C9B8844_CD01_4D77_B4EE_845A62D95C92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MultiEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMultiEdit window

// �� ���/���� ���� ǥ��/��Ŀ���� ���� ���� ��� ����� ���� ����Ʈ ��Ʈ�� Ŭ����
class CMultiEdit : public CEdit
{
// Construction
public:
	CMultiEdit();

// Attributes
public:
	CRect		m_rcClient;					// Ŭ���̾�Ʈ ����
	BOOL		m_bFocus;					// ���� ��Ŀ���� ���� �ִ��� ����
	int			m_nLineHeight;				// �� ������ ����
	int			m_nLastLine;				// ������ ĳ���� ���� �ִ� ���� ��ȣ

	COLORREF	m_clrBkgndNormal;			// ��Ŀ���� ���� ���� ���� ���� ����
	COLORREF	m_clrBkgndHot;				// ��Ŀ���� ���� ���� ���� ����
	CBrush		m_brsBkgndNormal;			// ��Ŀ���� ���� ���� ���� ���� ���� �귯��
	CBrush		m_brsBkgndHot;				// ��Ŀ���� ���� ���� ���� ���� �귯��

// Operations
public:
	// ���� ĳ���� ��ġ�� ���� ��ȣ�� �����ϴ� �Լ�
	int GetLineNo();
	// Ư�� ������ �簢 ������ ���/�����ϴ� �Լ�
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
