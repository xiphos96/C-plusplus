// ExplorerTreeCtrlDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ExplorerTreeCtrlDemo.h"
#include "ExplorerTreeCtrlDemoDlg.h"

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


// CExplorerTreeCtrlDemoDlg 대화 상자



CExplorerTreeCtrlDemoDlg::CExplorerTreeCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExplorerTreeCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExplorerTreeCtrlDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExplorerTreeCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExplorerTreeCtrlDemoDlg)
	DDX_Control(pDX, IDC_EXPLORER_TREE, m_ExplorerTree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExplorerTreeCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CExplorerTreeCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_EXPLORER_TREE, OnClickExplorerTree)
	ON_NOTIFY(TVN_SELCHANGED, IDC_EXPLORER_TREE, OnSelchangedExplorerTree)
	ON_BN_CLICKED(IDC_SELECT_BUTTON, OnSelectButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CExplorerTreeCtrlDemoDlg 메시지 처리기

BOOL CExplorerTreeCtrlDemoDlg::OnInitDialog()
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

	// "바탕화면" 항목을 확장한다
	m_ExplorerTree.Expand(m_ExplorerTree.GetRootItem(), TVE_EXPAND);

	// 현재 실행 경로를 얻는다
	CString strCurPath;
	::GetCurrentDirectory(MAX_PATH, strCurPath.GetBuffer(MAX_PATH));
	strCurPath.ReleaseBuffer();

	// 디렉토리 트리에서 현재 실행 경로를 선택한다
	m_ExplorerTree.SelectPath(strCurPath);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CExplorerTreeCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExplorerTreeCtrlDemoDlg::OnPaint() 
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
HCURSOR CExplorerTreeCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExplorerTreeCtrlDemoDlg::OnClickExplorerTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CString strPath;

	// 현재 선택된 디렉토리의 경로를 얻는다
	m_ExplorerTree.GetSelectedPath(strPath);

	// 에디트 박스에 설정한다
	GetDlgItem(IDC_PATH_EDIT)->SetWindowText(strPath);

	*pResult = 0;
}

void CExplorerTreeCtrlDemoDlg::OnSelchangedExplorerTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	// 새로 선택된 항목의 경로를 얻는다
	CString strPath;
	m_ExplorerTree.GetPath(pNMTreeView->itemNew.hItem, strPath);

	// 에디트 박스에 설정한다
	GetDlgItem(IDC_PATH_EDIT)->SetWindowText(strPath);

	*pResult = 0;
}

void CExplorerTreeCtrlDemoDlg::OnSelectButton() 
{
	// 에디트 박스에 입력된 경로를 얻는다
	CString strPath;
	GetDlgItem(IDC_PATH_EDIT)->GetWindowText(strPath);

	// 디렉토리 트리에서 해당 경로를 선택한다
	m_ExplorerTree.SelectPath(strPath);
}
