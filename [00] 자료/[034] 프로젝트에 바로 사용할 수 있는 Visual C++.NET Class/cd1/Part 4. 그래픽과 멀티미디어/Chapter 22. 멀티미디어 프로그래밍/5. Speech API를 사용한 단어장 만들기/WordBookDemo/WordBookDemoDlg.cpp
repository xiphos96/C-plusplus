// WordBookDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "WordBookDemo.h"
#include "WordBookDemoDlg.h"

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


// CWordBookDemoDlg 대화 상자



CWordBookDemoDlg::CWordBookDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWordBookDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWordBookDemoDlg)
	m_strEnglish = _T("");
	m_strKorean = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWordBookDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWordBookDemoDlg)
	DDX_Control(pDX, IDC_WORDBOOK_LIST, m_WordBook);
	DDX_Text(pDX, IDC_ENGLISH_EDIT, m_strEnglish);
	DDX_Text(pDX, IDC_KOREAN_EDIT, m_strKorean);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWordBookDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CWordBookDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_GETMINMAXINFO()
	ON_BN_CLICKED(IDC_ADD_BUTTON, OnAddButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CWordBookDemoDlg 메시지 처리기

BOOL CWordBookDemoDlg::OnInitDialog()
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

	// 클라이언트 영역을 저장한다
	GetClientRect(&m_rcClient);
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CWordBookDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWordBookDemoDlg::OnPaint() 
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
HCURSOR CWordBookDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CWordBookDemoDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

	// 단어장이 생성된 상태면
	if(m_WordBook.m_hWnd)
	{
		// 단어장 크기를 얻는다
		CRect rcList;
		m_WordBook.GetWindowRect(&rcList);
		ScreenToClient(&rcList);

		// 다이얼로그의 변화된 크기를 계산한다
		cx -= m_rcClient.Width();
		cy -= m_rcClient.Height();

		// 단어장의 크기를 보정한다
		rcList.right += cx;
		rcList.bottom += cy;

		// 단어장의 크기를 조정한다
		m_WordBook.MoveWindow(&rcList);

		// 새 클라이언트 영역을 저장한다
		GetClientRect(&m_rcClient);
	}
}

void CWordBookDemoDlg::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	// 최소 크기를 설정한다
	lpMMI->ptMinTrackSize.x = 498;
	lpMMI->ptMinTrackSize.y = 130;
	
	CDialog::OnGetMinMaxInfo(lpMMI);
}

BOOL CWordBookDemoDlg::PreTranslateMessage(MSG* pMsg) 
{
	// 만약 Enter키가 눌려졌으면
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		// 만약 영어 입력 에디트 컨트롤에서 엔터키가 눌려졌다면
		if(GetFocus()->m_hWnd == GetDlgItem(IDC_ENGLISH_EDIT)->m_hWnd)
		{
			// 영어 단어를 얻어온다
			CString strTemp;
			GetDlgItem(IDC_ENGLISH_EDIT)->GetWindowText(strTemp);

			// 단어 입력이 되지 않았다면 리턴한다
			if(strTemp.IsEmpty())	return TRUE;
			// 한글 해석 입력 에디트 컨트롤로 포커스를 이동한다
			GetDlgItem(IDC_KOREAN_EDIT)->SetFocus();
			return TRUE;
		}

		// 만약 한글 입력 에디트 컨트롤에서 엔터키가 눌려졌다면
		if(GetFocus()->m_hWnd == GetDlgItem(IDC_KOREAN_EDIT)->m_hWnd)
		{
			// 한글 해석을 얻어온다
			CString strTemp;
			GetDlgItem(IDC_KOREAN_EDIT)->GetWindowText(strTemp);

			// 해석이 입력되지 않았다면 리턴한다
			if(strTemp.IsEmpty())	return TRUE;
			// 단어장에 단어를 추가한다
			OnAddButton();
			return TRUE;
		}
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CWordBookDemoDlg::OnAddButton() 
{
	UpdateData(TRUE);

	// 만약 영어 단어나 해석이 입력되지 않았다면 리턴한다
	if(m_strEnglish.IsEmpty() || m_strKorean.IsEmpty())	return;

	// 영어 단어를 단어장에 추가한다
	m_WordBook.AddWord(m_strEnglish, m_strKorean);

	// 에디트 컨트롤들을 초기화한다
	m_strEnglish.Empty();
	m_strKorean.Empty();

	UpdateData(FALSE);

	// 영어 단어 에디트 컨트롤로 포커스를 이동한다
	GetDlgItem(IDC_ENGLISH_EDIT)->SetFocus();
}
