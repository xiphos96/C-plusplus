// cstm7dlg.cpp : implementation file
//

#include "stdafx.h"
#include "GAWizard.h"
#include "cstm7dlg.h"
#include "GAWizardaw.h"

#ifdef _PSEUDO_DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustom7Dlg dialog


CCustom7Dlg::CCustom7Dlg()
	: CAppWizStepDlg(CCustom7Dlg::IDD)
{
	//{{AFX_DATA_INIT(CCustom7Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	initializer_which = SELECT_INITIALIZER_DEFAULT;
}


void CCustom7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CAppWizStepDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustom7Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

// This is called whenever the user presses Next, Back, or Finish with this step
//  present.  Do all validation & data exchange from the dialog in this function.
BOOL CCustom7Dlg::OnDismiss()
{
	if (!UpdateData(TRUE))
		return FALSE;

	// TODO: Set template variables based on the dialog's data.
	dr(initializer_default);
	dr(initializer_uniform);
	dr(initializer_set);
	dr(initializer_unset);
	dr(initializer_ordered);

	switch(initializer_which)
	{
	case SELECT_INITIALIZER_DEFAULT: ds(initializer_default, 1); break;
	case SELECT_INITIALIZER_UNIFORM: ds(initializer_uniform, 1); break;
	case SELECT_INITIALIZER_SET: ds(initializer_set, 1); break;
	case SELECT_INITIALIZER_UNSET: ds(initializer_unset, 1); break;
	case SELECT_INITIALIZER_ORDERED: ds(initializer_ordered, 1); break;
	}

	return TRUE;	// return FALSE if the dialog shouldn't be dismissed
}


BEGIN_MESSAGE_MAP(CCustom7Dlg, CAppWizStepDlg)
	//{{AFX_MSG_MAP(CCustom7Dlg)
	ON_BN_CLICKED(IDC_INITIALIZER_DEFAULT, OnInitializerDefault)
	ON_BN_CLICKED(IDC_INITIALIZER_SET, OnInitializerSet)
	ON_BN_CLICKED(IDC_INITIALIZER_UNIFORM, OnInitializerUniform)
	ON_BN_CLICKED(IDC_INITIALIZER_UNSET, OnInitializerUnset)
	ON_BN_CLICKED(IDC_INITIALIZER_ORDERED, OnInitializerOrdered)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCustom7Dlg message handlers

BOOL CCustom7Dlg::OnInitDialog() 
{
	CAppWizStepDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton *)GetDlgItem(IDC_INITIALIZER_DEFAULT))->SetCheck(1);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCustom7Dlg::OnInitializerDefault() 
{
	// TODO: Add your control notification handler code here
	initializer_which = SELECT_INITIALIZER_DEFAULT;
	
}

void CCustom7Dlg::OnInitializerSet() 
{
	// TODO: Add your control notification handler code here
	initializer_which = SELECT_INITIALIZER_SET;
	
}

void CCustom7Dlg::OnInitializerUniform() 
{
	// TODO: Add your control notification handler code here
	initializer_which = SELECT_INITIALIZER_UNIFORM;
	
}

void CCustom7Dlg::OnInitializerUnset() 
{
	// TODO: Add your control notification handler code here
	initializer_which = SELECT_INITIALIZER_UNSET;
	
}

void CCustom7Dlg::OnInitializerOrdered() 
{
	// TODO: Add your control notification handler code here
	initializer_which = SELECT_INITIALIZER_ORDERED;
	
}
