#if !defined(AFX_SLIDINGDLG_H__044693ED_3664_4707_B90F_30442B38D3D8__INCLUDED_)
#define AFX_SLIDINGDLG_H__044693ED_3664_4707_B90F_30442B38D3D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SlidingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSlidingDlg dialog

class CSlidingDlg : public CDialog
{
// Construction
public:
	CSlidingDlg(UINT nResourceID, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSlidingDlg)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

protected:
	BOOL	m_bIsShow;								// ���� ���̴� �������� �����ϴ� ����
	CRect	m_rcWindow;								// �ʱ� ��ȭ���� ũ�� ���� ����
	CRect	m_rcLastPos;							// ������ ��ġ ���� ����


public:
	BOOL IsVisible();								// ���� ���̴� ���¸� �����ϴ� �Լ�
	BOOL StartSliding();							// �о� ���ų� Ȥ�� �ݴ� �Լ�

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSlidingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSlidingDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDINGDLG_H__044693ED_3664_4707_B90F_30442B38D3D8__INCLUDED_)
