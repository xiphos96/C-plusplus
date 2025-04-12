// SlideEditDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "SlideEditDemo.h"
#include "SlideEditDemoDlg.h"

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


// CSlideEditDemoDlg ��ȭ ����



CSlideEditDemoDlg::CSlideEditDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSlideEditDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSlideEditDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSlideEditDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSlideEditDemoDlg)
	DDX_Control(pDX, IDC_COLOR_STATIC, m_ColorStatic);
	DDX_Control(pDX, IDC_SLIDE_EDIT_R, m_SlideEditR);
	DDX_Control(pDX, IDC_SLIDE_EDIT_G, m_SlideEditG);
	DDX_Control(pDX, IDC_SLIDE_EDIT_B, m_SlideEditB);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSlideEditDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CSlideEditDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_SLIDE_POS_CHANGE, OnSlidePosChange)
	ON_MESSAGE(WM_SLIDE_END_SELECT, OnSlideEndSelect)
END_MESSAGE_MAP()


// CSlideEditDemoDlg �޽��� ó����

BOOL CSlideEditDemoDlg::OnInitDialog()
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

	// �����̵� ����Ʈ ��Ʈ�ѿ� ������ �����Ѵ�
	m_SlideEditR.SetRange(255, 0);
	m_SlideEditG.SetRange(255, 0);
	m_SlideEditB.SetRange(255, 0);

	// �����̵� ����Ʈ ��Ʈ���� �ʱⰪ�� �����Ѵ�
	m_SlideEditR.SetValue(255);
	m_SlideEditG.SetValue(255);
	m_SlideEditB.SetValue(255);

	// �÷� ����ƽ�� �ʱ� ������ �����Ѵ�
	m_ColorStatic.m_clrColor = RGB(255, 255, 255);
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CSlideEditDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSlideEditDemoDlg::OnPaint() 
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
HCURSOR CSlideEditDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// �����̵� ����Ʈ ��Ʈ�ѿ��� �����̵��� �̵��� ���� �ڵ鷯
LRESULT CSlideEditDemoDlg::OnSlidePosChange(WPARAM wParam, LPARAM lParam)
{
	// �÷� ����ƽ ��Ʈ���� ������ �����Ѵ�
	m_ColorStatic.m_clrColor = RGB(m_SlideEditR.GetValue(), m_SlideEditG.GetValue(), m_SlideEditB.GetValue());
	m_ColorStatic.Invalidate();

	return 1;
}

// �����̵� ����Ʈ ��Ʈ�ѿ��� �� ������ ���� �ڵ鷯
LRESULT CSlideEditDemoDlg::OnSlideEndSelect(WPARAM wParam, LPARAM lParam)
{
	// �÷� ����ƽ ��Ʈ���� ������ �����Ѵ�
	m_ColorStatic.m_clrColor = RGB(m_SlideEditR.GetValue(), m_SlideEditG.GetValue(), m_SlideEditB.GetValue());
	m_ColorStatic.Invalidate();

	return 1;
}
