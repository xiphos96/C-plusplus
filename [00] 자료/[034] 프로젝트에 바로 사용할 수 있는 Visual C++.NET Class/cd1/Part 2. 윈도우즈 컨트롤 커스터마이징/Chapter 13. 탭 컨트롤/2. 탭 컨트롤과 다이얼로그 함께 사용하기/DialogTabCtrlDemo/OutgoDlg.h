#if !defined(AFX_OUTGODLG_H__5B5AC1B1_177B_4BE7_B776_CDD67A4E2BF8__INCLUDED_)
#define AFX_OUTGODLG_H__5B5AC1B1_177B_4BE7_B776_CDD67A4E2BF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OutgoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutgoDlg dialog

// 지출 다이얼로그
class COutgoDlg : public CDialog
{
// Construction
public:
	COutgoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COutgoDlg)
	enum { IDD = IDD_OUTGO_DIALOG };
	CListCtrl	m_OutgoList;
	CString	m_strName;
	CString	m_strMoney;
	//}}AFX_DATA

	// 에디트 박스의 값을 초기화하는 함수
	void ResetEdit();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutgoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COutgoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAddButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTGODLG_H__5B5AC1B1_177B_4BE7_B776_CDD67A4E2BF8__INCLUDED_)
