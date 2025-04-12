#if !defined(AFX_CHILDDLG_H__0208CF4E_157A_43D9_B9B4_51A15870686A__INCLUDED_)
#define AFX_CHILDDLG_H__0208CF4E_157A_43D9_B9B4_51A15870686A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChildDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChildDlg dialog

// 미닫이 자식 대화상자 클래스
// CDialog가 아니라 CSlidingDlg에서 상속 받아 구현한다

#include "SlidingDlg.h"

class CChildDlg : public CSlidingDlg
{
// Construction
public:
	CChildDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChildDlg)
	enum { IDD = IDD_CHILD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChildDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDDLG_H__0208CF4E_157A_43D9_B9B4_51A15870686A__INCLUDED_)
