#if !defined(AFX_FULLSCREENDLG_H__8A1130D2_9519_467F_A522_0BEFE1C4CB87__INCLUDED_)
#define AFX_FULLSCREENDLG_H__8A1130D2_9519_467F_A522_0BEFE1C4CB87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FullScreenDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFullScreenDlg dialog

class CFullScreenDlg : public CDialog
{
// Construction
public:
	CFullScreenDlg(UINT nResourceID, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFullScreenDlg)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	CRect	m_rcClient;								// �ʱ� ��ȭ���� ũ�⸦ �����ϴ� ����
	CRect	m_rcWorkArea;							// �ʱ� �۾� ���� ũ�⸦ �����ϴ� ����
	BOOL	m_bIsVisibleTaskBar;					// �ʱ� �½�ũ�ٰ� ���̴� �������� �����ϴ� ����

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFullScreenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFullScreenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FULLSCREENDLG_H__8A1130D2_9519_467F_A522_0BEFE1C4CB87__INCLUDED_)
