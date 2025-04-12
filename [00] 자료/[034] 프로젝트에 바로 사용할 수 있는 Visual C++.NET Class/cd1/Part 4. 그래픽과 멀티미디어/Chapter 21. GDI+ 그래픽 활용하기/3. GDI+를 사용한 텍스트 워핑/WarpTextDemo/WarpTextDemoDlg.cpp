// WarpTextDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "WarpTextDemo.h"
#include "WarpTextDemoDlg.h"

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


// CWarpTextDemoDlg ��ȭ ����



CWarpTextDemoDlg::CWarpTextDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWarpTextDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWarpTextDemoDlg)
	m_strText = _T("���� �׽�Ʈ");
	m_bShowGuide = TRUE;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWarpTextDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWarpTextDemoDlg)
	DDX_Control(pDX, IDC_WARP_STATIC, m_WarpText);
	DDX_Text(pDX, IDC_TEXT_EDIT, m_strText);
	DDX_Check(pDX, IDC_SHOW_GUIDE_CHECK, m_bShowGuide);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWarpTextDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CWarpTextDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_REFRESH_BUTTON, OnRefreshButton)
	ON_BN_CLICKED(IDC_SHOW_GUIDE_CHECK, OnShowGuideCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CWarpTextDemoDlg �޽��� ó����

BOOL CWarpTextDemoDlg::OnInitDialog()
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

	// ������ �ؽ�Ʈ�� ��Ʈ�� �����Ѵ�
	m_WarpText.SetText(m_strText, "����ü");
	// ��Ʈ�� ä�� ������ �����Ѵ�
	m_WarpText.SetFontColor(RGB(179, 200, 200));
	// ��Ʈ�� �ܰ� ������ �����Ѵ�
	m_WarpText.SetOutlineColor(RGB(0, 0, 0));

	// ���� �ؽ�Ʈ ����ƽ ��Ʈ���� ũ�⸦ ��´�
	CRect rcStatic;
	GetDlgItem(IDC_WARP_STATIC)->GetClientRect(&rcStatic);

	// ������ ��ǥ�� �ۼ��Ѵ�
	CPoint ptWarp[4];
	// ��� ���� ��ǥ
	ptWarp[0].x = 0;
	ptWarp[0].y = 0;
	// ��� ���� ��ǥ
	ptWarp[1].x = rcStatic.right;
	ptWarp[1].y = 60;

	// �ϴ� ���� ��ǥ
	ptWarp[2].x = 120;
	ptWarp[2].y = rcStatic.bottom;
	// �ϴ� ���� ��ǥ
	ptWarp[3].x = rcStatic.right - 100;
	ptWarp[3].y = rcStatic.bottom - 80;

	// ������ ��ǥ�� �����Ѵ�
	m_WarpText.SetWarpPoint(ptWarp);
	// ���̵� ���� ����� ������ �����Ѵ�
	m_WarpText.ShowGuideLine(m_bShowGuide);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CWarpTextDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWarpTextDemoDlg::OnPaint() 
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
HCURSOR CWarpTextDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CWarpTextDemoDlg::OnRefreshButton() 
{
	UpdateData(TRUE);

	// ������ �ؽ�Ʈ�� ��Ʈ�� �����Ѵ�
	m_WarpText.SetText(m_strText, "����ü");
	// ȭ���� �ٽ� �׸���
	m_WarpText.Invalidate(FALSE);
}

void CWarpTextDemoDlg::OnShowGuideCheck() 
{
	UpdateData(TRUE);

	// ���̵� ���� ����� ������ �����Ѵ�
	m_WarpText.ShowGuideLine(m_bShowGuide);
	// ȭ���� �ٽ� �׸���
	m_WarpText.Invalidate(FALSE);
}
