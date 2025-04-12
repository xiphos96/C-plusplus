// FlatComboBoxDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "FlatComboBoxDemo.h"
#include "FlatComboBoxDemoDlg.h"

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


// CFlatComboBoxDemoDlg 대화 상자



CFlatComboBoxDemoDlg::CFlatComboBoxDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFlatComboBoxDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFlatComboBoxDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFlatComboBoxDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFlatComboBoxDemoDlg)
	DDX_Control(pDX, IDC_DROPLIST_COMBO, m_DropListCombo);
	DDX_Control(pDX, IDC_DROPDOWN_COMBO, m_DropDownCombo);
	DDX_Control(pDX, IDC_AUTOCOMPLETE_COMBO, m_AutoComplete);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFlatComboBoxDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CFlatComboBoxDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DROPLIST_CHECK, OnDroplistCheck)
	ON_BN_CLICKED(IDC_DROPDOWN_CHECK, OnDropdownCheck)
	ON_BN_CLICKED(IDC_AUTOCOMPLETE_CHECK, OnAutocompleteCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CFlatComboBoxDemoDlg 메시지 처리기

BOOL CFlatComboBoxDemoDlg::OnInitDialog()
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

	// 드롭 리스트 형식 콤보 박스에 문자열들을 추가한다
	m_DropListCombo.AddString("대한이 소한집에 왔다가 얼어 죽는다.");
	m_DropListCombo.AddString("2월 바람에 검은 소 뿔이 오그라진다.");
	m_DropListCombo.AddString("꽃샘추위에 설 늙은이 얼어 죽는다.");
	m_DropListCombo.AddString("봄비는 한 번 내릴때마다 따뜻해진다.");
	m_DropListCombo.AddString("햇무리, 달무리가 나타나면 비 올 징조이다.");
	m_DropListCombo.AddString("개미가 떼지어 이사를 하면 비 올 징조이다.");
	m_DropListCombo.AddString("7월 장마 끝물의 참외는 거저 줘도 안먹는다.");
	m_DropListCombo.AddString("처서가 지나면 모기도 입이 비뚤어진다.");
	m_DropListCombo.AddString("가을 안개는 곡식이 늘고 봄안개는 곡식이 준다.");
	m_DropListCombo.AddString("가을 동풍은 우물을 말린다.");
	m_DropListCombo.AddString("가을비는 한번 올때마다 추워진다.");
	m_DropListCombo.AddString("겨울에 눈이 많이 오면 보리 풍년이 든다.");
	
	// 드롭 다운 형식 콤보 박스에 문자열들을 추가한다
	m_DropDownCombo.AddString("대한이 소한집에 왔다가 얼어 죽는다.");
	m_DropDownCombo.AddString("2월 바람에 검은 소 뿔이 오그라진다.");
	m_DropDownCombo.AddString("꽃샘추위에 설 늙은이 얼어 죽는다.");
	m_DropDownCombo.AddString("봄비는 한 번 내릴때마다 따뜻해진다.");
	m_DropDownCombo.AddString("햇무리, 달무리가 나타나면 비 올 징조이다.");
	m_DropDownCombo.AddString("개미가 떼지어 이사를 하면 비 올 징조이다.");
	m_DropDownCombo.AddString("7월 장마 끝물의 참외는 거저 줘도 안먹는다.");
	m_DropDownCombo.AddString("처서가 지나면 모기도 입이 비뚤어진다.");
	m_DropDownCombo.AddString("가을 안개는 곡식이 늘고 봄안개는 곡식이 준다.");
	m_DropDownCombo.AddString("가을 동풍은 우물을 말린다.");
	m_DropDownCombo.AddString("가을비는 한번 올때마다 추워진다.");
	m_DropDownCombo.AddString("겨울에 눈이 많이 오면 보리 풍년이 든다.");
	
	// 자동 완성 드롭 다운 리스트에 문자열들을 추가한다
	m_AutoComplete.AddString("In the beginning, God created the heavens and the earth.");
	m_AutoComplete.AddString("The earth was without form and void, and darkness was over the face of the deep.");
	m_AutoComplete.AddString("And the Spirit of God was hovering over the face of the waters.");
	m_AutoComplete.AddString("And God said, \"Let there be light,\" and there was light.");
	m_AutoComplete.AddString("And God saw that the light was good.");
	m_AutoComplete.AddString("And God separated the light from the darkness.");
	m_AutoComplete.AddString("God called the light Day, and the darkness he called Night.");
	m_AutoComplete.AddString("And there was evening and there was morning, the first day.");
	m_AutoComplete.AddString("And God said, \"Let there be an expanse in the midst of the waters,");
	m_AutoComplete.AddString("and let it separate the waters from the waters.\"");
	m_AutoComplete.AddString("And God made the expanse and separated the waters");
	m_AutoComplete.AddString("that were under the expanse from the waters that were above the expanse.");
	m_AutoComplete.AddString("And it was so.");
	m_AutoComplete.AddString("And God called the expanse Heaven.");
	
	// 체크 박스들을 체크된 상태로 만든다
	((CButton*)GetDlgItem(IDC_DROPLIST_CHECK))->SetCheck(1);
	((CButton*)GetDlgItem(IDC_DROPDOWN_CHECK))->SetCheck(1);
	((CButton*)GetDlgItem(IDC_AUTOCOMPLETE_CHECK))->SetCheck(1);

	// 자동 완성 기능을 설정한다
	m_AutoComplete.EnableAutoComplete(TRUE);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CFlatComboBoxDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFlatComboBoxDemoDlg::OnPaint() 
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
HCURSOR CFlatComboBoxDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFlatComboBoxDemoDlg::OnDroplistCheck() 
{
	// 드롭 리스트 콤보박스 활성화 체크 버튼의 상태에 따라 드롭 리스트 콤보박스를 활성화 시킨다
	m_DropListCombo.EnableWindow(((CButton*)GetDlgItem(IDC_DROPLIST_CHECK))->GetCheck());
}

void CFlatComboBoxDemoDlg::OnDropdownCheck() 
{
	// 드롭 다운 콤보박스 활성화 체크 버튼의 상태에 따라 드롭 다운 콤보박스를 활성화 시킨다
	m_DropDownCombo.EnableWindow(((CButton*)GetDlgItem(IDC_DROPDOWN_CHECK))->GetCheck());
}

void CFlatComboBoxDemoDlg::OnAutocompleteCheck() 
{
	// 자동 완성 콤보박스 활성화 체크 버튼의 상태에 따라 자동 완성 콤보박스를 활성화 시킨다
	m_AutoComplete.EnableWindow(((CButton*)GetDlgItem(IDC_AUTOCOMPLETE_CHECK))->GetCheck());
}
