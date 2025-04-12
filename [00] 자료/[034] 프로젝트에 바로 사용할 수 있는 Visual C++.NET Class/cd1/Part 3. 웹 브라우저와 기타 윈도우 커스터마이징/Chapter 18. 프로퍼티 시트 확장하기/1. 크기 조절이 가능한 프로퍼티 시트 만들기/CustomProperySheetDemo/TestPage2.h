#if !defined(AFX_TESTPAGE2_H__D434549D_760F_4C5A_B48D_4B41D1089DBA__INCLUDED_)
#define AFX_TESTPAGE2_H__D434549D_760F_4C5A_B48D_4B41D1089DBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestPage2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestPage2 dialog

class CTestPage2 : public CPropertyPage
{
	DECLARE_DYNCREATE(CTestPage2)

// Construction
public:
	CTestPage2();
	~CTestPage2();

// Dialog Data
	//{{AFX_DATA(CTestPage2)
	enum { IDD = IDD_TEST_PAGE2 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTestPage2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTestPage2)
	afx_msg void OnEraseButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPAGE2_H__D434549D_760F_4C5A_B48D_4B41D1089DBA__INCLUDED_)
