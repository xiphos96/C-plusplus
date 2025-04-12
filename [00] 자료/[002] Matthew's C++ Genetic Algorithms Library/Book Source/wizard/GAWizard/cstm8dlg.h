#if !defined(AFX_CSTM8DLG_H__2A867983_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
#define AFX_CSTM8DLG_H__2A867983_411D_11D4_B08A_00C0268E7D02__INCLUDED_

// cstm8dlg.h : header file
//

#define SELECT_COMPARATOR_DEFAULT	1
#define SELECT_COMPARATOR_ELEMENT	2
#define SELECT_COMPARATOR_BIT		3
#define SELECT_COMPARATOR_TOPOLOGY	4
#define SELECT_TERMINATOR_GENERATION		1
#define SELECT_TERMINATOR_CONVERGENCE		2
#define SELECT_TERMINATOR_POPCONVERGENCE	3

/////////////////////////////////////////////////////////////////////////////
// CCustom8Dlg dialog

class CCustom8Dlg : public CAppWizStepDlg
{
// Construction
public:
	CCustom8Dlg();
	virtual BOOL OnDismiss();

// Dialog Data
	//{{AFX_DATA(CCustom8Dlg)
	enum { IDD = IDD_CUSTOM8 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustom8Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCustom8Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnComparatorBit();
	afx_msg void OnComparatorDefault();
	afx_msg void OnComparatorElement();
	afx_msg void OnComparatorTopology();
	afx_msg void OnTerminatorConvergence();
	afx_msg void OnTerminatorGeneration();
	afx_msg void OnTerminatorPopconvergence();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	int comparator_which;
	int terminator_which;
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTM8DLG_H__2A867983_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
