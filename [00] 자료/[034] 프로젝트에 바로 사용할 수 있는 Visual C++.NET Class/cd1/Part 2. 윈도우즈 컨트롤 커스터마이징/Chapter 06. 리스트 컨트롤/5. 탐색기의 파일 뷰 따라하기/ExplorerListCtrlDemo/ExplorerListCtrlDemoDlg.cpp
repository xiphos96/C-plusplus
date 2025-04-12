// ExplorerListCtrlDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ExplorerListCtrlDemo.h"
#include "ExplorerListCtrlDemoDlg.h"

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


// CExplorerListCtrlDemoDlg 대화 상자



CExplorerListCtrlDemoDlg::CExplorerListCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExplorerListCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExplorerListCtrlDemoDlg)
	m_nType = 3;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExplorerListCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExplorerListCtrlDemoDlg)
	DDX_Control(pDX, IDC_DRIVE_COMBO, m_DriveCombo);
	DDX_Control(pDX, IDC_EXPLORER_LIST, m_ExplorerListCtrl);
	DDX_Radio(pDX, IDC_ICON_RADIO, m_nType);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExplorerListCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CExplorerListCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ICON_RADIO, OnIconRadio)
	ON_BN_CLICKED(IDC_SMALL_ICON_RADIO, OnSmallIconRadio)
	ON_BN_CLICKED(IDC_LIST_RADIO, OnListRadio)
	ON_BN_CLICKED(IDC_REPORT_RADIO, OnReportRadio)
	ON_BN_CLICKED(IDC_GO_UP_BUTTON, OnGoUpButton)
	ON_CBN_SELCHANGE(IDC_DRIVE_COMBO, OnSelchangeDriveCombo)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_EXPLORER_FILE_SELECT, OnExplorerFileSelecct)
END_MESSAGE_MAP()


// CExplorerListCtrlDemoDlg 메시지 처리기

BOOL CExplorerListCtrlDemoDlg::OnInitDialog()
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

	SHFILEINFO		ShellFileInfo;

	HIMAGELIST hSmallIcon = (HIMAGELIST)::SHGetFileInfo("c:\\", 0, &ShellFileInfo, sizeof(SHFILEINFO),
		SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_SMALLICON);

	CImageList SmallImageList;
	SmallImageList.Attach(hSmallIcon);

	m_DriveCombo.SetImageList(&SmallImageList);

	SmallImageList.Detach();

	DWORD dwDrive = ::GetLogicalDrives();
	int i, nCount;

	for(nCount = i = 0; i < 32; i++)
	{
		if(dwDrive & ((DWORD)0x01 << i))		nCount++;
	}

	char *pDriveName = new char[nCount * 4 + 1];
	::GetLogicalDriveStrings(nCount * 4 + 1, pDriveName);
	
	COMBOBOXEXITEM	ComboExItem;
	ComboExItem.mask = CBEIF_IMAGE | CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
	ComboExItem.iItem = -1;					// Insert at end

	int nDrive = -1;
	for(i = 0; i < nCount; i++)
	{
		ComboExItem.pszText			= pDriveName + i * 4;
		ComboExItem.iImage			= m_ExplorerListCtrl.FindIconIndex(pDriveName, TRUE);
		ComboExItem.iSelectedImage	= ComboExItem.iImage;

		m_DriveCombo.InsertItem(&ComboExItem);

		if(pDriveName[i * 4] == 'C')	nDrive = i;
	}

	delete[] pDriveName;

	m_DriveCombo.SetCurSel(nDrive);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CExplorerListCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExplorerListCtrlDemoDlg::OnPaint() 
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
HCURSOR CExplorerListCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExplorerListCtrlDemoDlg::OnIconRadio() 
{
	// 리스트 컨트롤의 타입을 아이콘 타입으로 변경한다
	m_ExplorerListCtrl.ModifyStyle(LVS_TYPEMASK, LVS_ICON);
}

void CExplorerListCtrlDemoDlg::OnSmallIconRadio() 
{
	// 리스트 컨트롤의 타입을 작은 아이콘 타입으로 변경한다
	m_ExplorerListCtrl.ModifyStyle(LVS_TYPEMASK, LVS_SMALLICON);
}

void CExplorerListCtrlDemoDlg::OnListRadio() 
{
	// 리스트 컨트롤의 타입을 리스트 타입으로 변경한다
	m_ExplorerListCtrl.ModifyStyle(LVS_TYPEMASK, LVS_LIST);
}

void CExplorerListCtrlDemoDlg::OnReportRadio() 
{
	// 리스트 컨트롤의 타입을 리포트 타입으로 변경한다
	m_ExplorerListCtrl.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
}

void CExplorerListCtrlDemoDlg::OnGoUpButton() 
{
	m_ExplorerListCtrl.GoUp();
}

void CExplorerListCtrlDemoDlg::OnSelchangeDriveCombo() 
{
	int nSel = m_DriveCombo.GetCurSel();

	if(nSel == CB_ERR)		return;

	CString strDrive;
	
	m_DriveCombo.GetLBText(nSel, strDrive);
	m_ExplorerListCtrl.ChangeDrive(strDrive);
}

LRESULT CExplorerListCtrlDemoDlg::OnExplorerFileSelecct(WPARAM wParam, LPARAM lParam)
{
	MessageBox((LPCTSTR)lParam, "파일 선택", MB_ICONINFORMATION | MB_OK);
	return 0;
}
