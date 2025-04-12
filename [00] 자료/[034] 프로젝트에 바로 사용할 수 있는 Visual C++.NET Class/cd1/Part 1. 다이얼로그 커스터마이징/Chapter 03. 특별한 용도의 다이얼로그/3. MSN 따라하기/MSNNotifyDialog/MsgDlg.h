#if !defined(AFX_MSGDLG_H__B0EC3311_978D_463D_AC9E_D98DB7CB4629__INCLUDED_)
#define AFX_MSGDLG_H__B0EC3311_978D_463D_AC9E_D98DB7CB4629__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MsgDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMsgDlg dialog

// MSN 메시지 다이얼로그로 띄울 다이얼로그 클래스
// CMsnNotifyDlg에서 상속 받는다
#include "MsnNotifyDlg.h"

class CMsgDlg : public CMsnNotifyDlg
{
// Construction
public:
	CMsgDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMsgDlg)
	enum { IDD = IDD_MSG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMsgDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSGDLG_H__B0EC3311_978D_463D_AC9E_D98DB7CB4629__INCLUDED_)
