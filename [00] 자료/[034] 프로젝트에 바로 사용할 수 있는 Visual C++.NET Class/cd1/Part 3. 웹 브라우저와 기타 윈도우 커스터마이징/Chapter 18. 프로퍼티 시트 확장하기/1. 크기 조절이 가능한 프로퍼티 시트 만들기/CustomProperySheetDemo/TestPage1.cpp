// TestPage1.cpp : implementation file
//

#include "stdafx.h"
#include "custompropertysheetdemo.h"
#include "TestPage1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestPage1 property page

IMPLEMENT_DYNCREATE(CTestPage1, CPropertyPage)

CTestPage1::CTestPage1() : CPropertyPage(CTestPage1::IDD)
{
	//{{AFX_DATA_INIT(CTestPage1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CTestPage1::~CTestPage1()
{
}

void CTestPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestPage1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestPage1, CPropertyPage)
	//{{AFX_MSG_MAP(CTestPage1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestPage1 message handlers
