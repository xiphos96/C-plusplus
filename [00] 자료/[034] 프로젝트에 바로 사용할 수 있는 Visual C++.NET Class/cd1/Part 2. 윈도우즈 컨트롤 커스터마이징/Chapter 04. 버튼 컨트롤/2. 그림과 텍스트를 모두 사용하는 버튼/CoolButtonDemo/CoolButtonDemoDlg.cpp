// CoolButtonDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CoolButtonDemo.h"
#include "CoolButtonDemoDlg.h"

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


// CCoolButtonDemoDlg ��ȭ ����



CCoolButtonDemoDlg::CCoolButtonDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCoolButtonDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCoolButtonDemoDlg)
	m_nAlign = 0;
	m_bEnable = TRUE;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCoolButtonDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCoolButtonDemoDlg)
	DDX_Control(pDX, IDC_BMP_BUTTON, m_btnBmp);
	DDX_Control(pDX, IDC_ICON_BUTTON, m_btnIcon);
	DDX_Control(pDX, IDC_TRASPARENT_BUTTON, m_btnTransparent);
	DDX_Control(pDX, IDC_POSITION_BUTTON, m_btnPosition);
	DDX_Radio(pDX, IDC_LEFT_RADIO, m_nAlign);
	DDX_Check(pDX, IDC_ENABLE_CHECK, m_bEnable);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCoolButtonDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CCoolButtonDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LEFT_RADIO, OnLeftRadio)
	ON_BN_CLICKED(IDC_RIGHT_RADIO, OnRightRadio)
	ON_BN_CLICKED(IDC_TOP_RADIO, OnTopRadio)
	ON_BN_CLICKED(IDC_BOTTOM_RADIO, OnBottomRadio)
	ON_BN_CLICKED(IDC_OVER_RADIO, OnOverRadio)
	ON_BN_CLICKED(IDC_ENABLE_CHECK, OnEnableCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CCoolButtonDemoDlg �޽��� ó����

BOOL CCoolButtonDemoDlg::OnInitDialog()
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

	// ��Ʈ���� ���� ��ư
	m_btnBmp.SetButtonBmp(IDB_BUTTON1);								// ��Ʈ���� �����Ѵ�
	m_btnBmp.SetFlat(TRUE);											// ��� ��ư�� �����Ѵ�
	m_btnBmp.SetButtonColor(COLOR_TEXT, RGB(50, 50, 50));			// ���ڻ��� �����Ѵ�
	m_btnBmp.SetButtonColor(COLOR_BKGND, RGB(192, 192, 192));		// ������ �����Ѵ�
	m_btnBmp.SetButtonColor(COLOR_TEXT_IN, RGB(66, 168, 255));		// ���콺�� ���� ���� ���� ���ڻ��� �����Ѵ�
	m_btnBmp.SetButtonColor(COLOR_BKGND_IN, RGB(220, 220, 220));	// ���콺�� ���� ���� ���� ������ �����Ѵ�

	// �������� ���� ��ư
	m_btnIcon.SetButtonIcon(IDI_BUTTON);							// �������� �����Ѵ�
	m_btnIcon.SetFlat(FALSE);										// ��ü ��ư�� �����Ѵ�
	m_btnIcon.SetButtonColor(COLOR_TEXT, RGB(50, 50, 50));			// ���ڻ��� �����Ѵ� 
	m_btnIcon.SetButtonColor(COLOR_BKGND, RGB(192, 192, 192));		// ������ �����Ѵ�
	m_btnIcon.SetButtonColor(COLOR_TEXT_IN, RGB(66, 168, 255));		// ���콺�� ���� ���� ���� ���ڻ��� �����Ѵ�
	m_btnIcon.SetButtonColor(COLOR_BKGND_IN, RGB(220, 220, 220));	// ���콺�� ���� ���� ���� ������ �����Ѵ�

	// ��Ʈ���� ������ Ư�� ���� ���� ó���� ��ư
	m_btnTransparent.SetButtonBmp(IDB_BUTTON1, RGB(197, 197, 197));	// ��Ʈ���� �����ϰ� ������� �����Ѵ�
	m_btnTransparent.SetFlat(TRUE);									// ��� ��ư�� �����Ѵ�
	m_btnTransparent.SetButtonColor(COLOR_TEXT, RGB(50, 50, 50));	// ���ڻ��� �����Ѵ�
	m_btnTransparent.SetButtonColor(COLOR_BKGND, RGB(255, 255, 255));		// ������ �����Ѵ�
	m_btnTransparent.SetButtonColor(COLOR_TEXT_IN, RGB(66, 168, 255));		// ���콺�� ���� ���� ���� ���ڻ��� �����Ѵ�
	m_btnTransparent.SetButtonColor(COLOR_BKGND_IN, RGB(220, 220, 220));	// ���콺�� ���� ���� ���� ������ �����Ѵ�

	// ��ġ ���� ��ư
	m_btnPosition.SetButtonBmp(IDB_BUTTON2, RGB(255, 255, 255));	// ��Ʈ���� �����ϰ� ������� �����Ѵ�
	m_btnPosition.SetFlat(FALSE);									// ��ü ��ư�� �����Ѵ�
	m_btnPosition.SetTextAlign(ALIGN_LEFT);							// �ؽ�Ʈ ������ �������� �Ѵ�
	m_btnPosition.SetButtonColor(COLOR_TEXT, RGB(50, 50, 50));		// ���ڻ��� �����Ѵ�
	m_btnPosition.SetButtonColor(COLOR_BKGND, RGB(255, 255, 255));	// ������ �����Ѵ�
	m_btnPosition.SetButtonColor(COLOR_TEXT_IN, RGB(66, 168, 255));	// ���콺�� ���� ���� ���� ���ڻ��� �����Ѵ�
	m_btnPosition.SetButtonColor(COLOR_BKGND_IN, RGB(220, 220, 220));	// ���콺�� ���� ���� ���� ������ �����Ѵ�
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CCoolButtonDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCoolButtonDemoDlg::OnPaint() 
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
HCURSOR CCoolButtonDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCoolButtonDemoDlg::OnLeftRadio() 
{
	// �ؽ�Ʈ ������ �������� �Ѵ�
	m_btnPosition.SetTextAlign(ALIGN_LEFT);
}

void CCoolButtonDemoDlg::OnRightRadio() 
{
	// �ؽ�Ʈ ������ ���������� �Ѵ�
	m_btnPosition.SetTextAlign(ALIGN_RIGHT);
}

void CCoolButtonDemoDlg::OnTopRadio() 
{
	// �ؽ�Ʈ ������ �������� �Ѵ�
	m_btnPosition.SetTextAlign(ALIGN_TOP);
}

void CCoolButtonDemoDlg::OnBottomRadio() 
{
	// �ؽ�Ʈ ������ �Ʒ������� �Ѵ�
	m_btnPosition.SetTextAlign(ALIGN_BOTTOM);
}

void CCoolButtonDemoDlg::OnOverRadio() 
{
	// �ؽ�Ʈ�� �̹��� ���� ��ġ��Ų��
	m_btnPosition.SetTextAlign(ALIGN_OVER);
}

void CCoolButtonDemoDlg::OnEnableCheck() 
{
	// ��ư�� Ȱ��ȭ ��Ű�ų� ��Ȱ��ȭ ��Ų��
	UpdateData(TRUE);

	m_btnPosition.EnableWindow(m_bEnable);
}
