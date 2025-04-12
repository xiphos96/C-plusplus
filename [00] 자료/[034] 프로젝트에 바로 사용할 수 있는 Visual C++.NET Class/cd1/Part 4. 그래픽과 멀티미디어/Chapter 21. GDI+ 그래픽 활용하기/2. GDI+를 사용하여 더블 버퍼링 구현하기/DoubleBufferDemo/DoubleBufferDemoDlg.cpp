// DoubleBufferDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "DoubleBufferDemo.h"
#include "DoubleBufferDemoDlg.h"

#include "DoubleBuffer.h"

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


// CDoubleBufferDemoDlg 대화 상자



CDoubleBufferDemoDlg::CDoubleBufferDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDoubleBufferDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDoubleBufferDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDoubleBufferDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDoubleBufferDemoDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDoubleBufferDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDoubleBufferDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CDoubleBufferDemoDlg 메시지 처리기

BOOL CDoubleBufferDemoDlg::OnInitDialog()
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

	// 다이얼로그 DC에서 Graphics 객체를 생성한다
	CDC *pDC = GetDC();
	Graphics graphics(pDC->m_hDC);

	// 텍스트 출력을 위한 폰트와 좌표 변수를 생성한다
	Font font(L"굴림체", 16);
	PointF origin(0, 0);
	RectF rcString;

	// 메시지 텍스트를 설정한다
	m_strMessage = "더블버퍼링을 사용한 텍스트 스크롤입니다.";

	// 텍스트에 대한 BSTR을 얻는다
	BSTR bstrMessage = m_strMessage.AllocSysString();
	// 텍스트 출력에 필요한 크기를 계산한다
	graphics.MeasureString(bstrMessage, ::wcslen(bstrMessage),
		&font, origin, &rcString);
	// BSTR 메모리를 해제한다
	::SysFreeString(bstrMessage);

	// 텍스트 출력 크기를 저장한다
	m_TextSize.cx = (LONG)rcString.Width;
	m_TextSize.cy = (LONG)rcString.Height;

	ReleaseDC(pDC);

	GetClientRect(&m_rcClient);

	// 초기 텍스트 출력 위치를 우측변으로 한다
	m_nCurPos = m_rcClient.right;

	// 타이머를 실행한다
	SetTimer(1, 1, NULL);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CDoubleBufferDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDoubleBufferDemoDlg::OnPaint() 
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
		// 더블 버퍼링 객체를 생성한다
		CGraphics dbGraphics(m_hWnd);
		// 더블 버퍼링 객체에서 Graphics 포인터를 얻는다
		Graphics *pGraphics = dbGraphics.GetGraphics();

		// Graphics 포인터를 사용하여 배경을 검은 브러쉬로 칠한다
		Rect rect(0, 0, m_rcClient.Width(), m_rcClient.Height());
		SolidBrush BlackBrush(Color::Black);
		pGraphics->FillRectangle(&BlackBrush, rect);

		// 텍스트 출력을 위한 폰트와 브러쉬를 생성하고 좌표를 계산한다
		Font font(L"굴림체", 16);
		SolidBrush WhiteBrush(Color::White);
		PointF origin((REAL)m_nCurPos, (REAL)(m_rcClient.Height() - m_TextSize.cy) / 2);

		// 그래픽 출력 품질을 앤티앨리어싱으로 설정한다
		pGraphics->SetSmoothingMode(SmoothingModeAntiAlias);

		// 텍스트 출력 품질을 앤티앨리어싱으로 설정한다
		pGraphics->SetTextRenderingHint(TextRenderingHintAntiAlias);

		// 텍스트에 대한 BSTR을 얻는다
		BSTR bstrMessage = m_strMessage.AllocSysString();
		// 메시지 텍스트를 현재 위치에 하얀 색 브러쉬로 출력한다
		pGraphics->DrawString(bstrMessage, ::wcslen(bstrMessage),
			&font, origin, &WhiteBrush);
		// BSTR 메모리를 해제한다
		::SysFreeString(bstrMessage);

		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다. 
HCURSOR CDoubleBufferDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDoubleBufferDemoDlg::OnTimer(UINT nIDEvent) 
{
	// 텍스트 출력 위치를 왼쪽으로 이동한다
	m_nCurPos--;

	// 만약 모든 텍스트가 좌측변을 지났다면 텍스트 출력 위치를 우측변으로 설정한다
	if(m_nCurPos < -m_TextSize.cx)
		m_nCurPos = m_rcClient.right;

	// 화면을 다시 그린다
	Invalidate(FALSE);
	
	CDialog::OnTimer(nIDEvent);
}

void CDoubleBufferDemoDlg::OnDestroy() 
{
	CDialog::OnDestroy();

	// 타이머를 종료한다
	KillTimer(1);
}

BOOL CDoubleBufferDemoDlg::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}
