// ColorMessageBoxDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ColorMessageBox.h"
#include "ColorMessageBoxDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// �÷� �޽��� �ڽ��� ����ϱ� ���� ��� ����
#include "ColorMsgBoxHook.h"

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


// CColorMessageBoxDlg ��ȭ ����



CColorMessageBoxDlg::CColorMessageBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CColorMessageBoxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CColorMessageBoxDlg)
	m_nUse = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CColorMessageBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColorMessageBoxDlg)
	DDX_Control(pDX, IDC_COLOR_BKGND_STATIC, m_clrBkgnd);
	DDX_Control(pDX, IDC_COLOR_TEXT_STATIC, m_clrText);
	DDX_Radio(pDX, IDC_USE_RADIO, m_nUse);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CColorMessageBoxDlg, CDialog)
	//{{AFX_MSG_MAP(CColorMessageBoxDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_AFXMESSAGEBOX_BUTTON, OnAfxmessageboxButton)
	ON_BN_CLICKED(IDC_MESSAGEBOX_BUTTON, OnMessageboxButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CColorMessageBoxDlg �޽��� ó����

BOOL CColorMessageBoxDlg::OnInitDialog()
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

	// �⺻ �ؽ�Ʈ ����� ��� ������ �����Ѵ�
	m_clrText.m_clrColor	= RGB(30, 30, 30);
	m_clrBkgnd.m_clrColor	= RGB(255, 255, 255);
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CColorMessageBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CColorMessageBoxDlg::OnPaint() 
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
HCURSOR CColorMessageBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CColorMessageBoxDlg::OnMessageboxButton() 
{
	UpdateData(TRUE);

	// ���� �÷��� ����Ѵٸ�
	if(m_nUse == 0)
	{
		// �ؽ�Ʈ�� ��� ������ �÷� �޽��� �ڽ��� �����Ѵ�
		g_MsgBoxHook.SetColorText(m_clrText.m_clrColor);
		g_MsgBoxHook.SetColorBkgnd(m_clrBkgnd.m_clrColor);

		// �÷� �޽��� �ڽ��� ����
		g_MsgBoxHook.MessageBox(m_hWnd, "�޽��� �ڽ� �׽�Ʈ�Դϴ�.", "MessageBox", MB_ICONINFORMATION | MB_OK);
	}
	else
		// ���� �÷��� ������� �ʴ´ٸ� �⺻ �޽��� �ڽ��� ����
		MessageBox("�޽��� �ڽ� �׽�Ʈ�Դϴ�.", "MessageBox", MB_ICONINFORMATION | MB_OK);
}

void CColorMessageBoxDlg::OnAfxmessageboxButton() 
{
	UpdateData(TRUE);

	// ���� �÷��� ����Ѵٸ�
	if(m_nUse == 0)
	{
		// �ؽ�Ʈ�� ��� ������ �÷� �޽��� �ڽ��� �����Ѵ�
		g_MsgBoxHook.SetColorText(m_clrText.m_clrColor);
		g_MsgBoxHook.SetColorBkgnd(m_clrBkgnd.m_clrColor);

		// �÷� �޽��� �ڽ��� ����
		g_MsgBoxHook.AfxMessageBox("�޽��� �ڽ� �׽�Ʈ�Դϴ�.", MB_ICONWARNING | MB_YESNO);
	}
	else
		// ���� �÷��� ������� �ʴ´ٸ� �⺻ �޽��� �ڽ��� ����
		::AfxMessageBox("�޽��� �ڽ� �׽�Ʈ�Դϴ�.", MB_ICONWARNING | MB_YESNO);
}
