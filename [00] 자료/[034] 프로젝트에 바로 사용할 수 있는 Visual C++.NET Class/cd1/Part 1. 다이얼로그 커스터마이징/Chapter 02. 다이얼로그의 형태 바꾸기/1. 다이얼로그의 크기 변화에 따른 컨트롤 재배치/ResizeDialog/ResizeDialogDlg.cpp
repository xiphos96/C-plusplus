// ResizeDialogDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ResizeDialog.h"
#include "ResizeDialogDlg.h"

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


// CResizeDialogDlg 대화 상자



CResizeDialogDlg::CResizeDialogDlg(CWnd* pParent /*=NULL*/)
	: CResizeDlg(CResizeDialogDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CResizeDialogDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CResizeDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CResizeDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResizeDialogDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CResizeDialogDlg, CResizeDlg)
	//{{AFX_MSG_MAP(CResizeDialogDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CResizeDialogDlg 메시지 처리기

BOOL CResizeDialogDlg::OnInitDialog()
{
	CResizeDlg::OnInitDialog();

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

	// 다이얼로그의 각 컨트롤들에 대해,
	// 다이얼로그 크기 변화시 재배치 옵션을 설정한다

	// 텍스트 스태틱들은 재배치하지 않는다
	SetChildType(GetDlgItem(IDC_TEXT_STATIC1), RE_NONE);
	SetChildType(GetDlgItem(IDC_TEXT_STATIC2), RE_NONE);
	SetChildType(GetDlgItem(IDC_TEXT_STATIC3), RE_NONE);

	// 에디트 박스들은 우측 변을 다이얼로그 오른쪽 기준으로 위치를 고정한다
	SetChildType(GetDlgItem(IDC_EDIT1), RE_INV_X2);
	SetChildType(GetDlgItem(IDC_EDIT2), RE_INV_X2);
	SetChildType(GetDlgItem(IDC_EDIT3), RE_INV_X2);

	// 그룹 박스는 우측 변을 다이얼로그 오른쪽 기준으로 위치를 고정하고
	// 아래쪽 변을 다이얼로그 아래쪽 기준으로 위치를 고정한다
	SetChildType(GetDlgItem(IDC_GROUP_STATIC), RE_INV_X2 | RE_INV_Y2);

	// 설명 문구는 우측 변을 다이얼로그 오른쪽 기준으로 위치를 고정한다
	SetChildType(GetDlgItem(IDC_MENT_STATIC), RE_INV_X2);

	// 라인은 우측 변을 다이얼로그 오른쪽 기준으로 위치를 고정한다
	SetChildType(GetDlgItem(IDC_LINE_STATIC), RE_INV_X2);
	
	// 프로그래스바는 우측 변을 다이얼로그 오른쪽 기준으로 위치를 고정하고
	// 아래쪽 변을 다이얼로그 아래쪽 기준으로 위치를 고정한다
	SetChildType(GetDlgItem(IDC_PROGRESS1), RE_INV_X2 | RE_INV_Y2);
	
	// 버튼은 위쪽 변을 다이얼로그 아래쪽 기준으로 위치를 고정하고
	// 우측 변을 다이얼로그 오른쪽 기준으로 고정하고
	// 아래쪽 변을 다이얼로그 아래쪽 기준으로 고정한다
	SetChildType(GetDlgItem(IDC_BUTTON1), RE_INV_Y1 | RE_X2 | RE_INV_Y2);

	// 콤보 박스는 좌측 변을 비율대로 왼쪽 기준으로 조정하고
	// 위쪽 변을 다이얼로그 아래쪽 기준으로 고정하고
	// 우측 변을 다이얼로그 오른쪽 기준으로 고정하고
	// 아래쪽 변을 다이얼로그 아래쪽 기준으로 고정한다
	SetChildType(GetDlgItem(IDC_COMBO1), RE_X1 | RE_INV_Y1 | RE_INV_X2 | RE_INV_Y2);

	// 체크 박스는 좌측 변을 다이얼로그 오른쪽 기준으로 위치를 고정하고
	// 위쪽 변을 다이얼로그 아래쪽 기준으로 고정하고
	// 우측 변을 다이얼로그 오른쪽 기준으로 위치를 고정하고
	// 아래쪽 변을 다이얼로그 아래쪽 기준으로 고정한다
	SetChildType(GetDlgItem(IDC_CHECK1), RE_INV_ALL);

	// 확인 버튼은 좌측 변을 다이얼로그 오른쪽 기준으로 위치를 고정하고
	// 위쪽 변을 다이얼로그 아래쪽 기준으로 고정하고
	// 우측 변을 다이얼로그 오른쪽 기준으로 고정하고
	// 아래쪽 변을 다이얼로그 아래쪽 기준으로 고정한다
	SetChildType(GetDlgItem(IDOK), RE_INV_ALL);

	// 취소 버튼은 좌측 변을 다이얼로그 오른쪽 기준으로 위치를 고정하고
	// 위쪽 변을 다이얼로그 아래쪽 기준으로 고정하고
	// 우측 변을 다이얼로그 오른쪽 기준으로 고정하고
	// 아래쪽 변을 다이얼로그 아래쪽 기준으로 고정한다
	SetChildType(GetDlgItem(IDCANCEL), RE_INV_ALL);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CResizeDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CResizeDlg::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면 
// 아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
// 프레임워크에서 이 작업을 자동으로 수행합니다.

void CResizeDialogDlg::OnPaint() 
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
		CResizeDlg::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다. 
HCURSOR CResizeDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
