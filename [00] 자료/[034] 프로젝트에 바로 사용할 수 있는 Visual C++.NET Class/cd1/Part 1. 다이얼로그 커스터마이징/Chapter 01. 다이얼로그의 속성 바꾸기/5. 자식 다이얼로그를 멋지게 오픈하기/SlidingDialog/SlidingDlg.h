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
	BOOL	m_bIsShow;								// 현재 보이는 상태인지 저장하는 변수
	CRect	m_rcWindow;								// 초기 대화상자 크기 저장 변수
	CRect	m_rcLastPos;							// 마지막 위치 저장 변수


public:
	BOOL IsVisible();								// 현재 보이는 상태를 리턴하는 함수
	BOOL StartSliding();							// 밀어 열거나 혹은 닫는 함수

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
