// OutgoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dialogtabctrldemo.h"
#include "OutgoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutgoDlg dialog


COutgoDlg::COutgoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COutgoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COutgoDlg)
	m_strName = _T("");
	m_strMoney = _T("");
	//}}AFX_DATA_INIT
}


void COutgoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COutgoDlg)
	DDX_Control(pDX, IDC_OUTGO_LIST, m_OutgoList);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
	DDX_Text(pDX, IDC_MONEY_EDIT, m_strMoney);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COutgoDlg, CDialog)
	//{{AFX_MSG_MAP(COutgoDlg)
	ON_BN_CLICKED(IDC_ADD_BUTTON, OnAddButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutgoDlg message handlers

BOOL COutgoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// 지출 리스트 컨트롤에 컬럼을 추가한다
	m_OutgoList.InsertColumn(0, "항목 이름", LVCFMT_CENTER, 200);
	m_OutgoList.InsertColumn(1, "금액", LVCFMT_RIGHT, 100);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COutgoDlg::OnAddButton() 
{
	// 입력된 데이터를 멤버 변수에 업데이트 한다.
	UpdateData(TRUE);

	// 지출 리스트 컨트롤에 새로운 항목을 추가한다
	int nItem = m_OutgoList.InsertItem(m_OutgoList.GetItemCount(), m_strName);
	// 항목의 금액을 설정한다
	m_OutgoList.SetItemText(nItem, 1, m_strMoney);

	// 항목 이름 입력 에디트 컨트롤에 포커스를 설정한다
	GetDlgItem(IDC_NAME_EDIT)->SetFocus();
}

// 에디트 박스의 값을 초기화하는 함수
void COutgoDlg::ResetEdit()
{
	// 에디트 박스들의 텍스트를 초기화한다
	GetDlgItem(IDC_NAME_EDIT)->SetWindowText("");
	GetDlgItem(IDC_MONEY_EDIT)->SetWindowText("");
}
