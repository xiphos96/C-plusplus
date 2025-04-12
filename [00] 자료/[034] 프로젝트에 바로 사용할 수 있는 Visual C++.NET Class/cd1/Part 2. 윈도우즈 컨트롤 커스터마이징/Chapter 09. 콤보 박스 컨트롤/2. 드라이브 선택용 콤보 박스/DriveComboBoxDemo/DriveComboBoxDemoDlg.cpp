// DriveComboBoxDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "DriveComboBoxDemo.h"
#include "DriveComboBoxDemoDlg.h"

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


// CDriveComboBoxDemoDlg 대화 상자



CDriveComboBoxDemoDlg::CDriveComboBoxDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDriveComboBoxDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDriveComboBoxDemoDlg)
	m_strCount = _T("");
	m_strCurDrive = _T("");
	m_nIcon = -1;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDriveComboBoxDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDriveComboBoxDemoDlg)
	DDX_Control(pDX, IDC_DRIVE_COMBO, m_DriveCombo);
	DDX_Text(pDX, IDC_COUNT_EDIT, m_strCount);
	DDX_Text(pDX, IDC_CUR_DRIVE_EDIT, m_strCurDrive);
	DDX_Radio(pDX, IDC_BIG_RADIO, m_nIcon);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDriveComboBoxDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDriveComboBoxDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BIG_RADIO, OnBigRadio)
	ON_BN_CLICKED(IDC_SMALL_RADIO, OnSmallRadio)
	ON_CBN_SELCHANGE(IDC_DRIVE_COMBO, OnSelchangeDriveCombo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CDriveComboBoxDemoDlg 메시지 처리기

BOOL CDriveComboBoxDemoDlg::OnInitDialog()
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

	// 현재 드라이브 이미지 크기를 얻는다
	m_nIcon = m_DriveCombo.IsBigIcon() ? 0 : 1;
	// 현재 드라이브 갯수를 얻는다
	m_strCount.Format("%d개의 드라이브가 설치되어 있습니다.", m_DriveCombo.GetDriveCount());

	UpdateData(FALSE);
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CDriveComboBoxDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDriveComboBoxDemoDlg::OnPaint() 
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
HCURSOR CDriveComboBoxDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDriveComboBoxDemoDlg::OnBigRadio() 
{
	// 큰 아이콘으로 드라이브 아이콘을 변경한다
	m_nIcon = 0;
	m_DriveCombo.SetBigIcon(TRUE);
}

void CDriveComboBoxDemoDlg::OnSmallRadio() 
{
	// 작은 아이콘으로 드라이브 아이콘을 변경한다
	m_nIcon = 1;
	m_DriveCombo.SetBigIcon(FALSE);
}

void CDriveComboBoxDemoDlg::OnSelchangeDriveCombo() 
{
	// 현재 선택된 항목 번호를 얻는다
	int nSel = m_DriveCombo.GetCurSel();
	// 만약 선택된 항목이 없다면 리턴
	if(nSel == CB_ERR)		return;

	// 현재 선택된 항목의 텍스트(드라이브 이름)를 얻는다
	m_DriveCombo.GetLBText(nSel, m_strCurDrive);

	UpdateData(FALSE);
}
