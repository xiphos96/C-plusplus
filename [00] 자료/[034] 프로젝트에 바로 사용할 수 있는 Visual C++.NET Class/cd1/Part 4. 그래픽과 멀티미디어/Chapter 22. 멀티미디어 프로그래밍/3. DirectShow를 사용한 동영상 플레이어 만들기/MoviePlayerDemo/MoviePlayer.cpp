// MoviePlayer.cpp : implementation file
//

#include "stdafx.h"
#include "movieplayerdemo.h"
#include "MoviePlayer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// DirectShow ���̺귯�� ��ũ
#ifdef _AFXDLL
	#ifdef _DEBUG
		#pragma comment(lib, "strmbasd.lib")
	#else
		#pragma comment(lib, "strmbase.lib")
	#endif
#endif

// ��Ƽ�̵�� ���̺귯�� ��ũ
#pragma comment(lib, "winmm.lib")

// ��Ƽ�̵�� Ÿ�̸� �ݹ� �Լ� ����
void CALLBACK TimerProc (UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2);


/////////////////////////////////////////////////////////////////////////////
// CMoviePlayer

CMoviePlayer::CMoviePlayer()
{
	// ��Ƽ�̵�� Ÿ�̸� ���ڸ� �ʱ�ȭ�Ѵ�
	::memset(&m_TimerParameter, 0, sizeof(m_TimerParameter));
	m_TimerParameter.m_pMoviePlayer = this;

	// ��� �������� �ʱ�ȭ�Ѵ�
	m_hNotifyWnd = NULL;

	ResetVariables();
}

CMoviePlayer::~CMoviePlayer()
{
	// ����ǰ� �ִ� �̵� �ݴ´�
	Close();
}


BEGIN_MESSAGE_MAP(CMoviePlayer, CStatic)
	//{{AFX_MSG_MAP(CMoviePlayer)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_NCPAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMoviePlayer message handlers

// ��� ������ �ʱ�ȭ�ϴ� �Լ�
void CMoviePlayer::ResetVariables()
{
	m_pigb = NULL; 
	m_pimc = NULL;
	m_pimex = NULL;
	m_pims = NULL;
	m_piba = NULL;
	m_pibv = NULL;
	m_pivw = NULL;

	m_strFileName.Empty();

	SetStatus(Uninitialized);

	m_bVideoSupport = FALSE;
	m_bFullScreenMode = FALSE;
	m_sizeSrc = CSize(0, 0);

	m_dRate = 1.0;
	m_dStartPos = 0;
	m_dEndPos = 0;
	m_dDuration = 0;

	m_lVolume = 0;
	m_lBalance = 0;

	m_TimerNum = NULL;
}

// ������ ���� ���� �Լ�
BOOL CMoviePlayer::LoadMedia(LPCTSTR lpszFileName)
{
	// �̹� ���� ������ ������ �ִٸ� �ݴ´�
	if(m_pigb != NULL)		Close();

	// �� ���� ��θ� �����Ѵ�
	m_strFileName = lpszFileName;

	// ������ ������ �������Ѵ�
	if(!RenderMedia())		return FALSE;

	// ������ ������ ��� �ð��� ��� �����Ѵ�
	LONGLONG lDuration;
	if(SUCCEEDED(m_pims->GetDuration(&lDuration)))
		m_dDuration = (double) lDuration;

	// ������ ������ ���� ��ġ�� �� ��ġ�� ��� �����Ѵ�
	LONGLONG lSPos, lEPos;
	if(SUCCEEDED(m_pims->GetAvailable(&lSPos, &lEPos)))
	{
		m_dStartPos = (double) lSPos;
		m_dEndPos = (double) lEPos;
	}

	m_bVideoSupport = FALSE;

	// ���� �������� �θ� �����츦 �����Ѵ�
	if(SUCCEEDED(m_pivw->put_Owner((OAHWND) m_hWnd)))
	{
		// ���� �������� �Ӽ��� �����Ѵ�
		if(SUCCEEDED(m_pivw->put_WindowStyle(WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS)))
		{
			// ���� �������� �޽����� ������ �����츦 �����Ѵ�
			if(SUCCEEDED(m_pivw->put_MessageDrain((OAHWND) m_hWnd)))
				m_bVideoSupport = TRUE;
		}
	}

	// ������ �����ȴٸ�
	if(m_bVideoSupport)
	{
		// ���� ������ ���� ��´�
		LONG lWidth, lHeight;
		if(SUCCEEDED(m_pibv->get_SourceWidth(&lWidth)))
		{
			// ���� ������ ���̸� ��´�
			if(SUCCEEDED(m_pibv->get_SourceHeight(&lHeight)))
			{
				// ������ ���� ���̸� �����Ѵ�
				m_sizeSrc = CSize((int) lWidth, (int) lHeight);
			}
		}

		RECT rcClient;
		GetClientRect(&rcClient);

		if(m_pivw)
		{
			// ���� �������� ���� ��ġ�� �����Ѵ�
			m_pivw->SetWindowPosition(rcClient.left, rcClient.top,
				rcClient.right, rcClient.bottom);
			m_pivw->put_Visible(OATRUE);
		}
	}

	// ���� ��� ���¸� ���� ���·� �����Ѵ�
	SetStatus(Stopped);

	return TRUE;
}

// ������ ���� ����� ���� ���� �������� �����ϴ� �Լ�
BOOL CMoviePlayer::RenderMedia()
{
	// ���� �׷��� �޴��� ����
    if(FAILED(CoCreateInstance(CLSID_FilterGraph,
								 NULL,
								 CLSCTX_INPROC_SERVER,
								 IID_IGraphBuilder,
								 (void **) &m_pigb)))
	{
		// ���� �׷��� �Ŵ��� ������ �����ϸ� �ʱ�ȭ�Ѵ�
		Close();
		return FALSE;
	}

	// ���ϸ��� �����ڵ�� ��ȯ�Ѵ�
	WCHAR wFileName[MAX_PATH];
    MultiByteToWideChar(CP_ACP, 0, (LPCTSTR) m_strFileName,
                        -1, wFileName, MAX_PATH);

	// ���� �׷����� �����Ѵ�
	if(FAILED(m_pigb->RenderFile(wFileName, NULL)))
	{
		Close();
		return FALSE;
	}

	// �̵�� ��Ʈ�� �������̽��� ��´�
	if(FAILED(m_pigb->QueryInterface(IID_IMediaControl, (void **) &m_pimc)))
	{
		Close();
		return FALSE;
	}
	// �̺�Ʈ �������̽��� ��´�
	if(FAILED(m_pigb->QueryInterface(IID_IMediaEventEx, (void **) &m_pimex)))
	{
		Close();
		return FALSE;
	}
	// ���� ������ �������̽��� ��´�
	if(FAILED(m_pigb->QueryInterface(IID_IVideoWindow, (void **) &m_pivw)))
	{
		Close();
		return FALSE;
	}
	// ��ġ �̵� �������̽��� ��´�
	if(FAILED(m_pigb->QueryInterface(IID_IMediaSeeking, (void **) &m_pims)))
	{
		Close();
		return FALSE;
	}
	// ����� �������̽��� ��´�
	if(FAILED(m_pigb->QueryInterface(IID_IBasicAudio, (void **) &m_piba)))
	{
		Close();
		return FALSE;
	}
	// ���� �������̽��� ��´�
	if(FAILED(m_pigb->QueryInterface(IID_IBasicVideo, (void **) &m_pibv)))
	{
		Close();
		return FALSE;
	}

	// �̵� ���� �̺�Ʈ ���� �����츦 �����Ѵ�
	if(FAILED(m_pimex->SetNotifyWindow((OAHWND)m_hNotifyWnd, WM_MOVIE_GRAPHNOTIFY, (long)this)))
	{
		Close();
		return FALSE;
	}
	// �̵�� �̵��� ������ �̵�� �ð� ������ �����Ѵ�
	if(FAILED(m_pims->SetTimeFormat(&TIME_FORMAT_MEDIA_TIME)))
	{
		Close();
		return FALSE;
	}

	// ��Ƽ�̵�� Ÿ�̸� ���ڿ� �˸� ��� �������� �ڵ��� �����Ѵ�
	m_TimerParameter.m_hTimerOwner = m_hNotifyWnd;

	return TRUE;
}

// ��� �Լ�
BOOL CMoviePlayer::Play()
{
	// ��� ������ ���¶��
	if(CanPlay())
	{
		// ����� �����Ѵ�
		if(SUCCEEDED(m_pimc->Run()))
		{
			// ���� ���¸� �����Ѵ�
			SetStatus(Playing);

			// ��ġ �̵��� �ݿ��� �� �ֵ��� ��Ƽ�̵�� Ÿ�̸Ӹ� �����Ѵ�
			m_TimerNum = MCSetTimer();

			return TRUE;
		}
	}

	return FALSE;
}

// ���� �Լ�
BOOL CMoviePlayer::Stop()
{
	// ���� ������ ���¶��
	if(CanStop())
	{
		// ���� ���¸� �����Ѵ�
		SetStatus(Stopped);

		// ��Ƽ�̵�� Ÿ�̸Ӹ� �����Ѵ�
		MCKillTimer();

		// ����� �����Ѵ�
		if(SUCCEEDED(m_pimc->Stop()))
		{
			// ���� ��ġ�� ó������ �ű��
			SetCurPosition(0);

			if(m_pivw && m_bVideoSupport)
				m_pivw->put_Visible(OATRUE);

			// �˸� ��� �����쿡�� ���� ���¸� �˸���
			if(m_TimerParameter.m_hTimerOwner)
				::PostMessage(m_TimerParameter.m_hTimerOwner, WM_MOVIE_STOPED, 0, LPARAM(this));

			return TRUE;
		}
	}

	return FALSE;
}

// �Ͻ� ���� �Լ�
BOOL CMoviePlayer::Pause()
{
	// �Ͻ� ���� ������ ���¶��
	if(CanPause())
	{
		// �Ͻ� �����Ѵ�
		if(SUCCEEDED(m_pimc->Pause()))
		{
			// ���� ���¸� �����Ѵ�
			SetStatus(Paused);

			// ��Ƽ�̵�� Ÿ�̸Ӹ� �����Ѵ�
			MCKillTimer();

			return TRUE;
		}
	}

	return FALSE;
}

// ������ ���� �ݱ� �Լ�
void CMoviePlayer::Close()
{
	// ���� ���� ���� ��Ƽ�̵�� Ÿ�̸Ӹ� �����Ѵ�
	if(m_TimerNum) MCKillTimer();

	// �������̽����� �����Ѵ�
	if(m_pigb)		m_pigb->Release();
	m_pigb = NULL;
	if(m_pimex)		m_pimex->Release();
	m_pimex = NULL;
	if(m_pimc)		m_pimc->Release();
	m_pimc = NULL;
	if(m_pims)		m_pims->Release();
	m_pims = NULL;
	if(m_piba)		m_piba->Release();
	m_piba = NULL;
	if(m_pibv)		m_pibv->Release();
	m_pibv = NULL;
	if(m_pivw)
	{
		// ���� �������� ũ�⸦ 0���� �����Ѵ�
		m_pivw->SetWindowPosition(0, 0, 0, 0);
		m_pivw->put_Owner(NULL);
		m_pivw->Release();
	}
	m_pivw = NULL;

	// ��� �������� �ʱ�ȭ�Ѵ�
	ResetVariables();
}

// DirectShow �̺�Ʈ�� ó���ϴ� �Լ�
long CMoviePlayer::OnGraphNotify(long &wParam, long &lParam)
{
	if(!m_pigb)		return -1;

	IMediaEventEx *pimex;
    long lEventCode;

	// �̵�� �̺�Ʈ �������̽��� ��´�
	if(SUCCEEDED(m_pigb->QueryInterface(IID_IMediaEventEx, (void **) &pimex)))
	{
		// ���� �߻��� �̺�Ʈ�� ���´�
        if(SUCCEEDED(pimex->GetEvent(&lEventCode, &wParam, &lParam, 0)))
		{
			// �̺�Ʈ ���ڵ��� �����Ѵ�
            HRESULT hr = pimex->FreeEventParams(lEventCode, wParam, lParam);

			// ���� ��� �Ϸ� �̺�Ʈ���
			if(lEventCode == EC_COMPLETE)
			{
				// ����� �����Ѵ�
				Stop();
			}

			// �̵�� �̺�Ʈ �������̽��� �����Ѵ�
			pimex->Release();

			// �̺�Ʈ�� �����Ѵ�
			return lEventCode;
        }
		// �̵�� �̺�Ʈ �������̽��� �����Ѵ�
    	pimex->Release();
	}
	return -1;
}

// ��� ��ġ�� ����Ǿ��� �� ȣ��Ǵ� �Լ�
void CMoviePlayer::OnPosChanged(WPARAM wParam, LPARAM lParam)
{
	if((HWND)wParam != NULL)
	{
		// �˸� ��� �����쿡�� ��� ��ġ ������ �˸���
		::PostMessage(HWND(wParam), WM_MOVIE_POSCHANGED, 0, (LPARAM)this);
	}
}

// ��Ƽ�̵�� Ÿ�̸Ӹ� �����ϴ� �Լ�
MMRESULT CMoviePlayer::MCSetTimer()
{
	MMRESULT nTimer;

	// ������ ��Ƽ�̵�� Ÿ�̸Ӹ� �����Ѵ�
	if(m_TimerNum) MCKillTimer();

	// ��Ƽ�̵�� Ÿ�̸Ӹ� �����Ѵ�
	nTimer = timeSetEvent(125, 0, TimerProc, DWORD_PTR(&m_TimerParameter), TIME_PERIODIC);

	return nTimer;
}

// ��Ƽ�̵�� Ÿ�̸Ӹ� �����ϴ� �Լ�
void CMoviePlayer::MCKillTimer()
{
	timeKillEvent(m_TimerNum);
	m_TimerNum = NULL;
}

// ��Ƽ�̵�� Ÿ�̸� �ݹ� �Լ�
void CALLBACK TimerProc (UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
	LPTIMERPARAMETER pParam = (LPTIMERPARAMETER)dwUser;

	// ���� ��� ��ġ�� ��´�
	LONGLONG lPos = (LONGLONG)pParam->m_pMoviePlayer->GetCurPosition();

	// ���� ��� ��ġ�� ��ȿ���� �ʴٸ�
	if(lPos < 0 || lPos >= pParam->m_pMoviePlayer->GetDuration())
	{
		// ����� �����Ѵ�
		pParam->m_pMoviePlayer->Stop();

		// �˸� ��� �����쿡�� ����� �����Ǿ����� �˸���
		if(pParam->m_hTimerOwner)
			::PostMessage(pParam->m_hTimerOwner, WM_MOVIE_STOPED, 0, (LPARAM)pParam->m_pMoviePlayer);

		return;
	}

	// �˸� ��� �����쿡�� ��� ��ġ ������ �˸���
	pParam->m_pMoviePlayer->OnPosChanged((WPARAM)pParam->m_hTimerOwner, 0);
} 

// ���� �����츦 ��üȭ������ �����ϰų� �����ϴ� �Լ�
BOOL CMoviePlayer::SetFullScreenMode(BOOL bFullMode)
{
	// ������ �����Ǵ� �̵� ���� ���¶��
	if(!m_bVideoSupport)	return FALSE;
	if(m_pivw == NULL)		return FALSE;

	if(bFullMode)
	{
		// ���� �����츦 ��ü ȭ������ �����Ѵ�
		if(SUCCEEDED(m_pivw->put_FullScreenMode(OATRUE)))
		{
			m_bFullScreenMode = TRUE;
			return TRUE;
		}
	}
	else
	{
		// ���� �����츦 ��ü ȭ�鿡�� �����Ѵ�
		if(SUCCEEDED(m_pivw->put_FullScreenMode(OAFALSE)))
		{
			m_bFullScreenMode = FALSE;
			return TRUE;
		}
	}

	return FALSE;
}

// ���� ��ġ�� �����ϴ� �Լ�
double CMoviePlayer::GetCurPosition()
{
	if(!m_pims)		return -1;

	LONGLONG lCur;

	// ���� ��� ��ġ�� ��´�
	if(FAILED(m_pims->GetCurrentPosition(&lCur)))	return -1;

	return (double) lCur;
}

// ��� ��ġ�� �����ϴ� �Լ�
BOOL CMoviePlayer::SetCurPosition(double dCurPos)
{
	if(m_pims == NULL || m_pimc == NULL)		return FALSE;

	LONGLONG lPos = (LONGLONG) dCurPos;

	// ��� ��ġ�� �̵��Ѵ�
	return SUCCEEDED(m_pims->SetPositions(&lPos, AM_SEEKING_AbsolutePositioning, NULL, AM_SEEKING_NoPositioning));
}

// �� ������ �����ϴ� �Լ�
BOOL CMoviePlayer::SetVolume(LONG lVol)
{
	if(m_piba == NULL)		return FALSE;

	// ���� ���� ���� 0�� �Ѿ�� 0���� �����Ѵ�
	if(lVol > 0) lVol = 0;
	// ����� ���� �� �ִ� ���ļ��� ����Ͽ�,
	// 4000 (400 dB) ������ ���� ���� -10000(Mute)���� �����Ѵ�
	if(lVol <= -4000) lVol = -10000;

	// ������ �����Ѵ�
	if(SUCCEEDED(m_piba->put_Volume(lVol)))
	{
		m_lVolume = lVol;
		return TRUE;
	}

	return FALSE;
}

// ���ҰŸ� �����ϴ� �Լ�
BOOL CMoviePlayer::SetMute(BOOL bMute)
{
	if(m_piba == NULL)			return FALSE;

	if(bMute)
	{
		// ���� ���ҰŶ�� -10000���� ������ �����Ѵ�
		if(SUCCEEDED(m_piba->put_Volume(-10000)))	return TRUE;
	}
	else
	{
		// ���� ���ҰŰ� �ƴ϶�� ���� ������ �����Ѵ�
		if(SetVolume(m_lVolume))			return TRUE;
	}

	return FALSE;
}

// �¿� ���� �뷱����  �����ϴ� �Լ�
BOOL CMoviePlayer::SetBalance(LONG lBal)
{
	if(m_piba == NULL)		return FALSE;

	// �뷱�� ���� ��ȿ���� �˻��Ѵ� : -10000(Left) ~ 10000(Right)
	if(lBal > 10000)	lBal = 10000;
	if(lBal < -10000)	lBal = -10000;

	// �뷱���� �����Ѵ�
	if(SUCCEEDED(m_piba->put_Balance(lBal)))
	{
		m_lBalance = lBal;
		return TRUE;
	}

	return FALSE;
}

void CMoviePlayer::OnSize(UINT nType, int cx, int cy) 
{
	CStatic::OnSize(nType, cx, cy);

	// ������ �ִ� �̵����
	if(m_pivw && m_bVideoSupport)
	{
		CRect rcClient;
		GetClientRect(&rcClient);

		// ���ο� ������ ũ��� ���� ������ ũ�⸦ �����Ѵ�
		m_pivw->SetWindowPosition(rcClient.left, rcClient.top,
			rcClient.right, rcClient.bottom);
	}
}

void CMoviePlayer::OnPaint() 
{
	// ���� ������ �������� �ʴ� ���¶��
	if(!m_bVideoSupport)
	{
		CPaintDC dc(this); // device context for painting
		CRect rcClient;

		// ����� ���������� ĥ�Ѵ�
		GetClientRect(&rcClient);
		dc.FillSolidRect(&rcClient, RGB(0, 0, 0));
	}
}

void CMoviePlayer::OnNcPaint() 
{
	// �θ� ������� �ڽ� ��������� �ٽ� �׷������� �Ѵ�
	GetParent()->RedrawWindow(NULL, NULL, RDW_FRAME | RDW_INTERNALPAINT | RDW_NOERASE | RDW_UPDATENOW | RDW_ALLCHILDREN);
}
