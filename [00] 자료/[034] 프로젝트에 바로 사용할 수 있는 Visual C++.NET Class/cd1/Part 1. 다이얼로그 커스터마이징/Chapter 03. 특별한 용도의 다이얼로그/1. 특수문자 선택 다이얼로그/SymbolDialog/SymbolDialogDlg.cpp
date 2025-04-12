// SymbolDialogDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "SymbolDialog.h"
#include "SymbolDialogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "SymbolDlg.h"

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


// CSymbolDialogDlg 대화 상자



CSymbolDialogDlg::CSymbolDialogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSymbolDialogDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSymbolDialogDlg)
	m_strCode = _T("");
	m_nType = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSymbolDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSymbolDialogDlg)
	DDX_Control(pDX, IDC_FONT_COMBO, m_FontCombo);
	DDX_Text(pDX, IDC_CODE_EDIT, m_strCode);
	DDX_Radio(pDX, IDC_TYPE_RADIO1, m_nType);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSymbolDialogDlg, CDialog)
	//{{AFX_MSG_MAP(CSymbolDialogDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SELECT_BUTTON, OnSelectButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CSymbolDialogDlg 메시지 처리기

// 시스템의 폰트들을 콤보 박스에 추가하는 함수
int CALLBACK EnumFontsProc(CONST LOGFONT *lplf, CONST TEXTMETRIC *lptm, DWORD dwType, LPARAM lParam) 
{
	CComboBox *pCombo = (CComboBox*)lParam;
	pCombo->AddString(lplf->lfFaceName);

	return TRUE; 
} 

BOOL CSymbolDialogDlg::OnInitDialog()
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

	// 시스템의 폰트를 콤보 박스에 추가한다
	CDC *pDC = GetDC();	
    EnumFonts(pDC->m_hDC, NULL, (FONTENUMPROC)EnumFontsProc, (LPARAM)&m_FontCombo); 
	ReleaseDC(pDC);
 
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CSymbolDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSymbolDialogDlg::OnPaint() 
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
HCURSOR CSymbolDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSymbolDialogDlg::OnSelectButton() 
{
	UpdateData(TRUE);

	// 폰트가 선택 되었는지 확인한다
	if(m_FontCombo.GetCurSel() == CB_ERR)
	{
		MessageBox("폰트 이름을 선택하세요.", "특수 문자표", MB_OK);
		return;
	}

	// 문자 코드를 선택했는지 확인한다
	if(m_nType < 0)
	{
		MessageBox("문자 타입을 선택하세요.", "특수 문자표", MB_OK);
		return;
	}

	// 특수 문자 다이얼로그
	CSymbolDlg dlg;

	// 선택된 폰트 이름을 설정한다
	CString strFontName;
	m_FontCombo.GetLBText(m_FontCombo.GetCurSel(), strFontName);
	dlg.SetFontName(strFontName);

	// 선택된 문자 코드를 설정한다
	dlg.SetCodeType(m_nType == 1);

	// 다이얼로그를 띄운다
	if(dlg.DoModal() == IDOK)
	{
		// 선택된 문자 코드를 얻어 온다
		m_strCode = dlg.GetSelectedChar();

		UpdateData(FALSE);
	}	
}
