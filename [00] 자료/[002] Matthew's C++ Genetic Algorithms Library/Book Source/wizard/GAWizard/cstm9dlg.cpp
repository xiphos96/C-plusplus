// cstm9dlg.cpp : implementation file
//

#include "stdafx.h"
#include "GAWizard.h"
#include "cstm9dlg.h"
#include "GAWizardaw.h"

#ifdef _PSEUDO_DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustom9Dlg dialog


CCustom9Dlg::CCustom9Dlg()
	: CAppWizStepDlg(CCustom9Dlg::IDD)
{
	//{{AFX_DATA_INIT(CCustom9Dlg)
	m_GenomeDepth = 10;
	m_GenomeHeight = 10;
	m_VarMax = 0.0f;
	m_VarMin = 0.0f;
	m_GenomeNBit = 1;
	m_NGen = 100;
	m_NRepl = 5;
	m_NVar = 1;
	m_PConv = 0.99f;
	m_PCross = 0.6f;
	m_PMut = 0.01f;
	m_PopSize = 50;
	m_PRepl = 0.1f;
	m_GenomeWidth = 10;
	//}}AFX_DATA_INIT
}


void CCustom9Dlg::DoDataExchange(CDataExchange* pDX)
{
	CAppWizStepDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustom9Dlg)
	DDX_Control(pDX, IDC_SPIN_WIDTH, m_SpinWidth);
	DDX_Control(pDX, IDC_SPIN_POPSIZE, m_SpinPopSize);
	DDX_Control(pDX, IDC_SPIN_NVAR, m_SpinNVar);
	DDX_Control(pDX, IDC_SPIN_NREPLACEMENT, m_SpinNRepl);
	DDX_Control(pDX, IDC_SPIN_NGEN, m_SpinNGen);
	DDX_Control(pDX, IDC_SPIN_NBIT, m_SpinNBit);
	DDX_Control(pDX, IDC_SPIN_HEIGHT, m_SpinHeight);
	DDX_Control(pDX, IDC_SPIN_DEPTH, m_SpinDepth);
	DDX_Text(pDX, IDC_EDIT_DEPTH, m_GenomeDepth);
	DDX_Text(pDX, IDC_EDIT_HEIGHT, m_GenomeHeight);
	DDX_Text(pDX, IDC_EDIT_MAX, m_VarMax);
	DDX_Text(pDX, IDC_EDIT_MIN, m_VarMin);
	DDX_Text(pDX, IDC_EDIT_NBIT, m_GenomeNBit);
	DDX_Text(pDX, IDC_EDIT_NGEN, m_NGen);
	DDX_Text(pDX, IDC_EDIT_NREPLACEMENT, m_NRepl);
	DDX_Text(pDX, IDC_EDIT_NVAR, m_NVar);
	DDX_Text(pDX, IDC_EDIT_PCONVERGENCE, m_PConv);
	DDX_Text(pDX, IDC_EDIT_PCROSSOVER, m_PCross);
	DDX_Text(pDX, IDC_EDIT_PMUTATION, m_PMut);
	DDX_Text(pDX, IDC_EDIT_POPSIZE, m_PopSize);
	DDX_Text(pDX, IDC_EDIT_PREPLACEMENT, m_PRepl);
	DDX_Text(pDX, IDC_EDIT_WIDTH, m_GenomeWidth);
	//}}AFX_DATA_MAP
}

// This is called whenever the user presses Next, Back, or Finish with this step
//  present.  Do all validation & data exchange from the dialog in this function.
BOOL CCustom9Dlg::OnDismiss()
{
	if (!UpdateData(TRUE))
		return FALSE;

	// TODO: Set template variables based on the dialog's data.
	dsi(popsize,m_PopSize);
	dsi(ngen,m_NGen);
	dsf(pmut,m_PMut);
	dsf(pcross,m_PCross);
	dsf(pconv,m_PConv);
	dsf(prepl,m_PRepl);
	dsi(nrepl,m_NRepl);
	dsi(width,m_GenomeWidth);
	dsi(height,m_GenomeHeight);
	dsi(depth,m_GenomeDepth);
	dsi(nvar,m_NVar);
	dsi(nbit,m_GenomeNBit);
	dsf(varmin,m_VarMin);
	dsf(varmax,m_VarMax);
	dsi(popsize,m_PopSize);
	dsi(ngen,m_NGen);
	
	return TRUE;	// return FALSE if the dialog shouldn't be dismissed
}


BEGIN_MESSAGE_MAP(CCustom9Dlg, CAppWizStepDlg)
	//{{AFX_MSG_MAP(CCustom9Dlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCustom9Dlg message handlers

BOOL CCustom9Dlg::OnInitDialog() 
{
	CAppWizStepDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_SpinWidth.SetRange(0,1000);
	m_SpinHeight.SetRange(0,1000);
	m_SpinDepth.SetRange(0,1000);
	m_SpinPopSize.SetRange(0,1000);
	m_SpinNVar.SetRange(0,1000);
	m_SpinNGen.SetRange(0,1000);
	m_SpinNBit.SetRange(0,1000);
	m_SpinNRepl.SetRange(0,1000);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
