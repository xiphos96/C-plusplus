#if !defined(AFX_LINKSTATIC_H__5CD619D7_872F_459A_AEF8_2F10203C3034__INCLUDED_)
#define AFX_LINKSTATIC_H__5CD619D7_872F_459A_AEF8_2F10203C3034__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LinkStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLinkStatic window

// ������ ��ũ ����ƽ ��Ʈ�� Ŭ����
class CLinkStatic : public CStatic
{
// Construction
public:
	CLinkStatic();

// Attributes
public:
	CRect				m_rcClient;					// Ŭ���̾�Ʈ ũ��
	CRect				m_rcText;					// �ؽ�Ʈ ũ��

	CFont				m_HoverFont;				// ������ ���� ��Ʈ
	COLORREF			m_clrText;					// �ؽ�Ʈ ����
	COLORREF			m_clrHover;					// ���콺�� ��ġ���� ���� ����
	COLORREF			m_clrBkgnd;					// ��� ����
	COLORREF			m_clrTransparent;			// ��Ʈ���� ���� ����
	HCURSOR				m_hCursor;					// �ո�� Ŀ��

	BITMAP				m_bmpInfo;					// ���� �̹����� ����
	CBitmap				m_bmpImage;					// ��Ʈ�� ��ü
	CBitmap				m_bmpMask;					// ��Ʈ�� ��ü���� ���� ó���� ���� ����ũ ��Ʈ��
	CPoint				m_ptImage;					// �̹��� ��� ��ġ

	BOOL				m_bHover;					// ���콺�� ����ƽ ��Ʈ�� ���� �ִ��� ����
	BOOL				m_bLeftImage;				// �ؽ�Ʈ�� ���ʿ� �̹����� ����� ����

	CString				m_strToolTip;				// ���� �ؽ�Ʈ
	CToolTipCtrl		m_wndToolTip;				// ���� ��Ʈ��

// Operations
public:
	// ����ƽ ��Ʈ�ѿ� ��Ʈ���� �����ϴ� �Լ�
	void SetLinkBmp(UINT nBitmapID, BOOL bLeft);
	// ����ƽ ��Ʈ�ѿ� ��Ʈ���� �����ϰ� ������� �����ϴ� �Լ�
	void SetLinkBmp(UINT nBitmapID, COLORREF clrTransparent, BOOL bLeft);

	// ����ƽ ��Ʈ���� ������ ����/�����ϴ� �Լ�
	LPCTSTR GetToolTipText()			{ return m_strToolTip; }
	void SetToolTipText(LPCTSTR pTip);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkStatic)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLinkStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CLinkStatic)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnClicked();
	//}}AFX_MSG
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKSTATIC_H__5CD619D7_872F_459A_AEF8_2F10203C3034__INCLUDED_)
