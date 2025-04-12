// CustomSliderCtrlDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "CustomSliderCtrlDemo.h"
#include "CustomSliderCtrlDemoDlg.h"

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


// CCustomSliderCtrlDemoDlg 대화 상자



CCustomSliderCtrlDemoDlg::CCustomSliderCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCustomSliderCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCustomSliderCtrlDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCustomSliderCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustomSliderCtrlDemoDlg)
	DDX_Control(pDX, IDC_CUSTOM_VERT_SLIDER, m_CustomVertSlider);
	DDX_Control(pDX, IDC_CUSTOM_HORZ_SLIDER, m_CustomHorzSlider);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCustomSliderCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CCustomSliderCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RESTART_BUTTON, OnRestartButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CCustomSliderCtrlDemoDlg 메시지 처리기

BOOL CCustomSliderCtrlDemoDlg::OnInitDialog()
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

	// 수평 슬라이더의 속성을 설정한다
	m_CustomHorzSlider.SetRange(0, 100);					// 값의 범위 설정
	m_CustomHorzSlider.SetPos(0);							// 초기 위치 설정
	m_CustomHorzSlider.SetTicFreq(10);						// 눈금의 간격 설정
	m_CustomHorzSlider.SetSelection(0, 0);					// 범위 설정
	m_CustomHorzSlider.SetThumbColor(RGB(178, 197, 255));	// 핸들 색상 설정
	m_CustomHorzSlider.SetSelectionColor(RGB(0, 44, 178));	// 선택된 범위 색상 설정
	m_CustomHorzSlider.SetChannelColor(RGB(255, 86, 86));	// 선택되지 않은 범위 색상 설정
	
	// 수직 슬라이더의 속성을 설정한다
	m_CustomVertSlider.SetRange(0, 100);					// 값의 범위 설정
	m_CustomVertSlider.SetPos(0);							// 초기 위치 설정
	m_CustomVertSlider.SetTicFreq(10);						// 눈금의 간격 설정
	m_CustomVertSlider.SetSelection(0, 0);					// 범위 설정
	m_CustomVertSlider.SetThumbColor(RGB(178, 197, 255));	// 핸들 색상 설정
	m_CustomVertSlider.SetSelectionColor(RGB(0, 44, 178));	// 선택된 범위 색상 설정
	m_CustomVertSlider.SetChannelColor(RGB(255, 86, 86));	// 선택되지 않은 범위 색상 설정
	
	m_nThumbStep		= 1;								// 핸들의 이동 간격 설정
	m_nSelectionStep	= 2;								// 범위의 이동 간격 설정

	// 타이머를 사용하여 핸들과 범위를 이동 시켜본다
	SetTimer(1, 50, NULL);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CCustomSliderCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCustomSliderCtrlDemoDlg::OnPaint() 
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
HCURSOR CCustomSliderCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCustomSliderCtrlDemoDlg::OnTimer(UINT nIDEvent) 
{
	int nPos, nMin, nMax;

	// 현재 수평 슬라이더의 위치를 증가시킨다
	nPos = m_CustomHorzSlider.GetPos();
	nPos += m_nThumbStep;
	m_CustomHorzSlider.SetPos(nPos);
	// 만약 최대 값까지 이동되었다면 타이머를 종료한다
	nMax = m_CustomHorzSlider.GetRangeMax();
	if(nPos >= nMax)		KillTimer(nIDEvent);

	// 현재 수직 슬라이더의 위치를 증가시킨다
	nPos = m_CustomVertSlider.GetPos();
	nPos += m_nThumbStep;
	m_CustomVertSlider.SetPos(nPos);

	// 현재 수평 슬라이더의 범위를 증가시킨다
	m_CustomHorzSlider.GetSelection(nMin, nMax);
	nMax += m_nSelectionStep;
	m_CustomHorzSlider.SetSelection(nMin, nMax);

	// 현재 수직 슬라이더의 범위를 증가시킨다
	m_CustomVertSlider.GetSelection(nMin, nMax);
	nMax += m_nSelectionStep;
	m_CustomVertSlider.SetSelection(nMin, nMax);
	
	CDialog::OnTimer(nIDEvent);
}

void CCustomSliderCtrlDemoDlg::OnRestartButton() 
{
	// 수평 슬라이더를 초기화한다
	m_CustomHorzSlider.SetPos(0);
	m_CustomHorzSlider.SetSelection(0, 0);
	
	// 수직 슬라이더를 초기화한다
	m_CustomVertSlider.SetPos(0);
	m_CustomVertSlider.SetSelection(0, 0);
	
	// 타이머를 시작한다
	SetTimer(1, 50, NULL);
}
