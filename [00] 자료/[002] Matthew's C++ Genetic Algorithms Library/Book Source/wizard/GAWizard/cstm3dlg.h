#if !defined(AFX_CSTM3DLG_H__2A867979_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
#define AFX_CSTM3DLG_H__2A867979_411D_11D4_B08A_00C0268E7D02__INCLUDED_

// cstm3dlg.h : header file
//

#define SELECT_SCALING_NO				1
#define SELECT_SCALING_LINEAR			2
#define SELECT_SCALING_SIGMATRUNCATION	3
#define SELECT_SCALING_POWERLAW			4
#define SELECT_SCALING_SHARING			5
#define SELECT_SCALING_DEFAULT			6


/////////////////////////////////////////////////////////////////////////////
// CCustom3Dlg dialog

class CCustom3Dlg : public CAppWizStepDlg
{
// Construction
public:
	CCustom3Dlg();
	virtual BOOL OnDismiss();

// Dialog Data
	//{{AFX_DATA(CCustom3Dlg)
	enum { IDD = IDD_CUSTOM3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustom3Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCustom3Dlg)
	afx_msg void OnScalingLinear();
	afx_msg void OnScalingNo();
	afx_msg void OnScalingPowerlaw();
	afx_msg void OnScalingSharing();
	afx_msg void OnScalingSigmatruncation();
	virtual BOOL OnInitDialog();
	afx_msg void OnScalingDefault();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	int scaling_which;
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTM3DLG_H__2A867979_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
