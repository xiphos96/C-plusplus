#if !defined(AFX_CSTM9DLG_H__7DCBFD4B_42C8_11D4_B08A_00C0268E7D02__INCLUDED_)
#define AFX_CSTM9DLG_H__7DCBFD4B_42C8_11D4_B08A_00C0268E7D02__INCLUDED_

// cstm9dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustom9Dlg dialog

class CCustom9Dlg : public CAppWizStepDlg
{
// Construction
public:
	CCustom9Dlg();
	virtual BOOL OnDismiss();

// Dialog Data
	//{{AFX_DATA(CCustom9Dlg)
	enum { IDD = IDD_CUSTOM9 };
	CSpinButtonCtrl	m_SpinWidth;
	CSpinButtonCtrl	m_SpinPopSize;
	CSpinButtonCtrl	m_SpinNVar;
	CSpinButtonCtrl	m_SpinNRepl;
	CSpinButtonCtrl	m_SpinNGen;
	CSpinButtonCtrl	m_SpinNBit;
	CSpinButtonCtrl	m_SpinHeight;
	CSpinButtonCtrl	m_SpinDepth;
	int		m_GenomeDepth;
	int		m_GenomeHeight;
	float	m_VarMax;
	float	m_VarMin;
	int		m_GenomeNBit;
	int		m_NGen;
	int		m_NRepl;
	int		m_NVar;
	float	m_PConv;
	float	m_PCross;
	float	m_PMut;
	int		m_PopSize;
	float	m_PRepl;
	int		m_GenomeWidth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustom9Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCustom9Dlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTM9DLG_H__7DCBFD4B_42C8_11D4_B08A_00C0268E7D02__INCLUDED_)
