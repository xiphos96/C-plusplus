#if !defined(AFX_CSTM6DLG_H__2A86797F_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
#define AFX_CSTM6DLG_H__2A86797F_411D_11D4_B08A_00C0268E7D02__INCLUDED_

// cstm6dlg.h : header file
//

#define SELECT_MUTATOR_DEFAULT			1
#define SELECT_MUTATOR_SWAP				2
#define SELECT_MUTATOR_FLIP				3
#define SELECT_MUTATOR_DESTRUCTIVE		4
#define SELECT_MUTATOR_SWAPSUBTREE		5
#define SELECT_MUTATOR_SWAPNODE			6
#define SELECT_MUTATOR_REALGAUSSIAN		7
#define SELECT_MUTATOR_REALUNIFORM		8


/////////////////////////////////////////////////////////////////////////////
// CCustom6Dlg dialog

class CCustom6Dlg : public CAppWizStepDlg
{
// Construction
public:
	CCustom6Dlg();
	virtual BOOL OnDismiss();

// Dialog Data
	//{{AFX_DATA(CCustom6Dlg)
	enum { IDD = IDD_CUSTOM6 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustom6Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCustom6Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnMutatorDefault();
	afx_msg void OnMutatorDestructive();
	afx_msg void OnMutatorFlip();
	afx_msg void OnMutatorSwap();
	afx_msg void OnMUTATORSwapNodeMutator();
	afx_msg void OnMutatorSwapsubtree();
	afx_msg void OnMutatorRealgaussian();
	afx_msg void OnMutatorUniform();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	int mutator_which;
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTM6DLG_H__2A86797F_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
