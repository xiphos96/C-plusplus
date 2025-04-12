// CustomSliderCtrlDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CustomSliderCtrlDemo.h"
#include "CustomSliderCtrlDemoDlg.h"

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


// CCustomSliderCtrlDemoDlg ��ȭ ����



CCustomSliderCtrlDemoDlg::CCustomSliderCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCustomSliderCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCustomSliderCtrlDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCustomSliderCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustomSliderCtrlDemoDlg)
	DDX_Control(pDX, IDC_CUSTOM_VERT_SLIDER, m_CustomVertSlider);
	DDX_Control(pDX, IDC_CUSTOM_HORZ_SLIDER, m_CustomHorzSlider);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCustomSliderCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CCustomSliderCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RESTART_BUTTON, OnRestartButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CCustomSliderCtrlDemoDlg �޽��� ó����

BOOL CCustomSliderCtrlDemoDlg::OnInitDialog()
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

	// ���� �����̴��� �Ӽ��� �����Ѵ�
	m_CustomHorzSlider.SetRange(0, 100);					// ���� ���� ����
	m_CustomHorzSlider.SetPos(0);							// �ʱ� ��ġ ����
	m_CustomHorzSlider.SetTicFreq(10);						// ������ ���� ����
	m_CustomHorzSlider.SetSelection(0, 0);					// ���� ����
	m_CustomHorzSlider.SetThumbColor(RGB(178, 197, 255));	// �ڵ� ���� ����
	m_CustomHorzSlider.SetSelectionColor(RGB(0, 44, 178));	// ���õ� ���� ���� ����
	m_CustomHorzSlider.SetChannelColor(RGB(255, 86, 86));	// ���õ��� ���� ���� ���� ����
	
	// ���� �����̴��� �Ӽ��� �����Ѵ�
	m_CustomVertSlider.SetRange(0, 100);					// ���� ���� ����
	m_CustomVertSlider.SetPos(0);							// �ʱ� ��ġ ����
	m_CustomVertSlider.SetTicFreq(10);						// ������ ���� ����
	m_CustomVertSlider.SetSelection(0, 0);					// ���� ����
	m_CustomVertSlider.SetThumbColor(RGB(178, 197, 255));	// �ڵ� ���� ����
	m_CustomVertSlider.SetSelectionColor(RGB(0, 44, 178));	// ���õ� ���� ���� ����
	m_CustomVertSlider.SetChannelColor(RGB(255, 86, 86));	// ���õ��� ���� ���� ���� ����
	
	m_nThumbStep		= 1;								// �ڵ��� �̵� ���� ����
	m_nSelectionStep	= 2;								// ������ �̵� ���� ����

	// Ÿ�̸Ӹ� ����Ͽ� �ڵ�� ������ �̵� ���Ѻ���
	SetTimer(1, 50, NULL);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CCustomSliderCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCustomSliderCtrlDemoDlg::OnPaint() 
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
HCURSOR CCustomSliderCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCustomSliderCtrlDemoDlg::OnTimer(UINT nIDEvent) 
{
	int nPos, nMin, nMax;

	// ���� ���� �����̴��� ��ġ�� ������Ų��
	nPos = m_CustomHorzSlider.GetPos();
	nPos += m_nThumbStep;
	m_CustomHorzSlider.SetPos(nPos);
	// ���� �ִ� ������ �̵��Ǿ��ٸ� Ÿ�̸Ӹ� �����Ѵ�
	nMax = m_CustomHorzSlider.GetRangeMax();
	if(nPos >= nMax)		KillTimer(nIDEvent);

	// ���� ���� �����̴��� ��ġ�� ������Ų��
	nPos = m_CustomVertSlider.GetPos();
	nPos += m_nThumbStep;
	m_CustomVertSlider.SetPos(nPos);

	// ���� ���� �����̴��� ������ ������Ų��
	m_CustomHorzSlider.GetSelection(nMin, nMax);
	nMax += m_nSelectionStep;
	m_CustomHorzSlider.SetSelection(nMin, nMax);

	// ���� ���� �����̴��� ������ ������Ų��
	m_CustomVertSlider.GetSelection(nMin, nMax);
	nMax += m_nSelectionStep;
	m_CustomVertSlider.SetSelection(nMin, nMax);
	
	CDialog::OnTimer(nIDEvent);
}

void CCustomSliderCtrlDemoDlg::OnRestartButton() 
{
	// ���� �����̴��� �ʱ�ȭ�Ѵ�
	m_CustomHorzSlider.SetPos(0);
	m_CustomHorzSlider.SetSelection(0, 0);
	
	// ���� �����̴��� �ʱ�ȭ�Ѵ�
	m_CustomVertSlider.SetPos(0);
	m_CustomVertSlider.SetSelection(0, 0);
	
	// Ÿ�̸Ӹ� �����Ѵ�
	SetTimer(1, 50, NULL);
}
