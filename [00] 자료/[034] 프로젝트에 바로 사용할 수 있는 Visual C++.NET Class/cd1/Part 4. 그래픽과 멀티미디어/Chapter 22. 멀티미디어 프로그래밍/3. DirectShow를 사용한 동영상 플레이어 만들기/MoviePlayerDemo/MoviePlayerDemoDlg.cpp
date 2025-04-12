// MoviePlayerDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MoviePlayerDemo.h"
#include "MoviePlayerDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� ������
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ����
	//}}AFX_VIRTUAL

// ����
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


// CMoviePlayerDemoDlg ��ȭ ����



CMoviePlayerDemoDlg::CMoviePlayerDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMoviePlayerDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMoviePlayerDemoDlg)
	m_bMute = FALSE;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMoviePlayerDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMoviePlayerDemoDlg)
	DDX_Control(pDX, IDC_MOVIE_STATIC, m_MoviePlayer);
	DDX_Control(pDX, IDC_BALANCE_SLIDER, m_BalanceSlider);
	DDX_Control(pDX, IDC_VOLUME_SLIDER, m_VolumeSlider);
	DDX_Control(pDX, IDC_MEDIA_SLIDER, m_MediaSlider);
	DDX_Check(pDX, IDC_MUTE_CHECK, m_bMute);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMoviePlayerDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CMoviePlayerDemoDlg)
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
	ON_MESSAGE(WM_MOVIE_GRAPHNOTIFY, OnGraphNotify)
	ON_MESSAGE(WM_MOVIE_POSCHANGED, OnMoviePosChanged)
	ON_MESSAGE(WM_MOVIE_STOPED, OnMovieStopped)
	ON_MESSAGE(WM_MOVIE_CHANGE_STATUS, OnMovieChangeState)
END_MESSAGE_MAP()


// CMoviePlayerDemoDlg �޽��� ó����

BOOL CMoviePlayerDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	// �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// ������ ��� ���� �޽����� ������ ������ ����
	m_MoviePlayer.SetNotifyWnd(m_hWnd);

	// ��� �����̴��� �ʱ�ȭ�Ѵ�
	m_MediaSlider.SetRange(0, 0);
	m_MediaSlider.SetPos(0);

	// ���� �����̴��� �ʱ�ȭ�Ѵ�
	m_VolumeSlider.SetRange(0, 4000);
	m_VolumeSlider.SetPos((int)m_MoviePlayer.GetVolume() + 4000);

	// �¿� �뷱�� �����̴��� �ʱ�ȭ�Ѵ�
	m_BalanceSlider.SetRange(0, 20000);
	m_BalanceSlider.SetPos((int)m_MoviePlayer.GetBalance() + 10000);
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CMoviePlayerDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸����� 
// �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
// �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMoviePlayerDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�. 
HCURSOR CMoviePlayerDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMoviePlayerDemoDlg::OnOpenButton() 
{
	CFileDialog OpenDlg(TRUE, NULL, NULL,
		OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_LONGNAMES,
		"������ ����|*.mpg;*.avi;*.asf;*.wmv;*.mov;*.dat|��� ����|*.*||");
	
	OpenDlg.m_ofn.lpstrTitle = "������ ������ �����ϼ���";

	// ������ ������ �����Ѵ�
	if(OpenDlg.DoModal() != IDOK)		return;

	GetDlgItem(IDC_PATH_STATIC)->SetWindowText("������ ������ ���� ���Դϴ�.");

	// ������ ������ ����
	if(!m_MoviePlayer.LoadMedia(OpenDlg.GetPathName()))
	{
		GetDlgItem(IDC_PATH_STATIC)->SetWindowText("���� ������ �����ϴ�.");

		MessageBox("������ ������ ���� �������� ������ �߻��߽��ϴ�.");

		return;
	}

	GetDlgItem(IDC_PATH_STATIC)->SetWindowText(m_MoviePlayer.GetFileName());

	CString strTemp;

	// ������ ������ ��� �ð��� ��´� : 1�� ����
	LONG nDuration = LONG(m_MoviePlayer.GetDuration() / 10000000.0);

	// ��� �ð��� ��, ��, �� ������ ����Ѵ�
	int nHour = nDuration / 3600;
	nDuration -= nHour * 3600;
	int nMin = nDuration / 60;
	nDuration -= nMin * 60;
	int nSec = nDuration;

	// ȭ�鿡 ��� �ð��� ����Ѵ�
	strTemp.Format("%02d:%02d:%02d", nHour, nMin, nSec);
	GetDlgItem(IDC_DURATION_STATIC)->SetWindowText(strTemp);

	// ���� ��ġ�� ����Ѵ�
	GetDlgItem(IDC_TIME_STATIC)->SetWindowText("00:00:00");

	// ��� �����̴��� ������ �����Ѵ�
	int nTemp =  int(m_MoviePlayer.GetDuration() / 10000000.0);
	m_MediaSlider.SetRange(0, int(m_MoviePlayer.GetDuration() / 10000000.0));
	m_MediaSlider.SetPos(0);

	// ������ ������ ����Ѵ�
	if(!m_MoviePlayer.Play())
		MessageBox("������ ������ ����ϴ� �������� ������ �߻��߽��ϴ�.");
}

void CMoviePlayerDemoDlg::OnPlayButton() 
{
	// ���� ���� �����Ǿ� �ְų� �Ͻ� ���� �Ǿ� �ִٸ� ����Ѵ�
	if(m_MoviePlayer.GetStatus() == Paused || m_MoviePlayer.GetStatus() == Stopped)
		m_MoviePlayer.Play();
}

void CMoviePlayerDemoDlg::OnStopButton() 
{
	// ���� ���� ��� ���̰ų� �Ͻ� �����Ǿ� �ִٸ� �����Ѵ�
	if(m_MoviePlayer.GetStatus() == Playing || m_MoviePlayer.GetStatus() == Paused)
		m_MoviePlayer.Stop();
}

void CMoviePlayerDemoDlg::OnPauseButton() 
{
	// ���� ���� �Ͻ� ���� �Ǿ� �ִٸ� �����Ѵ�
	if(m_MoviePlayer.GetStatus() == Paused)
		m_MoviePlayer.Play();
	else
		// ���� ���� ���� ���̶�� �Ͻ� �����Ѵ�
		m_MoviePlayer.Pause();
}

void CMoviePlayerDemoDlg::OnRewButton() 
{
	// ���� ���� ���� ������ ������ ���ٸ� ����
	if(m_MoviePlayer.GetStatus() == Uninitialized)		return;

	// ���� ��ġ���� 10�� �ڷ� �̵��Ѵ�
	double dPos = m_MoviePlayer.GetCurPosition() - 10 * 10000000.0;

	if(dPos < 0)	dPos = 0;

	m_MoviePlayer.SetCurPosition(dPos);
}

void CMoviePlayerDemoDlg::OnFwdButton() 
{
	// ���� ���� ���� ������ ������ ���ٸ� ����
	if(m_MoviePlayer.GetStatus() == Uninitialized)		return;

	// ���� ��ġ���� 10�� ������ �̵��Ѵ�
	double dPos = m_MoviePlayer.GetCurPosition() + 10 * 10000000.0;

	if(dPos > m_MoviePlayer.GetDuration())	dPos = m_MoviePlayer.GetDuration();

	m_MoviePlayer.SetCurPosition(dPos);
}

void CMoviePlayerDemoDlg::OnMuteCheck() 
{
	UpdateData(TRUE);

	// ���ҰŸ� �����ϰų� �����Ѵ�
	m_MoviePlayer.SetMute(m_bMute);
}

LRESULT CMoviePlayerDemoDlg::OnGraphNotify(WPARAM wParam, LPARAM lParam)
{
	long nEventCode;
	long wParam2, lParam2;

	// �˸� �޽����� CMoviePlayer ��ü���� �����Ѵ�
	nEventCode = m_MoviePlayer.OnGraphNotify(wParam2, lParam2);

	return 0;
}

LRESULT CMoviePlayerDemoDlg::OnMoviePosChanged(WPARAM wParam, LPARAM lParam)
{
	// ���� ������ ��� ��ġ�� ����Ǹ�
	// ���� ��ġ�� ��´�
	LONG nPos = LONG(m_MoviePlayer.GetCurPosition() / 10000000.0);

	// ��� ��ġ�� ��, ��, �� ������ ����Ѵ�
	int nHour = nPos / 3600;
	int nMin = (nPos % 3600) / 60;
	int nSec = nPos % 60;

	// ��� ��ġ�� ȭ�鿡 ����Ѵ�
	CString strTemp;
	strTemp.Format("%02d:%02d:%02d", nHour, nMin, nSec);
	GetDlgItem(IDC_TIME_STATIC)->SetWindowText(strTemp);

	// ��� �����̴��� ��ġ�� �����Ѵ�
	m_MediaSlider.SetPos(nPos);

	return 0;
}

LRESULT CMoviePlayerDemoDlg::OnMovieStopped(WPARAM wParam, LPARAM lParam)
{
	// ȭ���� ��� ��ġ�� ó������ ����Ѵ�
	GetDlgItem(IDC_TIME_STATIC)->SetWindowText("00:00:00");

	// ��� �����̴��� ��ġ�� �̵��Ѵ�
	m_MediaSlider.SetPos(0);

	return 0;
}

LRESULT CMoviePlayerDemoDlg::OnMovieChangeState(WPARAM wParam, LPARAM lParam)
{
	CString strStatus;

	// ��� ���°� ����Ǹ� ���¿� ���� ���ڿ��� �����Ѵ�
	switch(wParam)
	{
	case Uninitialized :
		strStatus = "���� ������ �����ϴ�";
		break;
	case Playing:		// 1
		strStatus.Format("��� �� : %s", m_MoviePlayer.GetFileName());
		break;
	case Paused:		// 2
		strStatus.Format("�Ͻ� ���� : %s", m_MoviePlayer.GetFileName());
		break;
	case Stopped:		// 3 
		strStatus = "��� ����";
		break;
	}

	// ��� ���¸� ȭ�鿡 ����Ѵ�
	GetDlgItem(IDC_PATH_STATIC)->SetWindowText(strStatus);

	return 0;
}

void CMoviePlayerDemoDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// ���� ��� �����̴��ٸ� ���콺�� �̵��Ͽ��ٸ� 
	if(pScrollBar->m_hWnd == m_MediaSlider.m_hWnd)
	{
		if(nSBCode == TB_THUMBTRACK || nSBCode == TB_ENDTRACK)
		{
			CSliderCtrl *pSlider = (CSliderCtrl*)pScrollBar;

			// ������ ��� ��ġ�� �ű��
			m_MoviePlayer.SetCurPosition(pSlider->GetPos() * 10000000.0);
		}
	}
	// ���� ���� �����̴��ٸ� ���콺�� �̵��Ͽ��ٸ� 
	if(pScrollBar->m_hWnd == m_VolumeSlider.m_hWnd)
	{
		if(nSBCode == TB_THUMBTRACK || nSBCode == TB_ENDTRACK)
		{
			CSliderCtrl *pSlider = (CSliderCtrl*)pScrollBar;

			// ������ �����Ѵ�
			m_MoviePlayer.SetVolume(pSlider->GetPos() - 4000);
		}
	}
	// ���� �����̴��ٸ� ���콺�� �̵��Ͽ��ٸ� 
	if(pScrollBar->m_hWnd == m_BalanceSlider.m_hWnd)
	{
		if(nSBCode == TB_THUMBTRACK || nSBCode == TB_ENDTRACK)
		{
			CSliderCtrl *pSlider = (CSliderCtrl*)pScrollBar;

			// �¿� �뷱���� �����Ѵ�
			m_MoviePlayer.SetBalance(pSlider->GetPos() - 10000);
		}
	}
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
