// MultiListBoxDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MultiListBoxDemo.h"
#include "MultiListBoxDemoDlg.h"

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


// CMultiListBoxDemoDlg 대화 상자



CMultiListBoxDemoDlg::CMultiListBoxDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiListBoxDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiListBoxDemoDlg)
	m_strText = _T("");
	m_nImage = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiListBoxDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiListBoxDemoDlg)
	DDX_Control(pDX, IDC_MULTI_LIST, m_MultiList);
	DDX_Text(pDX, IDC_TEXT_EDIT, m_strText);
	DDX_CBIndex(pDX, IDC_IMAGE_COMBO, m_nImage);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMultiListBoxDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CMultiListBoxDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BUTTON, OnAddButton)
	ON_LBN_DBLCLK(IDC_MULTI_LIST, OnDblclkMultiList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CMultiListBoxDemoDlg 메시지 처리기

BOOL CMultiListBoxDemoDlg::OnInitDialog()
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

	// 비트맵을 사용해서 이미지 리스트를 생성한다
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BOOKLIST);
	m_ImageList.Create(88, 88, ILC_COLOR24 | ILC_MASK, 10, 1);
	m_ImageList.Add(&bmp, RGB(255, 0, 255));
	bmp.DeleteObject();

	// 이미지 리스트를 리스트 박스에 설정한다
	m_MultiList.SetImageList(&m_ImageList);

	// 리스트 박스에 항목을 추가한다
	m_MultiList.AddString("\n컴퓨터 매니아 플래시 MX\n\n맨투맨 수업이 가능하도록 구성된 학원/학교 교재입니다.\n그래픽과 OA를 다루고 있으며 기존 교재에 비해 예제 수가 많고 개별 지도가 가능하도록 구성된 도서입니다.", 0);
	m_MultiList.AddString("\nC# & .NET Programming Bible 2nd Edition\n\nC# 스펙을 자세히 다루어 초급자도 쉽게 이해할 수 있으며 책 전체적으로 작고 큰 예제가 많아 실습하면서 새로운 문법과 기능들을 학습할 수 있습니다.", 1);
	m_MultiList.AddString("\n쉽게 풀어쓴 Java Database Programming\n\nJDBC 3.0 최신 스펙을 기반으로 다양한 예제와 쉬운 설명으로 자바와 DB 연동 프로그래밍 기법에 대해 다루고 있으며 JDBC 기술의 특성상 자바의 초급부터 실무 경력자까지 필요한 부분만 찾아서 볼수 있도록 데이터베이스의 기초, JDBC 고급 응용기술, 자바관련 실무예제 등 3단계로 내용을 구성하고 있다.", 2);
	m_MultiList.AddString("\nmunge's cartoon book 멜랑꼴리\n\n네티즌 사이에서 인기를 얻고 있는www.munge.co.kr 사이트의 운영자인 저자는 앙증맞은 ‘두기둡스(Doogy Doop)’이 세상을 보는 생활에서 느껴지는 단상들을 만화로 이야기하고 있다.", 3);
	m_MultiList.AddString("\nC 언어로 배우는 TCP / IP 네트워크 프로그래밍\n\n이 책에서는 프로토콜의 해설에 기본 초점을 맞추고 있는 것이 아니라, 실제로 프로토콜을 조작하여, 프로토콜을 사용해 보는 것에 중점을 두고 있다.", 4);
	m_MultiList.AddString("\nMultimedia Sound Programmnig\n\n사운드 프로그래밍 이론과 중고급 프로그래밍의 주요개념을 설명하고 이론적 바탕과 실습의 조화로 학습 효율을 증대시킨다.", 5);
	m_MultiList.AddString("\nVisual C# .NET 2003 실전 프로젝트\n\n이 책은 Visual Studio.NET 2003 정품 한글판으로 작업되어 있습니다. C#의 기초 문법과 기본적인 예제를 만드는 방법을 소개하는데 그치지 않고 기초 지식을 마스터한 후 실무에 필요한 코드를 바탕으로 실제 프로젝트에 적용하는 방법을 소개하고 있습니다.", 6);
	m_MultiList.AddString("\nPhotoshop을 이용한 제품 디자인\n\n이 책은 특성상 포토샵의 명령 체계 정도는 알고 있는 사용자들을 기준으로 만들었습니다.", 7);
	m_MultiList.AddString("\nVisual Basic.NET Programming Bible 2nd Edition\n\n이 책은 VB.NET을 통한 .NET 환경에서의 프로그래밍에 관한 모든 내용을 다루고 있습니다.", 8);
	m_MultiList.AddString("\nVisual C++.NET Programming Bible 2nd Edition\n\n가장 큰 장점은 어렵다고만 느껴질 수 있는 Visual C++.NET 서적을 초보자도 쉽게 접근할 수 있도록 체계적인 설명과 상세한 용어 설명 등으로 구성하였다는 점입니다.", 9);

	// 특정 항목들을 비활성화 시킨다
	m_MultiList.EnableString(3, FALSE);
	m_MultiList.EnableString(6, FALSE);
	m_MultiList.EnableString(9, FALSE);

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CMultiListBoxDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMultiListBoxDemoDlg::OnPaint() 
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
HCURSOR CMultiListBoxDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMultiListBoxDemoDlg::OnAddButton() 
{
	// 새로운 항목을 리스트 박스에 추가한다
	UpdateData(TRUE);

	// 만약 텍스트가 입력되지 않았다면
	if(m_strText.IsEmpty())
	{
		MessageBox("항목 텍스트를 입력하세요.");
		return;
	}

	// 해당 텍스트와 이미지 번호로 항목을 추가한다
	m_MultiList.AddString(m_strText, m_nImage);
}

void CMultiListBoxDemoDlg::OnDblclkMultiList() 
{
	// 항목을 더블 클릭하면 현재 선택된 항목을 찾는다
	int nItem = m_MultiList.GetCurSel();

	CString strItem;
	// 만약 선택된 항목이 없다면 리턴
	if(nItem == LB_ERR)					return;
	// 만약 비활성화된 항목이라면 리턴
	if(!m_MultiList.IsEnabled(nItem))	return;

	// 항목의 텍스트를 얻는다
	m_MultiList.GetText(nItem, strItem);
	strItem.TrimLeft();

	// 책 제목 부분을 찾는다
	int nEnd = strItem.Find('\n');
	if(nEnd >= 0)
		strItem.Delete(nEnd, strItem.GetLength() - nEnd);

	// 메시지 박스를 출력한다
	MessageBox(strItem);
}
