#if !defined(AFX_CSTM4DLG_H__2A86797B_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
#define AFX_CSTM4DLG_H__2A86797B_411D_11D4_B08A_00C0268E7D02__INCLUDED_

// cstm4dlg.h : header file
//

#define SELECT_GENOME_1DBINARYSTRING	1
#define SELECT_GENOME_BIN2DEC			2
#define SELECT_GENOME_2DBINARYSTRING	3
#define SELECT_GENOME_3DBINARYSTRING	4
#define SELECT_GENOME_1DARRAY			5
#define SELECT_GENOME_1DARRAYALLELE		6
#define SELECT_GENOME_STRING			7
#define SELECT_GENOME_REAL				8
#define SELECT_GENOME_2DARRAY			9
#define SELECT_GENOME_2DARRAYALLELE		10
#define SELECT_GENOME_3DARRAY			11
#define SELECT_GENOME_3DARRAYALLELE		12
#define SELECT_GENOME_LIST				13
#define SELECT_GENOME_TREE				14

/////////////////////////////////////////////////////////////////////////////
// CCustom4Dlg dialog

class CCustom4Dlg : public CAppWizStepDlg
{
// Construction
public:
	CCustom4Dlg();
	virtual BOOL OnDismiss();

// Dialog Data
	//{{AFX_DATA(CCustom4Dlg)
	enum { IDD = IDD_CUSTOM4 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustom4Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCustom4Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnGenome1darray();
	afx_msg void OnGenome1darrayallele();
	afx_msg void OnGenome1dbinarystring();
	afx_msg void OnGenome2darray();
	afx_msg void OnGenome2darrayallele();
	afx_msg void OnGenome2dbinarystring();
	afx_msg void OnGenome3darray();
	afx_msg void OnGenome3darrayallele();
	afx_msg void OnGenome3dbinarystring();
	afx_msg void OnGenomeBin2dec();
	afx_msg void OnGenomeList();
	afx_msg void OnGenomeReal();
	afx_msg void OnGenomeString();
	afx_msg void OnGenomeTree();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	int genome_which;
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTM4DLG_H__2A86797B_411D_11D4_B08A_00C0268E7D02__INCLUDED_)
