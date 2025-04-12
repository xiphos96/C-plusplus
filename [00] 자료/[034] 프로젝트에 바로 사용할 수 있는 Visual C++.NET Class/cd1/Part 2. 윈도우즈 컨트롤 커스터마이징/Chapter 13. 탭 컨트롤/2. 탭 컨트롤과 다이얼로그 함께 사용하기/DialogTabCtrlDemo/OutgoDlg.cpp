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
	
	// ���� ����Ʈ ��Ʈ�ѿ� �÷��� �߰��Ѵ�
	m_OutgoList.InsertColumn(0, "�׸� �̸�", LVCFMT_CENTER, 200);
	m_OutgoList.InsertColumn(1, "�ݾ�", LVCFMT_RIGHT, 100);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COutgoDlg::OnAddButton() 
{
	// �Էµ� �����͸� ��� ������ ������Ʈ �Ѵ�.
	UpdateData(TRUE);

	// ���� ����Ʈ ��Ʈ�ѿ� ���ο� �׸��� �߰��Ѵ�
	int nItem = m_OutgoList.InsertItem(m_OutgoList.GetItemCount(), m_strName);
	// �׸��� �ݾ��� �����Ѵ�
	m_OutgoList.SetItemText(nItem, 1, m_strMoney);

	// �׸� �̸� �Է� ����Ʈ ��Ʈ�ѿ� ��Ŀ���� �����Ѵ�
	GetDlgItem(IDC_NAME_EDIT)->SetFocus();
}

// ����Ʈ �ڽ��� ���� �ʱ�ȭ�ϴ� �Լ�
void COutgoDlg::ResetEdit()
{
	// ����Ʈ �ڽ����� �ؽ�Ʈ�� �ʱ�ȭ�Ѵ�
	GetDlgItem(IDC_NAME_EDIT)->SetWindowText("");
	GetDlgItem(IDC_MONEY_EDIT)->SetWindowText("");
}
