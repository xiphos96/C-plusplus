// MCIMediaPlayerDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MCIMediaPlayerDemo.h"
#include "MCIMediaPlayerDemoDlg.h"

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


// CMCIMediaPlayerDemoDlg 대화 상자



CMCIMediaPlayerDemoDlg::CMCIMediaPlayerDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMCIMediaPlayerDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMCIMediaPlayerDemoDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMCIMediaPlayerDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMCIMediaPlayerDemoDlg)
	DDX_Control(pDX, IDC_MEDIA_SLIDER, m_MediaSlider);
	DDX_Control(pDX, IDC_MEDIAPLAYER_STATIC, m_MediaPlayer);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMCIMediaPlayerDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CMCIMediaPlayerDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_BUTTON, OnOpenButton)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_PLAY_BUTTON, OnPlayButton)
	ON_BN_CLICKED(IDC_STOP_BUTTON, OnStopButton)
	ON_BN_CLICKED(IDC_PAUSE_BUTTON, OnPauseButton)
	ON_BN_CLICKED(IDC_REW_BUTTON, OnRewButton)
	ON_BN_CLICKED(IDC_FWD_BUTTON, OnFwdButton)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MMP_CHANGE_STATUS, OnChangeStatus)
	ON_MESSAGE(WM_MMP_CHANGE_POSITION, OnChangePos)
END_MESSAGE_MAP()


// CMCIMediaPlayerDemoDlg 메시지 처리기

BOOL CMCIMediaPlayerDemoDlg::OnInitDialog()
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

	// 미디어 위치 슬라이더바를 초기화한다
	m_MediaSlider.SetRange(0, 0);
	m_MediaSlider.SetPos(0);

	// 상태표시용 스태틱 컨트롤의 텍스트를 초기화한다
	GetDlgItem(IDC_TIME_STATIC)->SetWindowText("열린 파일 없음");
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CMCIMediaPlayerDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMCIMediaPlayerDemoDlg::OnPaint() 
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
HCURSOR CMCIMediaPlayerDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMCIMediaPlayerDemoDlg::OnOpenButton() 
{
	CFileDialog OpenDlg(TRUE, NULL, NULL,
		OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_LONGNAMES,
		"All Media(*.mpg, *.avi, *.dat, *.mp3, *.wav)|*.mpg;*.avi;*.dat;*.mp3;*.wav|모든 파일|*.*||");
	
	OpenDlg.m_ofn.lpstrTitle = "미디어 파일을 선택하세요";

	if(OpenDlg.DoModal() != IDOK)		return;

	// 미디어 파일을 연다
	if(!m_MediaPlayer.LoadMedia(OpenDlg.GetPathName()))
	{
		MessageBox("미디어 파일을 여는 과정에서 오류가 발생했습니다.");
		return;
	}

	// 미디어의 전체 재생 시간을 얻는다
	int nLength = m_MediaPlayer.GetMediaTime();

	// 재생 시간에 맞게 슬라이더 컨트롤을 초기화한다
	m_MediaSlider.SetRange(0, nLength);
	m_MediaSlider.SetPos(0);

	// 미디어를 재생한다
	m_MediaPlayer.Play();
}

// 미디어 재생 상태의 변화 이벤트 함수
LRESULT CMCIMediaPlayerDemoDlg::OnChangeStatus(WPARAM wParam, LPARAM lParam)
{
	CString strMessage;

	// 현재 상태를 설명하는 텍스트를 출력한다
	switch(m_MediaPlayer.GetStatus())
	{
	case MCI_MODE_NOT_READY :
		strMessage = "열린 파일 없음";
		break;
	case MCI_MODE_OPEN :
		strMessage = "미디어 파일을 열고 있습니다.";
		break;
	case MCI_MODE_PAUSE :
		strMessage = "일시 정지되어 있습니다.";
		break;
	case MCI_MODE_PLAY :
		strMessage = "재생 중입니다.";
		break;
	case MCI_MODE_SEEK :
		strMessage = "위치 이동 중입니다.";
		break;
	case MCI_MODE_STOP :
		strMessage = "정지 상태입니다.";
		break;
	}

	GetDlgItem(IDC_TIME_STATIC)->SetWindowText(strMessage);

	return 0;
}

// 미디어 재생 위치 변화 이벤트 함수
LRESULT CMCIMediaPlayerDemoDlg::OnChangePos(WPARAM wParam, LPARAM lParam)
{
	// 슬라이더 컨트롤의 위치를 옮긴다
	m_MediaSlider.SetPos(lParam);

	// 현재 재생 위치를 시/분/초/ms 단위로 분할한다
	int nCurHour, nCurMin, nCurSec, nCurMSec;

	nCurHour = lParam / (60 * 60 * 1000);
	lParam -= nCurHour * (60 * 60 * 1000);

	nCurMin = lParam / (60 * 1000);
	lParam -= nCurMin * (60 * 1000);

	nCurSec = lParam / 1000;
	lParam -= nCurSec * 1000;

	nCurMSec = lParam;

	// 미디어의 전체 시간을 시/분/초/ms 단위로 분할한다
	int nTotal = m_MediaPlayer.GetMediaTime();
	int nMediaHour, nMediaMin, nMediaSec, nMediaMSec;

	nMediaHour = nTotal / (60 * 60 * 1000);
	nTotal -= nMediaHour * (60 * 60 * 1000);

	nMediaMin = nTotal / (60 * 1000);
	nTotal -= nMediaMin * (60 * 1000);

	nMediaSec = nTotal / 1000;
	nTotal -= nMediaSec * 1000;

	nMediaMSec = nTotal;

	// 현재 시간과 전체 시간을 스태틱 컨트롤에 출력한다
	CString strMessage;
	strMessage.Format("%02d:%02d:%02d:%04d / %02d:%02d:%02d:%04d",
		nCurHour, nCurMin, nCurSec, nCurMSec, 
		nMediaHour, nMediaMin, nMediaSec, nMediaMSec);

	GetDlgItem(IDC_TIME_STATIC)->SetWindowText(strMessage);

	return 0;
}

void CMCIMediaPlayerDemoDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// 만약 슬라이더바를 마우스로 이동하였다면 
	if(pScrollBar->m_hWnd == m_MediaSlider.m_hWnd)
	{
		if(nSBCode == TB_THUMBTRACK || nSBCode == TB_ENDTRACK)
		{
			CSliderCtrl *pSlider = (CSliderCtrl*)pScrollBar;

			// 미디어의 재생 위치를 옮긴다
			m_MediaPlayer.SetCurPos(pSlider->GetPos());
		}
	}
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CMCIMediaPlayerDemoDlg::OnPlayButton() 
{
	// 미디어 재생하기
	m_MediaPlayer.Play();
}

void CMCIMediaPlayerDemoDlg::OnStopButton() 
{
	// 미디어 재생 멈추기
	m_MediaPlayer.Stop();
}

void CMCIMediaPlayerDemoDlg::OnPauseButton() 
{
	// 만약 현재 일시 정지 상태라면 다시 재생하고
	if(m_MediaPlayer.GetStatus() == MCI_MODE_PAUSE)
		m_MediaPlayer.Resume();
	else
		// 현재 재생 중이라면 일시 정지한다
		m_MediaPlayer.Pause();
}

void CMCIMediaPlayerDemoDlg::OnRewButton() 
{
	// 현재 미디어 위치를 얻는다
	int nCurPos = m_MediaPlayer.GetCurPos();

	// 10초 앞으로 되돌린다
	nCurPos -= 10000;
	if(nCurPos < 0)		nCurPos = 0;

	m_MediaPlayer.SetCurPos(nCurPos);
}

void CMCIMediaPlayerDemoDlg::OnFwdButton() 
{
	// 현재 미디어 위치를 얻는다
	int nCurPos = m_MediaPlayer.GetCurPos();

	// 10초 뒤로 이동한다
	nCurPos += 10000;
	if(nCurPos > m_MediaPlayer.GetMediaTime())		nCurPos = m_MediaPlayer.GetMediaTime();

	m_MediaPlayer.SetCurPos(nCurPos);
}
