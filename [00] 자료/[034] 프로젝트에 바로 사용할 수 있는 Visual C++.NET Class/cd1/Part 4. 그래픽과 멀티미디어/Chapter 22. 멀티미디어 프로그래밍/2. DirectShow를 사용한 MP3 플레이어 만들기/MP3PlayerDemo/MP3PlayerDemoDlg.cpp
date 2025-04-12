// MP3PlayerDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MP3PlayerDemo.h"
#include "MP3PlayerDemoDlg.h"

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


// CMP3PlayerDemoDlg 대화 상자



CMP3PlayerDemoDlg::CMP3PlayerDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMP3PlayerDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMP3PlayerDemoDlg)
	m_bMute = FALSE;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMP3PlayerDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMP3PlayerDemoDlg)
	DDX_Control(pDX, IDC_BALANCE_SLIDER, m_BalanceSlider);
	DDX_Control(pDX, IDC_VOLUME_SLIDER, m_VolumeSlider);
	DDX_Control(pDX, IDC_MEDIA_SLIDER, m_MediaSlider);
	DDX_Check(pDX, IDC_MUTE_CHECK, m_bMute);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMP3PlayerDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CMP3PlayerDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_BUTTON, OnOpenButton)
	ON_BN_CLICKED(IDC_PLAY_BUTTON, OnPlayButton)
	ON_BN_CLICKED(IDC_STOP_BUTTON, OnStopButton)
	ON_BN_CLICKED(IDC_PAUSE_BUTTON, OnPauseButton)
	ON_BN_CLICKED(IDC_REW_BUTTON, OnRewButton)
	ON_BN_CLICKED(IDC_FWD_BUTTON, OnFwdButton)
	ON_BN_CLICKED(IDC_MUTE_CHECK, OnMuteCheck)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MP3_GRAPHNOTIFY, OnGraphNotify)
	ON_MESSAGE(WM_MP3_POSCHANGED, OnMP3PosChanged)
	ON_MESSAGE(WM_MP3_STOPED, OnMP3Stopped)
	ON_MESSAGE(WM_MP3_CHANGE_STATUS, OnMP3ChangeState)
END_MESSAGE_MAP()


// CMP3PlayerDemoDlg 메시지 처리기

BOOL CMP3PlayerDemoDlg::OnInitDialog()
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

	// MP3 재생 관련 메시지를 수신할 윈도우 설정
	m_MP3Player.SetNotifyWnd(m_hWnd);

	// 재생 슬라이더를 초기화한다
	m_MediaSlider.SetRange(0, 0);
	m_MediaSlider.SetPos(0);

	// 볼륨 슬라이더를 초기화한다
	m_VolumeSlider.SetRange(0, 4000);
	m_VolumeSlider.SetPos((int)m_MP3Player.GetVolume() + 4000);

	// 좌우 밸런스 슬라이더를 초기화한다
	m_BalanceSlider.SetRange(0, 20000);
	m_BalanceSlider.SetPos((int)m_MP3Player.GetBalance() + 10000);
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

void CMP3PlayerDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMP3PlayerDemoDlg::OnPaint() 
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
HCURSOR CMP3PlayerDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMP3PlayerDemoDlg::OnOpenButton() 
{
	CFileDialog OpenDlg(TRUE, NULL, NULL,
		OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_LONGNAMES,
		"MP3 파일|*.mp3|모든 파일|*.*||");
	
	OpenDlg.m_ofn.lpstrTitle = "MP3 파일을 선택하세요";

	// MP3 파일을 선택한다
	if(OpenDlg.DoModal() != IDOK)		return;

	GetDlgItem(IDC_PATH_STATIC)->SetWindowText("MP3 파일을 여는 중입니다.");

	// MP3 파일을 연다
	if(!m_MP3Player.LoadMP3(OpenDlg.GetPathName()))
	{
		GetDlgItem(IDC_PATH_STATIC)->SetWindowText("열린 파일이 없습니다.");

		MessageBox("MP3 파일을 여는 과정에서 오류가 발생했습니다.");

		return;
	}

	GetDlgItem(IDC_PATH_STATIC)->SetWindowText(m_MP3Player.GetFileName());

	CString strTemp;

	// MP3 파일의 재생 시간을 얻는다 : 0.01초 단위
	LONG nDuration = LONG(m_MP3Player.GetDuration() / 100000.0);

	// 재생 시간을 분, 초, 0.01초 단위로 계산한다
	int nMin = nDuration / 6000;
	nDuration -= nMin * 6000;
	int nSec = nDuration / 100;
	nDuration -= nSec * 100;
	int nSec2 = nDuration;

	// 화면에 재생 시간을 출력한다
	strTemp.Format("%02d:%02d:%02d", nMin, nSec, nSec2);
	GetDlgItem(IDC_DURATION_STATIC)->SetWindowText(strTemp);

	// 현재 위치를 출력한다
	GetDlgItem(IDC_TIME_STATIC)->SetWindowText("00:00:00");

	// 재생 슬라이더의 범위를 설정한다
	int nTemp =  int(m_MP3Player.GetDuration() / 10000000.0);
	m_MediaSlider.SetRange(0, int(m_MP3Player.GetDuration() / 10000000.0));
	m_MediaSlider.SetPos(0);

	// MP3 파일을 재생한다
	if(!m_MP3Player.Play())
		MessageBox("MP3 파일을 재생하는 과정에서 오류가 발생했습니다.");
}

void CMP3PlayerDemoDlg::OnPlayButton() 
{
	// 만약 현재 정지되어 있거나 일시 정지 되어 있다면 재생한다
	if(m_MP3Player.GetStatus() == Paused || m_MP3Player.GetStatus() == Stopped)
		m_MP3Player.Play();
}

void CMP3PlayerDemoDlg::OnStopButton() 
{
	// 만약 현재 재생 중이거나 일시 정지되어 있다면 정지한다
	if(m_MP3Player.GetStatus() == Playing || m_MP3Player.GetStatus() == Paused)
		m_MP3Player.Stop();
}

void CMP3PlayerDemoDlg::OnPauseButton() 
{
	// 만약 현재 일시 정지 되어 있다면 실행한다
	if(m_MP3Player.GetStatus() == Paused)
		m_MP3Player.Play();
	else
		// 만약 현재 실행 중이라면 일시 정지한다
		m_MP3Player.Pause();
}

void CMP3PlayerDemoDlg::OnRewButton() 
{
	// 만약 현재 열린 MP3 파일이 없다면 리턴
	if(m_MP3Player.GetStatus() == Uninitialized)		return;

	// 현재 위치에서 10초 뒤로 이동한다
	double dPos = m_MP3Player.GetCurPosition() - 10 * 10000000.0;

	if(dPos < 0)	dPos = 0;

	m_MP3Player.SetCurPosition(dPos);
}

void CMP3PlayerDemoDlg::OnFwdButton() 
{
	// 만약 현재 열린 MP3 파일이 없다면 리턴
	if(m_MP3Player.GetStatus() == Uninitialized)		return;

	// 현재 위치에서 10초 앞으로 이동한다
	double dPos = m_MP3Player.GetCurPosition() + 10 * 10000000.0;

	if(dPos > m_MP3Player.GetDuration())	dPos = m_MP3Player.GetDuration();

	m_MP3Player.SetCurPosition(dPos);
}

void CMP3PlayerDemoDlg::OnMuteCheck() 
{
	UpdateData(TRUE);

	// 음소거를 설정하거나 해제한다
	m_MP3Player.SetMute(m_bMute);
}

LRESULT CMP3PlayerDemoDlg::OnGraphNotify(WPARAM wParam, LPARAM lParam)
{
	long nEventCode;
	long wParam2, lParam2;

	// 알림 메시지를 CMP3Player 객체에게 전달한다
	nEventCode = m_MP3Player.OnGraphNotify(wParam2, lParam2);

	return 0;
}

LRESULT CMP3PlayerDemoDlg::OnMP3PosChanged(WPARAM wParam, LPARAM lParam)
{
	// 만약 MP3 재생 위치가 변경되면
	// 현재 위치를 얻는다
	LONG nPos = LONG(m_MP3Player.GetCurPosition() / 100000.0);

	// 재생 위치를 분, 초, 0.01 초 단위로 계산한다
	int nMin = nPos / 6000;
	int nSec = (nPos % 6000) / 100;
	int nSec2 = nPos % 100;

	// 재생 위치를 화면에 출력한다
	CString strTemp;
	strTemp.Format("%02d:%02d:%02d", nMin, nSec, nSec2);
	GetDlgItem(IDC_TIME_STATIC)->SetWindowText(strTemp);

	// 재생 슬라이더의 위치를 변경한다
	m_MediaSlider.SetPos(nPos / 100);

	return 0;
}

LRESULT CMP3PlayerDemoDlg::OnMP3Stopped(WPARAM wParam, LPARAM lParam)
{
	// 화면의 재생 위치를 처음으로 출력한다
	GetDlgItem(IDC_TIME_STATIC)->SetWindowText("00:00:00");

	// 재생 슬라이더의 위치를 이동한다
	m_MediaSlider.SetPos(0);

	return 0;
}

LRESULT CMP3PlayerDemoDlg::OnMP3ChangeState(WPARAM wParam, LPARAM lParam)
{
	CString strStatus;

	// 재생 상태가 변경되면 상태에 따른 문자열을 구성한다
	switch(wParam)
	{
	case Uninitialized :
		strStatus = "열린 파일이 없습니다";
		break;
	case Playing:		// 1
		strStatus.Format("재생 중 : %s", m_MP3Player.GetFileName());
		break;
	case Paused:		// 2
		strStatus.Format("일시 정지 : %s", m_MP3Player.GetFileName());
		break;
	case Stopped:		// 3 
		strStatus = "재생 정지";
		break;
	}

	// 재생 상태를 화면에 출력한다
	GetDlgItem(IDC_PATH_STATIC)->SetWindowText(strStatus);

	return 0;
}

void CMP3PlayerDemoDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// 만약 재생 슬라이더바를 마우스로 이동하였다면 
	if(pScrollBar->m_hWnd == m_MediaSlider.m_hWnd)
	{
		if(nSBCode == TB_THUMBTRACK || nSBCode == TB_ENDTRACK)
		{
			CSliderCtrl *pSlider = (CSliderCtrl*)pScrollBar;

			// MP3 재생 위치를 옮긴다
			m_MP3Player.SetCurPosition(pSlider->GetPos() * 10000000.0);
		}
	}
	// 만약 볼륨 슬라이더바를 마우스로 이동하였다면 
	if(pScrollBar->m_hWnd == m_VolumeSlider.m_hWnd)
	{
		if(nSBCode == TB_THUMBTRACK || nSBCode == TB_ENDTRACK)
		{
			CSliderCtrl *pSlider = (CSliderCtrl*)pScrollBar;

			// 볼륨을 변경한다
			m_MP3Player.SetVolume(pSlider->GetPos() - 4000);
		}
	}
	// 만약 슬라이더바를 마우스로 이동하였다면 
	if(pScrollBar->m_hWnd == m_BalanceSlider.m_hWnd)
	{
		if(nSBCode == TB_THUMBTRACK || nSBCode == TB_ENDTRACK)
		{
			CSliderCtrl *pSlider = (CSliderCtrl*)pScrollBar;

			// 좌우 밸런스를 변경한다
			m_MP3Player.SetBalance(pSlider->GetPos() - 10000);
		}
	}
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
