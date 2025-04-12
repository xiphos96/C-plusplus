// ColorMessageBoxDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ColorMessageBox.h"
#include "ColorMessageBoxDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 컬러 메시지 박스를 사용하기 위한 헤더 파일
#include "ColorMsgBoxHook.h"

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


// CColorMessageBoxDlg 대화 상자



CColorMessageBoxDlg::CColorMessageBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CColorMessageBoxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CColorMessageBoxDlg)
	m_nUse = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CColorMessageBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColorMessageBoxDlg)
	DDX_Control(pDX, IDC_COLOR_BKGND_STATIC, m_clrBkgnd);
	DDX_Control(pDX, IDC_COLOR_TEXT_STATIC, m_clrText);
	DDX_Radio(pDX, IDC_USE_RADIO, m_nUse);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CColorMessageBoxDlg, CDialog)
	//{{AFX_MSG_MAP(CColorMessageBoxDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_AFXMESSAGEBOX_BUTTON, OnAfxmessageboxButton)
	ON_BN_CLICKED(IDC_MESSAGEBOX_BUTTON, OnMessageboxButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CColorMessageBoxDlg 메시지 처리기

BOOL CColorMessageBoxDlg::OnInitDialog()
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

	// 기본 텍스트 색상과 배경 색상을 설정한다
	m_clrText.m_clrColor	= RGB(30, 30, 30);
	m_clrBkgnd.m_clrColor	= RGB(255, 255, 255);
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CColorMessageBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CColorMessageBoxDlg::OnPaint() 
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
HCURSOR CColorMessageBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CColorMessageBoxDlg::OnMessageboxButton() 
{
	UpdateData(TRUE);

	// 만약 컬러를 사용한다면
	if(m_nUse == 0)
	{
		// 텍스트와 배경 색상을 컬러 메시지 박스에 설정한다
		g_MsgBoxHook.SetColorText(m_clrText.m_clrColor);
		g_MsgBoxHook.SetColorBkgnd(m_clrBkgnd.m_clrColor);

		// 컬러 메시지 박스를 띄운다
		g_MsgBoxHook.MessageBox(m_hWnd, "메시지 박스 테스트입니다.", "MessageBox", MB_ICONINFORMATION | MB_OK);
	}
	else
		// 만약 컬러를 사용하지 않는다면 기본 메시지 박스를 띄운다
		MessageBox("메시지 박스 테스트입니다.", "MessageBox", MB_ICONINFORMATION | MB_OK);
}

void CColorMessageBoxDlg::OnAfxmessageboxButton() 
{
	UpdateData(TRUE);

	// 만약 컬러를 사용한다면
	if(m_nUse == 0)
	{
		// 텍스트와 배경 색상을 컬러 메시지 박스에 설정한다
		g_MsgBoxHook.SetColorText(m_clrText.m_clrColor);
		g_MsgBoxHook.SetColorBkgnd(m_clrBkgnd.m_clrColor);

		// 컬러 메시지 박스를 띄운다
		g_MsgBoxHook.AfxMessageBox("메시지 박스 테스트입니다.", MB_ICONWARNING | MB_YESNO);
	}
	else
		// 만약 컬러를 사용하지 않는다면 기본 메시지 박스를 띄운다
		::AfxMessageBox("메시지 박스 테스트입니다.", MB_ICONWARNING | MB_YESNO);
}
