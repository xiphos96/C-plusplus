// ExplorerPopupDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ExplorerPopupDemo.h"
#include "ExplorerPopupDemoDlg.h"

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


// CExplorerPopupDemoDlg 대화 상자



CExplorerPopupDemoDlg::CExplorerPopupDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExplorerPopupDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExplorerPopupDemoDlg)
	m_strAddress = _T("");
	m_bMenu = FALSE;
	m_bToolBar = FALSE;
	m_bAddressBar = FALSE;
	m_bStatusBar = FALSE;
	m_bResize = FALSE;
	m_nPosX = 0;
	m_nPosY = 0;
	m_nCX = 0;
	m_nCY = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExplorerPopupDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExplorerPopupDemoDlg)
	DDX_Text(pDX, IDC_ADDRESS_EDIT, m_strAddress);
	DDX_Control(pDX, IDC_EXPLORER, m_wndBrowser);
	DDX_Check(pDX, IDC_MENU_CHECK, m_bMenu);
	DDX_Check(pDX, IDC_TOOLBAR_CHECK, m_bToolBar);
	DDX_Check(pDX, IDC_ADDRESSBAR_CHECK, m_bAddressBar);
	DDX_Check(pDX, IDC_STATUSBAR_CHECK, m_bStatusBar);
	DDX_Check(pDX, IDC_RESIZE_CHECK, m_bResize);
	DDX_Text(pDX, IDC_CX_EDIT, m_nCX);
	DDX_Text(pDX, IDC_CY_EDIT, m_nCY);
	DDX_Text(pDX, IDC_POS_X_EDIT, m_nPosX);
	DDX_Text(pDX, IDC_POS_Y_EDIT, m_nPosY);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExplorerPopupDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CExplorerPopupDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHELLEXECUTE_BUTTON, OnShellexecuteButton)
	ON_BN_CLICKED(IDC_NEW_BUTTON, OnNewButton)
	ON_BN_CLICKED(IDC_NEW_USING_WEBBROWSER_BUTTON, OnNewUsingWebbrowserButton)
	ON_BN_CLICKED(IDC_NEW_EX_BUTTON, OnNewExButton)
	ON_BN_CLICKED(IDC_CLOSE_BUTTON, OnCloseButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CExplorerPopupDemoDlg 메시지 처리기

BOOL CExplorerPopupDemoDlg::OnInitDialog()
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

	// 초기 주소를 영진닷컴으로 설정한다
	m_strAddress = "http://www.youngjin.com";
	// 다이얼로그 안의 웹브라우저에서 영진닷컴을 열도록 한다
	m_wndBrowser.Navigate(m_strAddress, NULL, NULL, NULL, NULL);

	// 멤버 변수들의 초기값을 설정한다
	m_bMenu			= FALSE;
	m_bToolBar		= FALSE;
	m_bAddressBar	= FALSE;
	m_bStatusBar	= FALSE;
	m_bResize		= FALSE;
	m_nPosX			= 100;
	m_nPosY			= 100;
	m_nCX			= 400;
	m_nCY			= 300;

	UpdateData(FALSE);
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CExplorerPopupDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExplorerPopupDemoDlg::OnPaint() 
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
HCURSOR CExplorerPopupDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExplorerPopupDemoDlg::OnShellexecuteButton() 
{
	UpdateData(TRUE);

	// ShellExecute()로 웹브라우저를 만들어서 입력된 주소를 연다
	m_ExplorerPopup.OpenByShellExecute(m_strAddress);
}

void CExplorerPopupDemoDlg::OnNewButton() 
{
	UpdateData(TRUE);

	// 익스플로러 객체를 생성하여 입력된 주소를 연다
	m_ExplorerPopup.OpenNewWindow(m_strAddress);
}

void CExplorerPopupDemoDlg::OnNewUsingWebbrowserButton() 
{
	UpdateData(TRUE);

	// 다이얼로그에 생성되어 있는 웹브라우저를 사용하여 새 웹브라우저를 생성하고
	// 입력된 주소를 연다
	m_ExplorerPopup.OpenNewWindow(m_strAddress, &m_wndBrowser);
}

void CExplorerPopupDemoDlg::OnNewExButton() 
{
	UpdateData(TRUE);

	// 익스플로러 객체를 생성하고
	// 옵션들을 설정한 후 입력된 주소를 연다
	m_ExplorerPopup.OpenNewWindowEx(m_strAddress, m_bMenu, m_bToolBar, m_bAddressBar,
		m_bStatusBar, m_bResize, m_nPosX, m_nPosY, m_nCX, m_nCY);

	// 열기 버튼을 비활성화 시킨다
	GetDlgItem(IDC_NEW_EX_BUTTON)->EnableWindow(FALSE);
	// 닫기 버튼을 활성화 시킨다
	GetDlgItem(IDC_CLOSE_BUTTON)->EnableWindow(TRUE);
}

void CExplorerPopupDemoDlg::OnCloseButton() 
{
	UpdateData(TRUE);

	// 생성된 웹브라우저를 닫는다
	m_ExplorerPopup.CloseExplorer();

	// 열기 버튼을 활성화 시킨다
	GetDlgItem(IDC_NEW_EX_BUTTON)->EnableWindow(TRUE);
	// 닫기 버튼을 비활성화 시킨다
	GetDlgItem(IDC_CLOSE_BUTTON)->EnableWindow(FALSE);
}
