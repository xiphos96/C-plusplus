// GAWizardaw.cpp : implementation file
//

#include "stdafx.h"
#include "GAWizard.h"
#include "GAWizardaw.h"
#include "chooser.h"

#ifdef _PSEUDO_DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// This is called immediately after the custom AppWizard is loaded.  Initialize
//  the state of the custom AppWizard here.
void CGAWizardAppWiz::InitCustomAppWiz()
{
	// Create a new dialog chooser; CDialogChooser's constructor initializes
	//  its internal array with pointers to the steps.
	m_pChooser = new CDialogChooser;

	// Set the maximum number of steps.
	SetNumberOfSteps(LAST_DLG);

	// TODO: Add any other custom AppWizard-wide initialization here.
	ds(ga_simple,1);
	ds(selector_default,1);
	ds(scaling_default,1);
	ds(genome_bin2dec,1);
	ds(crossover_default,1);
	ds(mutator_default,1);
	ds(initializer_default,1);
	ds(comparator_default,1);
	ds(terminator_generation,1);
	dsi(popsize,50);
	dsi(ngen,100);
	dsf(pmut,0.01);
	dsf(pcross,0.6);
	dsf(pconv,0.99);
	dsf(prepl,0.1);
	dsi(nrepl,5);
	dsi(width,10);
	dsi(height,10);
	dsi(depth,10);
	dsi(nvar,1);
	dsi(nbit,1);
	dsf(varmin,0.0);
	dsf(varmax,0.0);
}

// This is called just before the custom AppWizard is unloaded.
void CGAWizardAppWiz::ExitCustomAppWiz()
{
	// Deallocate memory used for the dialog chooser
	ASSERT(m_pChooser != NULL);
	delete m_pChooser;
	m_pChooser = NULL;

	// TODO: Add code here to deallocate resources used by the custom AppWizard
}

// This is called when the user clicks "Create..." on the New Project dialog
//  or "Next" on one of the custom AppWizard's steps.
CAppWizStepDlg* CGAWizardAppWiz::Next(CAppWizStepDlg* pDlg)
{
	// Delegate to the dialog chooser
	return m_pChooser->Next(pDlg);
}

// This is called when the user clicks "Back" on one of the custom
//  AppWizard's steps.
CAppWizStepDlg* CGAWizardAppWiz::Back(CAppWizStepDlg* pDlg)
{
	// Delegate to the dialog chooser
	return m_pChooser->Back(pDlg);
}

void CGAWizardAppWiz::CustomizeProject(IBuildProject* pProject)
{
	// TODO: Add code here to customize the project.  If you don't wish
	//  to customize project, you may remove this virtual override.
	
	// This is called immediately after the default Debug and Release
	//  configurations have been created for each platform.  You may customize
	//  existing configurations on this project by using the methods
	//  of IBuildProject and IConfiguration such as AddToolSettings,
	//  RemoveToolSettings, and AddCustomBuildStep. These are documented in
	//  the Developer Studio object model documentation.

	// WARNING!!  IBuildProject and all interfaces you can get from it are OLE
	//  COM interfaces.  You must be careful to release all new interfaces
	//  you acquire.  In accordance with the standard rules of COM, you must
	//  NOT release pProject, unless you explicitly AddRef it, since pProject
	//  is passed as an "in" parameter to this function.  See the documentation
	//  on CCustomAppWiz::CustomizeProject for more information.
}


// Here we define one instance of the CGAWizardAppWiz class.  You can access
//  m_Dictionary and any other public members of this class through the
//  global GAWizardaw.
CGAWizardAppWiz GAWizardaw;
CString M;

