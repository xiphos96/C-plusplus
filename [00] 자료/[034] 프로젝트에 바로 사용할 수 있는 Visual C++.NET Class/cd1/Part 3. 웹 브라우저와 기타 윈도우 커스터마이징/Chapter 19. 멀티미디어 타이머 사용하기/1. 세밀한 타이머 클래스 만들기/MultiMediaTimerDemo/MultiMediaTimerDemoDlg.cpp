// MultiMediaTimerDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MultiMediaTimerDemo.h"
#include "MultiMediaTimerDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원
	//}}AFX_VIRTUAL

// 구현
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


// CMultiMediaTimerDemoDlg 대화 상자



CMultiMediaTimerDemoDlg::CMultiMediaTimerDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiMediaTimerDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiMediaTimerDemoDlg)
	m_nCount = -1;
	m_nInterval = 1000;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiMediaTimerDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiMediaTimerDemoDlg)
	DDX_Control(pDX, IDC_ON_TIMER_LIST, m_OnTimerList);
	DDX_Text(pDX, IDC_COUNT_EDIT, m_nCount);
	DDX_Text(pDX, IDC_INTERVAL_EDIT, m_nInterval);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMultiMediaTimerDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CMultiMediaTimerDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START_BUTTON, OnStartButton)
	ON_BN_CLICKED(IDC_STOP_BUTTON, OnStopButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CMultiMediaTimerDemoDlg 메시지 처리기

BOOL CMultiMediaTimerDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	// 프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CMultiMediaTimerDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면 
// 아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
// 프레임워크에서 이 작업을 자동으로 수행합니다.

void CMultiMediaTimerDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다. 
HCURSOR CMultiMediaTimerDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMultiMediaTimerDemoDlg::OnMMTimer(UINT uID)
{
	CString strTick;

	strTick.Format("현재 Tick : %d - 반복 횟수 : %d",
		::GetTickCount(), m_Timer.GetCount());

	if(m_Timer.GetCount() == 1)
	{
		GetDlgItem(IDC_START_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_STOP_BUTTON)->EnableWindow(FALSE);
	}

	m_OnTimerList.SetTopIndex(m_OnTimerList.AddString(strTick));
}

void CMultiMediaTimerDemoDlg::OnStartButton() 
{
	UpdateData(TRUE);

	if(m_Timer.IsRunning())		return;

	m_OnTimerList.ResetContent();

	m_Timer.SetTimerOwner(this);
	if(!m_Timer.SetInterval(m_nInterval))
	{
		MessageBox("타이머 간격이 시스템 능력을 벗어납니다.");
		return;
	}
	m_Timer.SetCount(m_nCount);

	GetDlgItem(IDC_START_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_STOP_BUTTON)->EnableWindow(TRUE);

	if(!m_Timer.StartTimer())
	{
		MessageBox("타이머를 실행할 수 없습니다.");
	}
}

void CMultiMediaTimerDemoDlg::OnStopButton() 
{
	if(!m_Timer.IsRunning())	return;

	GetDlgItem(IDC_START_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_STOP_BUTTON)->EnableWindow(FALSE);

	if(!m_Timer.StopTimer())
	{
		MessageBox("타이머를 멈출 수 없습니다.");
	}
}
