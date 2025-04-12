// CoolButtonDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "CoolButtonDemo.h"
#include "CoolButtonDemoDlg.h"

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


// CCoolButtonDemoDlg 대화 상자



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


// CCoolButtonDemoDlg 메시지 처리기

BOOL CCoolButtonDemoDlg::OnInitDialog()
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

	// 비트맵을 입힌 버튼
	m_btnBmp.SetButtonBmp(IDB_BUTTON1);								// 비트맵을 설정한다
	m_btnBmp.SetFlat(TRUE);											// 평면 버튼을 설정한다
	m_btnBmp.SetButtonColor(COLOR_TEXT, RGB(50, 50, 50));			// 글자색을 설정한다
	m_btnBmp.SetButtonColor(COLOR_BKGND, RGB(192, 192, 192));		// 배경색을 설정한다
	m_btnBmp.SetButtonColor(COLOR_TEXT_IN, RGB(66, 168, 255));		// 마우스가 진입 했을 때의 글자색을 설정한다
	m_btnBmp.SetButtonColor(COLOR_BKGND_IN, RGB(220, 220, 220));	// 마우스가 진입 했을 때의 배경색을 설정한다

	// 아이콘을 입힌 버튼
	m_btnIcon.SetButtonIcon(IDI_BUTTON);							// 아이콘을 설정한다
	m_btnIcon.SetFlat(FALSE);										// 입체 버튼을 설정한다
	m_btnIcon.SetButtonColor(COLOR_TEXT, RGB(50, 50, 50));			// 글자색을 설정한다 
	m_btnIcon.SetButtonColor(COLOR_BKGND, RGB(192, 192, 192));		// 배경색을 설정한다
	m_btnIcon.SetButtonColor(COLOR_TEXT_IN, RGB(66, 168, 255));		// 마우스가 진입 했을 때의 글자색을 설정한다
	m_btnIcon.SetButtonColor(COLOR_BKGND_IN, RGB(220, 220, 220));	// 마우스가 진입 했을 때의 배경색을 설정한다

	// 비트맵을 입히고 특정 색을 투명 처리한 버튼
	m_btnTransparent.SetButtonBmp(IDB_BUTTON1, RGB(197, 197, 197));	// 비트맵을 설정하고 투명색을 설정한다
	m_btnTransparent.SetFlat(TRUE);									// 평면 버튼을 설정한다
	m_btnTransparent.SetButtonColor(COLOR_TEXT, RGB(50, 50, 50));	// 글자색을 설정한다
	m_btnTransparent.SetButtonColor(COLOR_BKGND, RGB(255, 255, 255));		// 배경색을 설정한다
	m_btnTransparent.SetButtonColor(COLOR_TEXT_IN, RGB(66, 168, 255));		// 마우스가 진입 했을 때의 글자색을 설정한다
	m_btnTransparent.SetButtonColor(COLOR_BKGND_IN, RGB(220, 220, 220));	// 마우스가 진입 했을 때의 배경색을 설정한다

	// 위치 지정 버튼
	m_btnPosition.SetButtonBmp(IDB_BUTTON2, RGB(255, 255, 255));	// 비트맵을 설정하고 투명색을 설정한다
	m_btnPosition.SetFlat(FALSE);									// 입체 버튼을 설정한다
	m_btnPosition.SetTextAlign(ALIGN_LEFT);							// 텍스트 정렬을 왼쪽으로 한다
	m_btnPosition.SetButtonColor(COLOR_TEXT, RGB(50, 50, 50));		// 글자색을 설정한다
	m_btnPosition.SetButtonColor(COLOR_BKGND, RGB(255, 255, 255));	// 배경색을 설정한다
	m_btnPosition.SetButtonColor(COLOR_TEXT_IN, RGB(66, 168, 255));	// 마우스가 진입 했을 때의 글자색을 설정한다
	m_btnPosition.SetButtonColor(COLOR_BKGND_IN, RGB(220, 220, 220));	// 마우스가 진입 했을 때의 배경색을 설정한다
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면 
// 아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
// 프레임워크에서 이 작업을 자동으로 수행합니다.

void CCoolButtonDemoDlg::OnPaint() 
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
HCURSOR CCoolButtonDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCoolButtonDemoDlg::OnLeftRadio() 
{
	// 텍스트 정렬을 왼쪽으로 한다
	m_btnPosition.SetTextAlign(ALIGN_LEFT);
}

void CCoolButtonDemoDlg::OnRightRadio() 
{
	// 텍스트 정렬을 오른쪽으로 한다
	m_btnPosition.SetTextAlign(ALIGN_RIGHT);
}

void CCoolButtonDemoDlg::OnTopRadio() 
{
	// 텍스트 정렬을 위쪽으로 한다
	m_btnPosition.SetTextAlign(ALIGN_TOP);
}

void CCoolButtonDemoDlg::OnBottomRadio() 
{
	// 텍스트 정렬을 아래쪽으로 한다
	m_btnPosition.SetTextAlign(ALIGN_BOTTOM);
}

void CCoolButtonDemoDlg::OnOverRadio() 
{
	// 텍스트를 이미지 위에 위치시킨다
	m_btnPosition.SetTextAlign(ALIGN_OVER);
}

void CCoolButtonDemoDlg::OnEnableCheck() 
{
	// 버튼을 활성화 시키거나 비활성화 시킨다
	UpdateData(TRUE);

	m_btnPosition.EnableWindow(m_bEnable);
}
