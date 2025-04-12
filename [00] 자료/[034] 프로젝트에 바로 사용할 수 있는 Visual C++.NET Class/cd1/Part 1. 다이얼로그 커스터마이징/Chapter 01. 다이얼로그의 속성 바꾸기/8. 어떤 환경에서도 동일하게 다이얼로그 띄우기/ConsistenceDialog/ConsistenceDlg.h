#if !defined(AFX_CONSISTENCEDLG_H__F573362C_3602_4EC1_8A59_4A4449E63F0D__INCLUDED_)
#define AFX_CONSISTENCEDLG_H__F573362C_3602_4EC1_8A59_4A4449E63F0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConsistenceDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConsistenceDlg dialog

class CConsistenceDlg : public CDialog
{
// Construction
public:
	CConsistenceDlg(UINT nResourceID, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CConsistenceDlg)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	CFont		m_BaseFont;						// 기준 폰트 : 굴림 9포인트 폰트

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConsistenceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConsistenceDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONSISTENCEDLG_H__F573362C_3602_4EC1_8A59_4A4449E63F0D__INCLUDED_)
