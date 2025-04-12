#if !defined(AFX_CSTM7DLG_H__2A867981_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
#define AFX_CSTM7DLG_H__2A867981_411D_11D4_B08A_00C0268E7D02__INCLUDED_

// cstm7dlg.h : header file
//

#define SELECT_INITIALIZER_DEFAULT	1
#define SELECT_INITIALIZER_UNIFORM	2
#define SELECT_INITIALIZER_SET		3
#define SELECT_INITIALIZER_UNSET	4
#define SELECT_INITIALIZER_ORDERED	5

/////////////////////////////////////////////////////////////////////////////
// CCustom7Dlg dialog

class CCustom7Dlg : public CAppWizStepDlg
{
// Construction
public:
	CCustom7Dlg();
	virtual BOOL OnDismiss();

// Dialog Data
	//{{AFX_DATA(CCustom7Dlg)
	enum { IDD = IDD_CUSTOM7 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustom7Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCustom7Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnInitializerDefault();
	afx_msg void OnInitializerSet();
	afx_msg void OnInitializerUniform();
	afx_msg void OnInitializerUnset();
	afx_msg void OnInitializerOrdered();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	int initializer_which;
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTM7DLG_H__2A867981_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
