// TestSheet.cpp : implementation file
//

#include "stdafx.h"
#include "Custompropertysheetdemo.h"
#include "TestSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestSheet

IMPLEMENT_DYNAMIC(CTestSheet, CCustomPropertySheet)

CTestSheet::CTestSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CCustomPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_Page1);
	AddPage(&m_Page2);
}

CTestSheet::CTestSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CCustomPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_Page1);
	AddPage(&m_Page2);
}

CTestSheet::~CTestSheet()
{
}


BEGIN_MESSAGE_MAP(CTestSheet, CCustomPropertySheet)
	//{{AFX_MSG_MAP(CTestSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestSheet message handlers
