// ExplorerPrintDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ExplorerPrintDemo.h"
#include "ExplorerPrintDemoDlg.h"

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


// CExplorerPrintDemoDlg 대화 상자



CExplorerPrintDemoDlg::CExplorerPrintDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExplorerPrintDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExplorerPrintDemoDlg)
	m_strAddress = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExplorerPrintDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExplorerPrintDemoDlg)
	DDX_Text(pDX, IDC_ADDRESS_EDIT, m_strAddress);
	DDX_Control(pDX, IDC_EXPLORER_PRINT, m_wndBrowser);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExplorerPrintDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CExplorerPrintDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GO_BUTTON, OnGoButton)
	ON_BN_CLICKED(IDC_STOP_BUTTON, OnStopButton)
	ON_BN_CLICKED(IDC_REFRESH_BUTTON, OnRefreshButton)
	ON_BN_CLICKED(IDC_SAVE_AS_BUTTON, OnSaveAsButton)
	ON_BN_CLICKED(IDC_PRINT_BUTTON, OnPrintButton)
	ON_BN_CLICKED(IDC_PRINT_PREVIEW_BUTTON, OnPrintPreviewButton)
	ON_BN_CLICKED(IDC_PAGE_SETUP_BUTTON, OnPageSetupButton)
	ON_BN_CLICKED(IDC_PROPERTY_BUTTON, OnPropertyButton)
	ON_BN_CLICKED(IDC_FAVORITE_BUTTON, OnFavoriteButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CExplorerPrintDemoDlg 메시지 처리기

BOOL CExplorerPrintDemoDlg::OnInitDialog()
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

	// 초기 웹브라우저가 영진닷컴 홈페이지를 열도록 설정한다
	m_strAddress = "http://www.youngjin.com";
	m_wndBrowser.Navigate(m_strAddress, NULL, NULL, NULL, NULL);

	UpdateData(FALSE);
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CExplorerPrintDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExplorerPrintDemoDlg::OnPaint() 
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
HCURSOR CExplorerPrintDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExplorerPrintDemoDlg::OnGoButton() 
{
	UpdateData(TRUE);

	// 주소창에 입력된 주소의 사이트를 연다
	m_wndBrowser.Navigate(m_strAddress, NULL, NULL, NULL, NULL);
}

void CExplorerPrintDemoDlg::OnStopButton() 
{
	// 현재 웹브라우저의 이동을 중지한다
	m_wndBrowser.Stop();
}

void CExplorerPrintDemoDlg::OnRefreshButton() 
{
	// 현재 웹브라우저가 출력하는 페이지를 다시 로드하여 출력한다
	m_wndBrowser.Refresh();
}

void CExplorerPrintDemoDlg::OnSaveAsButton() 
{
	// 현재 웹브라우저가 출력하는 페이지를 로컬 디스크에 저장한다
	m_wndBrowser.SaveAs();
}

void CExplorerPrintDemoDlg::OnPrintButton() 
{
	// 현재 웹브라우저가 출력하는 페이지를 인쇄한다
	m_wndBrowser.Print();
}

void CExplorerPrintDemoDlg::OnPrintPreviewButton() 
{
	// 현재 웹브라우저가 출력하는 페이지의 인쇄 모습을 미리 보여준다
	m_wndBrowser.PrintPreview();
}

void CExplorerPrintDemoDlg::OnPageSetupButton() 
{
	// 현재 웹브라우저의 페이지 설정 다이얼로그를 출력한다
	m_wndBrowser.PageSetup();
}

void CExplorerPrintDemoDlg::OnPropertyButton() 
{
	// 현재 웹브라우저가 출력하는 페이지의 속성 페이지를 출력한다
	m_wndBrowser.Property();
}

void CExplorerPrintDemoDlg::OnFavoriteButton() 
{
	// 현재 웹브라우저가 출력하는 페이지를 즐겨찾기에 추가한다
	m_wndBrowser.AddToFavorites();
}
