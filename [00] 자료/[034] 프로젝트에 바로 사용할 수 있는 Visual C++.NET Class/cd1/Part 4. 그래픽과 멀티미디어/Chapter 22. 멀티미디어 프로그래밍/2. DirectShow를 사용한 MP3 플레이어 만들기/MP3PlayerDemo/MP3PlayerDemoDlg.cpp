// MP3PlayerDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MP3PlayerDemo.h"
#include "MP3PlayerDemoDlg.h"

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


// CMP3PlayerDemoDlg ��ȭ ����



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


// CMP3PlayerDemoDlg �޽��� ó����

BOOL CMP3PlayerDemoDlg::OnInitDialog()
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

	// MP3 ��� ���� �޽����� ������ ������ ����
	m_MP3Player.SetNotifyWnd(m_hWnd);

	// ��� �����̴��� �ʱ�ȭ�Ѵ�
	m_MediaSlider.SetRange(0, 0);
	m_MediaSlider.SetPos(0);

	// ���� �����̴��� �ʱ�ȭ�Ѵ�
	m_VolumeSlider.SetRange(0, 4000);
	m_VolumeSlider.SetPos((int)m_MP3Player.GetVolume() + 4000);

	// �¿� �뷱�� �����̴��� �ʱ�ȭ�Ѵ�
	m_BalanceSlider.SetRange(0, 20000);
	m_BalanceSlider.SetPos((int)m_MP3Player.GetBalance() + 10000);
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸����� 
// �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
// �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMP3PlayerDemoDlg::OnPaint() 
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
HCURSOR CMP3PlayerDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMP3PlayerDemoDlg::OnOpenButton() 
{
	CFileDialog OpenDlg(TRUE, NULL, NULL,
		OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_LONGNAMES,
		"MP3 ����|*.mp3|��� ����|*.*||");
	
	OpenDlg.m_ofn.lpstrTitle = "MP3 ������ �����ϼ���";

	// MP3 ������ �����Ѵ�
	if(OpenDlg.DoModal() != IDOK)		return;

	GetDlgItem(IDC_PATH_STATIC)->SetWindowText("MP3 ������ ���� ���Դϴ�.");

	// MP3 ������ ����
	if(!m_MP3Player.LoadMP3(OpenDlg.GetPathName()))
	{
		GetDlgItem(IDC_PATH_STATIC)->SetWindowText("���� ������ �����ϴ�.");

		MessageBox("MP3 ������ ���� �������� ������ �߻��߽��ϴ�.");

		return;
	}

	GetDlgItem(IDC_PATH_STATIC)->SetWindowText(m_MP3Player.GetFileName());

	CString strTemp;

	// MP3 ������ ��� �ð��� ��´� : 0.01�� ����
	LONG nDuration = LONG(m_MP3Player.GetDuration() / 100000.0);

	// ��� �ð��� ��, ��, 0.01�� ������ ����Ѵ�
	int nMin = nDuration / 6000;
	nDuration -= nMin * 6000;
	int nSec = nDuration / 100;
	nDuration -= nSec * 100;
	int nSec2 = nDuration;

	// ȭ�鿡 ��� �ð��� ����Ѵ�
	strTemp.Format("%02d:%02d:%02d", nMin, nSec, nSec2);
	GetDlgItem(IDC_DURATION_STATIC)->SetWindowText(strTemp);

	// ���� ��ġ�� ����Ѵ�
	GetDlgItem(IDC_TIME_STATIC)->SetWindowText("00:00:00");

	// ��� �����̴��� ������ �����Ѵ�
	int nTemp =  int(m_MP3Player.GetDuration() / 10000000.0);
	m_MediaSlider.SetRange(0, int(m_MP3Player.GetDuration() / 10000000.0));
	m_MediaSlider.SetPos(0);

	// MP3 ������ ����Ѵ�
	if(!m_MP3Player.Play())
		MessageBox("MP3 ������ ����ϴ� �������� ������ �߻��߽��ϴ�.");
}

void CMP3PlayerDemoDlg::OnPlayButton() 
{
	// ���� ���� �����Ǿ� �ְų� �Ͻ� ���� �Ǿ� �ִٸ� ����Ѵ�
	if(m_MP3Player.GetStatus() == Paused || m_MP3Player.GetStatus() == Stopped)
		m_MP3Player.Play();
}

void CMP3PlayerDemoDlg::OnStopButton() 
{
	// ���� ���� ��� ���̰ų� �Ͻ� �����Ǿ� �ִٸ� �����Ѵ�
	if(m_MP3Player.GetStatus() == Playing || m_MP3Player.GetStatus() == Paused)
		m_MP3Player.Stop();
}

void CMP3PlayerDemoDlg::OnPauseButton() 
{
	// ���� ���� �Ͻ� ���� �Ǿ� �ִٸ� �����Ѵ�
	if(m_MP3Player.GetStatus() == Paused)
		m_MP3Player.Play();
	else
		// ���� ���� ���� ���̶�� �Ͻ� �����Ѵ�
		m_MP3Player.Pause();
}

void CMP3PlayerDemoDlg::OnRewButton() 
{
	// ���� ���� ���� MP3 ������ ���ٸ� ����
	if(m_MP3Player.GetStatus() == Uninitialized)		return;

	// ���� ��ġ���� 10�� �ڷ� �̵��Ѵ�
	double dPos = m_MP3Player.GetCurPosition() - 10 * 10000000.0;

	if(dPos < 0)	dPos = 0;

	m_MP3Player.SetCurPosition(dPos);
}

void CMP3PlayerDemoDlg::OnFwdButton() 
{
	// ���� ���� ���� MP3 ������ ���ٸ� ����
	if(m_MP3Player.GetStatus() == Uninitialized)		return;

	// ���� ��ġ���� 10�� ������ �̵��Ѵ�
	double dPos = m_MP3Player.GetCurPosition() + 10 * 10000000.0;

	if(dPos > m_MP3Player.GetDuration())	dPos = m_MP3Player.GetDuration();

	m_MP3Player.SetCurPosition(dPos);
}

void CMP3PlayerDemoDlg::OnMuteCheck() 
{
	UpdateData(TRUE);

	// ���ҰŸ� �����ϰų� �����Ѵ�
	m_MP3Player.SetMute(m_bMute);
}

LRESULT CMP3PlayerDemoDlg::OnGraphNotify(WPARAM wParam, LPARAM lParam)
{
	long nEventCode;
	long wParam2, lParam2;

	// �˸� �޽����� CMP3Player ��ü���� �����Ѵ�
	nEventCode = m_MP3Player.OnGraphNotify(wParam2, lParam2);

	return 0;
}

LRESULT CMP3PlayerDemoDlg::OnMP3PosChanged(WPARAM wParam, LPARAM lParam)
{
	// ���� MP3 ��� ��ġ�� ����Ǹ�
	// ���� ��ġ�� ��´�
	LONG nPos = LONG(m_MP3Player.GetCurPosition() / 100000.0);

	// ��� ��ġ�� ��, ��, 0.01 �� ������ ����Ѵ�
	int nMin = nPos / 6000;
	int nSec = (nPos % 6000) / 100;
	int nSec2 = nPos % 100;

	// ��� ��ġ�� ȭ�鿡 ����Ѵ�
	CString strTemp;
	strTemp.Format("%02d:%02d:%02d", nMin, nSec, nSec2);
	GetDlgItem(IDC_TIME_STATIC)->SetWindowText(strTemp);

	// ��� �����̴��� ��ġ�� �����Ѵ�
	m_MediaSlider.SetPos(nPos / 100);

	return 0;
}

LRESULT CMP3PlayerDemoDlg::OnMP3Stopped(WPARAM wParam, LPARAM lParam)
{
	// ȭ���� ��� ��ġ�� ó������ ����Ѵ�
	GetDlgItem(IDC_TIME_STATIC)->SetWindowText("00:00:00");

	// ��� �����̴��� ��ġ�� �̵��Ѵ�
	m_MediaSlider.SetPos(0);

	return 0;
}

LRESULT CMP3PlayerDemoDlg::OnMP3ChangeState(WPARAM wParam, LPARAM lParam)
{
	CString strStatus;

	// ��� ���°� ����Ǹ� ���¿� ���� ���ڿ��� �����Ѵ�
	switch(wParam)
	{
	case Uninitialized :
		strStatus = "���� ������ �����ϴ�";
		break;
	case Playing:		// 1
		strStatus.Format("��� �� : %s", m_MP3Player.GetFileName());
		break;
	case Paused:		// 2
		strStatus.Format("�Ͻ� ���� : %s", m_MP3Player.GetFileName());
		break;
	case Stopped:		// 3 
		strStatus = "��� ����";
		break;
	}

	// ��� ���¸� ȭ�鿡 ����Ѵ�
	GetDlgItem(IDC_PATH_STATIC)->SetWindowText(strStatus);

	return 0;
}

void CMP3PlayerDemoDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// ���� ��� �����̴��ٸ� ���콺�� �̵��Ͽ��ٸ� 
	if(pScrollBar->m_hWnd == m_MediaSlider.m_hWnd)
	{
		if(nSBCode == TB_THUMBTRACK || nSBCode == TB_ENDTRACK)
		{
			CSliderCtrl *pSlider = (CSliderCtrl*)pScrollBar;

			// MP3 ��� ��ġ�� �ű��
			m_MP3Player.SetCurPosition(pSlider->GetPos() * 10000000.0);
		}
	}
	// ���� ���� �����̴��ٸ� ���콺�� �̵��Ͽ��ٸ� 
	if(pScrollBar->m_hWnd == m_VolumeSlider.m_hWnd)
	{
		if(nSBCode == TB_THUMBTRACK || nSBCode == TB_ENDTRACK)
		{
			CSliderCtrl *pSlider = (CSliderCtrl*)pScrollBar;

			// ������ �����Ѵ�
			m_MP3Player.SetVolume(pSlider->GetPos() - 4000);
		}
	}
	// ���� �����̴��ٸ� ���콺�� �̵��Ͽ��ٸ� 
	if(pScrollBar->m_hWnd == m_BalanceSlider.m_hWnd)
	{
		if(nSBCode == TB_THUMBTRACK || nSBCode == TB_ENDTRACK)
		{
			CSliderCtrl *pSlider = (CSliderCtrl*)pScrollBar;

			// �¿� �뷱���� �����Ѵ�
			m_MP3Player.SetBalance(pSlider->GetPos() - 10000);
		}
	}
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
