#if !defined(AFX_TESTPAGE1_H__BECC2543_C853_49F1_8B04_CDBCF928AFBE__INCLUDED_)
#define AFX_TESTPAGE1_H__BECC2543_C853_49F1_8B04_CDBCF928AFBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestPage1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestPage1 dialog

class CTestPage1 : public CPropertyPage
{
	DECLARE_DYNCREATE(CTestPage1)

// Construction
public:
	CTestPage1();
	~CTestPage1();

// Dialog Data
	//{{AFX_DATA(CTestPage1)
	enum { IDD = IDD_TEST_PAGE1 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTestPage1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTestPage1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPAGE1_H__BECC2543_C853_49F1_8B04_CDBCF928AFBE__INCLUDED_)
