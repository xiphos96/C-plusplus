// cstm3dlg.cpp : implementation file
//

#include "stdafx.h"
#include "GAWizard.h"
#include "cstm3dlg.h"
#include "GAWizardaw.h"

#ifdef _PSEUDO_DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustom3Dlg dialog


CCustom3Dlg::CCustom3Dlg()
	: CAppWizStepDlg(CCustom3Dlg::IDD)
{
	//{{AFX_DATA_INIT(CCustom3Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	scaling_which = SELECT_SCALING_DEFAULT;
}


void CCustom3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CAppWizStepDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustom3Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

// This is called whenever the user presses Next, Back, or Finish with this step
//  present.  Do all validation & data exchange from the dialog in this function.
BOOL CCustom3Dlg::OnDismiss()
{
	if (!UpdateData(TRUE))
		return FALSE;

	// TODO: Set template variables based on the dialog's data.
	dr(scaling_no);
	dr(scaling_linear);
	dr(scaling_sigmatruncation);
	dr(scaling_powerlaw);
	dr(scaling_sharing);
	dr(scaling_default);

	switch(scaling_which)
	{
	case SELECT_SCALING_NO: ds(scaling_no, 1); break;
	case SELECT_SCALING_LINEAR: ds(scaling_linear, 1); break;
	case SELECT_SCALING_SIGMATRUNCATION: ds(scaling_sigmatruncation, 1); break;
	case SELECT_SCALING_POWERLAW: ds(scaling_powerlaw, 1); break;
	case SELECT_SCALING_SHARING: ds(scaling_sharing, 1); break;
	case SELECT_SCALING_DEFAULT: ds(scaling_default, 1); break;
	}

	return TRUE;	// return FALSE if the dialog shouldn't be dismissed
}


BEGIN_MESSAGE_MAP(CCustom3Dlg, CAppWizStepDlg)
	//{{AFX_MSG_MAP(CCustom3Dlg)
	ON_BN_CLICKED(IDC_SCALING_LINEAR, OnScalingLinear)
	ON_BN_CLICKED(IDC_SCALING_NO, OnScalingNo)
	ON_BN_CLICKED(IDC_SCALING_POWERLAW, OnScalingPowerlaw)
	ON_BN_CLICKED(IDC_SCALING_SHARING, OnScalingSharing)
	ON_BN_CLICKED(IDC_SCALING_SIGMATRUNCATION, OnScalingSigmatruncation)
	ON_BN_CLICKED(IDC_SCALING_DEFAULT, OnScalingDefault)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCustom3Dlg message handlers

void CCustom3Dlg::OnScalingLinear() 
{
	// TODO: Add your control notification handler code here
	scaling_which = SELECT_SCALING_LINEAR;
	
}

void CCustom3Dlg::OnScalingNo() 
{
	// TODO: Add your control notification handler code here
	scaling_which = SELECT_SCALING_NO;
	
}

void CCustom3Dlg::OnScalingPowerlaw() 
{
	// TODO: Add your control notification handler code here
	scaling_which = SELECT_SCALING_POWERLAW;
	
}

void CCustom3Dlg::OnScalingSharing() 
{
	// TODO: Add your control notification handler code here
	scaling_which = SELECT_SCALING_SHARING;
	
}

void CCustom3Dlg::OnScalingSigmatruncation() 
{
	// TODO: Add your control notification handler code here
	scaling_which = SELECT_SCALING_SIGMATRUNCATION;
	
}

BOOL CCustom3Dlg::OnInitDialog() 
{
	CAppWizStepDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton *)GetDlgItem(IDC_SCALING_DEFAULT))->SetCheck(1);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCustom3Dlg::OnScalingDefault() 
{
	// TODO: Add your control notification handler code here
	scaling_which = SELECT_SCALING_DEFAULT;
	
}
