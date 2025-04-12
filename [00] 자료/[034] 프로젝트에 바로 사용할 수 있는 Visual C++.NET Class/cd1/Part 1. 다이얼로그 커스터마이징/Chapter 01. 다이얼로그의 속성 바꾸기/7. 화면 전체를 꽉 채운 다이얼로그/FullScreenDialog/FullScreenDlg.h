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

	CRect	m_rcClient;								// 초기 대화상자 크기를 저장하는 변수
	CRect	m_rcWorkArea;							// 초기 작업 영역 크기를 저장하는 변수
	BOOL	m_bIsVisibleTaskBar;					// 초기 태스크바가 보이는 상태인지 저장하는 변수

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
