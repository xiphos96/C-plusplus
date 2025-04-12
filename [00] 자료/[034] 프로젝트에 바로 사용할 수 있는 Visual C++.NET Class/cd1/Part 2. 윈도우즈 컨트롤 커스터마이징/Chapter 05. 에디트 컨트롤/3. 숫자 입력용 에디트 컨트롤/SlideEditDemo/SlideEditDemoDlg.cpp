// SlideEditDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "SlideEditDemo.h"
#include "SlideEditDemoDlg.h"

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


// CSlideEditDemoDlg 대화 상자



CSlideEditDemoDlg::CSlideEditDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSlideEditDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSlideEditDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSlideEditDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSlideEditDemoDlg)
	DDX_Control(pDX, IDC_COLOR_STATIC, m_ColorStatic);
	DDX_Control(pDX, IDC_SLIDE_EDIT_R, m_SlideEditR);
	DDX_Control(pDX, IDC_SLIDE_EDIT_G, m_SlideEditG);
	DDX_Control(pDX, IDC_SLIDE_EDIT_B, m_SlideEditB);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSlideEditDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CSlideEditDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_SLIDE_POS_CHANGE, OnSlidePosChange)
	ON_MESSAGE(WM_SLIDE_END_SELECT, OnSlideEndSelect)
END_MESSAGE_MAP()


// CSlideEditDemoDlg 메시지 처리기

BOOL CSlideEditDemoDlg::OnInitDialog()
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

	// 슬라이드 에디트 컨트롤에 범위를 설정한다
	m_SlideEditR.SetRange(255, 0);
	m_SlideEditG.SetRange(255, 0);
	m_SlideEditB.SetRange(255, 0);

	// 슬라이드 에디트 컨트롤의 초기값을 설정한다
	m_SlideEditR.SetValue(255);
	m_SlideEditG.SetValue(255);
	m_SlideEditB.SetValue(255);

	// 컬러 스태틱의 초기 색상을 설정한다
	m_ColorStatic.m_clrColor = RGB(255, 255, 255);
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CSlideEditDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSlideEditDemoDlg::OnPaint() 
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
HCURSOR CSlideEditDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 슬라이드 에디트 컨트롤에서 슬라이드의 이동에 따른 핸들러
LRESULT CSlideEditDemoDlg::OnSlidePosChange(WPARAM wParam, LPARAM lParam)
{
	// 컬러 스태틱 컨트롤의 색상을 변경한다
	m_ColorStatic.m_clrColor = RGB(m_SlideEditR.GetValue(), m_SlideEditG.GetValue(), m_SlideEditB.GetValue());
	m_ColorStatic.Invalidate();

	return 1;
}

// 슬라이드 에디트 컨트롤에서 값 변동에 대한 핸들러
LRESULT CSlideEditDemoDlg::OnSlideEndSelect(WPARAM wParam, LPARAM lParam)
{
	// 컬러 스태틱 컨트롤의 색상을 변경한다
	m_ColorStatic.m_clrColor = RGB(m_SlideEditR.GetValue(), m_SlideEditG.GetValue(), m_SlideEditB.GetValue());
	m_ColorStatic.Invalidate();

	return 1;
}
