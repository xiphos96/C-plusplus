#if !defined(AFX_MSNNOTIFYDLG_H__6D46E770_2E08_4EA0_9224_30EC6C53FBE8__INCLUDED_)
#define AFX_MSNNOTIFYDLG_H__6D46E770_2E08_4EA0_9224_30EC6C53FBE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MsnNotifyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMsnNotifyDlg dialog

// MSN �˸� â�� �޽����� Ŭ������ ��� �θ� �����쿡�� ���� �޽���
#define WM_NOTIFY_CLICKED		(WM_USER + 1)

// �˸� â�� ��Ÿ���ų�, ���̰ų�, ����� �� ����� Ÿ�̸� ID
#define CONST_TIMER_UP			1			// �˸� â ��Ÿ��
#define CONST_TIMER_SHOW		2			// �˸� â ����
#define CONST_TIMER_DOWN		3			// �˸� â �����

#define CONST_INCREMENT			2			// �˸� â�� ��ġ �̵� ����(�ȼ�)


// MSN �˸� â�� �⺻ Ŭ����
class CMsnNotifyDlg : public CDialog
{
// Construction
public:
	CMsnNotifyDlg(UINT nResourceID, CWnd* pParent = NULL);   // standard constructor
	virtual ~CMsnNotifyDlg();

// Dialog Data
	//{{AFX_DATA(CMsnNotifyDlg)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	HCURSOR		m_hCursor;					// �޽��� �������� ���콺 Ŀ��
	
	CBitmap		m_bmpBkgnd;					// �˸� â�� ��� �̹���
	BITMAP		m_bmpInfo;					// ��� �̹����� ���� ����

	CFont		m_MessageFont;				// �޽��� ��¿� ��Ʈ
	CFont		m_HotFont;					// ���콺�� ���� �ö��� ���� �޽��� ��� ��Ʈ
	COLORREF	m_clrText;					// �޽��� ��� ����
	CString		m_strMessage;				// �޽��� �ؽ�Ʈ
	CRect		m_rcMessage;				// �޽��� ��� ����

 	int			m_nTimeUp;					// �˸� â�� ��Ÿ���� ����
	int			m_nTimeShow;				// �˸� â�� �������� �ð�
	int			m_nTimeDown;				// �˸� â�� ������� ����

	int			m_nTimerID;					// ���� ���� ���� Ÿ�̸� ID
	BOOL		m_bHover;					// ���콺�� ���� �˸� â ���� �ִ��� ����

	CPoint		m_ptStart;					// �۾�ǥ������ ��ġ�� ���� �˸� â �»�� ��ġ
	CPoint		m_ptEnd;					// �۾�ǥ������ ��ġ�� ���� �˸� â�� �� ���̴� ��ġ
	CSize		m_szTerm;					// �۾�ǥ������ ��ġ�� ���� �˸� â �̵� ����

	void SetBitmap(UINT nBitmap);			// ��� �̹��� ���� �Լ�
	void SetBitmap(LPCTSTR pFileName);		// ��� �̹��� ���� �Լ�
	void InitPosition();					// ��� �̹����� ���� ���� ���� �Լ�

	// �޽��� �ؽ�Ʈ ����/���� �Լ�
	LPCTSTR GetMessage()					{ return m_strMessage; }
	void SetMessage(LPCTSTR pMessage)		{ m_strMessage = pMessage; }
	// �޽��� �ؽ�Ʈ ��¿� ���� ����/���� �Լ�
	COLORREF GetTextColor()					{ return m_clrText; }
	void SetTextColor(COLORREF clrText)		{ m_clrText = clrText; }
	// �޽��� �ؽ�Ʈ ��¿� ��Ʈ ���� �Լ�
	void SetTextFont(LPCTSTR pFontName, int nPoint);
	// �޽��� ��� ���� ����/���� �Լ�
	CRect* GetMessageRect()					{ return &m_rcMessage; }
	void SetMessageRect(CRect *pRect)		{ m_rcMessage.CopyRect(pRect); }

	// �˸� â ��� �ð� ���� ���� �Լ�
	void SetTime(int nUp, int nShow, int nDown)
	{
		m_nTimeUp	= nUp;
		m_nTimeShow	= nShow;
		m_nTimeDown	= nDown;
	}

	void Show();							// �˸� â ��� �Լ�
	void Hide();							// �˸� â ���ߴ� �Լ�

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsnNotifyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMsnNotifyDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseHover(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSNNOTIFYDLG_H__6D46E770_2E08_4EA0_9224_30EC6C53FBE8__INCLUDED_)
