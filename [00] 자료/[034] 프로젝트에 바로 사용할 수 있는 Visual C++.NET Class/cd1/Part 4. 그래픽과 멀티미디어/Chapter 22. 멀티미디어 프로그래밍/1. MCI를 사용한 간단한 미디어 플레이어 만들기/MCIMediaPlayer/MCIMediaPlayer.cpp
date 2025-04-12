// MCIMediaPlayer.cpp : implementation file
//

#include "stdafx.h"
#include "MCIMediaPlayerDemo.h"
#include "MCIMediaPlayer.h"


// Video for Windows ���̺귯�� ��ũ
#pragma comment(lib, "vfw32.lib")


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMCIMediaPlayer

CMCIMediaPlayer::CMCIMediaPlayer()
{
	// ��� �������� �ʱ�ȭ�Ѵ�
	m_hMCIWnd		= NULL;
	m_nMediaTime	= 0;
	m_nCurPos		= 0;
	m_bSeek			= FALSE;
}

CMCIMediaPlayer::~CMCIMediaPlayer()
{
	// MCI �����찡 ������ �ʾҴٸ� �ݴ´�
	if(m_hMCIWnd)	MCIWndDestroy(m_hMCIWnd);
}


BEGIN_MESSAGE_MAP(CMCIMediaPlayer, CStatic)
	//{{AFX_MSG_MAP(CMCIMediaPlayer)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_NCPAINT()
	//}}AFX_MSG_MAP
	ON_MESSAGE(MCIWNDM_NOTIFYMODE, OnChangeStatus)
	ON_MESSAGE(MCIWNDM_NOTIFYPOS, OnChangePos)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMCIMediaPlayer message handlers

void CMCIMediaPlayer::OnPaint() 
{
	// ���� ���� �̵� ������ �ʾҰų� 
	// ���� ���°� �ƴ� ���� ����� ���������� ����Ѵ�
	BOOL bFillBkgnd = TRUE;
	if(m_hMCIWnd != NULL)
	{
		switch(GetStatus())
		{
		case MCI_MODE_PAUSE :
		case MCI_MODE_PLAY :
		case MCI_MODE_SEEK :
			bFillBkgnd = FALSE;
			break;
		}
	}

	if(bFillBkgnd)
	{
		CPaintDC dc(this); // device context for painting

		CRect rcClient;
		GetClientRect(&rcClient);

		dc.FillSolidRect(&rcClient, RGB(0, 0, 0));
	}
}

BOOL CMCIMediaPlayer::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

void CMCIMediaPlayer::OnDestroy() 
{
	CStatic::OnDestroy();

	// MCI �����츦 �ݴ´�
	if(m_hMCIWnd)
	{
		CloseMedia();
		MCIWndDestroy(m_hMCIWnd);
	}
	m_hMCIWnd = NULL;
}

// �̵�� ������ �ε��ϴ� �Լ�
BOOL CMCIMediaPlayer::LoadMedia(LPCTSTR pFileName)
{
	// ���� ���� �̵�� ������ �ݴ´�
	CloseMedia();
	
	m_strFileName = pFileName;

	// MCI �����츦 �����Ѵ�
	m_hMCIWnd = ::MCIWndCreate(m_hWnd, AfxGetApp()->m_hInstance,
		WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN
		| MCIWNDF_NOMENU| MCIWNDF_NOTIFYPOS | MCIWNDF_NOTIFYMODE | MCIWNDF_NOPLAYBAR,
		m_strFileName);

	if(m_hMCIWnd == NULL)		return FALSE;

	// ��� �ð� ������ ms(1/1000��)�� �����Ѵ�
	MCIWndSetTimeFormat(m_hMCIWnd, "ms");
	// CMCIMediaPlayer�� ��ü ũ�⿡ �°� MCI �������� ũ�⸦ �����Ѵ�
	::ShowWindow(m_hMCIWnd, SW_MAXIMIZE); 	

	// �̵���� ��ü ��� �ð��� ��´�
	m_nMediaTime = 	MCIWndGetLength(m_hMCIWnd);

	return TRUE;
}

// �̵�� ������ �ݴ� �Լ�
BOOL CMCIMediaPlayer::CloseMedia()
{
	if(m_hMCIWnd == NULL)	return FALSE;

	// �̵�� ����� �����Ѵ�
	MCIWndStop(m_hMCIWnd);
	// �̵�� ������ �ݴ´�
	MCIWndClose(m_hMCIWnd);
	m_hMCIWnd = NULL;

	m_nMediaTime = 0;
	m_nCurPos = 0;
	m_strFileName.Empty();

	return TRUE;
}

// ��� �Լ�
void CMCIMediaPlayer::Play()
{
	if(m_hMCIWnd == NULL)	return;

	MCIWndPlay(m_hMCIWnd);
}

// ���� �Լ�
void CMCIMediaPlayer::Stop()
{
	if(m_hMCIWnd == NULL)	return;

	MCIWndStop(m_hMCIWnd);
}

// �Ͻ� ���� �Լ�
void CMCIMediaPlayer::Pause()
{
	if(m_hMCIWnd == NULL)	return;

	MCIWndPause(m_hMCIWnd);
}

// ����� �Լ�
void CMCIMediaPlayer::Resume()
{
	if(m_hMCIWnd == NULL)	return;

	MCIWndResume(m_hMCIWnd);
}

// �̵���� ��ü ��� �ð��� �����ϴ� �Լ�
LONG CMCIMediaPlayer::GetMediaTime()
{
	if(m_hMCIWnd == NULL)	return -1;

	return m_nMediaTime;
}

// �̵���� ���� ��� ��ġ�� �����ϴ� �Լ�
LONG CMCIMediaPlayer::GetCurPos()
{
	if(m_hMCIWnd == NULL)	return -1;

	return m_nCurPos;
}

// �̵���� ��� ��ġ�� �ű�� �Լ�
BOOL CMCIMediaPlayer::SetCurPos(LONG nPos)
{
	if(m_hMCIWnd == NULL)	return FALSE;

	// ���� �̵��� ��ġ�� ��ȿ���� �˻��Ѵ�
	if(nPos > m_nMediaTime)		nPos = m_nMediaTime;
	if(nPos < MCIWndGetStart(m_hMCIWnd))
		nPos = MCIWndGetStart(m_hMCIWnd);

	BOOL bRunning = GetStatus() == MCI_MODE_PLAY;

	// ��ġ �̵� ������ �����Ѵ�
	m_bSeek = TRUE;

	// ���� ���� ��� ���̶�� �����Ѵ�
	if(bRunning)	Stop();

	// ��� ��ġ�� �̵��Ѵ�
	LONG nRet = MCIWndSeek(m_hMCIWnd, nPos);

	// ���� ��� ���̾��ٸ� �ٽ� ����Ѵ�
	if(bRunning)	Play();
	
	// ��ġ �̵��� �������� �����Ѵ�
	m_bSeek = FALSE;

	return (nRet == 0);
}

// ���� ��� ���¸� �����ϴ� �Լ�
LONG CMCIMediaPlayer::GetStatus()
{
	if(m_hMCIWnd == NULL)		return MCI_MODE_NOT_READY;

	return MCIWndGetMode(m_hMCIWnd, 0, 0);
}

// ���� ������ �����ϴ� �Լ�
LONG CMCIMediaPlayer::GetVolume()
{
	if(m_hMCIWnd == NULL)	return -1;

	return MCIWndGetVolume(m_hMCIWnd);
}

// ������ �����ϴ� �Լ�
void CMCIMediaPlayer::SetVolume(LONG nVolume)
{
	if(m_hMCIWnd == NULL)	return;

	MCIWndSetVolume(m_hMCIWnd, nVolume);
}

// �̵���� ��� ���°� ����Ǿ��� �� ����Ǵ� �Լ�
LRESULT CMCIMediaPlayer::OnChangeStatus(WPARAM wParam, LPARAM lParam)
{
	if(m_bSeek)		return 0;

	// �θ� �����쿡�� �̵�� ��� ���� ������ �˸���
	if(GetParent())
		GetParent()->SendMessage(WM_MMP_CHANGE_STATUS, (WPARAM)this, lParam);

	switch(lParam)
	{
	case MCI_MODE_PLAY:
		// ���� ����� ���۵Ǹ� �̵�� ��ġ �˻縦 ���� Ÿ�̸Ӹ� �����Ѵ�
		SetTimer(1, 100, NULL);
		break;
	case MCI_MODE_STOP:
		// ���� ����� �����Ǹ� ó�� ��ġ�� �̵��Ѵ�
		SetCurPos(0);
	case MCI_MODE_PAUSE:
		// ���� ����� �����ǰų� �Ͻ� �����Ǹ� Ÿ�̸Ӹ� �����
		KillTimer(1);
		break;
	}

	return 0;
}

// �̵���� ��� ��ġ�� ����Ǿ��� �� ����Ǵ� �Լ�
LRESULT CMCIMediaPlayer::OnChangePos(WPARAM wParam, LPARAM lParam)
{
	if(m_bSeek)		return 0;

	if(GetParent())
	{
		// �θ� �����쿡�� ��� ��ġ ������ �˸���
		GetParent()->SendMessage(WM_MMP_CHANGE_POSITION, (WPARAM)this, lParam);
		// �θ� ������� �ڽ� ��������� �ٽ� �׷������� �Ѵ�
		GetParent()->RedrawWindow(NULL, NULL, RDW_FRAME | RDW_INTERNALPAINT | RDW_NOERASE | RDW_UPDATENOW | RDW_ALLCHILDREN);
	}

	TRACE("Media Current Position : %d\n", lParam);

	// ���� ��ġ�� �����Ѵ�
	m_nCurPos = lParam;

	return 0;
}

// ��� ��ġ ������ Ȯ���ϱ� ���� Ÿ�̸� �Լ�
void CMCIMediaPlayer::OnTimer(UINT nIDEvent) 
{
	// ���� ��� ��ġ�� ��´�
	LONG nCurPos = MCIWndGetPosition(m_hMCIWnd);

	// ���� ��� ��ġ�� ����Ǿ��ٸ�
	if(nCurPos != m_nCurPos)
	{
		// ���� ��ġ�� �ٽ� �����Ѵ�
		m_nCurPos = nCurPos;

		// �θ� �����쿡�� ��� ��ġ ������ �˸���
		GetParent()->SendMessage(WM_MMP_CHANGE_POSITION, (WPARAM)this, m_nCurPos);
		// �θ� ������� �ڽ� ��������� �ٽ� �׷������� �Ѵ�
		GetParent()->RedrawWindow(NULL, NULL, RDW_FRAME | RDW_INTERNALPAINT | RDW_NOERASE | RDW_UPDATENOW | RDW_ALLCHILDREN);
	}
	
	CStatic::OnTimer(nIDEvent);
}

// �θ� �������� ȭ�� ������ ��Ȯ�ϰ� �̷����� ���� �ʿ��� �Լ�
void CMCIMediaPlayer::OnNcPaint() 
{
	// �θ� ������� �ڽ� ��������� �ٽ� �׷������� �Ѵ�
	GetParent()->RedrawWindow(NULL, NULL, RDW_FRAME | RDW_INTERNALPAINT | RDW_NOERASE | RDW_UPDATENOW | RDW_ALLCHILDREN);
}
