#if !defined(AFX_FOLDERDLG_H__65482C4D_F115_42E2_9A75_25B40D38F6F6__INCLUDED_)
#define AFX_FOLDERDLG_H__65482C4D_F115_42E2_9A75_25B40D38F6F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FolderDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFolderDlg dialog

class CFolderDlg : public CDialog
{
// Construction
public:
	CFolderDlg(UINT nResourceID, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFolderDlg)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

protected:
	HICON	m_hIcon;									// �������� �� ������ ������

	DWORD	m_dwStyle;									// ���� ������ ��Ÿ�� ���� ����
	BOOL	m_bIsFolded;								// ������ �������� �����ϴ� ����
	CRect	m_rcWindow;									// ���� ������ ũ�⸦ �����ϴ� ����
	CRect	m_rcLastFold;								// ������ �������� ���� ��ġ/ũ�⸦ �����ϴ� ����

public:
	void SetFoldIcon(HICON hIcon);						// �������� �����ϴ� �Լ�

	void Fold();										// ���̾�α׸� ����� �Լ�
	void Stretch();										// ���̾�α׸� �ٽ� ��ġ�� �Լ�

protected:
	void Animate(CRect &rcStart, CRect &rcEnd);			// ���������� ����ϴ� �ִϸ��̼� �Լ�

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFolderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFolderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg UINT OnNcHitTest(CPoint point);
	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOLDERDLG_H__65482C4D_F115_42E2_9A75_25B40D38F6F6__INCLUDED_)
