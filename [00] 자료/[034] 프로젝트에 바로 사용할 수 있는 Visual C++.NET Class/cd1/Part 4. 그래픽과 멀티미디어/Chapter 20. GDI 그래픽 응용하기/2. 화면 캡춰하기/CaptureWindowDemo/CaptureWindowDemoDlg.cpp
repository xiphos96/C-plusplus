// CaptureWindowDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "CaptureWindowDemo.h"
#include "CaptureWindowDemoDlg.h"

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


// CCaptureWindowDemoDlg 대화 상자



CCaptureWindowDemoDlg::CCaptureWindowDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCaptureWindowDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCaptureWindowDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCaptureWindowDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCaptureWindowDemoDlg)
	DDX_Control(pDX, IDC_SELECTOR_STATIC, m_CaptureWindow);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCaptureWindowDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CCaptureWindowDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_SELECT_START, OnSelectStart)
	ON_MESSAGE(WM_SELECT_END, OnSelectEnd)
	ON_MESSAGE(WM_CAPTURE_FINISH, OnCaptureFinish)
END_MESSAGE_MAP()


// CCaptureWindowDemoDlg 메시지 처리기

BOOL CCaptureWindowDemoDlg::OnInitDialog()
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

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CCaptureWindowDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCaptureWindowDemoDlg::OnPaint() 
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
		CBitmap *pCapture = m_CaptureWindow.GetCapturedBitmap();

		if(pCapture->m_hObject)
		{
			CPaintDC dc(this);

			BITMAP bmpInfo;
			pCapture->GetBitmap(&bmpInfo);

			CDC MemDC;
			MemDC.CreateCompatibleDC(&dc);
			CBitmap *pOldBmp = MemDC.SelectObject(pCapture);

			dc.BitBlt(10, 40, bmpInfo.bmWidth, bmpInfo.bmHeight,
				&MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(pOldBmp);
			MemDC.DeleteDC();
		}

		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다. 
HCURSOR CCaptureWindowDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 윈도우 선택이 시작되었을 때 실행되는 함수
LRESULT CCaptureWindowDemoDlg::OnSelectStart(WPARAM wParam, LPARAM lParam)
{
	CCaptureWindow *pCollector = (CCaptureWindow*)lParam;

	return 1;
}

// 윈도우가 선택된 후 실행되는 함수
LRESULT CCaptureWindowDemoDlg::OnSelectEnd(WPARAM wParam, LPARAM lParam)
{
	CCaptureWindow *pCollector = (CCaptureWindow*)lParam;

	return 1;
}

// 윈도우를 캡춰한 후 실행되는 함수
LRESULT CCaptureWindowDemoDlg::OnCaptureFinish(WPARAM wParam, LPARAM lParam)
{
	CCaptureWindow *pCollector = (CCaptureWindow*)lParam;
	HWND hCaptured = (HWND)wParam;

	CBitmap *pCapture = pCollector->GetCapturedBitmap();

	if(pCapture->m_hObject)
	{
		BITMAP bmpInfo;
		pCapture->GetBitmap(&bmpInfo);

		int nWidth = bmpInfo.bmWidth + 20;
		if(nWidth < 465)		nWidth = 465;

		int nHeight = bmpInfo.bmHeight + 40 + 70;

		SetWindowPos(NULL, 0, 0, nWidth, nHeight, SWP_NOZORDER | SWP_NOMOVE);

		CRect rcButton;
		GetDlgItem(IDOK)->GetWindowRect(&rcButton);

		rcButton.left = nWidth - 10 - rcButton.Width();
		rcButton.right = nWidth - 10;
		rcButton.top = nHeight - 35 - rcButton.Height();
		rcButton.bottom = nHeight - 35;

		GetDlgItem(IDOK)->MoveWindow(&rcButton);

		CString strTitle;
		::GetWindowText(hCaptured, strTitle.GetBuffer(MAX_PATH), MAX_PATH);
		strTitle.ReleaseBuffer();

		CString strMessage;
		strMessage.Format("윈도우가 캡춰 되었습니다.\n\n타이틀 : [%s]", strTitle);
		MessageBox(strMessage, "Capture Window", MB_OK);
	}
	else
		MessageBox("캡춰된 윈도우가 없습니다.", "Capture Window", MB_OK);

	return 1;
}
