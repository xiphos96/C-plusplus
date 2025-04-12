// TestPage2.cpp : implementation file
//

#include "stdafx.h"
#include "custompropertysheetdemo.h"
#include "TestPage2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestPage2 property page

IMPLEMENT_DYNCREATE(CTestPage2, CPropertyPage)

CTestPage2::CTestPage2() : CPropertyPage(CTestPage2::IDD)
{
	//{{AFX_DATA_INIT(CTestPage2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CTestPage2::~CTestPage2()
{
}

void CTestPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestPage2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestPage2, CPropertyPage)
	//{{AFX_MSG_MAP(CTestPage2)
	ON_BN_CLICKED(IDC_ERASE_BUTTON, OnEraseButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestPage2 message handlers

void CTestPage2::OnEraseButton() 
{
	GetDlgItem(IDC_EDIT1)->SetWindowText("");
}
