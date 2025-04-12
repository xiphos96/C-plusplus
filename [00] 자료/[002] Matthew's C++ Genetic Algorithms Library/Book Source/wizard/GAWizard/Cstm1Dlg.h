#if !defined(AFX_CSTM1DLG_H__2A867975_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
#define AFX_CSTM1DLG_H__2A867975_411D_11D4_B08A_00C0268E7D02__INCLUDED_

// cstm1dlg.h : header file
//

#define SELECT_GA_SIMPLE		1
#define SELECT_GA_INCREMENTAL	2
#define SELECT_GA_STEADYSTATE	3
#define SELECT_GA_DEME			4

/////////////////////////////////////////////////////////////////////////////
// CCustom1Dlg dialog

class CCustom1Dlg : public CAppWizStepDlg
{
// Construction
public:
	CCustom1Dlg();
	virtual BOOL OnDismiss();

// Dialog Data
	//{{AFX_DATA(CCustom1Dlg)
	enum { IDD = IDD_CUSTOM1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustom1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCustom1Dlg)
	afx_msg void OnGaSimple();
	afx_msg void OnGaIncremental();
	afx_msg void OnGaSteadystate();
	afx_msg void OnGaDeme();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	int ga_which;
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTM1DLG_H__2A867975_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
