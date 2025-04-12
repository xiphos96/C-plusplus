#if !defined(AFX_TRANSPARENTDLG_H__71129CCD_1BC9_437E_A209_5C6C64E84629__INCLUDED_)
#define AFX_TRANSPARENTDLG_H__71129CCD_1BC9_437E_A209_5C6C64E84629__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TransparentDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTransparentDlg dialog

class CTransparentDlg : public CDialog
{
// Construction
public:
	CTransparentDlg(UINT nResourceID, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTransparentDlg)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransparentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTransparentDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSPARENTDLG_H__71129CCD_1BC9_437E_A209_5C6C64E84629__INCLUDED_)
