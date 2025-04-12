// FilterEditDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "FilterEditDemo.h"
#include "FilterEditDemoDlg.h"

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


// CFilterEditDemoDlg ��ȭ ����



CFilterEditDemoDlg::CFilterEditDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFilterEditDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFilterEditDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFilterEditDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFilterEditDemoDlg)
	DDX_Control(pDX, IDC_FORMAT_EDIT, m_FormatEdit);
	DDX_Control(pDX, IDC_TIME_EDIT, m_TimeEdit);
	DDX_Control(pDX, IDC_DATE_EDIT, m_DateEdit);
	DDX_Control(pDX, IDC_CURRENCY_EDIT, m_CurrencyEdit);
	DDX_Control(pDX, IDC_ALNUM_EDIT, m_AlnumEdit);
	DDX_Control(pDX, IDC_ALPHA_EDIT, m_AlphaEdit);
	DDX_Control(pDX, IDC_LOWERCASE_EDIT, m_LowerCaseEdit);
	DDX_Control(pDX, IDC_UPPERCAES_EDIT, m_UpperCaseEdit);
	DDX_Control(pDX, IDC_REALNUMBER_EDIT, m_RealNumEdit);
	DDX_Control(pDX, IDC_SIGNEDNUM_EDIT, m_SignedNumEdit);
	DDX_Control(pDX, IDC_NUMBER_EDIT, m_NumberEdit);
	DDX_Control(pDX, IDC_NONE_EDIT, m_NoneEdit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFilterEditDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CFilterEditDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CFilterEditDemoDlg �޽��� ó����

BOOL CFilterEditDemoDlg::OnInitDialog()
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

	// �� ���鿡 ���� �׽�Ʈ�� ����Ʈ ��Ʈ�ѿ� �Ӽ� ����
	m_NoneEdit.SetFormat(FILTER_NONE);
	m_NumberEdit.SetFormat(FILTER_NUMBER);
	m_SignedNumEdit.SetFormat(FILTER_SIGNEDNUMBER);
	m_RealNumEdit.SetFormat(FILTER_REALNUMBER);
	m_UpperCaseEdit.SetFormat(FILTER_UPPERCASE);
	m_LowerCaseEdit.SetFormat(FILTER_LOWERCASE);
	m_AlphaEdit.SetFormat(FILTER_ALPHA);
	m_AlnumEdit.SetFormat(FILTER_ALNUM);
	m_CurrencyEdit.SetFormat(FILTER_CURRENCY);
	m_DateEdit.SetFormat(FILTER_DATE);
	m_TimeEdit.SetFormat(FILTER_TIME);

	m_FormatEdit.SetFormat("(###) ###-#### [$$$]");
	m_FormatEdit.SetTextColor(RGB(0, 0, 255));
	m_FormatEdit.SetBkgndColor(RGB(255, 255, 0));

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CFilterEditDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFilterEditDemoDlg::OnPaint() 
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
HCURSOR CFilterEditDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
