// BmpButtonDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "BmpButtonDemo.h"
#include "BmpButtonDemoDlg.h"
#include ".\bmpbuttondemodlg.h"

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


// CBmpButtonDemoDlg 대화 상자



CBmpButtonDemoDlg::CBmpButtonDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBmpButtonDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBmpButtonDemoDlg)
	m_nOrigin = 0;
	m_nSpeed = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBmpButtonDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBmpButtonDemoDlg)
	DDX_Control(pDX, IDC_SPEED_BITMAP_BUTTON, m_btnSpeed);
	DDX_Control(pDX, IDC_ORIGIN_BITMAP_BUTTON, m_btnOrigin);
	DDX_Text(pDX, IDC_ORIGIN_EDIT, m_nOrigin);
	DDX_Text(pDX, IDC_SPEED_EDIT, m_nSpeed);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBmpButtonDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CBmpButtonDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ORIGIN_BITMAP_BUTTON, OnOriginBitmapButton)
	ON_BN_CLICKED(IDC_SPEED_BITMAP_BUTTON, OnSpeedBitmapButton)
	//}}AFX_MSG_MAP
//	ON_BN_DOUBLECLICKED(IDC_SPEED_BITMAP_BUTTON, OnBnDoubleclickedSpeedBitmapButton)
//	ON_BN_DOUBLECLICKED(IDC_ORIGIN_BITMAP_BUTTON, OnBnDoubleclickedOriginBitmapButton)
END_MESSAGE_MAP()


// CBmpButtonDemoDlg 메시지 처리기

BOOL CBmpButtonDemoDlg::OnInitDialog()
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

	// 원래 비트맵 버튼의 비트맵 로드
	m_btnOrigin.LoadBitmaps(IDB_BMP_NORMAL, IDB_BMP_PRESS);
	// 비트맵 크기로 버튼 크기 변경
	m_btnOrigin.SizeToContent();

	// 빠른 비트맵 버튼의 비트맵 로드
	m_btnSpeed.LoadBitmaps(IDB_BMP_NORMAL, IDB_BMP_PRESS);
	// 비트맵 크기로 버튼 크기 변경
	m_btnSpeed.SizeToContent();
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CBmpButtonDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBmpButtonDemoDlg::OnPaint() 
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
HCURSOR CBmpButtonDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 원래 비트맵 버튼 클릭 이벤트 핸들러
void CBmpButtonDemoDlg::OnOriginBitmapButton() 
{
	// 버튼 클릭 횟수를 1 증가 시킨다
	UpdateData(TRUE);

	m_nOrigin++;

	UpdateData(FALSE);
}

// 빠른 비트맵 버튼 클릭 이벤트 핸들러
void CBmpButtonDemoDlg::OnSpeedBitmapButton() 
{
	// 버튼 클릭 횟수를 1 증가 시킨다
	UpdateData(TRUE);

	m_nSpeed++;

	UpdateData(FALSE);
}
