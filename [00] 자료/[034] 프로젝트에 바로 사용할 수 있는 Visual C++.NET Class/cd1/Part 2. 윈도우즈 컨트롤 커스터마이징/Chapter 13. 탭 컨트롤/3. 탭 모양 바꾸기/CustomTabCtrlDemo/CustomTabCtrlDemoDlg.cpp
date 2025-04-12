// CustomTabCtrlDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "CustomTabCtrlDemo.h"
#include "CustomTabCtrlDemoDlg.h"

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


// CCustomTabCtrlDemoDlg 대화 상자



CCustomTabCtrlDemoDlg::CCustomTabCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCustomTabCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCustomTabCtrlDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CCustomTabCtrlDemoDlg::~CCustomTabCtrlDemoDlg()
{
	// 이미지 리스트를 제거한다
	m_ImageList.DeleteImageList();
}

void CCustomTabCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustomTabCtrlDemoDlg)
	DDX_Control(pDX, IDC_CUSTOM_TAB, m_CustomTab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCustomTabCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CCustomTabCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CCustomTabCtrlDemoDlg 메시지 처리기

BOOL CCustomTabCtrlDemoDlg::OnInitDialog()
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

	// 이미지 리스트를 생성한다
	m_ImageList.Create(IDB_IMAGE_LIST, 20, 1, RGB(255, 0, 255));

	// 이미지 리스트를 탭 컨트롤에 설정한다
	m_CustomTab.SetImageList(&m_ImageList);
	// 탭 버튼 배경 이미지를 설정한다
	m_CustomTab.SetTabBmp(IDB_BKGND_LEFT, IDB_BKGND_CENTER, IDB_BKGND_RIGHT);
	
	// 탭 이미지와 함께 탭을 추가한다
	m_CustomTab.InsertItem(0, "뒤로", 0);
	m_CustomTab.InsertItem(1, "앞으로", 1);
	m_CustomTab.InsertItem(2, "중지", 2);
	m_CustomTab.InsertItem(3, "새로고침", 3);
	m_CustomTab.InsertItem(4, "홈", 4);
	m_CustomTab.InsertItem(5, "검색", 5);
	m_CustomTab.InsertItem(6, "즐겨찾기", 6);
	m_CustomTab.InsertItem(7, "미디어", 7);
	m_CustomTab.InsertItem(8, "기록", 8);

	// 각 탭에 컨트롤들을 추가한다
	m_CustomTab.AddControl(0, GetDlgItem(IDC_BACK_STATIC));
	m_CustomTab.AddControl(1, GetDlgItem(IDC_FORWARD_STATIC));
	m_CustomTab.AddControl(2, GetDlgItem(IDC_STOP_STATIC));
	m_CustomTab.AddControl(3, GetDlgItem(IDC_REFRESH_STATIC));
	m_CustomTab.AddControl(4, GetDlgItem(IDC_HOME_STATIC));
	m_CustomTab.AddControl(5, GetDlgItem(IDC_SEARCH_STATIC));
	m_CustomTab.AddControl(6, GetDlgItem(IDC_FAVORITE_STATIC));
	m_CustomTab.AddControl(7, GetDlgItem(IDC_MEDIA_STATIC));
	m_CustomTab.AddControl(8, GetDlgItem(IDC_HISTORY_STATIC));

	// 초기 페이지를 0번 페이지로 설정한다
	m_CustomTab.SetCurSel(0);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CCustomTabCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCustomTabCtrlDemoDlg::OnPaint() 
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
HCURSOR CCustomTabCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
