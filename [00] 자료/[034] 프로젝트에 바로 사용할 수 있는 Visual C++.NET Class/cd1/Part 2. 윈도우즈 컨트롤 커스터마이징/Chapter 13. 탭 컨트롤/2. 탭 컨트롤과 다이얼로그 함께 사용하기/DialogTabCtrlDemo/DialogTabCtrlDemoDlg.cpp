// DialogTabCtrlDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "DialogTabCtrlDemo.h"
#include "DialogTabCtrlDemoDlg.h"

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


// CDialogTabCtrlDemoDlg 대화 상자



CDialogTabCtrlDemoDlg::CDialogTabCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogTabCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogTabCtrlDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogTabCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogTabCtrlDemoDlg)
	DDX_Control(pDX, IDC_DIALOG_TAB, m_DialogTab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDialogTabCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDialogTabCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_AT_SELCHANGE, OnATSelChange)
END_MESSAGE_MAP()


// CDialogTabCtrlDemoDlg 메시지 처리기

BOOL CDialogTabCtrlDemoDlg::OnInitDialog()
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

	// 수입 다이얼로그를 생성한다
	if(!m_IncomeDlg.Create(IDD_INCOME_DIALOG, &m_DialogTab))
	{
		MessageBox("수입 다이얼로그를 생성할 수 없습니다.");
		OnCancel();
		return TRUE;
	}

	// 지출 다이얼로그를 생성한다
	if(!m_OutgoDlg.Create(IDD_OUTGO_DIALOG, &m_DialogTab))
	{
		MessageBox("지출 다이얼로그를 생성할 수 없습니다.");
		OnCancel();
		return TRUE;
	}

	// 합계 다이얼로그를 생성한다
	if(!m_ReportDlg.Create(IDD_REPORT_DIALOG, &m_DialogTab))
	{
		MessageBox("합계 다이얼로그를 생성할 수 없습니다.");
		OnCancel();
		return TRUE;
	}

	// 다이얼로그 탭 컨트롤에 탭을 추가한다 - 탭을 구현하는 다이얼로그를 함께 전달한다
	m_DialogTab.InsertItem(0, "수입", &m_IncomeDlg);
	m_DialogTab.InsertItem(1, "지출", &m_OutgoDlg);
	m_DialogTab.InsertItem(2, "합계", &m_ReportDlg);

	// 초기 탭을 0번으로 설정한다
	m_DialogTab.SetCurSel(0);
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CDialogTabCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDialogTabCtrlDemoDlg::OnPaint() 
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
HCURSOR CDialogTabCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 다이얼로그 탭 컨트롤의 탭 변경시 호출되는 함수
LRESULT CDialogTabCtrlDemoDlg::OnATSelChange(WPARAM wParam, LPARAM lParam) 
{
	switch(lParam)
	{
	case 0:
		// 수입 탭이 선택되면 수입 다이얼로그의 에디트 박스들의 텍스트를 초기화한다
		m_IncomeDlg.ResetEdit();
		break;
	case 1:
		// 지출 탭이 선택되면 지출 다이얼로그의 에디트 박스들의 텍스트를 초기화한다
		m_OutgoDlg.ResetEdit();
		break;
	case 2:
		// 합계 탭이 선택되면 합계 다이얼로그에서 합계를 계산하여 출력한다
		m_ReportDlg.RefreshSum();
		break;
	}

	return 0;
}
