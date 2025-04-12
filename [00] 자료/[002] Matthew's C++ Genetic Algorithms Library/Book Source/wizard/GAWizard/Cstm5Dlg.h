#if !defined(AFX_CSTM5DLG_H__2A86797D_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
#define AFX_CSTM5DLG_H__2A86797D_411D_11D4_B08A_00C0268E7D02__INCLUDED_

// cstm5dlg.h : header file
//

#define SELECT_CROSSOVER_DEFAULT		1
#define SELECT_CROSSOVER_UNIFORM		2
#define SELECT_CROSSOVER_EVENODD		3
#define SELECT_CROSSOVER_ONEPOINT		4
#define SELECT_CROSSOVER_TWOPOINT		5
#define SELECT_CROSSOVER_PARTIALMATCH	6
#define SELECT_CROSSOVER_ORDER			7
#define SELECT_CROSSOVER_CYCLE			8
#define SELECT_CROSSOVER_REALBLEND		9
#define SELECT_CROSSOVER_REALARITHMETIC	10

/////////////////////////////////////////////////////////////////////////////
// CCustom5Dlg dialog

class CCustom5Dlg : public CAppWizStepDlg
{
// Construction
public:
	CCustom5Dlg();
	virtual BOOL OnDismiss();

// Dialog Data
	//{{AFX_DATA(CCustom5Dlg)
	enum { IDD = IDD_CUSTOM5 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustom5Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCustom5Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnCrossoverCycle();
	afx_msg void OnCrossoverDefault();
	afx_msg void OnCrossoverEvenodd();
	afx_msg void OnCrossoverOnepoint();
	afx_msg void OnCrossoverOrder();
	afx_msg void OnCrossoverPartialmatch();
	afx_msg void OnCrossoverTwopoint();
	afx_msg void OnCrossoverUniform();
	afx_msg void OnCrossoverRealarithmetic();
	afx_msg void OnCrossoverRealblend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	int crossover_which;
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTM5DLG_H__2A86797D_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
