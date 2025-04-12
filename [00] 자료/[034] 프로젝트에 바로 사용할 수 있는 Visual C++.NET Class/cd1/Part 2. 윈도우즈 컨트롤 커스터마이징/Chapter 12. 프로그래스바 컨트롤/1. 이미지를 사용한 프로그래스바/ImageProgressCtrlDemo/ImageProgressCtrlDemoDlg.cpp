// ImageProgressCtrlDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ImageProgressCtrlDemo.h"
#include "ImageProgressCtrlDemoDlg.h"

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


// CImageProgressCtrlDemoDlg 대화 상자



CImageProgressCtrlDemoDlg::CImageProgressCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImageProgressCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImageProgressCtrlDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImageProgressCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImageProgressCtrlDemoDlg)
	DDX_Control(pDX, IDC_HORZ_PROGRESS, m_HorzProgressCtrl);
	DDX_Control(pDX, IDC_VERT_PROGRESS, m_VertProgressCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CImageProgressCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CImageProgressCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RESTART_BUTTON, OnRestartButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CImageProgressCtrlDemoDlg 메시지 처리기

BOOL CImageProgressCtrlDemoDlg::OnInitDialog()
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

	// 이미지 프로그레스바의 포멧 문자열 구성
	CString strFormat;
	strFormat.Format("[%%d / %d] 완료", 200);

	// 수평 이미지 프로그레스바의 속성을 설정한다
	m_HorzProgressCtrl.SetRange(0, 200);
	m_HorzProgressCtrl.SetPos(0);
	m_HorzProgressCtrl.SetStep(2);
	// 문자열 포멧을 사용하여 진행 상태 표시
	m_HorzProgressCtrl.SetTextType(TEXT_FORMAT);
	// 문자열 포멧 설정
	m_HorzProgressCtrl.SetTextFormat(strFormat);
	// 배경 테두리의 비트맵 설정
	m_HorzProgressCtrl.SetBorderBitmap(BMP_LEFT, IDB_BORDER_LEFT);
	m_HorzProgressCtrl.SetBorderBitmap(BMP_CENTER, IDB_BORDER_CENTER);
	m_HorzProgressCtrl.SetBorderBitmap(BMP_RIGHT, IDB_BORDER_RIGHT);
	// 진행바의 비트맵 설정
	m_HorzProgressCtrl.SetPosBitmap(BMP_LEFT, IDB_POS_LEFT);
	m_HorzProgressCtrl.SetPosBitmap(BMP_CENTER, IDB_POS_CENTER);
	m_HorzProgressCtrl.SetPosBitmap(BMP_RIGHT, IDB_POS_RIGHT);

	// 수직 이미지 프로그레스바의 속성을 설정한다
	m_VertProgressCtrl.SetRange(0, 100);
	m_VertProgressCtrl.SetPos(0);
	m_VertProgressCtrl.SetStep(1);
	// 퍼센트로 진행 상태 표시
	m_VertProgressCtrl.SetTextType(TEXT_PERCENT);

	// 테스트를 위해 타이머를 시작한다
	SetTimer(1, 50, NULL);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CImageProgressCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CImageProgressCtrlDemoDlg::OnPaint() 
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
HCURSOR CImageProgressCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CImageProgressCtrlDemoDlg::OnTimer(UINT nIDEvent) 
{
	int nMin, nMax;

	// 수평/수직 프로그레스바의 위치를 증가시킨다
	m_HorzProgressCtrl.StepIt();
	m_HorzProgressCtrl.Invalidate(FALSE);
	m_VertProgressCtrl.StepIt();
	m_VertProgressCtrl.Invalidate(FALSE);

	// 만약 수평 프로그레스바의 현재 위치가 최대값이라면 타이머를 종료한다
	m_HorzProgressCtrl.GetRange(nMin, nMax);
	if(m_HorzProgressCtrl.GetPos() >= nMax)		KillTimer(nIDEvent);
	
	CDialog::OnTimer(nIDEvent);
}

void CImageProgressCtrlDemoDlg::OnRestartButton() 
{
	// 수평/수직 프로그레스바의 위치를 0으로 초기화한다
	m_HorzProgressCtrl.SetPos(0);
	m_VertProgressCtrl.SetPos(0);

	// 타이머를 실행한다
	SetTimer(1, 50, NULL);
}
