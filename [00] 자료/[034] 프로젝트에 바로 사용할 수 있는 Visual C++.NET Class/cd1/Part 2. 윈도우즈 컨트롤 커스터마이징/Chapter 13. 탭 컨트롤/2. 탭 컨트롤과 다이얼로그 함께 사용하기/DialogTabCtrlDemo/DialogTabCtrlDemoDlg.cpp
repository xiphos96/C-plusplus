// DialogTabCtrlDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "DialogTabCtrlDemo.h"
#include "DialogTabCtrlDemoDlg.h"

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


// CDialogTabCtrlDemoDlg ��ȭ ����



CDialogTabCtrlDemoDlg::CDialogTabCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogTabCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogTabCtrlDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogTabCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogTabCtrlDemoDlg)
	DDX_Control(pDX, IDC_DIALOG_TAB, m_DialogTab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDialogTabCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDialogTabCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_AT_SELCHANGE, OnATSelChange)
END_MESSAGE_MAP()


// CDialogTabCtrlDemoDlg �޽��� ó����

BOOL CDialogTabCtrlDemoDlg::OnInitDialog()
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

	// ���� ���̾�α׸� �����Ѵ�
	if(!m_IncomeDlg.Create(IDD_INCOME_DIALOG, &m_DialogTab))
	{
		MessageBox("���� ���̾�α׸� ������ �� �����ϴ�.");
		OnCancel();
		return TRUE;
	}

	// ���� ���̾�α׸� �����Ѵ�
	if(!m_OutgoDlg.Create(IDD_OUTGO_DIALOG, &m_DialogTab))
	{
		MessageBox("���� ���̾�α׸� ������ �� �����ϴ�.");
		OnCancel();
		return TRUE;
	}

	// �հ� ���̾�α׸� �����Ѵ�
	if(!m_ReportDlg.Create(IDD_REPORT_DIALOG, &m_DialogTab))
	{
		MessageBox("�հ� ���̾�α׸� ������ �� �����ϴ�.");
		OnCancel();
		return TRUE;
	}

	// ���̾�α� �� ��Ʈ�ѿ� ���� �߰��Ѵ� - ���� �����ϴ� ���̾�α׸� �Բ� �����Ѵ�
	m_DialogTab.InsertItem(0, "����", &m_IncomeDlg);
	m_DialogTab.InsertItem(1, "����", &m_OutgoDlg);
	m_DialogTab.InsertItem(2, "�հ�", &m_ReportDlg);

	// �ʱ� ���� 0������ �����Ѵ�
	m_DialogTab.SetCurSel(0);
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CDialogTabCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDialogTabCtrlDemoDlg::OnPaint() 
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
HCURSOR CDialogTabCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ���̾�α� �� ��Ʈ���� �� ����� ȣ��Ǵ� �Լ�
LRESULT CDialogTabCtrlDemoDlg::OnATSelChange(WPARAM wParam, LPARAM lParam) 
{
	switch(lParam)
	{
	case 0:
		// ���� ���� ���õǸ� ���� ���̾�α��� ����Ʈ �ڽ����� �ؽ�Ʈ�� �ʱ�ȭ�Ѵ�
		m_IncomeDlg.ResetEdit();
		break;
	case 1:
		// ���� ���� ���õǸ� ���� ���̾�α��� ����Ʈ �ڽ����� �ؽ�Ʈ�� �ʱ�ȭ�Ѵ�
		m_OutgoDlg.ResetEdit();
		break;
	case 2:
		// �հ� ���� ���õǸ� �հ� ���̾�α׿��� �հ踦 ����Ͽ� ����Ѵ�
		m_ReportDlg.RefreshSum();
		break;
	}

	return 0;
}
