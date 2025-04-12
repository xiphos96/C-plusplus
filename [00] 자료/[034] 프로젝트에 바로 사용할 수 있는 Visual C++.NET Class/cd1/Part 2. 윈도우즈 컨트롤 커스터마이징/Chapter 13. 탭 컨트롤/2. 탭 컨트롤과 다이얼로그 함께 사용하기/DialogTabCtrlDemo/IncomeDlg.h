#if !defined(AFX_INCOMEDLG_H__BE90004D_607F_4A0B_A37D_7BCDF2F57082__INCLUDED_)
#define AFX_INCOMEDLG_H__BE90004D_607F_4A0B_A37D_7BCDF2F57082__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IncomeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIncomeDlg dialog

// 수입 다이얼로그
class CIncomeDlg : public CDialog
{
// Construction
public:
	CIncomeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CIncomeDlg)
	enum { IDD = IDD_INCOME_DIALOG };
	CListCtrl	m_IncomeList;
	CString	m_strName;
	CString	m_strMoney;
	//}}AFX_DATA

	// 에디트 박스의 값을 초기화하는 함수
	void ResetEdit();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIncomeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CIncomeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAddButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INCOMEDLG_H__BE90004D_607F_4A0B_A37D_7BCDF2F57082__INCLUDED_)
