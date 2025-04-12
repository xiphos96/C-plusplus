// DDListCtrlDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "DDListCtrlDemo.h"
#include "DDListCtrlDemoDlg.h"

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


// CDDListCtrlDemoDlg ��ȭ ����



CDDListCtrlDemoDlg::CDDListCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDDListCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDDListCtrlDemoDlg)
	m_nMode = 3;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDDListCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDDListCtrlDemoDlg)
	DDX_Control(pDX, IDC_TARGET_LIST, m_TargetList);
	DDX_Control(pDX, IDC_ALL_LIST, m_AllList);
	DDX_Radio(pDX, IDC_ICON_RADIO, m_nMode);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDDListCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDDListCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ICON_RADIO, OnIconRadio)
	ON_BN_CLICKED(IDC_SMALL_ICON_RADIO, OnSmallIconRadio)
	ON_BN_CLICKED(IDC_LIST_RADIO, OnListRadio)
	ON_BN_CLICKED(IDC_REPORT_RADIO, OnReportRadio)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CDDListCtrlDemoDlg �޽��� ó����

BOOL CDDListCtrlDemoDlg::OnInitDialog()
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

	// �̹��� ����Ʈ�� �����Ѵ�
	m_BigImageList.Create(IDB_LIST_BIG, 32, 1, RGB(255, 255, 255));
	m_SmallImageList.Create(IDB_LIST_SMALL, 16, 1, RGB(255, 255, 255));

	// ���� ����Ʈ ��Ʈ�ѿ� �̹��� ����Ʈ�� �����Ѵ�
	m_AllList.SetImageList(&m_BigImageList, LVSIL_NORMAL);
	m_AllList.SetImageList(&m_SmallImageList, LVSIL_SMALL);

	// ���� ����Ʈ ��Ʈ�ѿ� �̹��� ����Ʈ�� �����Ѵ�
	m_TargetList.SetImageList(&m_BigImageList, LVSIL_NORMAL);
	m_TargetList.SetImageList(&m_SmallImageList, LVSIL_SMALL);

	// �÷��� �����Ѵ�
	m_AllList.InsertColumn(0, "���� �̸�", LVCFMT_LEFT, 240);
	m_TargetList.InsertColumn(0, "���� �̸�", LVCFMT_LEFT, 240);

	// ���� ����Ʈ ��Ʈ�ѿ� �׸��� �߰��Ѵ�
	m_AllList.InsertItem(0, "�����", 0);
	m_AllList.InsertItem(1, "�Ķ���", 1);
	m_AllList.InsertItem(2, "�䳢", 2);
	m_AllList.InsertItem(3, "��Ÿ", 3);
	m_AllList.InsertItem(4, "�ɰ�", 4);
	m_AllList.InsertItem(5, "�糪��", 5);
	m_AllList.InsertItem(6, "������", 6);
	m_AllList.InsertItem(7, "�����", 7);
	m_AllList.InsertItem(8, "���", 8);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CDDListCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDDListCtrlDemoDlg::OnPaint() 
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
HCURSOR CDDListCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDDListCtrlDemoDlg::OnIconRadio() 
{
	// ����Ʈ ��Ʈ���� Ÿ���� ������ Ÿ������ �����Ѵ�
	m_AllList.ModifyStyle(LVS_TYPEMASK, LVS_ICON);
	m_TargetList.ModifyStyle(LVS_TYPEMASK, LVS_ICON);
}

void CDDListCtrlDemoDlg::OnSmallIconRadio() 
{
	// ����Ʈ ��Ʈ���� Ÿ���� ���� ������ Ÿ������ �����Ѵ�
	m_AllList.ModifyStyle(LVS_TYPEMASK, LVS_SMALLICON);
	m_TargetList.ModifyStyle(LVS_TYPEMASK, LVS_SMALLICON);
}

void CDDListCtrlDemoDlg::OnListRadio() 
{
	// ����Ʈ ��Ʈ���� Ÿ���� ����Ʈ Ÿ������ �����Ѵ�
	m_AllList.ModifyStyle(LVS_TYPEMASK, LVS_LIST);
	m_TargetList.ModifyStyle(LVS_TYPEMASK, LVS_LIST);
}

void CDDListCtrlDemoDlg::OnReportRadio() 
{
	// ����Ʈ ��Ʈ���� Ÿ���� ����Ʈ Ÿ������ �����Ѵ�
	m_AllList.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
	m_TargetList.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
}
