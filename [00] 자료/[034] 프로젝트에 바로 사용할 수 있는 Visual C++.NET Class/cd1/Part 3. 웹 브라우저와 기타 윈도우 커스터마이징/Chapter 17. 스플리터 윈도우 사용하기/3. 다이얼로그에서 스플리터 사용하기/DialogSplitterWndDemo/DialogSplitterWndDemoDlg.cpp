// DialogSplitterWndDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "DialogSplitterWndDemo.h"
#include "DialogSplitterWndDemoDlg.h"

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


// CDialogSplitterWndDemoDlg ��ȭ ����



CDialogSplitterWndDemoDlg::CDialogSplitterWndDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogSplitterWndDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogSplitterWndDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogSplitterWndDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogSplitterWndDemoDlg)
	DDX_Control(pDX, IDC_SPLITTER2_STATIC, m_wndSplitter2);
	DDX_Control(pDX, IDC_SPLITTER_STATIC, m_wndSplitter);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDialogSplitterWndDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDialogSplitterWndDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CDialogSplitterWndDemoDlg �޽��� ó����

BOOL CDialogSplitterWndDemoDlg::OnInitDialog()
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

	// ���� ���ø����� �Ӽ��� �����Ѵ�
	m_wndSplitter.SetDirection(DIR_VERT);
	// ������ ���̾�α� ���� ������ �̵��� �� �ְ�, �������� 50 �ȼ� �̵��� �� �ֵ��� �����Ѵ�
	m_wndSplitter.SetRange(-1, 50);

	// ���� ���ø����� ������ �����ϴ� ��Ʈ�ѵ��� ���ø��Ϳ� �����Ѵ�
	// IDC_TEST_STATIC�� ���ø��Ͱ� �־����� ���� ũ�⸦ �ø��� ����� ������� �ʴ´�
	m_wndSplitter.AddControl(POS_LEFT, GetDlgItem(IDC_TEST_STATIC), FALSE);
	m_wndSplitter.AddControl(POS_LEFT, GetDlgItem(IDC_TEST_EDIT), TRUE);
	m_wndSplitter.AddControl(POS_LEFT, GetDlgItem(IDC_TEST_BUTTON), TRUE);
	m_wndSplitter.AddControl(POS_LEFT, GetDlgItem(IDC_TEST_CALENDAR), TRUE);

	// ���� ���ø����� ������ �����ϴ� ��Ʈ�ѵ��� ���ø��Ϳ� �����Ѵ�
	// ��� ��Ʈ�ѿ� ���� ���ø��Ͱ� �־����� ���� ũ�⸦ �ø����� �����Ѵ�
	m_wndSplitter.AddControl(POS_RIGHT, GetDlgItem(IDC_TEST_TREE), TRUE);
	m_wndSplitter.AddControl(POS_RIGHT, &m_wndSplitter2, TRUE);
	m_wndSplitter.AddControl(POS_RIGHT, GetDlgItem(IDC_TEST_LIST), TRUE);
	
	// ���� ���ø��� �Ӽ��� �����Ѵ�
	m_wndSplitter2.SetDirection(DIR_HORZ);
	// ����� 80 �ȼ� �̵��� �� �ְ�, �ϴ��� 150 �ȼ� �̵��� �� �ֵ��� �����Ѵ�
	m_wndSplitter2.SetRange(80, 150);

	// ���� ���ø����� ��� ��Ʈ���� ���ø��Ϳ� �����Ѵ�
	m_wndSplitter2.AddControl(POS_TOP, GetDlgItem(IDC_TEST_TREE), TRUE);

	// ���� ���ø����� �ϴ� ��Ʈ���� ���ø��Ϳ� �����Ѵ�
	m_wndSplitter2.AddControl(POS_BOTTOM, GetDlgItem(IDC_TEST_LIST), TRUE);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CDialogSplitterWndDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDialogSplitterWndDemoDlg::OnPaint() 
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
HCURSOR CDialogSplitterWndDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
