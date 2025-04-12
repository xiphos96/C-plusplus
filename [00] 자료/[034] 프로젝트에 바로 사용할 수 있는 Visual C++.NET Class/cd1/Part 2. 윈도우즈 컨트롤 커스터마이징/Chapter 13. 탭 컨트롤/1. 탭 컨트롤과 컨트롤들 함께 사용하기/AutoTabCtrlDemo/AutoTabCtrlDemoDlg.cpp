// AutoTabCtrlDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "AutoTabCtrlDemo.h"
#include "AutoTabCtrlDemoDlg.h"

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


// CAutoTabCtrlDemoDlg 대화 상자



CAutoTabCtrlDemoDlg::CAutoTabCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutoTabCtrlDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAutoTabCtrlDemoDlg)
	m_strName = _T("");
	m_strMoney = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutoTabCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutoTabCtrlDemoDlg)
	DDX_Control(pDX, IDC_OUTGO_LIST, m_OutgoList);
	DDX_Control(pDX, IDC_INCOME_LIST, m_IncomeList);
	DDX_Control(pDX, IDC_AUTO_TAB, m_AutoTab);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
	DDX_Text(pDX, IDC_MONEY_EDIT, m_strMoney);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAutoTabCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CAutoTabCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BUTTON, OnAddButton)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_AT_SELCHANGE, OnATSelChange)
END_MESSAGE_MAP()


// CAutoTabCtrlDemoDlg 메시지 처리기

BOOL CAutoTabCtrlDemoDlg::OnInitDialog()
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

	// 세개의 탭을 추가한다
	m_AutoTab.InsertItem(0, "수입");
	m_AutoTab.InsertItem(1, "지출");
	m_AutoTab.InsertItem(2, "합계");

	// 각 탭에 속하는 컨트롤들을 자동 탭 컨트롤에 설정한다
	// 이때, 0번 탭과 1번 탭에 동시에 나오는 컨트롤들은 0번과 1번 탭에 모두 설정한다
	m_AutoTab.AddControl(0, &m_IncomeList);
	m_AutoTab.AddControl(0, GetDlgItem(IDC_NAME_STATIC));
	m_AutoTab.AddControl(0, GetDlgItem(IDC_NAME_EDIT));
	m_AutoTab.AddControl(0, GetDlgItem(IDC_MONEY_STATIC));
	m_AutoTab.AddControl(0, GetDlgItem(IDC_MONEY_EDIT));
	m_AutoTab.AddControl(0, GetDlgItem(IDC_ADD_BUTTON));
	m_AutoTab.AddControl(1, &m_OutgoList);
	m_AutoTab.AddControl(1, GetDlgItem(IDC_NAME_STATIC));
	m_AutoTab.AddControl(1, GetDlgItem(IDC_NAME_EDIT));
	m_AutoTab.AddControl(1, GetDlgItem(IDC_MONEY_STATIC));
	m_AutoTab.AddControl(1, GetDlgItem(IDC_MONEY_EDIT));
	m_AutoTab.AddControl(1, GetDlgItem(IDC_ADD_BUTTON));
	m_AutoTab.AddControl(2, GetDlgItem(IDC_REPORT_STATIC));

	// 0번 탭을 선택한다
	m_AutoTab.SetCurSel(0);
	
	// 수입 리스트 컨트롤에 컬럼을 추가한다
	m_IncomeList.InsertColumn(0, "항목 이름", LVCFMT_CENTER, 200);
	m_IncomeList.InsertColumn(1, "금액", LVCFMT_RIGHT, 100);

	// 지출 리스트 컨트롤에 컬럼을 추가한다
	m_OutgoList.InsertColumn(0, "항목 이름", LVCFMT_CENTER, 200);
	m_OutgoList.InsertColumn(1, "금액", LVCFMT_RIGHT, 100);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CAutoTabCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAutoTabCtrlDemoDlg::OnPaint() 
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
HCURSOR CAutoTabCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAutoTabCtrlDemoDlg::OnAddButton() 
{
	// 입력된 데이터를 멤버 변수에 업데이트 한다.
	UpdateData(TRUE);

	// 현재 선택된 탭 번호를 얻는다
	int nTab = m_AutoTab.GetCurSel(), nItem;

	switch(nTab)
	{
	case 0:
		// 만약 수입 탭이라면 항목 이름을 수입 리스트에 추가한다
		nItem = m_IncomeList.InsertItem(m_IncomeList.GetItemCount(), m_strName);
		// 항목의 금액을 설정한다
		m_IncomeList.SetItemText(nItem, 1, m_strMoney);
		break;
	case 1:
		// 만약 지출 탭이라면 항목 이름을 지출 리스트에 추가한다
		nItem = m_OutgoList.InsertItem(m_OutgoList.GetItemCount(), m_strName);
		// 항목의 금액을 설정한다
		m_OutgoList.SetItemText(nItem, 1, m_strMoney);
		break;
	}

	// 항목 이름 입력 에디트 컨트롤에 포커스를 설정한다
	GetDlgItem(IDC_NAME_EDIT)->SetFocus();
}

// 자동 탭 컨트롤의 탭 변경시 호출되는 함수
LRESULT CAutoTabCtrlDemoDlg::OnATSelChange(WPARAM wParam, LPARAM lParam) 
{
	switch(lParam)
	{
	case 0:
	case 1:
		// 0번과 1번 탭이 선택되면 에디트 박스들의 텍스트를 초기화한다
		GetDlgItem(IDC_NAME_EDIT)->SetWindowText("");
		GetDlgItem(IDC_MONEY_EDIT)->SetWindowText("");
		break;
	case 2:
		{
			// 2번 탭이 선택되면
			int i, nSize, nIncome, nOutgo, nSum, nValue;
			CString strText;

			nSum = nIncome = nOutgo = 0;

			// 수입 리스트에 추가된 수입 항목들의 금액들을 합산한다
			nSize = m_IncomeList.GetItemCount();
			for(i = 0; i < nSize; i++)
			{
				strText = m_IncomeList.GetItemText(i, 1);
				nValue = ::atoi(strText);

				nIncome += nValue;
			}

			// 지출 리스트에 추가된 지출 항목들의 금액들을 합산한다
			nSize = m_OutgoList.GetItemCount();
			for(i = 0; i < nSize; i++)
			{
				strText = m_OutgoList.GetItemText(i, 1);
				nValue = ::atoi(strText);

				nOutgo += nValue;
			}

			// 수입에서 지출을 감산하여 합계를 구한다
			nSum = nIncome - nOutgo;

			// 내역을 문자열로 생성한다
			strText.Format("\n========= 수입과 지출 =========\n\n총 수입 : %9d\n\n총 지출 : %9d\n\n==============================\n\n총 합계 : %9d",
				nIncome, nOutgo, nSum);

			// 스태틱 컨트롤에 합계 내역을 출력한다
			GetDlgItem(IDC_REPORT_STATIC)->SetWindowText(strText);
		}
		break;
	}

	return 0;
}
