#if !defined(AFX_COLORPALETTEWND_H__BF2D5D23_953A_445C_856A_D44DDE53DCF4__INCLUDED_)
#define AFX_COLORPALETTEWND_H__BF2D5D23_953A_445C_856A_D44DDE53DCF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorPaletteWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorPaletteWnd window

// �ȷ�Ʈ ������ ���� �޽��� ����
#define CLR_TRACKCOLOR		(WM_USER + 1000)
#define CLR_DROPDOWN		(WM_USER + 1001)
#define CLR_CLOSEUP			(WM_USER + 1002)
#define CLR_SELENDOK		(WM_USER + 1003)
#define CLR_SELENDCANCEL	(WM_USER + 1004)

// �ȷ�Ʈ�� �� ���� ���� ���� ����ü
struct COLOR_TABLE
{
	COLORREF	clrColor;
	CString		strName;
};


// �ȷ�Ʈ ������ Ŭ����
class CColorPaletteWnd : public CWnd
{
// Construction
public:
	CColorPaletteWnd();

// Attributes
public:
	static COLOR_TABLE	*m_pColorTable;				// 40������ �⺻ ���� ���� ����
	static int			m_nCount;					// ���� ���̺��� ����ϴ� ��ư ����

	CWnd				*m_pParent;					// �θ� ������(��ư)�� ������
	COLORREF			m_clrColor;					// �ʱ� ����

	COLORREF			m_clrBkgnd;					// ��� ����

	CFont				m_TextFont;					// ���� ��¿� ��Ʈ

	int					m_nBorder;					// �ȷ�Ʈ�� �׵θ� �β�
	int					m_nSelected;				// ���� ���õ� �׸��� ��ȣ

	CRect				m_rcDefault;				// "�⺻ ����" ��ư�� ����
	CRect				m_rcColorBox;				// ���� ��ư���� ��ġ�� ����
	CRect				m_rcMore;					// "More Colors..." ��ư�� ����
	CRect				m_rcWindow;					// ��ü �ȷ�Ʈ �������� ũ��

	CString				m_strToolTip;				// ���� �ؽ�Ʈ
	CToolTipCtrl		m_wndToolTip;				// ���� ��Ʈ��

	BOOL				m_bColorDialog;				// ���� ���� ���̾�αװ� ����� �������� ����

// Operations
public:
	// �ʱ� ����� ��ġ�� �ȷ�Ʈ �����츦 �����ϴ� �Լ�
	BOOL Init(COLORREF clrColor, CWnd *pParent, int x, int y, UINT nID);
	// Ư�� ���� ���� ���� ���̺����� ��ȣ�� �����ϴ� �Լ�
	int FindColor(COLORREF clrColor);

	// ���� ���̺� ���� �ʱ�ȭ �Լ�
	static void InitColorTable();
	// Ư�� ���� ���� ���� �̸��� �����ϴ� �Լ�
	static void FindColorName(COLORREF clrColor, CString &strName);

	// �ȷ�Ʈ �������� �� ������Ҹ� ȭ�鿡 ����ϴ� �Լ�
	void DrawColorCell(CDC *pDC, int nItem);
	// ����ڰ� ������ �����ϰų� ����� ��� ó���ϴ� �Լ�
	void EndSelect(BOOL bSelOK);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorPaletteWnd)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CColorPaletteWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CColorPaletteWnd)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
#if _MSC_VER <= 1200
	// VC++ 6.0������ �ڵ�
	afx_msg void OnActivateApp(BOOL bActive, HTASK dwThreadID);
#else
	// VC++.Net������ �ڵ�
	afx_msg void OnActivateApp(BOOL bActive, DWORD dwThreadID);
#endif
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORPALETTEWND_H__BF2D5D23_953A_445C_856A_D44DDE53DCF4__INCLUDED_)
