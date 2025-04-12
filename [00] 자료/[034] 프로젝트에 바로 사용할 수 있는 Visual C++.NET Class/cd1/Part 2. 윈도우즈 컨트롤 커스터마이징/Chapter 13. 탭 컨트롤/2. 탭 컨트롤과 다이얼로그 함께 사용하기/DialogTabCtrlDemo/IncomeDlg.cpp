// IncomeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dialogtabctrldemo.h"
#include "IncomeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIncomeDlg dialog


CIncomeDlg::CIncomeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIncomeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIncomeDlg)
	m_strName = _T("");
	m_strMoney = _T("");
	//}}AFX_DATA_INIT
}


void CIncomeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIncomeDlg)
	DDX_Control(pDX, IDC_INCOME_LIST, m_IncomeList);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
	DDX_Text(pDX, IDC_MONEY_EDIT, m_strMoney);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIncomeDlg, CDialog)
	//{{AFX_MSG_MAP(CIncomeDlg)
	ON_BN_CLICKED(IDC_ADD_BUTTON, OnAddButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIncomeDlg message handlers

BOOL CIncomeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// 수입 리스트 컨트롤에 컬럼을 추가한다
	m_IncomeList.InsertColumn(0, "항목 이름", LVCFMT_CENTER, 200);
	m_IncomeList.InsertColumn(1, "금액", LVCFMT_RIGHT, 100);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CIncomeDlg::OnAddButton() 
{
	// 입력된 데이터를 멤버 변수에 업데이트 한다.
	UpdateData(TRUE);

	// 수입 리스트 컨트롤에 새로운 항목을 추가한다
	int nItem = m_IncomeList.InsertItem(m_IncomeList.GetItemCount(), m_strName);
	// 항목의 금액을 설정한다
	m_IncomeList.SetItemText(nItem, 1, m_strMoney);

	// 항목 이름 입력 에디트 컨트롤에 포커스를 설정한다
	GetDlgItem(IDC_NAME_EDIT)->SetFocus();
}

// 에디트 박스의 값을 초기화하는 함수
void CIncomeDlg::ResetEdit()
{
	// 에디트 박스들의 텍스트를 초기화한다
	GetDlgItem(IDC_NAME_EDIT)->SetWindowText("");
	GetDlgItem(IDC_MONEY_EDIT)->SetWindowText("");
}
