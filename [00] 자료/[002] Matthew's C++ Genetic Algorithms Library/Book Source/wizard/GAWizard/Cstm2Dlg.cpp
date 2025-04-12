// cstm2dlg.cpp : implementation file
//

#include "stdafx.h"
#include "GAWizard.h"
#include "cstm2dlg.h"
#include "GAWizardaw.h"

#ifdef _PSEUDO_DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustom2Dlg dialog


CCustom2Dlg::CCustom2Dlg()
	: CAppWizStepDlg(CCustom2Dlg::IDD)
{
	//{{AFX_DATA_INIT(CCustom2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	selector_which = SELECT_SELECTOR_DEFAULT;
}


void CCustom2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CAppWizStepDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustom2Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

// This is called whenever the user presses Next, Back, or Finish with this step
//  present.  Do all validation & data exchange from the dialog in this function.
BOOL CCustom2Dlg::OnDismiss()
{
	if (!UpdateData(TRUE))
		return FALSE;

	// TODO: Set template variables based on the dialog's data.
	dr(selector_rank);
	dr(selector_roulettewheel);
	dr(selector_tournament);
	dr(selector_ds);
	dr(selector_srs);
	dr(selector_uniform);
	dr(selector_default);

	switch(selector_which)
	{
	case SELECT_SELECTOR_RANK: ds(selector_rank, 1); break;
	case SELECT_SELECTOR_ROULETTEWHEEL: ds(selector_roulettewheel, 1); break;
	case SELECT_SELECTOR_TOURNAMENT: ds(selector_tournament, 1); break;
	case SELECT_SELECTOR_DS: ds(selector_ds, 1); break;
	case SELECT_SELECTOR_SRS: ds(selector_srs, 1); break;
	case SELECT_SELECTOR_UNIFORM: ds(selector_uniform, 1); break;
	case SELECT_SELECTOR_DEFAULT: ds(selector_default, 1); break;
	}

	return TRUE;	// return FALSE if the dialog shouldn't be dismissed
}


BEGIN_MESSAGE_MAP(CCustom2Dlg, CAppWizStepDlg)
	//{{AFX_MSG_MAP(CCustom2Dlg)
	ON_BN_CLICKED(IDC_SELECTOR_DS, OnSelectorDs)
	ON_BN_CLICKED(IDC_SELECTOR_RANK, OnSelectorRank)
	ON_BN_CLICKED(IDC_SELECTOR_ROULETTEWHEEL, OnSelectorRoulettewheel)
	ON_BN_CLICKED(IDC_SELECTOR_SRS, OnSelectorSrs)
	ON_BN_CLICKED(IDC_SELECTOR_TOURNAMENT, OnSelectorTournament)
	ON_BN_CLICKED(IDC_SELECTOR_UNIFORM, OnSelectorUniform)
	ON_BN_CLICKED(IDC_SELECTOR_DEFAULT, OnSelectorDefault)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCustom2Dlg message handlers

void CCustom2Dlg::OnSelectorDs() 
{
	// TODO: Add your control notification handler code here
	selector_which = SELECT_SELECTOR_DS;
	
}

void CCustom2Dlg::OnSelectorRank() 
{
	// TODO: Add your control notification handler code here
	selector_which = SELECT_SELECTOR_RANK;
}

void CCustom2Dlg::OnSelectorRoulettewheel() 
{
	// TODO: Add your control notification handler code here
	selector_which = SELECT_SELECTOR_ROULETTEWHEEL;
}

void CCustom2Dlg::OnSelectorSrs() 
{
	// TODO: Add your control notification handler code here
	selector_which = SELECT_SELECTOR_SRS;
}

void CCustom2Dlg::OnSelectorTournament() 
{
	// TODO: Add your control notification handler code here
	selector_which = SELECT_SELECTOR_TOURNAMENT;
}

void CCustom2Dlg::OnSelectorUniform() 
{
	// TODO: Add your control notification handler code here
	selector_which = SELECT_SELECTOR_UNIFORM;
}

BOOL CCustom2Dlg::OnInitDialog() 
{
	CAppWizStepDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton *)GetDlgItem(IDC_SELECTOR_DEFAULT))->SetCheck(1);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCustom2Dlg::OnSelectorDefault() 
{
	// TODO: Add your control notification handler code here
	selector_which = SELECT_SELECTOR_DEFAULT;
	
}
