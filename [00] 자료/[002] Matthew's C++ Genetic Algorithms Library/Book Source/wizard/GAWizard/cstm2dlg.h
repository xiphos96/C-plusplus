#if !defined(AFX_CSTM2DLG_H__2A867977_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
#define AFX_CSTM2DLG_H__2A867977_411D_11D4_B08A_00C0268E7D02__INCLUDED_

// cstm2dlg.h : header file
//

#define SELECT_SELECTOR_RANK			1
#define SELECT_SELECTOR_ROULETTEWHEEL	2
#define SELECT_SELECTOR_TOURNAMENT		3
#define SELECT_SELECTOR_DS				4
#define SELECT_SELECTOR_SRS				5
#define SELECT_SELECTOR_UNIFORM			6
#define SELECT_SELECTOR_DEFAULT			7


/////////////////////////////////////////////////////////////////////////////
// CCustom2Dlg dialog

class CCustom2Dlg : public CAppWizStepDlg
{
// Construction
public:
	CCustom2Dlg();
	virtual BOOL OnDismiss();

// Dialog Data
	//{{AFX_DATA(CCustom2Dlg)
	enum { IDD = IDD_CUSTOM2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustom2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCustom2Dlg)
	afx_msg void OnSelectorDs();
	afx_msg void OnSelectorRank();
	afx_msg void OnSelectorRoulettewheel();
	afx_msg void OnSelectorSrs();
	afx_msg void OnSelectorTournament();
	afx_msg void OnSelectorUniform();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelectorDefault();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	int selector_which;
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTM2DLG_H__2A867977_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
