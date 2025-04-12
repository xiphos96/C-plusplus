// cstm5dlg.cpp : implementation file
//

#include "stdafx.h"
#include "GAWizard.h"
#include "cstm5dlg.h"
#include "GAWizardaw.h"

#ifdef _PSEUDO_DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustom5Dlg dialog


CCustom5Dlg::CCustom5Dlg()
	: CAppWizStepDlg(CCustom5Dlg::IDD)
{
	//{{AFX_DATA_INIT(CCustom5Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	crossover_which = SELECT_CROSSOVER_DEFAULT;
}


void CCustom5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CAppWizStepDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustom5Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

// This is called whenever the user presses Next, Back, or Finish with this step
//  present.  Do all validation & data exchange from the dialog in this function.
BOOL CCustom5Dlg::OnDismiss()
{
	if (!UpdateData(TRUE))
		return FALSE;

	// TODO: Set template variables based on the dialog's data.
	dr(crossover_default);
	dr(crossover_uniform);
	dr(crossover_evenodd);
	dr(crossover_onepoint);
	dr(crossover_twopoint);
	dr(crossover_partialmatch);
	dr(crossover_order);
	dr(crossover_cycle);
	dr(crossover_realblend);
	dr(crossover_realarithmetic);

	switch(crossover_which)
	{
	case SELECT_CROSSOVER_DEFAULT: ds(crossover_default, 1); break;
	case SELECT_CROSSOVER_UNIFORM: ds(crossover_uniform, 1); break;
	case SELECT_CROSSOVER_EVENODD: ds(crossover_evenodd, 1); break;
	case SELECT_CROSSOVER_ONEPOINT: ds(crossover_onepoint, 1); break;
	case SELECT_CROSSOVER_TWOPOINT: ds(crossover_twopoint, 1); break;
	case SELECT_CROSSOVER_PARTIALMATCH: ds(crossover_partialmatch, 1); break;
	case SELECT_CROSSOVER_ORDER: ds(crossover_order, 1); break;
	case SELECT_CROSSOVER_CYCLE: ds(crossover_cycle, 1); break;
	case SELECT_CROSSOVER_REALBLEND: ds(crossover_realblend, 1); break;
	case SELECT_CROSSOVER_REALARITHMETIC: ds(crossover_realarithmetic, 1); break;
	}

	return TRUE;	// return FALSE if the dialog shouldn't be dismissed
}


BEGIN_MESSAGE_MAP(CCustom5Dlg, CAppWizStepDlg)
	//{{AFX_MSG_MAP(CCustom5Dlg)
	ON_BN_CLICKED(IDC_CROSSOVER_CYCLE, OnCrossoverCycle)
	ON_BN_CLICKED(IDC_CROSSOVER_DEFAULT, OnCrossoverDefault)
	ON_BN_CLICKED(IDC_CROSSOVER_EVENODD, OnCrossoverEvenodd)
	ON_BN_CLICKED(IDC_CROSSOVER_ONEPOINT, OnCrossoverOnepoint)
	ON_BN_CLICKED(IDC_CROSSOVER_ORDER, OnCrossoverOrder)
	ON_BN_CLICKED(IDC_CROSSOVER_PARTIALMATCH, OnCrossoverPartialmatch)
	ON_BN_CLICKED(IDC_CROSSOVER_TWOPOINT, OnCrossoverTwopoint)
	ON_BN_CLICKED(IDC_CROSSOVER_UNIFORM, OnCrossoverUniform)
	ON_BN_CLICKED(IDC_CROSSOVER_REALARITHMETIC, OnCrossoverRealarithmetic)
	ON_BN_CLICKED(IDC_CROSSOVER_REALBLEND, OnCrossoverRealblend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCustom5Dlg message handlers

BOOL CCustom5Dlg::OnInitDialog() 
{
	CAppWizStepDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton *)GetDlgItem(IDC_CROSSOVER_DEFAULT))->SetCheck(1);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCustom5Dlg::OnCrossoverCycle() 
{
	// TODO: Add your control notification handler code here
	crossover_which = SELECT_CROSSOVER_CYCLE;
	
}

void CCustom5Dlg::OnCrossoverDefault() 
{
	// TODO: Add your control notification handler code here
	crossover_which = SELECT_CROSSOVER_DEFAULT;
	
}

void CCustom5Dlg::OnCrossoverEvenodd() 
{
	// TODO: Add your control notification handler code here
	crossover_which = SELECT_CROSSOVER_EVENODD;
	
}

void CCustom5Dlg::OnCrossoverOnepoint() 
{
	// TODO: Add your control notification handler code here
	crossover_which = SELECT_CROSSOVER_ONEPOINT;
	
}

void CCustom5Dlg::OnCrossoverOrder() 
{
	// TODO: Add your control notification handler code here
	crossover_which = SELECT_CROSSOVER_ORDER;
	
}

void CCustom5Dlg::OnCrossoverPartialmatch() 
{
	// TODO: Add your control notification handler code here
	crossover_which = SELECT_CROSSOVER_PARTIALMATCH;
	
}

void CCustom5Dlg::OnCrossoverTwopoint() 
{
	// TODO: Add your control notification handler code here
	crossover_which = SELECT_CROSSOVER_TWOPOINT;
	
}

void CCustom5Dlg::OnCrossoverUniform() 
{
	// TODO: Add your control notification handler code here
	crossover_which = SELECT_CROSSOVER_UNIFORM;
	
}

void CCustom5Dlg::OnCrossoverRealarithmetic() 
{
	// TODO: Add your control notification handler code here
	crossover_which = SELECT_CROSSOVER_REALARITHMETIC;
	
}

void CCustom5Dlg::OnCrossoverRealblend() 
{
	// TODO: Add your control notification handler code here
	crossover_which = SELECT_CROSSOVER_REALBLEND;
	
}
