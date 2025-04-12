// MCIMediaPlayer.cpp : implementation file
//

#include "stdafx.h"
#include "MCIMediaPlayerDemo.h"
#include "MCIMediaPlayer.h"


// Video for Windows 라이브러리 링크
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
	// 멤버 변수들을 초기화한다
	m_hMCIWnd		= NULL;
	m_nMediaTime	= 0;
	m_nCurPos		= 0;
	m_bSeek			= FALSE;
}

CMCIMediaPlayer::~CMCIMediaPlayer()
{
	// MCI 윈도우가 닫히지 않았다면 닫는다
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
	// 만약 현재 미디어가 열리지 않았거나 
	// 실행 상태가 아닌 경우는 배경을 검은색으로 출력한다
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

	// MCI 윈도우를 닫는다
	if(m_hMCIWnd)
	{
		CloseMedia();
		MCIWndDestroy(m_hMCIWnd);
	}
	m_hMCIWnd = NULL;
}

// 미디어 파일을 로드하는 함수
BOOL CMCIMediaPlayer::LoadMedia(LPCTSTR pFileName)
{
	// 현재 열린 미디어 파일을 닫는다
	CloseMedia();
	
	m_strFileName = pFileName;

	// MCI 윈도우를 생성한다
	m_hMCIWnd = ::MCIWndCreate(m_hWnd, AfxGetApp()->m_hInstance,
		WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN
		| MCIWNDF_NOMENU| MCIWNDF_NOTIFYPOS | MCIWNDF_NOTIFYMODE | MCIWNDF_NOPLAYBAR,
		m_strFileName);

	if(m_hMCIWnd == NULL)		return FALSE;

	// 재생 시간 형식을 ms(1/1000초)로 설정한다
	MCIWndSetTimeFormat(m_hMCIWnd, "ms");
	// CMCIMediaPlayer의 전체 크기에 맞게 MCI 윈도우의 크기를 조정한다
	::ShowWindow(m_hMCIWnd, SW_MAXIMIZE); 	

	// 미디어의 전체 재생 시간을 얻는다
	m_nMediaTime = 	MCIWndGetLength(m_hMCIWnd);

	return TRUE;
}

// 미디어 파일을 닫는 함수
BOOL CMCIMediaPlayer::CloseMedia()
{
	if(m_hMCIWnd == NULL)	return FALSE;

	// 미디어 재생을 정지한다
	MCIWndStop(m_hMCIWnd);
	// 미디어 파일을 닫는다
	MCIWndClose(m_hMCIWnd);
	m_hMCIWnd = NULL;

	m_nMediaTime = 0;
	m_nCurPos = 0;
	m_strFileName.Empty();

	return TRUE;
}

// 재생 함수
void CMCIMediaPlayer::Play()
{
	if(m_hMCIWnd == NULL)	return;

	MCIWndPlay(m_hMCIWnd);
}

// 정지 함수
void CMCIMediaPlayer::Stop()
{
	if(m_hMCIWnd == NULL)	return;

	MCIWndStop(m_hMCIWnd);
}

// 일시 정지 함수
void CMCIMediaPlayer::Pause()
{
	if(m_hMCIWnd == NULL)	return;

	MCIWndPause(m_hMCIWnd);
}

// 재시작 함수
void CMCIMediaPlayer::Resume()
{
	if(m_hMCIWnd == NULL)	return;

	MCIWndResume(m_hMCIWnd);
}

// 미디어의 전체 재생 시간을 리턴하는 함수
LONG CMCIMediaPlayer::GetMediaTime()
{
	if(m_hMCIWnd == NULL)	return -1;

	return m_nMediaTime;
}

// 미디어의 현재 재생 위치를 리턴하는 함수
LONG CMCIMediaPlayer::GetCurPos()
{
	if(m_hMCIWnd == NULL)	return -1;

	return m_nCurPos;
}

// 미디어의 재생 위치를 옮기는 함수
BOOL CMCIMediaPlayer::SetCurPos(LONG nPos)
{
	if(m_hMCIWnd == NULL)	return FALSE;

	// 새로 이동될 위치가 유효한지 검사한다
	if(nPos > m_nMediaTime)		nPos = m_nMediaTime;
	if(nPos < MCIWndGetStart(m_hMCIWnd))
		nPos = MCIWndGetStart(m_hMCIWnd);

	BOOL bRunning = GetStatus() == MCI_MODE_PLAY;

	// 위치 이동 중임을 설정한다
	m_bSeek = TRUE;

	// 만약 현재 재생 중이라면 정지한다
	if(bRunning)	Stop();

	// 재생 위치를 이동한다
	LONG nRet = MCIWndSeek(m_hMCIWnd, nPos);

	// 만약 재생 중이었다면 다시 재생한다
	if(bRunning)	Play();
	
	// 위치 이동이 끝났음을 설정한다
	m_bSeek = FALSE;

	return (nRet == 0);
}

// 현재 재생 상태를 리턴하는 함수
LONG CMCIMediaPlayer::GetStatus()
{
	if(m_hMCIWnd == NULL)		return MCI_MODE_NOT_READY;

	return MCIWndGetMode(m_hMCIWnd, 0, 0);
}

// 현재 볼륨을 리턴하는 함수
LONG CMCIMediaPlayer::GetVolume()
{
	if(m_hMCIWnd == NULL)	return -1;

	return MCIWndGetVolume(m_hMCIWnd);
}

// 볼륨을 설정하는 함수
void CMCIMediaPlayer::SetVolume(LONG nVolume)
{
	if(m_hMCIWnd == NULL)	return;

	MCIWndSetVolume(m_hMCIWnd, nVolume);
}

// 미디어의 재생 상태가 변경되었을 때 실행되는 함수
LRESULT CMCIMediaPlayer::OnChangeStatus(WPARAM wParam, LPARAM lParam)
{
	if(m_bSeek)		return 0;

	// 부모 윈도우에게 미디어 재생 상태 변경을 알린다
	if(GetParent())
		GetParent()->SendMessage(WM_MMP_CHANGE_STATUS, (WPARAM)this, lParam);

	switch(lParam)
	{
	case MCI_MODE_PLAY:
		// 만약 재생이 시작되면 미디어 위치 검사를 위해 타이머를 시작한다
		SetTimer(1, 100, NULL);
		break;
	case MCI_MODE_STOP:
		// 만약 재생이 정지되면 처음 위치로 이동한다
		SetCurPos(0);
	case MCI_MODE_PAUSE:
		// 만약 재생이 정지되거나 일시 정지되면 타이머를 멈춘다
		KillTimer(1);
		break;
	}

	return 0;
}

// 미디어의 재생 위치가 변경되었을 때 실행되는 함수
LRESULT CMCIMediaPlayer::OnChangePos(WPARAM wParam, LPARAM lParam)
{
	if(m_bSeek)		return 0;

	if(GetParent())
	{
		// 부모 윈도우에게 재생 위치 변경을 알린다
		GetParent()->SendMessage(WM_MMP_CHANGE_POSITION, (WPARAM)this, lParam);
		// 부모 윈도우와 자식 윈도우들이 다시 그려지도록 한다
		GetParent()->RedrawWindow(NULL, NULL, RDW_FRAME | RDW_INTERNALPAINT | RDW_NOERASE | RDW_UPDATENOW | RDW_ALLCHILDREN);
	}

	TRACE("Media Current Position : %d\n", lParam);

	// 현재 위치를 저장한다
	m_nCurPos = lParam;

	return 0;
}

// 재생 위치 변경을 확인하기 위한 타이머 함수
void CMCIMediaPlayer::OnTimer(UINT nIDEvent) 
{
	// 현재 재생 위치를 얻는다
	LONG nCurPos = MCIWndGetPosition(m_hMCIWnd);

	// 만약 재생 위치가 변경되었다면
	if(nCurPos != m_nCurPos)
	{
		// 현재 위치를 다시 저장한다
		m_nCurPos = nCurPos;

		// 부모 윈도우에게 재생 위치 변경을 알린다
		GetParent()->SendMessage(WM_MMP_CHANGE_POSITION, (WPARAM)this, m_nCurPos);
		// 부모 윈도우와 자식 윈도우들이 다시 그려지도록 한다
		GetParent()->RedrawWindow(NULL, NULL, RDW_FRAME | RDW_INTERNALPAINT | RDW_NOERASE | RDW_UPDATENOW | RDW_ALLCHILDREN);
	}
	
	CStatic::OnTimer(nIDEvent);
}

// 부모 윈도우의 화면 갱신이 정확하게 이뤄지기 위해 필요한 함수
void CMCIMediaPlayer::OnNcPaint() 
{
	// 부모 윈도우와 자식 윈도우들이 다시 그려지도록 한다
	GetParent()->RedrawWindow(NULL, NULL, RDW_FRAME | RDW_INTERNALPAINT | RDW_NOERASE | RDW_UPDATENOW | RDW_ALLCHILDREN);
}
