// CustomTabCtrlDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CustomTabCtrlDemo.h"
#include "CustomTabCtrlDemoDlg.h"

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


// CCustomTabCtrlDemoDlg ��ȭ ����



CCustomTabCtrlDemoDlg::CCustomTabCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCustomTabCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCustomTabCtrlDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CCustomTabCtrlDemoDlg::~CCustomTabCtrlDemoDlg()
{
	// �̹��� ����Ʈ�� �����Ѵ�
	m_ImageList.DeleteImageList();
}

void CCustomTabCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustomTabCtrlDemoDlg)
	DDX_Control(pDX, IDC_CUSTOM_TAB, m_CustomTab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCustomTabCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CCustomTabCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CCustomTabCtrlDemoDlg �޽��� ó����

BOOL CCustomTabCtrlDemoDlg::OnInitDialog()
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
	m_ImageList.Create(IDB_IMAGE_LIST, 20, 1, RGB(255, 0, 255));

	// �̹��� ����Ʈ�� �� ��Ʈ�ѿ� �����Ѵ�
	m_CustomTab.SetImageList(&m_ImageList);
	// �� ��ư ��� �̹����� �����Ѵ�
	m_CustomTab.SetTabBmp(IDB_BKGND_LEFT, IDB_BKGND_CENTER, IDB_BKGND_RIGHT);
	
	// �� �̹����� �Բ� ���� �߰��Ѵ�
	m_CustomTab.InsertItem(0, "�ڷ�", 0);
	m_CustomTab.InsertItem(1, "������", 1);
	m_CustomTab.InsertItem(2, "����", 2);
	m_CustomTab.InsertItem(3, "���ΰ�ħ", 3);
	m_CustomTab.InsertItem(4, "Ȩ", 4);
	m_CustomTab.InsertItem(5, "�˻�", 5);
	m_CustomTab.InsertItem(6, "���ã��", 6);
	m_CustomTab.InsertItem(7, "�̵��", 7);
	m_CustomTab.InsertItem(8, "���", 8);

	// �� �ǿ� ��Ʈ�ѵ��� �߰��Ѵ�
	m_CustomTab.AddControl(0, GetDlgItem(IDC_BACK_STATIC));
	m_CustomTab.AddControl(1, GetDlgItem(IDC_FORWARD_STATIC));
	m_CustomTab.AddControl(2, GetDlgItem(IDC_STOP_STATIC));
	m_CustomTab.AddControl(3, GetDlgItem(IDC_REFRESH_STATIC));
	m_CustomTab.AddControl(4, GetDlgItem(IDC_HOME_STATIC));
	m_CustomTab.AddControl(5, GetDlgItem(IDC_SEARCH_STATIC));
	m_CustomTab.AddControl(6, GetDlgItem(IDC_FAVORITE_STATIC));
	m_CustomTab.AddControl(7, GetDlgItem(IDC_MEDIA_STATIC));
	m_CustomTab.AddControl(8, GetDlgItem(IDC_HISTORY_STATIC));

	// �ʱ� �������� 0�� �������� �����Ѵ�
	m_CustomTab.SetCurSel(0);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CCustomTabCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCustomTabCtrlDemoDlg::OnPaint() 
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
HCURSOR CCustomTabCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
