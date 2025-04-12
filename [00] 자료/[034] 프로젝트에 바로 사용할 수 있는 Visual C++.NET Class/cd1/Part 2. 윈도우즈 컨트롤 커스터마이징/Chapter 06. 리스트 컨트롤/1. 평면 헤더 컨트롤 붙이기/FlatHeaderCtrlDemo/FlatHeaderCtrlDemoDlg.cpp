// FlatHeaderCtrlDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "FlatHeaderCtrlDemo.h"
#include "FlatHeaderCtrlDemoDlg.h"

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


// CFlatHeaderCtrlDemoDlg ��ȭ ����



CFlatHeaderCtrlDemoDlg::CFlatHeaderCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFlatHeaderCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFlatHeaderCtrlDemoDlg)
	m_strName = _T("");
	m_strAge = _T("");
	m_strAddr = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFlatHeaderCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFlatHeaderCtrlDemoDlg)
	DDX_Control(pDX, IDC_FLAT_LIST, m_FlatList);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
	DDX_Text(pDX, IDC_AGE_EDIT, m_strAge);
	DDX_Text(pDX, IDC_ADDR_EDIT, m_strAddr);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFlatHeaderCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CFlatHeaderCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BUTTON, OnAddButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CFlatHeaderCtrlDemoDlg �޽��� ó����

BOOL CFlatHeaderCtrlDemoDlg::OnInitDialog()
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

	// ����Ʈ ��Ʈ�ѿ� �÷��� �߰��Ѵ�
	m_FlatList.InsertColumn(0, "�̸�", LVCFMT_RIGHT, 120);
	m_FlatList.InsertColumn(1, "����", LVCFMT_CENTER, 80);
	m_FlatList.InsertColumn(2, "�ּ�", LVCFMT_LEFT, 300);

	// ����Ʈ ��Ʈ���� ��� ����� ������ �̹����� �����Ѵ�
	m_FlatList.SetHeaderImage(IDB_HEADER_BITMAP, 16, 1);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CFlatHeaderCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFlatHeaderCtrlDemoDlg::OnPaint() 
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
HCURSOR CFlatHeaderCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFlatHeaderCtrlDemoDlg::OnAddButton() 
{
	// �߰� ��ư�� Ŭ���ϸ�
	// ���� �Էµ� ������ ����Ʈ ��Ʈ�ѿ� �߰��Ѵ�
	UpdateData(TRUE);

	// ���� Ȯ��
	if(m_strName.IsEmpty())
	{
		MessageBox("�̸��� �Է��ϼ���.");
		GetDlgItem(IDC_NAME_EDIT)->SetFocus();
		return;
	}
	if(m_strAge.IsEmpty())
	{
		MessageBox("���̸� �Է��ϼ���.");
		GetDlgItem(IDC_AGE_EDIT)->SetFocus();
		return;
	}
	if(m_strAddr.IsEmpty())
	{
		MessageBox("�ּҸ� �Է��ϼ���.");
		GetDlgItem(IDC_ADDR_EDIT)->SetFocus();
		return;
	}

	// �׸� �߰�
	int nItem = m_FlatList.InsertItem(m_FlatList.GetItemCount(), m_strName);
	m_FlatList.SetItemText(nItem, 1, m_strAge);
	m_FlatList.SetItemText(nItem, 2, m_strAddr);
}
