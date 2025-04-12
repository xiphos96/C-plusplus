// CamCastDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CamCastDemo.h"
#include "CamCastDemoDlg.h"

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


// CCamCastDemoDlg ��ȭ ����



CCamCastDemoDlg::CCamCastDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCamCastDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCamCastDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCamCastDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCamCastDemoDlg)
	DDX_Control(pDX, IDC_CAMCAST_STATIC, m_CamCast);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCamCastDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CCamCastDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_REC_BUTTON, OnRecButton)
	ON_BN_CLICKED(IDC_CAST_BUTTON, OnCastButton)
	ON_BN_CLICKED(IDC_STOP_BUTTON, OnStopButton)
	ON_BN_CLICKED(IDC_CONFIG_BUTTON, OnConfigButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CCamCastDemoDlg �޽��� ó����

BOOL CCamCastDemoDlg::OnInitDialog()
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

	// ������ ��ȭ ��� Ŭ������ �ʱ�ȭ�մϴ�
	if(!m_CamCast.Initialize())
	{
		GetDlgItem(IDC_REC_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAST_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_STOP_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_CONFIG_BUTTON)->EnableWindow(FALSE);

		MessageBox("�̵�� ���ڴ��� �ʱ�ȭ�� �� �����ϴ�.");
	}
	else
	{
		GetDlgItem(IDC_STOP_BUTTON)->EnableWindow(FALSE);
	}
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CCamCastDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCamCastDemoDlg::OnPaint() 
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
HCURSOR CCamCastDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCamCastDemoDlg::OnRecButton() 
{
	// ��ȭ�� �������� ������ ��θ� �Է� �޴´�
	CFileDialog SaveDlg(FALSE, "wmv", NULL,
		OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_LONGNAMES,
		"WMV ����|*.wmv|��� ����|*.*||");
	
	SaveDlg.m_ofn.lpstrTitle = "��ȭ�� �������� ������ ��θ� �Է��ϼ���";

	if(SaveDlg.DoModal() != IDOK)		return;

	// �������� ���Ϸ� ��ȭ�Ѵ�
	if(m_CamCast.Record(SaveDlg.GetPathName()))
	{
		GetDlgItem(IDC_REC_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAST_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_STOP_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_CONFIG_BUTTON)->EnableWindow(FALSE);
	}
	else
		MessageBox("Error");
}

void CCamCastDemoDlg::OnCastButton() 
{
	// �������� 8080��Ʈ�� ����Ѵ�
	if(m_CamCast.Cast(8080))
	{
		GetDlgItem(IDC_REC_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAST_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_STOP_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_CONFIG_BUTTON)->EnableWindow(FALSE);
	}
	else
		MessageBox("Error");
}

void CCamCastDemoDlg::OnStopButton() 
{
	// ������ ��ȭ�� ����� �����Ѵ�
	if(m_CamCast.Stop())
	{
		GetDlgItem(IDC_REC_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_CAST_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_STOP_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_CONFIG_BUTTON)->EnableWindow(TRUE);
	}
	else
		MessageBox("Error");
}

void CCamCastDemoDlg::OnConfigButton() 
{
	// ������ ��ȭ�� ��ۿ� ���� �ɼ��� �����Ѵ�
	if(!m_CamCast.Config())		MessageBox("Canceled");
}
