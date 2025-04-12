// AutoTabCtrlDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "AutoTabCtrlDemo.h"
#include "AutoTabCtrlDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� ������
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ����
	//}}AFX_VIRTUAL

// ����
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CAutoTabCtrlDemoDlg ��ȭ ����



CAutoTabCtrlDemoDlg::CAutoTabCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutoTabCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAutoTabCtrlDemoDlg)
	m_strName = _T("");
	m_strMoney = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutoTabCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutoTabCtrlDemoDlg)
	DDX_Control(pDX, IDC_OUTGO_LIST, m_OutgoList);
	DDX_Control(pDX, IDC_INCOME_LIST, m_IncomeList);
	DDX_Control(pDX, IDC_AUTO_TAB, m_AutoTab);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
	DDX_Text(pDX, IDC_MONEY_EDIT, m_strMoney);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAutoTabCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CAutoTabCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BUTTON, OnAddButton)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_AT_SELCHANGE, OnATSelChange)
END_MESSAGE_MAP()


// CAutoTabCtrlDemoDlg �޽��� ó����

BOOL CAutoTabCtrlDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	// �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// ������ ���� �߰��Ѵ�
	m_AutoTab.InsertItem(0, "����");
	m_AutoTab.InsertItem(1, "����");
	m_AutoTab.InsertItem(2, "�հ�");

	// �� �ǿ� ���ϴ� ��Ʈ�ѵ��� �ڵ� �� ��Ʈ�ѿ� �����Ѵ�
	// �̶�, 0�� �ǰ� 1�� �ǿ� ���ÿ� ������ ��Ʈ�ѵ��� 0���� 1�� �ǿ� ��� �����Ѵ�
	m_AutoTab.AddControl(0, &m_IncomeList);
	m_AutoTab.AddControl(0, GetDlgItem(IDC_NAME_STATIC));
	m_AutoTab.AddControl(0, GetDlgItem(IDC_NAME_EDIT));
	m_AutoTab.AddControl(0, GetDlgItem(IDC_MONEY_STATIC));
	m_AutoTab.AddControl(0, GetDlgItem(IDC_MONEY_EDIT));
	m_AutoTab.AddControl(0, GetDlgItem(IDC_ADD_BUTTON));
	m_AutoTab.AddControl(1, &m_OutgoList);
	m_AutoTab.AddControl(1, GetDlgItem(IDC_NAME_STATIC));
	m_AutoTab.AddControl(1, GetDlgItem(IDC_NAME_EDIT));
	m_AutoTab.AddControl(1, GetDlgItem(IDC_MONEY_STATIC));
	m_AutoTab.AddControl(1, GetDlgItem(IDC_MONEY_EDIT));
	m_AutoTab.AddControl(1, GetDlgItem(IDC_ADD_BUTTON));
	m_AutoTab.AddControl(2, GetDlgItem(IDC_REPORT_STATIC));

	// 0�� ���� �����Ѵ�
	m_AutoTab.SetCurSel(0);
	
	// ���� ����Ʈ ��Ʈ�ѿ� �÷��� �߰��Ѵ�
	m_IncomeList.InsertColumn(0, "�׸� �̸�", LVCFMT_CENTER, 200);
	m_IncomeList.InsertColumn(1, "�ݾ�", LVCFMT_RIGHT, 100);

	// ���� ����Ʈ ��Ʈ�ѿ� �÷��� �߰��Ѵ�
	m_OutgoList.InsertColumn(0, "�׸� �̸�", LVCFMT_CENTER, 200);
	m_OutgoList.InsertColumn(1, "�ݾ�", LVCFMT_RIGHT, 100);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CAutoTabCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸����� 
// �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
// �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CAutoTabCtrlDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�. 
HCURSOR CAutoTabCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAutoTabCtrlDemoDlg::OnAddButton() 
{
	// �Էµ� �����͸� ��� ������ ������Ʈ �Ѵ�.
	UpdateData(TRUE);

	// ���� ���õ� �� ��ȣ�� ��´�
	int nTab = m_AutoTab.GetCurSel(), nItem;

	switch(nTab)
	{
	case 0:
		// ���� ���� ���̶�� �׸� �̸��� ���� ����Ʈ�� �߰��Ѵ�
		nItem = m_IncomeList.InsertItem(m_IncomeList.GetItemCount(), m_strName);
		// �׸��� �ݾ��� �����Ѵ�
		m_IncomeList.SetItemText(nItem, 1, m_strMoney);
		break;
	case 1:
		// ���� ���� ���̶�� �׸� �̸��� ���� ����Ʈ�� �߰��Ѵ�
		nItem = m_OutgoList.InsertItem(m_OutgoList.GetItemCount(), m_strName);
		// �׸��� �ݾ��� �����Ѵ�
		m_OutgoList.SetItemText(nItem, 1, m_strMoney);
		break;
	}

	// �׸� �̸� �Է� ����Ʈ ��Ʈ�ѿ� ��Ŀ���� �����Ѵ�
	GetDlgItem(IDC_NAME_EDIT)->SetFocus();
}

// �ڵ� �� ��Ʈ���� �� ����� ȣ��Ǵ� �Լ�
LRESULT CAutoTabCtrlDemoDlg::OnATSelChange(WPARAM wParam, LPARAM lParam) 
{
	switch(lParam)
	{
	case 0:
	case 1:
		// 0���� 1�� ���� ���õǸ� ����Ʈ �ڽ����� �ؽ�Ʈ�� �ʱ�ȭ�Ѵ�
		GetDlgItem(IDC_NAME_EDIT)->SetWindowText("");
		GetDlgItem(IDC_MONEY_EDIT)->SetWindowText("");
		break;
	case 2:
		{
			// 2�� ���� ���õǸ�
			int i, nSize, nIncome, nOutgo, nSum, nValue;
			CString strText;

			nSum = nIncome = nOutgo = 0;

			// ���� ����Ʈ�� �߰��� ���� �׸���� �ݾ׵��� �ջ��Ѵ�
			nSize = m_IncomeList.GetItemCount();
			for(i = 0; i < nSize; i++)
			{
				strText = m_IncomeList.GetItemText(i, 1);
				nValue = ::atoi(strText);

				nIncome += nValue;
			}

			// ���� ����Ʈ�� �߰��� ���� �׸���� �ݾ׵��� �ջ��Ѵ�
			nSize = m_OutgoList.GetItemCount();
			for(i = 0; i < nSize; i++)
			{
				strText = m_OutgoList.GetItemText(i, 1);
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
		break;
	}

	return 0;
}
