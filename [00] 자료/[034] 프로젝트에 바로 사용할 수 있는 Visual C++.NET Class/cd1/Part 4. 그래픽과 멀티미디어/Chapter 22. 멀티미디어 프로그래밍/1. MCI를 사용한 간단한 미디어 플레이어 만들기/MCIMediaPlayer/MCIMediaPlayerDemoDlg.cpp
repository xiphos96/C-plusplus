// MCIMediaPlayerDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MCIMediaPlayerDemo.h"
#include "MCIMediaPlayerDemoDlg.h"

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


// CMCIMediaPlayerDemoDlg ��ȭ ����



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


// CMCIMediaPlayerDemoDlg �޽��� ó����

BOOL CMCIMediaPlayerDemoDlg::OnInitDialog()
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

	// �̵�� ��ġ �����̴��ٸ� �ʱ�ȭ�Ѵ�
	m_MediaSlider.SetRange(0, 0);
	m_MediaSlider.SetPos(0);

	// ����ǥ�ÿ� ����ƽ ��Ʈ���� �ؽ�Ʈ�� �ʱ�ȭ�Ѵ�
	GetDlgItem(IDC_TIME_STATIC)->SetWindowText("���� ���� ����");
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸����� 
// �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
// �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMCIMediaPlayerDemoDlg::OnPaint() 
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
HCURSOR CMCIMediaPlayerDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMCIMediaPlayerDemoDlg::OnOpenButton() 
{
	CFileDialog OpenDlg(TRUE, NULL, NULL,
		OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_LONGNAMES,
		"All Media(*.mpg, *.avi, *.dat, *.mp3, *.wav)|*.mpg;*.avi;*.dat;*.mp3;*.wav|��� ����|*.*||");
	
	OpenDlg.m_ofn.lpstrTitle = "�̵�� ������ �����ϼ���";

	if(OpenDlg.DoModal() != IDOK)		return;

	// �̵�� ������ ����
	if(!m_MediaPlayer.LoadMedia(OpenDlg.GetPathName()))
	{
		MessageBox("�̵�� ������ ���� �������� ������ �߻��߽��ϴ�.");
		return;
	}

	// �̵���� ��ü ��� �ð��� ��´�
	int nLength = m_MediaPlayer.GetMediaTime();

	// ��� �ð��� �°� �����̴� ��Ʈ���� �ʱ�ȭ�Ѵ�
	m_MediaSlider.SetRange(0, nLength);
	m_MediaSlider.SetPos(0);

	// �̵� ����Ѵ�
	m_MediaPlayer.Play();
}

// �̵�� ��� ������ ��ȭ �̺�Ʈ �Լ�
LRESULT CMCIMediaPlayerDemoDlg::OnChangeStatus(WPARAM wParam, LPARAM lParam)
{
	CString strMessage;

	// ���� ���¸� �����ϴ� �ؽ�Ʈ�� ����Ѵ�
	switch(m_MediaPlayer.GetStatus())
	{
	case MCI_MODE_NOT_READY :
		strMessage = "���� ���� ����";
		break;
	case MCI_MODE_OPEN :
		strMessage = "�̵�� ������ ���� �ֽ��ϴ�.";
		break;
	case MCI_MODE_PAUSE :
		strMessage = "�Ͻ� �����Ǿ� �ֽ��ϴ�.";
		break;
	case MCI_MODE_PLAY :
		strMessage = "��� ���Դϴ�.";
		break;
	case MCI_MODE_SEEK :
		strMessage = "��ġ �̵� ���Դϴ�.";
		break;
	case MCI_MODE_STOP :
		strMessage = "���� �����Դϴ�.";
		break;
	}

	GetDlgItem(IDC_TIME_STATIC)->SetWindowText(strMessage);

	return 0;
}

// �̵�� ��� ��ġ ��ȭ �̺�Ʈ �Լ�
LRESULT CMCIMediaPlayerDemoDlg::OnChangePos(WPARAM wParam, LPARAM lParam)
{
	// �����̴� ��Ʈ���� ��ġ�� �ű��
	m_MediaSlider.SetPos(lParam);

	// ���� ��� ��ġ�� ��/��/��/ms ������ �����Ѵ�
	int nCurHour, nCurMin, nCurSec, nCurMSec;

	nCurHour = lParam / (60 * 60 * 1000);
	lParam -= nCurHour * (60 * 60 * 1000);

	nCurMin = lParam / (60 * 1000);
	lParam -= nCurMin * (60 * 1000);

	nCurSec = lParam / 1000;
	lParam -= nCurSec * 1000;

	nCurMSec = lParam;

	// �̵���� ��ü �ð��� ��/��/��/ms ������ �����Ѵ�
	int nTotal = m_MediaPlayer.GetMediaTime();
	int nMediaHour, nMediaMin, nMediaSec, nMediaMSec;

	nMediaHour = nTotal / (60 * 60 * 1000);
	nTotal -= nMediaHour * (60 * 60 * 1000);

	nMediaMin = nTotal / (60 * 1000);
	nTotal -= nMediaMin * (60 * 1000);

	nMediaSec = nTotal / 1000;
	nTotal -= nMediaSec * 1000;

	nMediaMSec = nTotal;

	// ���� �ð��� ��ü �ð��� ����ƽ ��Ʈ�ѿ� ����Ѵ�
	CString strMessage;
	strMessage.Format("%02d:%02d:%02d:%04d / %02d:%02d:%02d:%04d",
		nCurHour, nCurMin, nCurSec, nCurMSec, 
		nMediaHour, nMediaMin, nMediaSec, nMediaMSec);

	GetDlgItem(IDC_TIME_STATIC)->SetWindowText(strMessage);

	return 0;
}

void CMCIMediaPlayerDemoDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// ���� �����̴��ٸ� ���콺�� �̵��Ͽ��ٸ� 
	if(pScrollBar->m_hWnd == m_MediaSlider.m_hWnd)
	{
		if(nSBCode == TB_THUMBTRACK || nSBCode == TB_ENDTRACK)
		{
			CSliderCtrl *pSlider = (CSliderCtrl*)pScrollBar;

			// �̵���� ��� ��ġ�� �ű��
			m_MediaPlayer.SetCurPos(pSlider->GetPos());
		}
	}
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CMCIMediaPlayerDemoDlg::OnPlayButton() 
{
	// �̵�� ����ϱ�
	m_MediaPlayer.Play();
}

void CMCIMediaPlayerDemoDlg::OnStopButton() 
{
	// �̵�� ��� ���߱�
	m_MediaPlayer.Stop();
}

void CMCIMediaPlayerDemoDlg::OnPauseButton() 
{
	// ���� ���� �Ͻ� ���� ���¶�� �ٽ� ����ϰ�
	if(m_MediaPlayer.GetStatus() == MCI_MODE_PAUSE)
		m_MediaPlayer.Resume();
	else
		// ���� ��� ���̶�� �Ͻ� �����Ѵ�
		m_MediaPlayer.Pause();
}

void CMCIMediaPlayerDemoDlg::OnRewButton() 
{
	// ���� �̵�� ��ġ�� ��´�
	int nCurPos = m_MediaPlayer.GetCurPos();

	// 10�� ������ �ǵ�����
	nCurPos -= 10000;
	if(nCurPos < 0)		nCurPos = 0;

	m_MediaPlayer.SetCurPos(nCurPos);
}

void CMCIMediaPlayerDemoDlg::OnFwdButton() 
{
	// ���� �̵�� ��ġ�� ��´�
	int nCurPos = m_MediaPlayer.GetCurPos();

	// 10�� �ڷ� �̵��Ѵ�
	nCurPos += 10000;
	if(nCurPos > m_MediaPlayer.GetMediaTime())		nCurPos = m_MediaPlayer.GetMediaTime();

	m_MediaPlayer.SetCurPos(nCurPos);
}
