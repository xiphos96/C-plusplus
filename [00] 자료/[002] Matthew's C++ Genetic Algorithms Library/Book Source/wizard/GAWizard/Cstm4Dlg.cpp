// cstm4dlg.cpp : implementation file
//

#include "stdafx.h"
#include "GAWizard.h"
#include "cstm4dlg.h"
#include "GAWizardaw.h"

#ifdef _PSEUDO_DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustom4Dlg dialog


CCustom4Dlg::CCustom4Dlg()
	: CAppWizStepDlg(CCustom4Dlg::IDD)
{
	//{{AFX_DATA_INIT(CCustom4Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	genome_which = SELECT_GENOME_BIN2DEC;
}


void CCustom4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CAppWizStepDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustom4Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

// This is called whenever the user presses Next, Back, or Finish with this step
//  present.  Do all validation & data exchange from the dialog in this function.
BOOL CCustom4Dlg::OnDismiss()
{
	if (!UpdateData(TRUE))
		return FALSE;

	// TODO: Set template variables based on the dialog's data.
	dr(genome_1dbinarystring);
	dr(genome_bin2dec);
	dr(genome_2dbinarystring);
	dr(genome_3dbinarystring);
	dr(genome_1darray);
	dr(genome_1darrayallele);
	dr(genome_string);
	dr(genome_real);
	dr(genome_2darray);
	dr(genome_2darrayallele);
	dr(genome_3darray);
	dr(genome_3darrayallele);
	dr(genome_list);
	dr(genome_tree);

	switch(genome_which)
	{
	case SELECT_GENOME_1DBINARYSTRING: ds(genome_1dbinarystring, 1); break;
	case SELECT_GENOME_BIN2DEC: ds(genome_bin2dec, 1); break;
	case SELECT_GENOME_2DBINARYSTRING: ds(genome_2dbinarystring, 1); break;
	case SELECT_GENOME_3DBINARYSTRING: ds(genome_3dbinarystring, 1); break;
	case SELECT_GENOME_1DARRAY: ds(genome_1darray, 1); break;
	case SELECT_GENOME_1DARRAYALLELE: ds(genome_1darrayallele, 1); break;
	case SELECT_GENOME_STRING: ds(genome_string, 1); break;
	case SELECT_GENOME_REAL: ds(genome_real, 1); break;
	case SELECT_GENOME_2DARRAY: ds(genome_2darray, 1); break;
	case SELECT_GENOME_2DARRAYALLELE: ds(genome_2darrayallele, 1); break;
	case SELECT_GENOME_3DARRAY: ds(genome_3darray, 1); break;
	case SELECT_GENOME_3DARRAYALLELE: ds(genome_3darrayallele, 1); break;
	case SELECT_GENOME_LIST: ds(genome_list, 1); break;
	case SELECT_GENOME_TREE: ds(genome_tree, 1); break;
	}

	return TRUE;	// return FALSE if the dialog shouldn't be dismissed
}


BEGIN_MESSAGE_MAP(CCustom4Dlg, CAppWizStepDlg)
	//{{AFX_MSG_MAP(CCustom4Dlg)
	ON_BN_CLICKED(IDC_GENOME_1DARRAY, OnGenome1darray)
	ON_BN_CLICKED(IDC_GENOME_1DARRAYALLELE, OnGenome1darrayallele)
	ON_BN_CLICKED(IDC_GENOME_1DBINARYSTRING, OnGenome1dbinarystring)
	ON_BN_CLICKED(IDC_GENOME_2DARRAY, OnGenome2darray)
	ON_BN_CLICKED(IDC_GENOME_2DARRAYALLELE, OnGenome2darrayallele)
	ON_BN_CLICKED(IDC_GENOME_2DBINARYSTRING, OnGenome2dbinarystring)
	ON_BN_CLICKED(IDC_GENOME_3DARRAY, OnGenome3darray)
	ON_BN_CLICKED(IDC_GENOME_3DARRAYALLELE, OnGenome3darrayallele)
	ON_BN_CLICKED(IDC_GENOME_3DBINARYSTRING, OnGenome3dbinarystring)
	ON_BN_CLICKED(IDC_GENOME_BIN2DEC, OnGenomeBin2dec)
	ON_BN_CLICKED(IDC_GENOME_LIST, OnGenomeList)
	ON_BN_CLICKED(IDC_GENOME_REAL, OnGenomeReal)
	ON_BN_CLICKED(IDC_GENOME_STRING, OnGenomeString)
	ON_BN_CLICKED(IDC_GENOME_TREE, OnGenomeTree)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCustom4Dlg message handlers

BOOL CCustom4Dlg::OnInitDialog() 
{
	CAppWizStepDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton *)GetDlgItem(IDC_GENOME_BIN2DEC))->SetCheck(1);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCustom4Dlg::OnGenome1darray() 
{
	// TODO: Add your control notification handler code here
	genome_which = SELECT_GENOME_1DARRAY;
	
}

void CCustom4Dlg::OnGenome1darrayallele() 
{
	// TODO: Add your control notification handler code here
	genome_which = SELECT_GENOME_1DARRAYALLELE;
	
}

void CCustom4Dlg::OnGenome1dbinarystring() 
{
	// TODO: Add your control notification handler code here
	genome_which = SELECT_GENOME_1DBINARYSTRING;
	
}

void CCustom4Dlg::OnGenome2darray() 
{
	// TODO: Add your control notification handler code here
	genome_which = SELECT_GENOME_2DARRAY;
	
}

void CCustom4Dlg::OnGenome2darrayallele() 
{
	// TODO: Add your control notification handler code here
	genome_which = SELECT_GENOME_2DARRAYALLELE;
	
}

void CCustom4Dlg::OnGenome2dbinarystring() 
{
	// TODO: Add your control notification handler code here
	genome_which = SELECT_GENOME_2DBINARYSTRING;
	
}

void CCustom4Dlg::OnGenome3darray() 
{
	// TODO: Add your control notification handler code here
	genome_which = SELECT_GENOME_3DARRAY;
	
}

void CCustom4Dlg::OnGenome3darrayallele() 
{
	// TODO: Add your control notification handler code here
	genome_which = SELECT_GENOME_3DARRAYALLELE;
	
}

void CCustom4Dlg::OnGenome3dbinarystring() 
{
	// TODO: Add your control notification handler code here
	genome_which = SELECT_GENOME_3DBINARYSTRING;
	
}

void CCustom4Dlg::OnGenomeBin2dec() 
{
	// TODO: Add your control notification handler code here
	genome_which = SELECT_GENOME_BIN2DEC;
	
}

void CCustom4Dlg::OnGenomeList() 
{
	// TODO: Add your control notification handler code here
	genome_which = SELECT_GENOME_LIST;
	
}

void CCustom4Dlg::OnGenomeReal() 
{
	// TODO: Add your control notification handler code here
	genome_which = SELECT_GENOME_REAL;
	
}

void CCustom4Dlg::OnGenomeString() 
{
	// TODO: Add your control notification handler code here
	genome_which = SELECT_GENOME_STRING;
	
}

void CCustom4Dlg::OnGenomeTree() 
{
	// TODO: Add your control notification handler code here
	genome_which = SELECT_GENOME_TREE;
	
}
