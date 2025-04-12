// imagetest.h : main header file for the IMAGETEST application
//

#if !defined(AFX_IMAGETEST_H__E58C5A12_CA8F_4EF8_8BFD_C6222E96A315__INCLUDED_)
#define AFX_IMAGETEST_H__E58C5A12_CA8F_4EF8_8BFD_C6222E96A315__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CImagetestApp:
// See imagetest.cpp for the implementation of this class
//

class CImagetestApp : public CWinApp
{
public:
	CImagetestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImagetestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CImagetestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGETEST_H__E58C5A12_CA8F_4EF8_8BFD_C6222E96A315__INCLUDED_)
