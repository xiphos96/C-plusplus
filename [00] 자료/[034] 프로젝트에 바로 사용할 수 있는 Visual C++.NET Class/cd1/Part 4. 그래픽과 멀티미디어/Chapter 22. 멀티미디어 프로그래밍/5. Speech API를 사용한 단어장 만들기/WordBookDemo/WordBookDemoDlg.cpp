// WordBookDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "WordBookDemo.h"
#include "WordBookDemoDlg.h"

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


// CWordBookDemoDlg ��ȭ ����



CWordBookDemoDlg::CWordBookDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWordBookDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWordBookDemoDlg)
	m_strEnglish = _T("");
	m_strKorean = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWordBookDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWordBookDemoDlg)
	DDX_Control(pDX, IDC_WORDBOOK_LIST, m_WordBook);
	DDX_Text(pDX, IDC_ENGLISH_EDIT, m_strEnglish);
	DDX_Text(pDX, IDC_KOREAN_EDIT, m_strKorean);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWordBookDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CWordBookDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_GETMINMAXINFO()
	ON_BN_CLICKED(IDC_ADD_BUTTON, OnAddButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CWordBookDemoDlg �޽��� ó����

BOOL CWordBookDemoDlg::OnInitDialog()
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

	// Ŭ���̾�Ʈ ������ �����Ѵ�
	GetClientRect(&m_rcClient);
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CWordBookDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWordBookDemoDlg::OnPaint() 
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
HCURSOR CWordBookDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CWordBookDemoDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

	// �ܾ����� ������ ���¸�
	if(m_WordBook.m_hWnd)
	{
		// �ܾ��� ũ�⸦ ��´�
		CRect rcList;
		m_WordBook.GetWindowRect(&rcList);
		ScreenToClient(&rcList);

		// ���̾�α��� ��ȭ�� ũ�⸦ ����Ѵ�
		cx -= m_rcClient.Width();
		cy -= m_rcClient.Height();

		// �ܾ����� ũ�⸦ �����Ѵ�
		rcList.right += cx;
		rcList.bottom += cy;

		// �ܾ����� ũ�⸦ �����Ѵ�
		m_WordBook.MoveWindow(&rcList);

		// �� Ŭ���̾�Ʈ ������ �����Ѵ�
		GetClientRect(&m_rcClient);
	}
}

void CWordBookDemoDlg::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	// �ּ� ũ�⸦ �����Ѵ�
	lpMMI->ptMinTrackSize.x = 498;
	lpMMI->ptMinTrackSize.y = 130;
	
	CDialog::OnGetMinMaxInfo(lpMMI);
}

BOOL CWordBookDemoDlg::PreTranslateMessage(MSG* pMsg) 
{
	// ���� EnterŰ�� ����������
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		// ���� ���� �Է� ����Ʈ ��Ʈ�ѿ��� ����Ű�� �������ٸ�
		if(GetFocus()->m_hWnd == GetDlgItem(IDC_ENGLISH_EDIT)->m_hWnd)
		{
			// ���� �ܾ ���´�
			CString strTemp;
			GetDlgItem(IDC_ENGLISH_EDIT)->GetWindowText(strTemp);

			// �ܾ� �Է��� ���� �ʾҴٸ� �����Ѵ�
			if(strTemp.IsEmpty())	return TRUE;
			// �ѱ� �ؼ� �Է� ����Ʈ ��Ʈ�ѷ� ��Ŀ���� �̵��Ѵ�
			GetDlgItem(IDC_KOREAN_EDIT)->SetFocus();
			return TRUE;
		}

		// ���� �ѱ� �Է� ����Ʈ ��Ʈ�ѿ��� ����Ű�� �������ٸ�
		if(GetFocus()->m_hWnd == GetDlgItem(IDC_KOREAN_EDIT)->m_hWnd)
		{
			// �ѱ� �ؼ��� ���´�
			CString strTemp;
			GetDlgItem(IDC_KOREAN_EDIT)->GetWindowText(strTemp);

			// �ؼ��� �Էµ��� �ʾҴٸ� �����Ѵ�
			if(strTemp.IsEmpty())	return TRUE;
			// �ܾ��忡 �ܾ �߰��Ѵ�
			OnAddButton();
			return TRUE;
		}
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CWordBookDemoDlg::OnAddButton() 
{
	UpdateData(TRUE);

	// ���� ���� �ܾ �ؼ��� �Էµ��� �ʾҴٸ� �����Ѵ�
	if(m_strEnglish.IsEmpty() || m_strKorean.IsEmpty())	return;

	// ���� �ܾ �ܾ��忡 �߰��Ѵ�
	m_WordBook.AddWord(m_strEnglish, m_strKorean);

	// ����Ʈ ��Ʈ�ѵ��� �ʱ�ȭ�Ѵ�
	m_strEnglish.Empty();
	m_strKorean.Empty();

	UpdateData(FALSE);

	// ���� �ܾ� ����Ʈ ��Ʈ�ѷ� ��Ŀ���� �̵��Ѵ�
	GetDlgItem(IDC_ENGLISH_EDIT)->SetFocus();
}
