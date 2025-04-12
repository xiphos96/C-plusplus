// DDTreeCtrlDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "DDTreeCtrlDemo.h"
#include "DDTreeCtrlDemoDlg.h"

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


// CDDTreeCtrlDemoDlg ��ȭ ����



CDDTreeCtrlDemoDlg::CDDTreeCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDDTreeCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDDTreeCtrlDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDDTreeCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDDTreeCtrlDemoDlg)
	DDX_Control(pDX, IDC_TARGET_TREE, m_TargetTree);
	DDX_Control(pDX, IDC_ALL_TREE, m_AllTree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDDTreeCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDDTreeCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CDDTreeCtrlDemoDlg �޽��� ó����

BOOL CDDTreeCtrlDemoDlg::OnInitDialog()
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
	m_TreeImageList.Create(IDB_ITEM_BITMAP, 16, 1, RGB(255, 255, 255));

	// ���� Ʈ�� ��Ʈ�ѿ� �̹��� ����Ʈ�� �����Ѵ�
	m_AllTree.SetImageList(&m_TreeImageList, TVSIL_NORMAL);

	// ���� Ʈ�� ��Ʈ�ѿ� �̹��� ����Ʈ�� �����Ѵ�
	m_TargetTree.SetImageList(&m_TreeImageList, LVSIL_NORMAL);

	// ���� Ʈ�� ��Ʈ�ѿ� �׸���� �߰��Ѵ�
	HTREEITEM hRoot = m_AllTree.InsertItem("����", 9, 10);
	HTREEITEM hFish = m_AllTree.InsertItem("���", 9, 10, hRoot);
	HTREEITEM hBird = m_AllTree.InsertItem("����", 9, 10, hRoot);
	HTREEITEM hMammal = m_AllTree.InsertItem("������", 9, 10, hRoot);
	HTREEITEM hCrustacea = m_AllTree.InsertItem("������", 9, 10, hRoot);

	m_AllTree.InsertItem("�����", 0, 0, hFish);
	m_AllTree.InsertItem("�Ķ���", 1, 1, hBird);
	m_AllTree.InsertItem("�䳢", 2, 2, hMammal);
	m_AllTree.InsertItem("��Ÿ", 3, 3, hMammal);
	m_AllTree.InsertItem("�ɰ�", 4, 4, hCrustacea);
	m_AllTree.InsertItem("�糪��", 5, 5, hMammal);
	m_AllTree.InsertItem("������", 6, 6, hMammal);
	m_AllTree.InsertItem("�����", 7, 7, hMammal);
	m_AllTree.InsertItem("���", 8, 8, hMammal);

	// ��Ʈ ��带 Ȯ���Ѵ�
	m_AllTree.Expand(hRoot, TVE_EXPAND);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CDDTreeCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDDTreeCtrlDemoDlg::OnPaint() 
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
HCURSOR CDDTreeCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
