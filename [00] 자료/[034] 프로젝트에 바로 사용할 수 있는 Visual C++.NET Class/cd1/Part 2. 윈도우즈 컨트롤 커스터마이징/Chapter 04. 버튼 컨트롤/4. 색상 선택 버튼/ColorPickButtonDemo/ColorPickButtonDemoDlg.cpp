// ColorPickButtonDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ColorPickButtonDemo.h"
#include "ColorPickButtonDemoDlg.h"

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


// CColorPickButtonDemoDlg 대화 상자



CColorPickButtonDemoDlg::CColorPickButtonDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CColorPickButtonDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CColorPickButtonDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CColorPickButtonDemoDlg::~CColorPickButtonDemoDlg()
{
	// 배경 출력용 브러쉬 삭제
	if(m_BkgndBrush.m_hObject)	m_BkgndBrush.DeleteObject();
}

void CColorPickButtonDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColorPickButtonDemoDlg)
	DDX_Control(pDX, IDC_TEXT_DEFAULT_COLOR_BUTTON, m_btnTextDefault);
	DDX_Control(pDX, IDC_BKGND_DEFAULT_COLOR_BUTTON, m_btnBkgndDefault);
	DDX_Control(pDX, IDC_TEXT_COLOR_BUTTON, m_btnText);
	DDX_Control(pDX, IDC_BKGND_COLOR_BUTTON, m_btnBkgnd);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CColorPickButtonDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CColorPickButtonDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
	ON_MESSAGE(CLR_SELENDOK, OnSelEndOKColor)
END_MESSAGE_MAP()


// CColorPickButtonDemoDlg 메시지 처리기

BOOL CColorPickButtonDemoDlg::OnInitDialog()
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

	// 글자 기본 색상과 배경 기본 색상을 시스템 색상으로 설정한다
	m_clrTextDefault	= ::GetSysColor(COLOR_BTNTEXT);
	m_clrBkgndDefault	= ::GetSysColor(COLOR_BTNFACE);
	// 글자 색상과 배경 색상을 기본 색상으로 설정한다.
	m_clrText			= m_clrTextDefault;
	m_clrBkgnd			= m_clrBkgndDefault;

	// 배경 색상으로 브러쉬를 생성한다
	m_BkgndBrush.CreateSolidBrush(m_clrBkgnd);

	// 기본 글자 색상 버튼을 설정한다
	m_btnTextDefault.SetDefaultColor(m_clrTextDefault);
	m_btnTextDefault.SetColor(m_clrTextDefault);

	// 기본 배경 색상 버튼을 설정한다
	m_btnBkgndDefault.SetDefaultColor(m_clrBkgndDefault);
	m_btnBkgndDefault.SetColor(m_clrBkgndDefault);

	// 글자 색상 버튼을 설정한다
	m_btnText.SetDefaultColor(m_clrTextDefault);
	m_btnText.SetColor(m_clrText);
	m_btnText.SetFlat(FALSE);

	// 배경 색상 버튼을 설정한다
	m_btnBkgnd.SetDefaultColor(m_clrBkgndDefault);
	m_btnBkgnd.SetColor(m_clrBkgnd);
	m_btnBkgnd.SetFlat(FALSE);
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CColorPickButtonDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CColorPickButtonDemoDlg::OnPaint() 
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
HCURSOR CColorPickButtonDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HBRUSH CColorPickButtonDemoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	// 테스트용 스태틱 컨트롤의 글자 색상과 배경을 설정한다
	if(CTLCOLOR_STATIC == nCtlColor)
	{
		if(pWnd->m_hWnd == GetDlgItem(IDC_TEXT_STATIC)->m_hWnd)
		{
			pDC->SetBkMode(TRANSPARENT);
			pDC->SetTextColor(m_clrText);
			return HBRUSH(m_BkgndBrush);
		}
	}

	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	return hbr;
}

// 색상 선택 완료 메시지 핸들러
LRESULT CColorPickButtonDemoDlg::OnSelEndOKColor(WPARAM wParam, LPARAM lParam) 
{
	switch(wParam)
	{
	case IDC_TEXT_DEFAULT_COLOR_BUTTON:
		// 기본 글자 색상 변경시
		// 글자 색상 버튼의 기본 색상을 변경한다
		m_btnText.SetDefaultColor(m_btnTextDefault.GetColor());
		break;
	case IDC_TEXT_COLOR_BUTTON:
		// 글자 색상 변경시
		// 글자 색상을 변경하고 테스트 스태틱 컨트롤을 다시 그린다
		m_clrText = m_btnText.GetColor();
		GetDlgItem(IDC_TEXT_STATIC)->Invalidate();
		break;
	case IDC_BKGND_DEFAULT_COLOR_BUTTON:
		// 기본 배경 색상 변경시
		// 배경 색상 버튼의 기본 색상을 변경한다
		m_btnBkgnd.SetDefaultColor(m_btnBkgndDefault.GetColor());
		break;
	case IDC_BKGND_COLOR_BUTTON:
		// 배경 색상 변경시
		// 배경 색상을 변경하고 브러쉬를 새로 생성한 후 테스트 스태틱 컨트롤을 다시 그린다
		m_clrBkgnd = m_btnBkgnd.GetColor();
		m_BkgndBrush.DeleteObject();
		m_BkgndBrush.CreateSolidBrush(m_clrBkgnd);
		GetDlgItem(IDC_TEXT_STATIC)->Invalidate();
		break;
	}
	return 1;
}
