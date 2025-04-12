// cstm8dlg.cpp : implementation file
//

#include "stdafx.h"
#include "GAWizard.h"
#include "cstm8dlg.h"
#include "GAWizardaw.h"

#ifdef _PSEUDO_DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustom8Dlg dialog


CCustom8Dlg::CCustom8Dlg()
	: CAppWizStepDlg(CCustom8Dlg::IDD)
{
	//{{AFX_DATA_INIT(CCustom8Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	comparator_which = SELECT_COMPARATOR_DEFAULT;
	terminator_which = SELECT_TERMINATOR_GENERATION;
}


void CCustom8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CAppWizStepDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustom8Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

// This is called whenever the user presses Next, Back, or Finish with this step
//  present.  Do all validation & data exchange from the dialog in this function.
BOOL CCustom8Dlg::OnDismiss()
{
	if (!UpdateData(TRUE))
		return FALSE;

	// TODO: Set template variables based on the dialog's data.
	dr(comparator_default);
	dr(comparator_element);
	dr(comparator_bit);
	dr(comparator_topology);

	dr(terminator_generation);
	dr(terminator_convergence);
	dr(terminator_popconvergence);

	switch(comparator_which)
	{
	case SELECT_COMPARATOR_DEFAULT: ds(comparator_default, 1); break;
	case SELECT_COMPARATOR_ELEMENT: ds(comparator_element, 1); break;
	case SELECT_COMPARATOR_BIT: ds(comparator_bit, 1); break;
	case SELECT_COMPARATOR_TOPOLOGY: ds(comparator_bit, 1); break;
	}

	switch(terminator_which)
	{
	case SELECT_TERMINATOR_GENERATION: ds(terminator_generation, 1); break;
	case SELECT_TERMINATOR_CONVERGENCE: ds(terminator_convergence, 1); break;
	case SELECT_TERMINATOR_POPCONVERGENCE: ds(terminator_popconvergence, 1); break;
	}

	return TRUE;	// return FALSE if the dialog shouldn't be dismissed
}


BEGIN_MESSAGE_MAP(CCustom8Dlg, CAppWizStepDlg)
	//{{AFX_MSG_MAP(CCustom8Dlg)
	ON_BN_CLICKED(IDC_COMPARATOR_BIT, OnComparatorBit)
	ON_BN_CLICKED(IDC_COMPARATOR_DEFAULT, OnComparatorDefault)
	ON_BN_CLICKED(IDC_COMPARATOR_ELEMENT, OnComparatorElement)
	ON_BN_CLICKED(IDC_COMPARATOR_TOPOLOGY, OnComparatorTopology)
	ON_BN_CLICKED(IDC_TERMINATOR_CONVERGENCE, OnTerminatorConvergence)
	ON_BN_CLICKED(IDC_TERMINATOR_GENERATION, OnTerminatorGeneration)
	ON_BN_CLICKED(IDC_TERMINATOR_POPCONVERGENCE, OnTerminatorPopconvergence)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCustom8Dlg message handlers

BOOL CCustom8Dlg::OnInitDialog() 
{
	CAppWizStepDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton *)GetDlgItem(IDC_COMPARATOR_DEFAULT))->SetCheck(1);
	((CButton *)GetDlgItem(IDC_TERMINATOR_GENERATION))->SetCheck(1);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCustom8Dlg::OnComparatorBit() 
{
	// TODO: Add your control notification handler code here
	comparator_which = SELECT_COMPARATOR_BIT;
	
}

void CCustom8Dlg::OnComparatorDefault() 
{
	// TODO: Add your control notification handler code here
	comparator_which = SELECT_COMPARATOR_DEFAULT;
	
}

void CCustom8Dlg::OnComparatorElement() 
{
	// TODO: Add your control notification handler code here
	comparator_which = SELECT_COMPARATOR_ELEMENT;
	
}

void CCustom8Dlg::OnComparatorTopology() 
{
	// TODO: Add your control notification handler code here
	comparator_which = SELECT_COMPARATOR_TOPOLOGY;
	
}

void CCustom8Dlg::OnTerminatorConvergence() 
{
	// TODO: Add your control notification handler code here
	terminator_which = SELECT_TERMINATOR_CONVERGENCE;
	
}

void CCustom8Dlg::OnTerminatorGeneration() 
{
	// TODO: Add your control notification handler code here
	terminator_which = SELECT_TERMINATOR_GENERATION;
	
}

void CCustom8Dlg::OnTerminatorPopconvergence() 
{
	// TODO: Add your control notification handler code here
	terminator_which = SELECT_TERMINATOR_POPCONVERGENCE;
	
}
