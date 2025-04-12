#if !defined(AFX_GAWIZARDAW_H__7DCBFD2E_42C8_11D4_B08A_00C0268E7D02__INCLUDED_)
#define AFX_GAWIZARDAW_H__7DCBFD2E_42C8_11D4_B08A_00C0268E7D02__INCLUDED_

// GAWizardaw.h : header file
//

class CDialogChooser;

// All function calls made by mfcapwz.dll to this custom AppWizard (except for
//  GetCustomAppWizClass-- see GAWizard.cpp) are through this class.  You may
//  choose to override more of the CCustomAppWiz virtual functions here to
//  further specialize the behavior of this custom AppWizard.
class CGAWizardAppWiz : public CCustomAppWiz
{
public:
	virtual CAppWizStepDlg* Next(CAppWizStepDlg* pDlg);
	virtual CAppWizStepDlg* Back(CAppWizStepDlg* pDlg);
		
	virtual void InitCustomAppWiz();
	virtual void ExitCustomAppWiz();
	virtual void CustomizeProject(IBuildProject* pProject);

protected:
	CDialogChooser* m_pChooser;
};

// This declares the one instance of the CGAWizardAppWiz class.  You can access
//  m_Dictionary and any other public members of this class through the
//  global GAWizardaw.  (Its definition is in GAWizardaw.cpp.)
extern CGAWizardAppWiz GAWizardaw;
extern CString M;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAWIZARDAW_H__7DCBFD2E_42C8_11D4_B08A_00C0268E7D02__INCLUDED_)
