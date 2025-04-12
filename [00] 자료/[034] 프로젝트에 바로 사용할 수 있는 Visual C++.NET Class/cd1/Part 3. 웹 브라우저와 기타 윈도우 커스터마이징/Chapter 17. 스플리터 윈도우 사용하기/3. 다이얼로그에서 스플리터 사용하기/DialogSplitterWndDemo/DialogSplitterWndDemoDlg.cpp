// DialogSplitterWndDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "DialogSplitterWndDemo.h"
#include "DialogSplitterWndDemoDlg.h"

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


// CDialogSplitterWndDemoDlg 대화 상자



CDialogSplitterWndDemoDlg::CDialogSplitterWndDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogSplitterWndDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogSplitterWndDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogSplitterWndDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogSplitterWndDemoDlg)
	DDX_Control(pDX, IDC_SPLITTER2_STATIC, m_wndSplitter2);
	DDX_Control(pDX, IDC_SPLITTER_STATIC, m_wndSplitter);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDialogSplitterWndDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDialogSplitterWndDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CDialogSplitterWndDemoDlg 메시지 처리기

BOOL CDialogSplitterWndDemoDlg::OnInitDialog()
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

	// 수직 스플리터의 속성을 설정한다
	m_wndSplitter.SetDirection(DIR_VERT);
	// 좌측은 다이얼로그 좌측 변까지 이동할 수 있고, 오른쪽은 50 픽셀 이동할 수 있도록 설정한다
	m_wndSplitter.SetRange(-1, 50);

	// 수직 스플리터의 좌측에 존재하는 컨트롤들을 스플리터에 설정한다
	// IDC_TEST_STATIC은 스플리터가 멀어짐에 따라 크기를 늘리는 기능을 사용하지 않는다
	m_wndSplitter.AddControl(POS_LEFT, GetDlgItem(IDC_TEST_STATIC), FALSE);
	m_wndSplitter.AddControl(POS_LEFT, GetDlgItem(IDC_TEST_EDIT), TRUE);
	m_wndSplitter.AddControl(POS_LEFT, GetDlgItem(IDC_TEST_BUTTON), TRUE);
	m_wndSplitter.AddControl(POS_LEFT, GetDlgItem(IDC_TEST_CALENDAR), TRUE);

	// 수직 스플리터의 우측에 존재하는 컨트롤들을 스플리터에 설정한다
	// 모든 컨트롤에 대해 스플리터가 멀어짐에 따라 크기를 늘리도록 설정한다
	m_wndSplitter.AddControl(POS_RIGHT, GetDlgItem(IDC_TEST_TREE), TRUE);
	m_wndSplitter.AddControl(POS_RIGHT, &m_wndSplitter2, TRUE);
	m_wndSplitter.AddControl(POS_RIGHT, GetDlgItem(IDC_TEST_LIST), TRUE);
	
	// 수평 스플리터 속성을 설정한다
	m_wndSplitter2.SetDirection(DIR_HORZ);
	// 상단은 80 픽셀 이동할 수 있고, 하단은 150 픽셀 이동할 수 있도록 설정한다
	m_wndSplitter2.SetRange(80, 150);

	// 수평 스플리터의 상단 컨트롤을 스플리터에 설정한다
	m_wndSplitter2.AddControl(POS_TOP, GetDlgItem(IDC_TEST_TREE), TRUE);

	// 수평 스플리터의 하단 컨트롤을 스플리터에 설정한다
	m_wndSplitter2.AddControl(POS_BOTTOM, GetDlgItem(IDC_TEST_LIST), TRUE);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CDialogSplitterWndDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDialogSplitterWndDemoDlg::OnPaint() 
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
HCURSOR CDialogSplitterWndDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
