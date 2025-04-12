// ExplorerPopupDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ExplorerPopupDemo.h"
#include "ExplorerPopupDemoDlg.h"

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


// CExplorerPopupDemoDlg ��ȭ ����



CExplorerPopupDemoDlg::CExplorerPopupDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExplorerPopupDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExplorerPopupDemoDlg)
	m_strAddress = _T("");
	m_bMenu = FALSE;
	m_bToolBar = FALSE;
	m_bAddressBar = FALSE;
	m_bStatusBar = FALSE;
	m_bResize = FALSE;
	m_nPosX = 0;
	m_nPosY = 0;
	m_nCX = 0;
	m_nCY = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExplorerPopupDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExplorerPopupDemoDlg)
	DDX_Text(pDX, IDC_ADDRESS_EDIT, m_strAddress);
	DDX_Control(pDX, IDC_EXPLORER, m_wndBrowser);
	DDX_Check(pDX, IDC_MENU_CHECK, m_bMenu);
	DDX_Check(pDX, IDC_TOOLBAR_CHECK, m_bToolBar);
	DDX_Check(pDX, IDC_ADDRESSBAR_CHECK, m_bAddressBar);
	DDX_Check(pDX, IDC_STATUSBAR_CHECK, m_bStatusBar);
	DDX_Check(pDX, IDC_RESIZE_CHECK, m_bResize);
	DDX_Text(pDX, IDC_CX_EDIT, m_nCX);
	DDX_Text(pDX, IDC_CY_EDIT, m_nCY);
	DDX_Text(pDX, IDC_POS_X_EDIT, m_nPosX);
	DDX_Text(pDX, IDC_POS_Y_EDIT, m_nPosY);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExplorerPopupDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CExplorerPopupDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHELLEXECUTE_BUTTON, OnShellexecuteButton)
	ON_BN_CLICKED(IDC_NEW_BUTTON, OnNewButton)
	ON_BN_CLICKED(IDC_NEW_USING_WEBBROWSER_BUTTON, OnNewUsingWebbrowserButton)
	ON_BN_CLICKED(IDC_NEW_EX_BUTTON, OnNewExButton)
	ON_BN_CLICKED(IDC_CLOSE_BUTTON, OnCloseButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CExplorerPopupDemoDlg �޽��� ó����

BOOL CExplorerPopupDemoDlg::OnInitDialog()
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

	// �ʱ� �ּҸ� ������������ �����Ѵ�
	m_strAddress = "http://www.youngjin.com";
	// ���̾�α� ���� ������������ ���������� ������ �Ѵ�
	m_wndBrowser.Navigate(m_strAddress, NULL, NULL, NULL, NULL);

	// ��� �������� �ʱⰪ�� �����Ѵ�
	m_bMenu			= FALSE;
	m_bToolBar		= FALSE;
	m_bAddressBar	= FALSE;
	m_bStatusBar	= FALSE;
	m_bResize		= FALSE;
	m_nPosX			= 100;
	m_nPosY			= 100;
	m_nCX			= 400;
	m_nCY			= 300;

	UpdateData(FALSE);
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CExplorerPopupDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExplorerPopupDemoDlg::OnPaint() 
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
HCURSOR CExplorerPopupDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExplorerPopupDemoDlg::OnShellexecuteButton() 
{
	UpdateData(TRUE);

	// ShellExecute()�� ���������� ���� �Էµ� �ּҸ� ����
	m_ExplorerPopup.OpenByShellExecute(m_strAddress);
}

void CExplorerPopupDemoDlg::OnNewButton() 
{
	UpdateData(TRUE);

	// �ͽ��÷η� ��ü�� �����Ͽ� �Էµ� �ּҸ� ����
	m_ExplorerPopup.OpenNewWindow(m_strAddress);
}

void CExplorerPopupDemoDlg::OnNewUsingWebbrowserButton() 
{
	UpdateData(TRUE);

	// ���̾�α׿� �����Ǿ� �ִ� ���������� ����Ͽ� �� ���������� �����ϰ�
	// �Էµ� �ּҸ� ����
	m_ExplorerPopup.OpenNewWindow(m_strAddress, &m_wndBrowser);
}

void CExplorerPopupDemoDlg::OnNewExButton() 
{
	UpdateData(TRUE);

	// �ͽ��÷η� ��ü�� �����ϰ�
	// �ɼǵ��� ������ �� �Էµ� �ּҸ� ����
	m_ExplorerPopup.OpenNewWindowEx(m_strAddress, m_bMenu, m_bToolBar, m_bAddressBar,
		m_bStatusBar, m_bResize, m_nPosX, m_nPosY, m_nCX, m_nCY);

	// ���� ��ư�� ��Ȱ��ȭ ��Ų��
	GetDlgItem(IDC_NEW_EX_BUTTON)->EnableWindow(FALSE);
	// �ݱ� ��ư�� Ȱ��ȭ ��Ų��
	GetDlgItem(IDC_CLOSE_BUTTON)->EnableWindow(TRUE);
}

void CExplorerPopupDemoDlg::OnCloseButton() 
{
	UpdateData(TRUE);

	// ������ ���������� �ݴ´�
	m_ExplorerPopup.CloseExplorer();

	// ���� ��ư�� Ȱ��ȭ ��Ų��
	GetDlgItem(IDC_NEW_EX_BUTTON)->EnableWindow(TRUE);
	// �ݱ� ��ư�� ��Ȱ��ȭ ��Ų��
	GetDlgItem(IDC_CLOSE_BUTTON)->EnableWindow(FALSE);
}
