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

// 수입 다이얼로그와 지출 다이얼로그에 접근하기 위해 필요한 헤더 파일들
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
	
	// 합계 출력 스태틱 컨트롤의 텍스트를 초기화한다
	GetDlgItem(IDC_REPORT_STATIC)->SetWindowText("");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

// 수입 다이얼로그와 지출 다이얼로그의 항목으로 합계를 계산하고 출력하는 함수
void CReportDlg::RefreshSum()
{
	// 다이얼로그 탭의 포인터를 구한다
	CDialogTabCtrl	*pTab		= (CDialogTabCtrl*)GetParent();
	// 수입 다이얼로그의 포인터를 구한다
	CIncomeDlg		*pIncome	= (CIncomeDlg*)pTab->GetDialog(0);
	// 지출 다이얼로그의 포인터를 구한다
	COutgoDlg		*pOutgo		= (COutgoDlg*)pTab->GetDialog(1);

	int i, nSize, nIncome, nOutgo, nSum, nValue;
	CString strText;

	nSum = nIncome = nOutgo = 0;

	// 수입 리스트에 추가된 수입 항목들의 금액들을 합산한다
	nSize = pIncome->m_IncomeList.GetItemCount();
	for(i = 0; i < nSize; i++)
	{
		strText = pIncome->m_IncomeList.GetItemText(i, 1);
		nValue = ::atoi(strText);

		nIncome += nValue;
	}

	// 지출 리스트에 추가된 지출 항목들의 금액들을 합산한다
	nSize = pOutgo->m_OutgoList.GetItemCount();
	for(i = 0; i < nSize; i++)
	{
		strText = pOutgo->m_OutgoList.GetItemText(i, 1);
		nValue = ::atoi(strText);

		nOutgo += nValue;
	}

	// 수입에서 지출을 감산하여 합계를 구한다
	nSum = nIncome - nOutgo;

	// 내역을 문자열로 생성한다
	strText.Format("\n========= 수입과 지출 =========\n\n총 수입 : %9d\n\n총 지출 : %9d\n\n==============================\n\n총 합계 : %9d",
		nIncome, nOutgo, nSum);

	// 스태틱 컨트롤에 합계 내역을 출력한다
	GetDlgItem(IDC_REPORT_STATIC)->SetWindowText(strText);
}
