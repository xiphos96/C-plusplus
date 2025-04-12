// FileNameEditDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "FileNameEditDemo.h"
#include "FileNameEditDemoDlg.h"

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


// CFileNameEditDemoDlg ��ȭ ����



CFileNameEditDemoDlg::CFileNameEditDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileNameEditDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileNameEditDemoDlg)
	m_strFilePath = _T("");
	m_strFolderPath = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileNameEditDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileNameEditDemoDlg)
	DDX_Control(pDX, IDC_FILE_EDIT, m_FileEdit);
	DDX_Control(pDX, IDC_FOLDER_EDIT, m_FolderEdit);
	DDX_Control(pDX, IDC_FILE_EDIT2, m_FileEdit2);
	DDX_Control(pDX, IDC_FOLDER_EDIT2, m_FolderEdit2);
	//}}AFX_DATA_MAP
	// CFildNameEditŬ������ ����Ͽ� DDX/DDV�� �����ϱ� ���� �Լ�
	DDX_FileName(pDX, IDC_FILE_EDIT2, m_strFilePath);
	DDX_FileName(pDX, IDC_FOLDER_EDIT2, m_strFolderPath);
}

BEGIN_MESSAGE_MAP(CFileNameEditDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CFileNameEditDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GET_TEXT_BUTTON, OnGetTextButton)
	ON_BN_CLICKED(IDC_GET_TEXT_BUTTON2, OnGetTextButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CFileNameEditDemoDlg �޽��� ó����

BOOL CFileNameEditDemoDlg::OnInitDialog()
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

	// ���� ���� ���� �����Ѵ�
	m_FolderEdit.SetFileMode(FALSE);
	// ���� ���� ���� �����Ѵ�
	m_FolderEdit2.SetFileMode(FALSE);
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CFileNameEditDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileNameEditDemoDlg::OnPaint() 
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
HCURSOR CFileNameEditDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFileNameEditDemoDlg::OnGetTextButton() 
{
	// �б������� ������ ����Ʈ ��Ʈ���� ���� ��θ� ��´�
	UpdateData(TRUE);
	MessageBox(m_strFilePath);
}

void CFileNameEditDemoDlg::OnGetTextButton2() 
{
	// �б������� ������ ����Ʈ ��Ʈ���� ���� ��θ� ��´�
	UpdateData(TRUE);
	MessageBox(m_strFolderPath);
}
