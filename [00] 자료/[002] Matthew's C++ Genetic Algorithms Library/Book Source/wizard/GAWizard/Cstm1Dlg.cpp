// cstm1dlg.cpp : implementation file
//

#include "stdafx.h"
#include "GAWizard.h"
#include "cstm1dlg.h"
#include "GAWizardaw.h"

#ifdef _PSEUDO_DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustom1Dlg dialog


CCustom1Dlg::CCustom1Dlg()
	: CAppWizStepDlg(CCustom1Dlg::IDD)
{
	//{{AFX_DATA_INIT(CCustom1Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	ga_which = SELECT_GA_SIMPLE;
}


void CCustom1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CAppWizStepDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustom1Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

// This is called whenever the user presses Next, Back, or Finish with this step
//  present.  Do all validation & data exchange from the dialog in this function.
BOOL CCustom1Dlg::OnDismiss()
{
	if (!UpdateData(TRUE))
		return FALSE;

	// TODO: Set template variables based on the dialog's data.
	dr(ga_simple);
	dr(ga_incremental);
	dr(ga_steadystate);
	dr(ga_deme);

	switch(ga_which)
	{
	case SELECT_GA_SIMPLE: ds(ga_simple, 1); break;
	case SELECT_GA_INCREMENTAL: ds(ga_incremental, 1); break;
	case SELECT_GA_STEADYSTATE: ds(ga_steadystate, 1); break;
	case SELECT_GA_DEME: ds(ga_deme, 1); break;
	}

	return TRUE;	// return FALSE if the dialog shouldn't be dismissed
}


BEGIN_MESSAGE_MAP(CCustom1Dlg, CAppWizStepDlg)
	//{{AFX_MSG_MAP(CCustom1Dlg)
	ON_BN_CLICKED(IDC_GA_SIMPLE, OnGaSimple)
	ON_BN_CLICKED(IDC_GA_INCREMENTAL, OnGaIncremental)
	ON_BN_CLICKED(IDC_GA_STEADYSTATE, OnGaSteadystate)
	ON_BN_CLICKED(IDC_GA_DEME, OnGaDeme)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCustom1Dlg message handlers

void CCustom1Dlg::OnGaSimple() 
{
	// TODO: Add your control notification handler code here
	ga_which = SELECT_GA_SIMPLE;
}

void CCustom1Dlg::OnGaIncremental() 
{
	// TODO: Add your control notification handler code here
	ga_which = SELECT_GA_INCREMENTAL;
}

void CCustom1Dlg::OnGaSteadystate() 
{
	// TODO: Add your control notification handler code here
	ga_which = SELECT_GA_STEADYSTATE;
}

void CCustom1Dlg::OnGaDeme() 
{
	// TODO: Add your control notification handler code here
	ga_which = SELECT_GA_DEME;	
}

BOOL CCustom1Dlg::OnInitDialog() 
{
	CAppWizStepDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton *)GetDlgItem(IDC_GA_SIMPLE))->SetCheck(1);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
