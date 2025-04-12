// ExplorerPrintDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ExplorerPrintDemo.h"
#include "ExplorerPrintDemoDlg.h"

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


// CExplorerPrintDemoDlg ��ȭ ����



CExplorerPrintDemoDlg::CExplorerPrintDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExplorerPrintDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExplorerPrintDemoDlg)
	m_strAddress = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExplorerPrintDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExplorerPrintDemoDlg)
	DDX_Text(pDX, IDC_ADDRESS_EDIT, m_strAddress);
	DDX_Control(pDX, IDC_EXPLORER_PRINT, m_wndBrowser);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExplorerPrintDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CExplorerPrintDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GO_BUTTON, OnGoButton)
	ON_BN_CLICKED(IDC_STOP_BUTTON, OnStopButton)
	ON_BN_CLICKED(IDC_REFRESH_BUTTON, OnRefreshButton)
	ON_BN_CLICKED(IDC_SAVE_AS_BUTTON, OnSaveAsButton)
	ON_BN_CLICKED(IDC_PRINT_BUTTON, OnPrintButton)
	ON_BN_CLICKED(IDC_PRINT_PREVIEW_BUTTON, OnPrintPreviewButton)
	ON_BN_CLICKED(IDC_PAGE_SETUP_BUTTON, OnPageSetupButton)
	ON_BN_CLICKED(IDC_PROPERTY_BUTTON, OnPropertyButton)
	ON_BN_CLICKED(IDC_FAVORITE_BUTTON, OnFavoriteButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CExplorerPrintDemoDlg �޽��� ó����

BOOL CExplorerPrintDemoDlg::OnInitDialog()
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

	// �ʱ� ���������� �������� Ȩ�������� ������ �����Ѵ�
	m_strAddress = "http://www.youngjin.com";
	m_wndBrowser.Navigate(m_strAddress, NULL, NULL, NULL, NULL);

	UpdateData(FALSE);
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CExplorerPrintDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExplorerPrintDemoDlg::OnPaint() 
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
HCURSOR CExplorerPrintDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExplorerPrintDemoDlg::OnGoButton() 
{
	UpdateData(TRUE);

	// �ּ�â�� �Էµ� �ּ��� ����Ʈ�� ����
	m_wndBrowser.Navigate(m_strAddress, NULL, NULL, NULL, NULL);
}

void CExplorerPrintDemoDlg::OnStopButton() 
{
	// ���� ���������� �̵��� �����Ѵ�
	m_wndBrowser.Stop();
}

void CExplorerPrintDemoDlg::OnRefreshButton() 
{
	// ���� ���������� ����ϴ� �������� �ٽ� �ε��Ͽ� ����Ѵ�
	m_wndBrowser.Refresh();
}

void CExplorerPrintDemoDlg::OnSaveAsButton() 
{
	// ���� ���������� ����ϴ� �������� ���� ��ũ�� �����Ѵ�
	m_wndBrowser.SaveAs();
}

void CExplorerPrintDemoDlg::OnPrintButton() 
{
	// ���� ���������� ����ϴ� �������� �μ��Ѵ�
	m_wndBrowser.Print();
}

void CExplorerPrintDemoDlg::OnPrintPreviewButton() 
{
	// ���� ���������� ����ϴ� �������� �μ� ����� �̸� �����ش�
	m_wndBrowser.PrintPreview();
}

void CExplorerPrintDemoDlg::OnPageSetupButton() 
{
	// ���� ���������� ������ ���� ���̾�α׸� ����Ѵ�
	m_wndBrowser.PageSetup();
}

void CExplorerPrintDemoDlg::OnPropertyButton() 
{
	// ���� ���������� ����ϴ� �������� �Ӽ� �������� ����Ѵ�
	m_wndBrowser.Property();
}

void CExplorerPrintDemoDlg::OnFavoriteButton() 
{
	// ���� ���������� ����ϴ� �������� ���ã�⿡ �߰��Ѵ�
	m_wndBrowser.AddToFavorites();
}
