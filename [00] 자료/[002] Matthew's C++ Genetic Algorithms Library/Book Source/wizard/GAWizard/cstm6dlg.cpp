// cstm6dlg.cpp : implementation file
//

#include "stdafx.h"
#include "GAWizard.h"
#include "cstm6dlg.h"
#include "GAWizardaw.h"

#ifdef _PSEUDO_DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustom6Dlg dialog


CCustom6Dlg::CCustom6Dlg()
	: CAppWizStepDlg(CCustom6Dlg::IDD)
{
	//{{AFX_DATA_INIT(CCustom6Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	mutator_which = SELECT_MUTATOR_DEFAULT;
}


void CCustom6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CAppWizStepDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustom6Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

// This is called whenever the user presses Next, Back, or Finish with this step
//  present.  Do all validation & data exchange from the dialog in this function.
BOOL CCustom6Dlg::OnDismiss()
{
	if (!UpdateData(TRUE))
		return FALSE;

	// TODO: Set template variables based on the dialog's data.
	dr(mutator_default);
	dr(mutator_swap);
	dr(mutator_flip);
	dr(mutator_destructive);
	dr(mutator_swapsubtree);
	dr(mutator_swapnode);
	dr(mutator_realgaussian);
	dr(mutator_realuniform);

	switch(mutator_which)
	{
	case SELECT_MUTATOR_DEFAULT: ds(mutator_default, 1); break;
	case SELECT_MUTATOR_SWAP: ds(mutator_swap, 1); break;
	case SELECT_MUTATOR_FLIP: ds(mutator_flip, 1); break;
	case SELECT_MUTATOR_DESTRUCTIVE: ds(mutator_destructive, 1); break;
	case SELECT_MUTATOR_SWAPSUBTREE: ds(mutator_swapsubtree, 1); break;
	case SELECT_MUTATOR_SWAPNODE: ds(mutator_swapnode, 1); break;
	case SELECT_MUTATOR_REALGAUSSIAN: ds(mutator_realgaussian, 1); break;
	case SELECT_MUTATOR_REALUNIFORM: ds(mutator_realuniform, 1); break;
	}

	return TRUE;	// return FALSE if the dialog shouldn't be dismissed
}


BEGIN_MESSAGE_MAP(CCustom6Dlg, CAppWizStepDlg)
	//{{AFX_MSG_MAP(CCustom6Dlg)
	ON_BN_CLICKED(IDC_MUTATOR_DEFAULT, OnMutatorDefault)
	ON_BN_CLICKED(IDC_MUTATOR_DESTRUCTIVE, OnMutatorDestructive)
	ON_BN_CLICKED(IDC_MUTATOR_FLIP, OnMutatorFlip)
	ON_BN_CLICKED(IDC_MUTATOR_SWAP, OnMutatorSwap)
	ON_BN_CLICKED(IDC_MUTATOR_SwapNodeMutator, OnMUTATORSwapNodeMutator)
	ON_BN_CLICKED(IDC_MUTATOR_SWAPSUBTREE, OnMutatorSwapsubtree)
	ON_BN_CLICKED(IDC_MUTATOR_REALGAUSSIAN, OnMutatorRealgaussian)
	ON_BN_CLICKED(IDC_MUTATOR_UNIFORM, OnMutatorUniform)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCustom6Dlg message handlers

BOOL CCustom6Dlg::OnInitDialog() 
{
	CAppWizStepDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton *)GetDlgItem(IDC_MUTATOR_DEFAULT))->SetCheck(1);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCustom6Dlg::OnMutatorDefault() 
{
	// TODO: Add your control notification handler code here
	mutator_which = SELECT_MUTATOR_DEFAULT;
	
}

void CCustom6Dlg::OnMutatorDestructive() 
{
	// TODO: Add your control notification handler code here
	mutator_which = SELECT_MUTATOR_DESTRUCTIVE;
	
}

void CCustom6Dlg::OnMutatorFlip() 
{
	// TODO: Add your control notification handler code here
	mutator_which = SELECT_MUTATOR_FLIP;
	
}

void CCustom6Dlg::OnMutatorSwap() 
{
	// TODO: Add your control notification handler code here
	mutator_which = SELECT_MUTATOR_SWAP;
	
}

void CCustom6Dlg::OnMUTATORSwapNodeMutator() 
{
	// TODO: Add your control notification handler code here
	mutator_which = SELECT_MUTATOR_SWAPNODE;
	
}

void CCustom6Dlg::OnMutatorSwapsubtree() 
{
	// TODO: Add your control notification handler code here
	mutator_which = SELECT_MUTATOR_SWAPSUBTREE;
	
}

void CCustom6Dlg::OnMutatorRealgaussian() 
{
	// TODO: Add your control notification handler code here
	mutator_which = SELECT_MUTATOR_REALGAUSSIAN;
	
}

void CCustom6Dlg::OnMutatorUniform() 
{
	// TODO: Add your control notification handler code here
	mutator_which = SELECT_MUTATOR_REALUNIFORM;
	
}
