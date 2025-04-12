// FontEffectDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "FontEffectDemo.h"
#include "FontEffectDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <math.h>


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


// CFontEffectDemoDlg 대화 상자



CFontEffectDemoDlg::CFontEffectDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFontEffectDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFontEffectDemoDlg)
	m_bOutLine = FALSE;
	m_nShapeType = 0;
	m_strText = _T("폰트 효과 테스트");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFontEffectDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFontEffectDemoDlg)
	DDX_Control(pDX, IDC_EFFECT_STATIC, m_FontEffect);
	DDX_Control(pDX, IDC_SHAPE_BUTTON3, m_btnShape3);
	DDX_Control(pDX, IDC_SHAPE_BUTTON2, m_btnShape2);
	DDX_Control(pDX, IDC_SHAPE_BUTTON1, m_btnShape1);
	DDX_Check(pDX, IDC_OUTLINE_CHECK, m_bOutLine);
	DDX_Radio(pDX, IDC_SHAPE_BUTTON1, m_nShapeType);
	DDX_Text(pDX, IDC_TEXT_EDIT, m_strText);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFontEffectDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CFontEffectDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHAPE_BUTTON1, OnShapeButton1)
	ON_BN_CLICKED(IDC_SHAPE_BUTTON2, OnShapeButton2)
	ON_BN_CLICKED(IDC_SHAPE_BUTTON3, OnShapeButton3)
	ON_BN_CLICKED(IDC_OUTLINE_CHECK, OnOutlineCheck)
	ON_BN_CLICKED(IDC_REFRESH_BUTTON, OnRefreshButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CFontEffectDemoDlg 메시지 처리기

BOOL CFontEffectDemoDlg::OnInitDialog()
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

	m_btnShape1.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_SHAPE1)));
	m_btnShape2.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_SHAPE2)));
	m_btnShape3.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_SHAPE3)));

	OnRefreshButton();

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CFontEffectDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFontEffectDemoDlg::OnPaint() 
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
HCURSOR CFontEffectDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFontEffectDemoDlg::OnShapeButton1() 
{
	// 사인 그래프를 그리는 효과 함수를 설정한다
	m_FontEffect.SetFunction(ShapeFunc1, TRUE);
}

void CFontEffectDemoDlg::OnShapeButton2() 
{
	// 아래쪽으로 높이가 증가하는 효과 함수를 설정한다
	m_FontEffect.SetFunction(ShapeFunc2, TRUE);
}

void CFontEffectDemoDlg::OnShapeButton3() 
{
	// 위족과 아래쪽으로 함께 높이가 증가하는 효과 함수를 설정한다
	m_FontEffect.SetFunction(ShapeFunc3, TRUE);
}

void CFontEffectDemoDlg::OnOutlineCheck() 
{
	UpdateData(TRUE);

	// 외곽선 옵션을 변경한다
	m_FontEffect.SetOutLine(m_bOutLine);
}

void CFontEffectDemoDlg::OnRefreshButton() 
{
	UpdateData(TRUE);

	// 텍스트를 변경한다
	m_FontEffect.SetText(m_strText);

	switch(m_nShapeType)
	{
	case 0:
		// 사인 그래프를 그리는 효과 함수를 설정한다
		m_FontEffect.SetFunction(ShapeFunc1, TRUE);
		break;

	case 1:
		// 아래쪽으로 높이가 증가하는 효과 함수를 설정한다
		m_FontEffect.SetFunction(ShapeFunc2, TRUE);
		break;

	case 2:
		// 위족과 아래쪽으로 함께 높이가 증가하는 효과 함수를 설정한다
		m_FontEffect.SetFunction(ShapeFunc3, TRUE);
		break;
	}

	// 경로를 다시 구성하고 화면을 갱신한다
	m_FontEffect.BuildEffect();
}

// 사인 그래프를 그리는 효과 함수
void CFontEffectDemoDlg::ShapeFunc1(int nSize, CPoint *pPoint, CSize TextSize)
{
	double dSin;
	for(int i = 0; i < nSize; i++)
	{
		dSin = sin(2 * 3.1415926535 * pPoint[i].x / TextSize.cx);
		dSin *= 30;
		pPoint[i].y = (int)(pPoint[i].y + dSin);
	}
}

// 아래쪽으로 높이가 증가하는 효과 함수
void CFontEffectDemoDlg::ShapeFunc2(int nSize, CPoint *pPoint, CSize TextSize)
{
	for(int i = 0; i < nSize; i++)
	{
		pPoint[i].y = (int)(pPoint[i].y * ((double)pPoint[i].x * 4 / TextSize.cx + 1));
	}
}

// 위족과 아래쪽으로 함께 높이가 증가하는 효과 함수
void CFontEffectDemoDlg::ShapeFunc3(int nSize, CPoint *pPoint, CSize TextSize)
{
	for(int i = 0; i < nSize; i++)
	{
		pPoint[i].y -= TextSize.cy / 2;
		pPoint[i].y = (int)(pPoint[i].y * ((double)pPoint[i].x * 4 / TextSize.cx + 1));
	}
}
