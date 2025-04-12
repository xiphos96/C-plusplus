// HTMLCollectorDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "HTMLCollectorDemo.h"
#include "HTMLCollectorDemoDlg.h"

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


// CHTMLCollectorDemoDlg 대화 상자



CHTMLCollectorDemoDlg::CHTMLCollectorDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHTMLCollectorDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHTMLCollectorDemoDlg)
	m_strSource = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CHTMLCollectorDemoDlg::~CHTMLCollectorDemoDlg()
{
	// 이미지 리스트를 제거한다
	m_ImageList.DeleteImageList();
}

void CHTMLCollectorDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHTMLCollectorDemoDlg)
	DDX_Control(pDX, IDC_IE_LIST, m_IEList);
	DDX_Control(pDX, IDC_FINDER_STATIC, m_HTMLCollector);
	DDX_Text(pDX, IDC_SOURCE_EDIT, m_strSource);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHTMLCollectorDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CHTMLCollectorDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_REFRESH_BUTTON, OnRefreshButton)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, OnSaveButton)
	ON_NOTIFY(NM_DBLCLK, IDC_IE_LIST, OnDblclkIeList)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_IE_FINDER_START, OnIEFinderStart)
	ON_MESSAGE(WM_IE_FINDER_END, OnIEFinderEnd)
	ON_MESSAGE(WM_IE_FINDER_SELECT, OnIEFinderSelect)
END_MESSAGE_MAP()


// CHTMLCollectorDemoDlg 메시지 처리기

BOOL CHTMLCollectorDemoDlg::OnInitDialog()
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

	// 비트맵 리소스로부터 이미지 리스트를 생성한다
	CBitmap bmpIE;
	bmpIE.LoadBitmap(IDB_WEB_PAGE);
	m_ImageList.Create(16, 16, ILC_COLORDDB|ILC_MASK, 16, 1);
	m_ImageList.Add(&bmpIE, RGB(198, 198, 198));
	
	// 웹브라우저 리스트에 이미지 리스트를 설정한다
	m_IEList.SetImageList(&m_ImageList, LVSIL_SMALL);
	// 웹브라우저 리스트의 확장 속성을 설정한다
	m_IEList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_FLATSB);

	// 웹브라우저 리스트에 컬럼을 추가한다
	m_IEList.InsertColumn(0, "제목", LVCFMT_LEFT, 300, 0);
	m_IEList.InsertColumn(1, "주소", LVCFMT_LEFT, 300, 1);

	// 현재 열려 있는 웹브라우저를 검색하여 배열을 생성한다
	m_HTMLCollector.RefreshIEArray();

	// 검색된 웹브라우저의 갯수를 얻는다
	int i, nSize = m_HTMLCollector.GetIEArrayCount(), nItem;
	SIEWnd *pIEWnd;

	// 검색된 모든 웹브라우저에 대해서
	for(i = 0; i < nSize; i++)
	{
		// 웹브라우저 정보 구조체를 얻는다
		pIEWnd = m_HTMLCollector.GetIEWnd(i);

		// 웹브라우저의 제목으로 항목을 추가한다
		nItem = m_IEList.InsertItem(i, pIEWnd->strTitle, 0);
		// 웹브라우저의 주소를 두번째 항목 텍스트로 설정한다
		m_IEList.SetItemText(nItem, 1, pIEWnd->strAddress);
	}

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CHTMLCollectorDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHTMLCollectorDemoDlg::OnPaint() 
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
HCURSOR CHTMLCollectorDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 웹브라우저 리스트를 다시 구성하는 함수
void CHTMLCollectorDemoDlg::OnRefreshButton() 
{
	// 웹브라우저 리스트를 지운다
	m_IEList.DeleteAllItems();

	// 현재 열려 있는 웹브라우저를 다시 검색하여 배열을 생성한다
	m_HTMLCollector.RefreshIEArray();

	// 검색된 웹브라우저의 갯수를 얻는다
	int i, nSize = m_HTMLCollector.GetIEArrayCount(), nItem;
	SIEWnd *pIEWnd;

	// 검색된 모든 웹브라우저에 대해서
	for(i = 0; i < nSize; i++)
	{
		// 웹브라우저 정보 구조체를 얻는다
		pIEWnd = m_HTMLCollector.GetIEWnd(i);

		// 웹브라우저의 제목으로 항목을 추가한다
		nItem = m_IEList.InsertItem(i, pIEWnd->strTitle, 0);
		// 웹브라우저의 주소를 두번째 항목 텍스트로 설정한다
		m_IEList.SetItemText(nItem, 1, pIEWnd->strAddress);
	}
}

// HTML 소스를 파일로 저장하는 함수
void CHTMLCollectorDemoDlg::OnSaveButton() 
{
	// 획득된 HTML 소스를 얻는다
	LPCTSTR pSource = m_HTMLCollector.GetSource();

	// 만약 HTML 소스의 길이가 0이라면 리턴한다
	if(strlen(pSource) == 0)
	{
		MessageBox("저장할 소스가 없습니다.");
		return;
	}

	// 파일 다이얼로그를 열어 HTML 소스를 저장할 파일 경로를 입력 받는다
	CFileDialog dlg(FALSE, "htm", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"HTML 파일(*.htm)|*.htm|텍스트 파일(*.txt)|*.txt|모든 파일(*.*)|*.*||", this);

	if(dlg.DoModal() == IDOK)
	{
		// 입력된 파일 경로에 텍스트 파일을 생성하여 연다
		FILE *pFile = fopen(dlg.GetPathName(), "wt");

		// 획득된 HTML 소스를 텍스트 파일에 저장한다
		fwrite(pSource, strlen(pSource), 1, pFile);

		// 텍스트 파일을 닫는다
		fclose(pFile);
	}
}

// 웹브라우저 리스트를 더블클릭 하였을 때 실행되는 함수
void CHTMLCollectorDemoDlg::OnDblclkIeList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// 선택된 항목의 위치를 얻는다
	POSITION pos = m_IEList.GetFirstSelectedItemPosition();
	
	// 만약 선택된 항목이 없다면 메시지 박스를 출력한다
	if(pos == NULL)
	{
		MessageBox("원하는 사이트를 보여주는 웹브라우저를 선택하세요.");
	}
	else
	{
		// 선택된 항목의 번호를 얻는다
		int nSelected = m_IEList.GetNextSelectedItem(pos);

		// 해당 항목의 소스를 HTML 소스 획득 클래스에서 얻는다
		m_strSource = m_HTMLCollector.GetSource(nSelected);

		// 다이얼로그의 에디트 박스에 HTML 소스를 설정한다
		UpdateData(FALSE);
	}
	
	*pResult = 0;
}

// 웹브라우저 선택이 시작되었을 때 실행되는 함수
LRESULT CHTMLCollectorDemoDlg::OnIEFinderStart(WPARAM wParam, LPARAM lParam)
{
	// 다이얼로그를 최소화 시킨다
	ShowWindow(SW_MINIMIZE);
	return 1;
}

// 웹브라우저 선택이 끝났을 때 실행되는 함수
LRESULT CHTMLCollectorDemoDlg::OnIEFinderEnd(WPARAM wParam, LPARAM lParam)
{
	// 다이얼로그를 복원시킨다
	ShowWindow(SW_RESTORE);
	return 1;
}

// 웹브라우저가 선택되고 소스를 획득한 후 실행되는 함수
LRESULT CHTMLCollectorDemoDlg::OnIEFinderSelect(WPARAM wParam, LPARAM lParam)
{
	// 인자로 넘어오는 HTML 소스 획득 클래스 포인터를 저장한다
	CHTMLCollector *pCollector = (CHTMLCollector*)lParam;

	// HTML 소스 획득 클래스에서 HTML 소스를 얻는다
	m_strSource = pCollector->GetSource();

	// 다이얼로그의 에디트 박스에 HTML 소스를 설정한다
	UpdateData(FALSE);
	return 1;
}
