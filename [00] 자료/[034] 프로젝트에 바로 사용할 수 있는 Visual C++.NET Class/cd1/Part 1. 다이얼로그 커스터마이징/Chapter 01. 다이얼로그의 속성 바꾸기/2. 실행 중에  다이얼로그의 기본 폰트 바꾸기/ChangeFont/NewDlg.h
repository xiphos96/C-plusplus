#if !defined(AFX_NEWDLG_H__CA96994B_84F6_4CAA_8677_49163392DEDE__INCLUDED_)
#define AFX_NEWDLG_H__CA96994B_84F6_4CAA_8677_49163392DEDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewDlg dialog

#include "DefFontDialog.h"

// 폰트 설정을 위해 CDefFontDialog에서 상속 받음

class CNewDlg : public CDefFontDialog
{
// Construction
public:
	CNewDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewDlg)
	enum { IDD = IDD_NEW_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWDLG_H__CA96994B_84F6_4CAA_8677_49163392DEDE__INCLUDED_)
