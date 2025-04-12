// ColorPickButtonDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ColorPickButtonDemo.h"
#include "ColorPickButtonDemoDlg.h"

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


// CColorPickButtonDemoDlg ��ȭ ����



CColorPickButtonDemoDlg::CColorPickButtonDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CColorPickButtonDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CColorPickButtonDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CColorPickButtonDemoDlg::~CColorPickButtonDemoDlg()
{
	// ��� ��¿� �귯�� ����
	if(m_BkgndBrush.m_hObject)	m_BkgndBrush.DeleteObject();
}

void CColorPickButtonDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColorPickButtonDemoDlg)
	DDX_Control(pDX, IDC_TEXT_DEFAULT_COLOR_BUTTON, m_btnTextDefault);
	DDX_Control(pDX, IDC_BKGND_DEFAULT_COLOR_BUTTON, m_btnBkgndDefault);
	DDX_Control(pDX, IDC_TEXT_COLOR_BUTTON, m_btnText);
	DDX_Control(pDX, IDC_BKGND_COLOR_BUTTON, m_btnBkgnd);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CColorPickButtonDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CColorPickButtonDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
	ON_MESSAGE(CLR_SELENDOK, OnSelEndOKColor)
END_MESSAGE_MAP()


// CColorPickButtonDemoDlg �޽��� ó����

BOOL CColorPickButtonDemoDlg::OnInitDialog()
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

	// ���� �⺻ ����� ��� �⺻ ������ �ý��� �������� �����Ѵ�
	m_clrTextDefault	= ::GetSysColor(COLOR_BTNTEXT);
	m_clrBkgndDefault	= ::GetSysColor(COLOR_BTNFACE);
	// ���� ����� ��� ������ �⺻ �������� �����Ѵ�.
	m_clrText			= m_clrTextDefault;
	m_clrBkgnd			= m_clrBkgndDefault;

	// ��� �������� �귯���� �����Ѵ�
	m_BkgndBrush.CreateSolidBrush(m_clrBkgnd);

	// �⺻ ���� ���� ��ư�� �����Ѵ�
	m_btnTextDefault.SetDefaultColor(m_clrTextDefault);
	m_btnTextDefault.SetColor(m_clrTextDefault);

	// �⺻ ��� ���� ��ư�� �����Ѵ�
	m_btnBkgndDefault.SetDefaultColor(m_clrBkgndDefault);
	m_btnBkgndDefault.SetColor(m_clrBkgndDefault);

	// ���� ���� ��ư�� �����Ѵ�
	m_btnText.SetDefaultColor(m_clrTextDefault);
	m_btnText.SetColor(m_clrText);
	m_btnText.SetFlat(FALSE);

	// ��� ���� ��ư�� �����Ѵ�
	m_btnBkgnd.SetDefaultColor(m_clrBkgndDefault);
	m_btnBkgnd.SetColor(m_clrBkgnd);
	m_btnBkgnd.SetFlat(FALSE);
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CColorPickButtonDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CColorPickButtonDemoDlg::OnPaint() 
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
HCURSOR CColorPickButtonDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HBRUSH CColorPickButtonDemoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	// �׽�Ʈ�� ����ƽ ��Ʈ���� ���� ����� ����� �����Ѵ�
	if(CTLCOLOR_STATIC == nCtlColor)
	{
		if(pWnd->m_hWnd == GetDlgItem(IDC_TEXT_STATIC)->m_hWnd)
		{
			pDC->SetBkMode(TRANSPARENT);
			pDC->SetTextColor(m_clrText);
			return HBRUSH(m_BkgndBrush);
		}
	}

	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	return hbr;
}

// ���� ���� �Ϸ� �޽��� �ڵ鷯
LRESULT CColorPickButtonDemoDlg::OnSelEndOKColor(WPARAM wParam, LPARAM lParam) 
{
	switch(wParam)
	{
	case IDC_TEXT_DEFAULT_COLOR_BUTTON:
		// �⺻ ���� ���� �����
		// ���� ���� ��ư�� �⺻ ������ �����Ѵ�
		m_btnText.SetDefaultColor(m_btnTextDefault.GetColor());
		break;
	case IDC_TEXT_COLOR_BUTTON:
		// ���� ���� �����
		// ���� ������ �����ϰ� �׽�Ʈ ����ƽ ��Ʈ���� �ٽ� �׸���
		m_clrText = m_btnText.GetColor();
		GetDlgItem(IDC_TEXT_STATIC)->Invalidate();
		break;
	case IDC_BKGND_DEFAULT_COLOR_BUTTON:
		// �⺻ ��� ���� �����
		// ��� ���� ��ư�� �⺻ ������ �����Ѵ�
		m_btnBkgnd.SetDefaultColor(m_btnBkgndDefault.GetColor());
		break;
	case IDC_BKGND_COLOR_BUTTON:
		// ��� ���� �����
		// ��� ������ �����ϰ� �귯���� ���� ������ �� �׽�Ʈ ����ƽ ��Ʈ���� �ٽ� �׸���
		m_clrBkgnd = m_btnBkgnd.GetColor();
		m_BkgndBrush.DeleteObject();
		m_BkgndBrush.CreateSolidBrush(m_clrBkgnd);
		GetDlgItem(IDC_TEXT_STATIC)->Invalidate();
		break;
	}
	return 1;
}
