// ExplorerUIDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ExplorerUIDemo.h"
#include "ExplorerUIDemoDlg.h"

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


// CExplorerUIDemoDlg ��ȭ ����



CExplorerUIDemoDlg::CExplorerUIDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExplorerUIDemoDlg::IDD, pParent)
{
	// ��� �������� �ʱ�ȭ�Ѵ�
	//{{AFX_DATA_INIT(CExplorerUIDemoDlg)
	m_strAddress = _T("");
	m_bContextMenu = FALSE;
	m_bNo3DBorder = FALSE;
	m_bNoScrollBar = FALSE;
	m_bFlatScrollBar = FALSE;
	m_strAddress2 = _T("");
	m_bContextMenu2 = FALSE;
	m_bNo3DBorder2 = FALSE;
	m_bNoScrollBar2 = FALSE;
	m_bFlatScrollBar2 = FALSE;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExplorerUIDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExplorerUIDemoDlg)
	DDX_Control(pDX, IDC_EXPLORER_UI, m_wndExplorerUI);
	DDX_Text(pDX, IDC_ADDRESS_EDIT, m_strAddress);
	DDX_Check(pDX, IDC_CONTEXT_MENU_CHECK, m_bContextMenu);
	DDX_Check(pDX, IDC_NO_3D_BORDER_CHECK, m_bNo3DBorder);
	DDX_Check(pDX, IDC_NO_SCROLL_CHECK, m_bNoScrollBar);
	DDX_Check(pDX, IDC_FLAT_SCROLL_CHECK, m_bFlatScrollBar);
	DDX_Control(pDX, IDC_EXPLORER_UI2, m_wndExplorerUI2);
	DDX_Text(pDX, IDC_ADDRESS_EDIT2, m_strAddress2);
	DDX_Check(pDX, IDC_CONTEXT_MENU_CHECK2, m_bContextMenu2);
	DDX_Check(pDX, IDC_NO_3D_BORDER_CHECK2, m_bNo3DBorder2);
	DDX_Check(pDX, IDC_NO_SCROLL_CHECK2, m_bNoScrollBar2);
	DDX_Check(pDX, IDC_FLAT_SCROLL_CHECK2, m_bFlatScrollBar2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExplorerUIDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CExplorerUIDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GO_BUTTON, OnGoButton)
	ON_BN_CLICKED(IDC_CONTEXT_MENU_CHECK, OnContextMenuCheck)
	ON_BN_CLICKED(IDC_NO_3D_BORDER_CHECK, OnNo3dBorderCheck)
	ON_BN_CLICKED(IDC_NO_SCROLL_CHECK, OnNoScrollCheck)
	ON_BN_CLICKED(IDC_FLAT_SCROLL_CHECK, OnFlatScrollCheck)
	ON_BN_CLICKED(IDC_GO_BUTTON2, OnGoButton2)
	ON_BN_CLICKED(IDC_CONTEXT_MENU_CHECK2, OnContextMenuCheck2)
	ON_BN_CLICKED(IDC_NO_3D_BORDER_CHECK2, OnNo3dBorderCheck2)
	ON_BN_CLICKED(IDC_NO_SCROLL_CHECK2, OnNoScrollCheck2)
	ON_BN_CLICKED(IDC_FLAT_SCROLL_CHECK2, OnFlatScrollCheck2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CExplorerUIDemoDlg �޽��� ó����

BOOL CExplorerUIDemoDlg::OnInitDialog()
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

	// ù��° �������� ��Ʈ�ѿ� ���� �ɼ� ��� ���� ����
	m_strAddress		= "http://www.youngjin.com";	// �ʱ� URL�� ������������ ����
	m_bContextMenu		= TRUE;							// �ʱ⿡�� ���ؽ�Ʈ �޴��� ��Ÿ������ ����
	m_bNo3DBorder		= TRUE;							// �ʱ⿡�� 3D �׵θ��� ���ߵ��� ����
	m_bNoScrollBar		= FALSE;						// �ʱ⿡�� ��ũ�ѹٸ� ����ϵ��� ����
	m_bFlatScrollBar	= TRUE;							// �ʱ⿡�� ��� ��ũ�ѹٸ� ����ϵ��� ����

	// ù��° �������� ��Ʈ�ѿ� �ɼ��� �����Ѵ�
	m_wndExplorerUI.m_bContextMenu		= m_bContextMenu;
	m_wndExplorerUI.m_bNo3DBorder		= m_bNo3DBorder;
	m_wndExplorerUI.m_bNoScrollBar		= m_bNoScrollBar;
	m_wndExplorerUI.m_bFlatScrollBar	= m_bFlatScrollBar;

	// ù��° ������������ �������� ����Ʈ�� ����
	m_wndExplorerUI.Navigate("http://www.youngjin.com", NULL, NULL, NULL, NULL);
	
	// �ι�° �������� ��Ʈ�ѿ� ���� �ɼ� ��� ���� ����
	m_strAddress2		= "http://www.youngjin.com";	// �ʱ� URL�� ������������ ����
	m_bContextMenu2		= TRUE;							// �ʱ⿡�� ���ؽ�Ʈ �޴��� ��Ÿ������ ����
	m_bNo3DBorder2		= TRUE;							// �ʱ⿡�� 3D �׵θ��� ���ߵ��� ����
	m_bNoScrollBar2		= FALSE;						// �ʱ⿡�� ��ũ�ѹٸ� ����ϵ��� ����
	m_bFlatScrollBar2	= TRUE;							// �ʱ⿡�� ��� ��ũ�ѹٸ� ����ϵ��� ����

	// �ι�° �������� ��Ʈ�ѿ� �ɼ��� �����Ѵ�
	m_wndExplorerUI2.m_bContextMenu		= m_bContextMenu2;
	m_wndExplorerUI2.m_bNo3DBorder		= m_bNo3DBorder2;
	m_wndExplorerUI2.m_bNoScrollBar		= m_bNoScrollBar2;
	m_wndExplorerUI2.m_bFlatScrollBar	= m_bFlatScrollBar2;

	// �ι�° ���������� ����� �����ϱ� ���� ����� ���� ��Ʈ���� �����Ѵ�
	m_wndExplorerUI2.SetShapeBitmap("skin.bmp", RGB(0, 0, 0));
	// �ι�° ������������ �������� ����Ʈ�� ����
	m_wndExplorerUI2.Navigate("http://www.youngjin.com", NULL, NULL, NULL, NULL);
	
	// ���̾�α��� ��Ʈ�ѿ� ��� �������� ���� �����Ѵ�
	UpdateData(FALSE);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CExplorerUIDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExplorerUIDemoDlg::OnPaint() 
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
HCURSOR CExplorerUIDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExplorerUIDemoDlg::OnGoButton() 
{
	UpdateData(TRUE);

	// ���ο� �ּҸ� ù��° ���������� ����
	m_wndExplorerUI.Navigate(m_strAddress, NULL, NULL, NULL, NULL);
}

void CExplorerUIDemoDlg::OnContextMenuCheck() 
{
	UpdateData(TRUE);

	// ù��° ���������� ���� ���ؽ�Ʈ �޴� ��� ���θ� �����Ѵ�
	m_wndExplorerUI.m_bContextMenu		= m_bContextMenu;
}

void CExplorerUIDemoDlg::OnNo3dBorderCheck() 
{
	UpdateData(TRUE);

	// ù��° ���������� ���� 3D �׵θ� ��� ���θ� �����Ѵ�
	m_wndExplorerUI.m_bNo3DBorder		= m_bNo3DBorder;
	// �Ӽ��� ��ٷ� �ݿ��ϱ� ���� ������ �ٽ� �ε��Ѵ�
	m_wndExplorerUI.Refresh();
}

void CExplorerUIDemoDlg::OnNoScrollCheck() 
{
	UpdateData(TRUE);

	// ù��° ���������� ���� ��ũ�ѹ� ��� ���θ� �����Ѵ�
	m_wndExplorerUI.m_bNoScrollBar		= m_bNoScrollBar;
	// �Ӽ��� ��ٷ� �ݿ��ϱ� ���� ������ �ٽ� �ε��Ѵ�
	m_wndExplorerUI.Refresh();
}

void CExplorerUIDemoDlg::OnFlatScrollCheck() 
{
	UpdateData(TRUE);

	// ù��° ���������� ���� ��� ��ũ�ѹ� ��� ���θ� �����Ѵ�
	m_wndExplorerUI.m_bFlatScrollBar	= m_bFlatScrollBar;
	// �Ӽ��� ��ٷ� �ݿ��ϱ� ���� ������ �ٽ� �ε��Ѵ�
	m_wndExplorerUI.Refresh();
}

void CExplorerUIDemoDlg::OnGoButton2() 
{
	UpdateData(TRUE);

	// ���ο� �ּҸ� �ι�° ���������� ����
	m_wndExplorerUI2.Navigate(m_strAddress2, NULL, NULL, NULL, NULL);
}

void CExplorerUIDemoDlg::OnContextMenuCheck2() 
{
	UpdateData(TRUE);

	// �ι�° ���������� ���� ���ؽ�Ʈ �޴� ��� ���θ� �����Ѵ�
	m_wndExplorerUI2.m_bContextMenu		= m_bContextMenu2;
}

void CExplorerUIDemoDlg::OnNo3dBorderCheck2() 
{
	UpdateData(TRUE);

	// �ι�° ���������� ���� 3D �׵θ� ��� ���θ� �����Ѵ�
	m_wndExplorerUI2.m_bNo3DBorder		= m_bNo3DBorder2;
	// �Ӽ��� ��ٷ� �ݿ��ϱ� ���� ������ �ٽ� �ε��Ѵ�
	m_wndExplorerUI2.Refresh();
}

void CExplorerUIDemoDlg::OnNoScrollCheck2() 
{
	UpdateData(TRUE);

	// �ι�° ���������� ���� ��ũ�ѹ� ��� ���θ� �����Ѵ�
	m_wndExplorerUI2.m_bNoScrollBar		= m_bNoScrollBar2;
	// �Ӽ��� ��ٷ� �ݿ��ϱ� ���� ������ �ٽ� �ε��Ѵ�
	m_wndExplorerUI2.Refresh();
}

void CExplorerUIDemoDlg::OnFlatScrollCheck2() 
{
	UpdateData(TRUE);

	// �ι�° ���������� ���� ��� ��ũ�ѹ� ��� ���θ� �����Ѵ�
	m_wndExplorerUI2.m_bFlatScrollBar	= m_bFlatScrollBar2;
	// �Ӽ��� ��ٷ� �ݿ��ϱ� ���� ������ �ٽ� �ε��Ѵ�
	m_wndExplorerUI2.Refresh();
}
