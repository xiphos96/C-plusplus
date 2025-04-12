// FlatHeaderCtrlDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "FlatHeaderCtrlDemo.h"
#include "FlatHeaderCtrlDemoDlg.h"

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


// CFlatHeaderCtrlDemoDlg 대화 상자



CFlatHeaderCtrlDemoDlg::CFlatHeaderCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFlatHeaderCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFlatHeaderCtrlDemoDlg)
	m_strName = _T("");
	m_strAge = _T("");
	m_strAddr = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFlatHeaderCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFlatHeaderCtrlDemoDlg)
	DDX_Control(pDX, IDC_FLAT_LIST, m_FlatList);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
	DDX_Text(pDX, IDC_AGE_EDIT, m_strAge);
	DDX_Text(pDX, IDC_ADDR_EDIT, m_strAddr);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFlatHeaderCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CFlatHeaderCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BUTTON, OnAddButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CFlatHeaderCtrlDemoDlg 메시지 처리기

BOOL CFlatHeaderCtrlDemoDlg::OnInitDialog()
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

	// 리스트 컨트롤에 컬럼을 추가한다
	m_FlatList.InsertColumn(0, "이름", LVCFMT_RIGHT, 120);
	m_FlatList.InsertColumn(1, "나이", LVCFMT_CENTER, 80);
	m_FlatList.InsertColumn(2, "주소", LVCFMT_LEFT, 300);

	// 리스트 컨트롤의 평면 헤더에 설정할 이미지를 설정한다
	m_FlatList.SetHeaderImage(IDB_HEADER_BITMAP, 16, 1);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CFlatHeaderCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFlatHeaderCtrlDemoDlg::OnPaint() 
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
HCURSOR CFlatHeaderCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFlatHeaderCtrlDemoDlg::OnAddButton() 
{
	// 추가 버튼을 클릭하면
	// 현재 입력된 내용을 리스트 컨트롤에 추가한다
	UpdateData(TRUE);

	// 내용 확인
	if(m_strName.IsEmpty())
	{
		MessageBox("이름을 입력하세요.");
		GetDlgItem(IDC_NAME_EDIT)->SetFocus();
		return;
	}
	if(m_strAge.IsEmpty())
	{
		MessageBox("나이를 입력하세요.");
		GetDlgItem(IDC_AGE_EDIT)->SetFocus();
		return;
	}
	if(m_strAddr.IsEmpty())
	{
		MessageBox("주소를 입력하세요.");
		GetDlgItem(IDC_ADDR_EDIT)->SetFocus();
		return;
	}

	// 항목 추가
	int nItem = m_FlatList.InsertItem(m_FlatList.GetItemCount(), m_strName);
	m_FlatList.SetItemText(nItem, 1, m_strAge);
	m_FlatList.SetItemText(nItem, 2, m_strAddr);
}
