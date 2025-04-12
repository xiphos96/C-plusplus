// BmpButtonDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "BmpButtonDemo.h"
#include "BmpButtonDemoDlg.h"
#include ".\bmpbuttondemodlg.h"

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


// CBmpButtonDemoDlg ��ȭ ����



CBmpButtonDemoDlg::CBmpButtonDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBmpButtonDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBmpButtonDemoDlg)
	m_nOrigin = 0;
	m_nSpeed = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBmpButtonDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBmpButtonDemoDlg)
	DDX_Control(pDX, IDC_SPEED_BITMAP_BUTTON, m_btnSpeed);
	DDX_Control(pDX, IDC_ORIGIN_BITMAP_BUTTON, m_btnOrigin);
	DDX_Text(pDX, IDC_ORIGIN_EDIT, m_nOrigin);
	DDX_Text(pDX, IDC_SPEED_EDIT, m_nSpeed);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBmpButtonDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CBmpButtonDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ORIGIN_BITMAP_BUTTON, OnOriginBitmapButton)
	ON_BN_CLICKED(IDC_SPEED_BITMAP_BUTTON, OnSpeedBitmapButton)
	//}}AFX_MSG_MAP
//	ON_BN_DOUBLECLICKED(IDC_SPEED_BITMAP_BUTTON, OnBnDoubleclickedSpeedBitmapButton)
//	ON_BN_DOUBLECLICKED(IDC_ORIGIN_BITMAP_BUTTON, OnBnDoubleclickedOriginBitmapButton)
END_MESSAGE_MAP()


// CBmpButtonDemoDlg �޽��� ó����

BOOL CBmpButtonDemoDlg::OnInitDialog()
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

	// ���� ��Ʈ�� ��ư�� ��Ʈ�� �ε�
	m_btnOrigin.LoadBitmaps(IDB_BMP_NORMAL, IDB_BMP_PRESS);
	// ��Ʈ�� ũ��� ��ư ũ�� ����
	m_btnOrigin.SizeToContent();

	// ���� ��Ʈ�� ��ư�� ��Ʈ�� �ε�
	m_btnSpeed.LoadBitmaps(IDB_BMP_NORMAL, IDB_BMP_PRESS);
	// ��Ʈ�� ũ��� ��ư ũ�� ����
	m_btnSpeed.SizeToContent();
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CBmpButtonDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBmpButtonDemoDlg::OnPaint() 
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
HCURSOR CBmpButtonDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ���� ��Ʈ�� ��ư Ŭ�� �̺�Ʈ �ڵ鷯
void CBmpButtonDemoDlg::OnOriginBitmapButton() 
{
	// ��ư Ŭ�� Ƚ���� 1 ���� ��Ų��
	UpdateData(TRUE);

	m_nOrigin++;

	UpdateData(FALSE);
}

// ���� ��Ʈ�� ��ư Ŭ�� �̺�Ʈ �ڵ鷯
void CBmpButtonDemoDlg::OnSpeedBitmapButton() 
{
	// ��ư Ŭ�� Ƚ���� 1 ���� ��Ų��
	UpdateData(TRUE);

	m_nSpeed++;

	UpdateData(FALSE);
}
