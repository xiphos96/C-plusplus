// DDTreeCtrlDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "DDTreeCtrlDemo.h"
#include "DDTreeCtrlDemoDlg.h"

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


// CDDTreeCtrlDemoDlg 대화 상자



CDDTreeCtrlDemoDlg::CDDTreeCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDDTreeCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDDTreeCtrlDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDDTreeCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDDTreeCtrlDemoDlg)
	DDX_Control(pDX, IDC_TARGET_TREE, m_TargetTree);
	DDX_Control(pDX, IDC_ALL_TREE, m_AllTree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDDTreeCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDDTreeCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CDDTreeCtrlDemoDlg 메시지 처리기

BOOL CDDTreeCtrlDemoDlg::OnInitDialog()
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

	// 이미지 리스트를 생성한다
	m_TreeImageList.Create(IDB_ITEM_BITMAP, 16, 1, RGB(255, 255, 255));

	// 좌측 트리 컨트롤에 이미지 리스트를 설정한다
	m_AllTree.SetImageList(&m_TreeImageList, TVSIL_NORMAL);

	// 우측 트리 컨트롤에 이미지 리스트를 설정한다
	m_TargetTree.SetImageList(&m_TreeImageList, LVSIL_NORMAL);

	// 좌측 트리 컨트롤에 항목들을 추가한다
	HTREEITEM hRoot = m_AllTree.InsertItem("동물", 9, 10);
	HTREEITEM hFish = m_AllTree.InsertItem("어류", 9, 10, hRoot);
	HTREEITEM hBird = m_AllTree.InsertItem("조류", 9, 10, hRoot);
	HTREEITEM hMammal = m_AllTree.InsertItem("포유류", 9, 10, hRoot);
	HTREEITEM hCrustacea = m_AllTree.InsertItem("갑각류", 9, 10, hRoot);

	m_AllTree.InsertItem("물고기", 0, 0, hFish);
	m_AllTree.InsertItem("파랑새", 1, 1, hBird);
	m_AllTree.InsertItem("토끼", 2, 2, hMammal);
	m_AllTree.InsertItem("낙타", 3, 3, hMammal);
	m_AllTree.InsertItem("꽃게", 4, 4, hCrustacea);
	m_AllTree.InsertItem("당나귀", 5, 5, hMammal);
	m_AllTree.InsertItem("강아지", 6, 6, hMammal);
	m_AllTree.InsertItem("펜더곰", 7, 7, hMammal);
	m_AllTree.InsertItem("펭귄", 8, 8, hMammal);

	// 루트 노드를 확장한다
	m_AllTree.Expand(hRoot, TVE_EXPAND);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CDDTreeCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDDTreeCtrlDemoDlg::OnPaint() 
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
HCURSOR CDDTreeCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
