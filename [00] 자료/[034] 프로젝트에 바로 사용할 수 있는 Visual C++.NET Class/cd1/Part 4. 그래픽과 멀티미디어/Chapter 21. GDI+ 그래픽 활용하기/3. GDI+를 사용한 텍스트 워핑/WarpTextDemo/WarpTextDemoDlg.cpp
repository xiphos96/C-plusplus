// WarpTextDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "WarpTextDemo.h"
#include "WarpTextDemoDlg.h"

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


// CWarpTextDemoDlg 대화 상자



CWarpTextDemoDlg::CWarpTextDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWarpTextDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWarpTextDemoDlg)
	m_strText = _T("워핑 테스트");
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


// CWarpTextDemoDlg 메시지 처리기

BOOL CWarpTextDemoDlg::OnInitDialog()
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

	// 워핑할 텍스트와 폰트를 설정한다
	m_WarpText.SetText(m_strText, "굴림체");
	// 폰트의 채움 색상을 설정한다
	m_WarpText.SetFontColor(RGB(179, 200, 200));
	// 폰트의 외곽 색상을 설정한다
	m_WarpText.SetOutlineColor(RGB(0, 0, 0));

	// 워핑 텍스트 스태틱 컨트롤의 크기를 얻는다
	CRect rcStatic;
	GetDlgItem(IDC_WARP_STATIC)->GetClientRect(&rcStatic);

	// 워핑할 좌표를 작성한다
	CPoint ptWarp[4];
	// 상단 좌측 좌표
	ptWarp[0].x = 0;
	ptWarp[0].y = 0;
	// 상단 우측 좌표
	ptWarp[1].x = rcStatic.right;
	ptWarp[1].y = 60;

	// 하단 좌측 좌표
	ptWarp[2].x = 120;
	ptWarp[2].y = rcStatic.bottom;
	// 하단 우측 좌표
	ptWarp[3].x = rcStatic.right - 100;
	ptWarp[3].y = rcStatic.bottom - 80;

	// 워핑할 좌표를 설정한다
	m_WarpText.SetWarpPoint(ptWarp);
	// 가이드 선을 출력할 것인지 설정한다
	m_WarpText.ShowGuideLine(m_bShowGuide);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면 
// 아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
// 프레임워크에서 이 작업을 자동으로 수행합니다.

void CWarpTextDemoDlg::OnPaint() 
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
HCURSOR CWarpTextDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CWarpTextDemoDlg::OnRefreshButton() 
{
	UpdateData(TRUE);

	// 워핑할 텍스트와 폰트를 설정한다
	m_WarpText.SetText(m_strText, "굴림체");
	// 화면을 다시 그린다
	m_WarpText.Invalidate(FALSE);
}

void CWarpTextDemoDlg::OnShowGuideCheck() 
{
	UpdateData(TRUE);

	// 가이드 선을 출력할 것인지 설정한다
	m_WarpText.ShowGuideLine(m_bShowGuide);
	// 화면을 다시 그린다
	m_WarpText.Invalidate(FALSE);
}
