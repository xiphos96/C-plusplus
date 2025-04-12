// ExplorerUIDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ExplorerUIDemo.h"
#include "ExplorerUIDemoDlg.h"

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


// CExplorerUIDemoDlg 대화 상자



CExplorerUIDemoDlg::CExplorerUIDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExplorerUIDemoDlg::IDD, pParent)
{
	// 멤버 변수들을 초기화한다
	//{{AFX_DATA_INIT(CExplorerUIDemoDlg)
	m_strAddress = _T("");
	m_bContextMenu = FALSE;
	m_bNo3DBorder = FALSE;
	m_bNoScrollBar = FALSE;
	m_bFlatScrollBar = FALSE;
	m_strAddress2 = _T("");
	m_bContextMenu2 = FALSE;
	m_bNo3DBorder2 = FALSE;
	m_bNoScrollBar2 = FALSE;
	m_bFlatScrollBar2 = FALSE;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExplorerUIDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExplorerUIDemoDlg)
	DDX_Control(pDX, IDC_EXPLORER_UI, m_wndExplorerUI);
	DDX_Text(pDX, IDC_ADDRESS_EDIT, m_strAddress);
	DDX_Check(pDX, IDC_CONTEXT_MENU_CHECK, m_bContextMenu);
	DDX_Check(pDX, IDC_NO_3D_BORDER_CHECK, m_bNo3DBorder);
	DDX_Check(pDX, IDC_NO_SCROLL_CHECK, m_bNoScrollBar);
	DDX_Check(pDX, IDC_FLAT_SCROLL_CHECK, m_bFlatScrollBar);
	DDX_Control(pDX, IDC_EXPLORER_UI2, m_wndExplorerUI2);
	DDX_Text(pDX, IDC_ADDRESS_EDIT2, m_strAddress2);
	DDX_Check(pDX, IDC_CONTEXT_MENU_CHECK2, m_bContextMenu2);
	DDX_Check(pDX, IDC_NO_3D_BORDER_CHECK2, m_bNo3DBorder2);
	DDX_Check(pDX, IDC_NO_SCROLL_CHECK2, m_bNoScrollBar2);
	DDX_Check(pDX, IDC_FLAT_SCROLL_CHECK2, m_bFlatScrollBar2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExplorerUIDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CExplorerUIDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GO_BUTTON, OnGoButton)
	ON_BN_CLICKED(IDC_CONTEXT_MENU_CHECK, OnContextMenuCheck)
	ON_BN_CLICKED(IDC_NO_3D_BORDER_CHECK, OnNo3dBorderCheck)
	ON_BN_CLICKED(IDC_NO_SCROLL_CHECK, OnNoScrollCheck)
	ON_BN_CLICKED(IDC_FLAT_SCROLL_CHECK, OnFlatScrollCheck)
	ON_BN_CLICKED(IDC_GO_BUTTON2, OnGoButton2)
	ON_BN_CLICKED(IDC_CONTEXT_MENU_CHECK2, OnContextMenuCheck2)
	ON_BN_CLICKED(IDC_NO_3D_BORDER_CHECK2, OnNo3dBorderCheck2)
	ON_BN_CLICKED(IDC_NO_SCROLL_CHECK2, OnNoScrollCheck2)
	ON_BN_CLICKED(IDC_FLAT_SCROLL_CHECK2, OnFlatScrollCheck2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CExplorerUIDemoDlg 메시지 처리기

BOOL CExplorerUIDemoDlg::OnInitDialog()
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

	// 첫번째 웹브라우저 컨트롤에 대한 옵션 멤버 변수 설정
	m_strAddress		= "http://www.youngjin.com";	// 초기 URL을 영진닷컴으로 설정
	m_bContextMenu		= TRUE;							// 초기에는 컨텍스트 메뉴가 나타나도록 설정
	m_bNo3DBorder		= TRUE;							// 초기에는 3D 테두리를 감추도록 설정
	m_bNoScrollBar		= FALSE;						// 초기에는 스크롤바를 출력하도록 설정
	m_bFlatScrollBar	= TRUE;							// 초기에는 평면 스크롤바를 사용하도록 설정

	// 첫번째 웹브라우저 컨트롤에 옵션을 설정한다
	m_wndExplorerUI.m_bContextMenu		= m_bContextMenu;
	m_wndExplorerUI.m_bNo3DBorder		= m_bNo3DBorder;
	m_wndExplorerUI.m_bNoScrollBar		= m_bNoScrollBar;
	m_wndExplorerUI.m_bFlatScrollBar	= m_bFlatScrollBar;

	// 첫번째 웹브라우저에서 영진닷컴 사이트를 연다
	m_wndExplorerUI.Navigate("http://www.youngjin.com", NULL, NULL, NULL, NULL);
	
	// 두번째 웹브라우저 컨트롤에 대한 옵션 멤버 변수 설정
	m_strAddress2		= "http://www.youngjin.com";	// 초기 URL을 영진닷컴으로 설정
	m_bContextMenu2		= TRUE;							// 초기에는 컨텍스트 메뉴가 나타나도록 설정
	m_bNo3DBorder2		= TRUE;							// 초기에는 3D 테두리를 감추도록 설정
	m_bNoScrollBar2		= FALSE;						// 초기에는 스크롤바를 출력하도록 설정
	m_bFlatScrollBar2	= TRUE;							// 초기에는 평면 스크롤바를 사용하도록 설정

	// 두번째 웹브라우저 컨트롤에 옵션을 설정한다
	m_wndExplorerUI2.m_bContextMenu		= m_bContextMenu2;
	m_wndExplorerUI2.m_bNo3DBorder		= m_bNo3DBorder2;
	m_wndExplorerUI2.m_bNoScrollBar		= m_bNoScrollBar2;
	m_wndExplorerUI2.m_bFlatScrollBar	= m_bFlatScrollBar2;

	// 두번째 웹브라우저의 모양을 변경하기 위해 모양을 갖는 비트맵을 설정한다
	m_wndExplorerUI2.SetShapeBitmap("skin.bmp", RGB(0, 0, 0));
	// 두번째 웹브라우저에서 영진닷컴 사이트를 연다
	m_wndExplorerUI2.Navigate("http://www.youngjin.com", NULL, NULL, NULL, NULL);
	
	// 다이얼로그의 컨트롤에 멤버 변수들의 값을 대입한다
	UpdateData(FALSE);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CExplorerUIDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExplorerUIDemoDlg::OnPaint() 
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
HCURSOR CExplorerUIDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExplorerUIDemoDlg::OnGoButton() 
{
	UpdateData(TRUE);

	// 새로운 주소를 첫번째 웹브라우저로 연다
	m_wndExplorerUI.Navigate(m_strAddress, NULL, NULL, NULL, NULL);
}

void CExplorerUIDemoDlg::OnContextMenuCheck() 
{
	UpdateData(TRUE);

	// 첫번째 웹브라우저에 대해 컨텍스트 메뉴 출력 여부를 설정한다
	m_wndExplorerUI.m_bContextMenu		= m_bContextMenu;
}

void CExplorerUIDemoDlg::OnNo3dBorderCheck() 
{
	UpdateData(TRUE);

	// 첫번째 웹브라우저에 대해 3D 테두리 출력 여부를 설정한다
	m_wndExplorerUI.m_bNo3DBorder		= m_bNo3DBorder;
	// 속성을 곧바로 반영하기 위해 문서를 다시 로드한다
	m_wndExplorerUI.Refresh();
}

void CExplorerUIDemoDlg::OnNoScrollCheck() 
{
	UpdateData(TRUE);

	// 첫번째 웹브라우저에 대해 스크롤바 출력 여부를 설정한다
	m_wndExplorerUI.m_bNoScrollBar		= m_bNoScrollBar;
	// 속성을 곧바로 반영하기 위해 문서를 다시 로드한다
	m_wndExplorerUI.Refresh();
}

void CExplorerUIDemoDlg::OnFlatScrollCheck() 
{
	UpdateData(TRUE);

	// 첫번째 웹브라우저에 대해 평면 스크롤바 사용 여부를 설정한다
	m_wndExplorerUI.m_bFlatScrollBar	= m_bFlatScrollBar;
	// 속성을 곧바로 반영하기 위해 문서를 다시 로드한다
	m_wndExplorerUI.Refresh();
}

void CExplorerUIDemoDlg::OnGoButton2() 
{
	UpdateData(TRUE);

	// 새로운 주소를 두번째 웹브라우저로 연다
	m_wndExplorerUI2.Navigate(m_strAddress2, NULL, NULL, NULL, NULL);
}

void CExplorerUIDemoDlg::OnContextMenuCheck2() 
{
	UpdateData(TRUE);

	// 두번째 웹브라우저에 대해 컨텍스트 메뉴 출력 여부를 설정한다
	m_wndExplorerUI2.m_bContextMenu		= m_bContextMenu2;
}

void CExplorerUIDemoDlg::OnNo3dBorderCheck2() 
{
	UpdateData(TRUE);

	// 두번째 웹브라우저에 대해 3D 테두리 출력 여부를 설정한다
	m_wndExplorerUI2.m_bNo3DBorder		= m_bNo3DBorder2;
	// 속성을 곧바로 반영하기 위해 문서를 다시 로드한다
	m_wndExplorerUI2.Refresh();
}

void CExplorerUIDemoDlg::OnNoScrollCheck2() 
{
	UpdateData(TRUE);

	// 두번째 웹브라우저에 대해 스크롤바 출력 여부를 설정한다
	m_wndExplorerUI2.m_bNoScrollBar		= m_bNoScrollBar2;
	// 속성을 곧바로 반영하기 위해 문서를 다시 로드한다
	m_wndExplorerUI2.Refresh();
}

void CExplorerUIDemoDlg::OnFlatScrollCheck2() 
{
	UpdateData(TRUE);

	// 두번째 웹브라우저에 대해 평면 스크롤바 사용 여부를 설정한다
	m_wndExplorerUI2.m_bFlatScrollBar	= m_bFlatScrollBar2;
	// 속성을 곧바로 반영하기 위해 문서를 다시 로드한다
	m_wndExplorerUI2.Refresh();
}
