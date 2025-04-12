// AnimGIFDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "AnimGIFDemo.h"
#include "AnimGIFDemoDlg.h"
#include ".\animgifdemodlg.h"

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


// CAnimGIFDemoDlg ��ȭ ����



CAnimGIFDemoDlg::CAnimGIFDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnimGIFDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAnimGIFDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnimGIFDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnimGIFDemoDlg)
	DDX_Control(pDX, IDC_GIF_STATIC, m_AnimGIF);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAnimGIFDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CAnimGIFDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PLAY_BUTTON, OnPlayButton)
	ON_BN_CLICKED(IDC_PAUSE_BUTTON, OnPauseButton)
	ON_BN_CLICKED(IDC_RESUME_BUTTON, OnResumeButton)
	//}}AFX_MSG_MAP
//	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CAnimGIFDemoDlg �޽��� ó����

BOOL CAnimGIFDemoDlg::OnInitDialog()
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

	GetDlgItem(IDC_PAUSE_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_RESUME_BUTTON)->EnableWindow(FALSE);

	m_AnimGIF.LoadGIF(IDR_ANIM_GIF, "GIF");

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CAnimGIFDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAnimGIFDemoDlg::OnPaint() 
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
HCURSOR CAnimGIFDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAnimGIFDemoDlg::OnPlayButton() 
{
	GetDlgItem(IDC_PLAY_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_PAUSE_BUTTON)->EnableWindow(TRUE);

	m_AnimGIF.Play();
}

void CAnimGIFDemoDlg::OnPauseButton() 
{
	GetDlgItem(IDC_PAUSE_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_RESUME_BUTTON)->EnableWindow(TRUE);

	m_AnimGIF.Pause();
}

void CAnimGIFDemoDlg::OnResumeButton() 
{
	GetDlgItem(IDC_RESUME_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_PAUSE_BUTTON)->EnableWindow(TRUE);

	m_AnimGIF.Resume();
}
