// ChildDlg.cpp : implementation file
//

#include "stdafx.h"
#include "slidingdialog.h"
#include "ChildDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildDlg dialog


CChildDlg::CChildDlg(CWnd* pParent /*=NULL*/)
	: CSlidingDlg(CChildDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChildDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CSlidingDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChildDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChildDlg, CSlidingDlg)
	//{{AFX_MSG_MAP(CChildDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildDlg message handlers
