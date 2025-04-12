// ReportDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dialogtabctrldemo.h"
#include "ReportDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// ���� ���̾�α׿� ���� ���̾�α׿� �����ϱ� ���� �ʿ��� ��� ���ϵ�
#include "DialogTabCtrl.h"
#include "IncomeDlg.h"
#include "OutgoDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CReportDlg dialog


CReportDlg::CReportDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReportDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReportDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CReportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReportDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReportDlg, CDialog)
	//{{AFX_MSG_MAP(CReportDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReportDlg message handlers

BOOL CReportDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// �հ� ��� ����ƽ ��Ʈ���� �ؽ�Ʈ�� �ʱ�ȭ�Ѵ�
	GetDlgItem(IDC_REPORT_STATIC)->SetWindowText("");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

// ���� ���̾�α׿� ���� ���̾�α��� �׸����� �հ踦 ����ϰ� ����ϴ� �Լ�
void CReportDlg::RefreshSum()
{
	// ���̾�α� ���� �����͸� ���Ѵ�
	CDialogTabCtrl	*pTab		= (CDialogTabCtrl*)GetParent();
	// ���� ���̾�α��� �����͸� ���Ѵ�
	CIncomeDlg		*pIncome	= (CIncomeDlg*)pTab->GetDialog(0);
	// ���� ���̾�α��� �����͸� ���Ѵ�
	COutgoDlg		*pOutgo		= (COutgoDlg*)pTab->GetDialog(1);

	int i, nSize, nIncome, nOutgo, nSum, nValue;
	CString strText;

	nSum = nIncome = nOutgo = 0;

	// ���� ����Ʈ�� �߰��� ���� �׸���� �ݾ׵��� �ջ��Ѵ�
	nSize = pIncome->m_IncomeList.GetItemCount();
	for(i = 0; i < nSize; i++)
	{
		strText = pIncome->m_IncomeList.GetItemText(i, 1);
		nValue = ::atoi(strText);

		nIncome += nValue;
	}

	// ���� ����Ʈ�� �߰��� ���� �׸���� �ݾ׵��� �ջ��Ѵ�
	nSize = pOutgo->m_OutgoList.GetItemCount();
	for(i = 0; i < nSize; i++)
	{
		strText = pOutgo->m_OutgoList.GetItemText(i, 1);
		nValue = ::atoi(strText);

		nOutgo += nValue;
	}

	// ���Կ��� ������ �����Ͽ� �հ踦 ���Ѵ�
	nSum = nIncome - nOutgo;

	// ������ ���ڿ��� �����Ѵ�
	strText.Format("\n========= ���԰� ���� =========\n\n�� ���� : %9d\n\n�� ���� : %9d\n\n==============================\n\n�� �հ� : %9d",
		nIncome, nOutgo, nSum);

	// ����ƽ ��Ʈ�ѿ� �հ� ������ ����Ѵ�
	GetDlgItem(IDC_REPORT_STATIC)->SetWindowText(strText);
}
