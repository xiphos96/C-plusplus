// DriveComboBoxDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "DriveComboBoxDemo.h"
#include "DriveComboBoxDemoDlg.h"

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


// CDriveComboBoxDemoDlg ��ȭ ����



CDriveComboBoxDemoDlg::CDriveComboBoxDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDriveComboBoxDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDriveComboBoxDemoDlg)
	m_strCount = _T("");
	m_strCurDrive = _T("");
	m_nIcon = -1;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDriveComboBoxDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDriveComboBoxDemoDlg)
	DDX_Control(pDX, IDC_DRIVE_COMBO, m_DriveCombo);
	DDX_Text(pDX, IDC_COUNT_EDIT, m_strCount);
	DDX_Text(pDX, IDC_CUR_DRIVE_EDIT, m_strCurDrive);
	DDX_Radio(pDX, IDC_BIG_RADIO, m_nIcon);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDriveComboBoxDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDriveComboBoxDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BIG_RADIO, OnBigRadio)
	ON_BN_CLICKED(IDC_SMALL_RADIO, OnSmallRadio)
	ON_CBN_SELCHANGE(IDC_DRIVE_COMBO, OnSelchangeDriveCombo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CDriveComboBoxDemoDlg �޽��� ó����

BOOL CDriveComboBoxDemoDlg::OnInitDialog()
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

	// ���� ����̺� �̹��� ũ�⸦ ��´�
	m_nIcon = m_DriveCombo.IsBigIcon() ? 0 : 1;
	// ���� ����̺� ������ ��´�
	m_strCount.Format("%d���� ����̺갡 ��ġ�Ǿ� �ֽ��ϴ�.", m_DriveCombo.GetDriveCount());

	UpdateData(FALSE);
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CDriveComboBoxDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDriveComboBoxDemoDlg::OnPaint() 
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
HCURSOR CDriveComboBoxDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDriveComboBoxDemoDlg::OnBigRadio() 
{
	// ū ���������� ����̺� �������� �����Ѵ�
	m_nIcon = 0;
	m_DriveCombo.SetBigIcon(TRUE);
}

void CDriveComboBoxDemoDlg::OnSmallRadio() 
{
	// ���� ���������� ����̺� �������� �����Ѵ�
	m_nIcon = 1;
	m_DriveCombo.SetBigIcon(FALSE);
}

void CDriveComboBoxDemoDlg::OnSelchangeDriveCombo() 
{
	// ���� ���õ� �׸� ��ȣ�� ��´�
	int nSel = m_DriveCombo.GetCurSel();
	// ���� ���õ� �׸��� ���ٸ� ����
	if(nSel == CB_ERR)		return;

	// ���� ���õ� �׸��� �ؽ�Ʈ(����̺� �̸�)�� ��´�
	m_DriveCombo.GetLBText(nSel, m_strCurDrive);

	UpdateData(FALSE);
}
