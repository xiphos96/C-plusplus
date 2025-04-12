// ImageProgressCtrlDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ImageProgressCtrlDemo.h"
#include "ImageProgressCtrlDemoDlg.h"

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


// CImageProgressCtrlDemoDlg ��ȭ ����



CImageProgressCtrlDemoDlg::CImageProgressCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImageProgressCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImageProgressCtrlDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImageProgressCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImageProgressCtrlDemoDlg)
	DDX_Control(pDX, IDC_HORZ_PROGRESS, m_HorzProgressCtrl);
	DDX_Control(pDX, IDC_VERT_PROGRESS, m_VertProgressCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CImageProgressCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CImageProgressCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RESTART_BUTTON, OnRestartButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CImageProgressCtrlDemoDlg �޽��� ó����

BOOL CImageProgressCtrlDemoDlg::OnInitDialog()
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

	// �̹��� ���α׷������� ���� ���ڿ� ����
	CString strFormat;
	strFormat.Format("[%%d / %d] �Ϸ�", 200);

	// ���� �̹��� ���α׷������� �Ӽ��� �����Ѵ�
	m_HorzProgressCtrl.SetRange(0, 200);
	m_HorzProgressCtrl.SetPos(0);
	m_HorzProgressCtrl.SetStep(2);
	// ���ڿ� ������ ����Ͽ� ���� ���� ǥ��
	m_HorzProgressCtrl.SetTextType(TEXT_FORMAT);
	// ���ڿ� ���� ����
	m_HorzProgressCtrl.SetTextFormat(strFormat);
	// ��� �׵θ��� ��Ʈ�� ����
	m_HorzProgressCtrl.SetBorderBitmap(BMP_LEFT, IDB_BORDER_LEFT);
	m_HorzProgressCtrl.SetBorderBitmap(BMP_CENTER, IDB_BORDER_CENTER);
	m_HorzProgressCtrl.SetBorderBitmap(BMP_RIGHT, IDB_BORDER_RIGHT);
	// ������� ��Ʈ�� ����
	m_HorzProgressCtrl.SetPosBitmap(BMP_LEFT, IDB_POS_LEFT);
	m_HorzProgressCtrl.SetPosBitmap(BMP_CENTER, IDB_POS_CENTER);
	m_HorzProgressCtrl.SetPosBitmap(BMP_RIGHT, IDB_POS_RIGHT);

	// ���� �̹��� ���α׷������� �Ӽ��� �����Ѵ�
	m_VertProgressCtrl.SetRange(0, 100);
	m_VertProgressCtrl.SetPos(0);
	m_VertProgressCtrl.SetStep(1);
	// �ۼ�Ʈ�� ���� ���� ǥ��
	m_VertProgressCtrl.SetTextType(TEXT_PERCENT);

	// �׽�Ʈ�� ���� Ÿ�̸Ӹ� �����Ѵ�
	SetTimer(1, 50, NULL);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CImageProgressCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CImageProgressCtrlDemoDlg::OnPaint() 
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
HCURSOR CImageProgressCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CImageProgressCtrlDemoDlg::OnTimer(UINT nIDEvent) 
{
	int nMin, nMax;

	// ����/���� ���α׷������� ��ġ�� ������Ų��
	m_HorzProgressCtrl.StepIt();
	m_HorzProgressCtrl.Invalidate(FALSE);
	m_VertProgressCtrl.StepIt();
	m_VertProgressCtrl.Invalidate(FALSE);

	// ���� ���� ���α׷������� ���� ��ġ�� �ִ밪�̶�� Ÿ�̸Ӹ� �����Ѵ�
	m_HorzProgressCtrl.GetRange(nMin, nMax);
	if(m_HorzProgressCtrl.GetPos() >= nMax)		KillTimer(nIDEvent);
	
	CDialog::OnTimer(nIDEvent);
}

void CImageProgressCtrlDemoDlg::OnRestartButton() 
{
	// ����/���� ���α׷������� ��ġ�� 0���� �ʱ�ȭ�Ѵ�
	m_HorzProgressCtrl.SetPos(0);
	m_VertProgressCtrl.SetPos(0);

	// Ÿ�̸Ӹ� �����Ѵ�
	SetTimer(1, 50, NULL);
}
