#if !defined(AFX_TESTSHEET_H__746FB950_C44F_4EFF_B4FB_DD35027A653E__INCLUDED_)
#define AFX_TESTSHEET_H__746FB950_C44F_4EFF_B4FB_DD35027A653E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestSheet

#include "CustomPropertySheet.h"

#include "TestPage1.h"
#include "TestPage2.h"


class CTestSheet : public CCustomPropertySheet
{
	DECLARE_DYNAMIC(CTestSheet)

// Construction
public:
	CTestSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CTestSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
	CTestPage1	m_Page1;
	CTestPage2	m_Page2;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestSheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTestSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTSHEET_H__746FB950_C44F_4EFF_B4FB_DD35027A653E__INCLUDED_)
