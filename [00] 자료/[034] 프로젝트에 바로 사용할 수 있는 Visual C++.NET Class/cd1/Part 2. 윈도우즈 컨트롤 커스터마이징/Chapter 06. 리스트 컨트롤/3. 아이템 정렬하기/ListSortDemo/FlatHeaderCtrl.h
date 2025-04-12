#if !defined(AFX_FLATHEADERCTRL_H__97A15E65_209F_4833_AF23_0FF044C89F8A__INCLUDED_)
#define AFX_FLATHEADERCTRL_H__97A15E65_209F_4833_AF23_0FF044C89F8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlatHeaderCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFlatHeaderCtrl window

// ��� ��� ��Ʈ�� Ŭ����
class CFlatHeaderCtrl : public CHeaderCtrl
{
// Construction
public:
	CFlatHeaderCtrl();

// Attributes
public:
	CRect		m_rcClient;				// Ŭ���̾�Ʈ ����
	COLORREF	m_clrFace;				// ��� ��Ʈ���� ��� ����
	COLORREF	m_clrHighLight;			// ��� ��Ʈ���� ���� �� ����
	COLORREF	m_clrShadow;			// ��� ��Ʈ���� ��ο� �� ����
	COLORREF	m_clrText;				// ��� ��Ʈ���� ���� ����
	CPen		m_HighLightPen;			// �����ڸ� ����ϱ� ���� ���� �� ��
	CPen		m_ShadowPen;			// �����ڸ� ����ϱ� ���� ��ο� �� ��

	CToolTipCtrl m_wndToolTip;			// ���� ��Ʈ��

	int			m_nClickColumn;			// ���콺�� Ŭ���� �׸� ��ȣ
	int			m_nSortColumn;			// ������ ������ �÷� ��ȣ
	BOOL		m_bSortAscending;		// ������ ����

// Operations
public:
	// �׸��� �̹����� ����ϴ� �Լ�
	int DrawImage(CDC *pDC, CRect *pRect, LPHDITEM pItem, CImageList *pImageList, CSize *pSize);
	// �׸��� �ؽ�Ʈ�� ����ϴ� �Լ�
	int DrawText(CDC* pDC, CRect *pRect, LPHDITEM pItem);
	// �׸��� ��Ʈ���� ����ϴ� �Լ�
	int DrawBitmap(CDC* pDC, CRect *pRect, LPHDITEM pItem, CBitmap* pBitmap);
	// �׸��� ���� ���� ǥ���ڸ� ����ϴ� �Լ�
	int DrawSortMark(CDC *pDC, CRect *pRect, LPHDITEM pItem);

	// Ư�� �÷��� ���� ������ �����ϴ� �Լ�
	BOOL AddTool(int nCol, LPCTSTR pTipText);
	// �� �÷� �׸��� ��ġ�� ���� ���� ��� ������ �ٽ� ����ϴ� �Լ�
	void RecalcToolRect();

	// ���ο� ���� ���� �÷��� ������ �����ϴ� �Լ�
	void SetSortColumn(int nCol, BOOL bAscending);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlatHeaderCtrl)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFlatHeaderCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFlatHeaderCtrl)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLATHEADERCTRL_H__97A15E65_209F_4833_AF23_0FF044C89F8A__INCLUDED_)
