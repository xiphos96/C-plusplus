// MediaControllerEx.cpp : implementation file
//

#include "stdafx.h"
#include "MP3Player.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// DirectShow 라이브러리 링크
#ifdef _AFXDLL
	#ifdef _DEBUG
		#pragma comment(lib, "strmbasd.lib")
	#else
		#pragma comment(lib, "strmbase.lib")
	#endif
#endif

// 멀티미디어 라이브러리 링크
#pragma comment(lib, "winmm.lib")

// 멀티미디어 타이머 콜백 함수 선언
void CALLBACK TimerProc (UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2);



CMP3Player::CMP3Player()
{
	// 멀티미디어 타이머 인자를 초기화한다
	::memset(&m_TimerParameter, 0, sizeof(m_TimerParameter));
	m_TimerParameter.m_pMP3Player = this;

	// 멤버 변수들을 초기화한다
	m_hNotifyWnd = NULL;

	ResetVariables();
}

CMP3Player::~CMP3Player()
{
	// 실행되고 있는 미디어를 닫는다
	Close();
}

// 멤버 변수를 초기화하는 함수
void CMP3Player::ResetVariables()
{
	m_pigb = NULL; 
	m_pimc = NULL;
	m_pimex = NULL;
	m_pims = NULL;
	m_piba = NULL;

	m_strFileName.Empty();

	SetStatus(Uninitialized);

	m_dRate = 1.0;
	m_dStartPos = 0;
	m_dEndPos = 0;
	m_dDuration = 0;

	m_lVolume = 0;
	m_lBalance = 0;

	m_TimerNum = NULL;
}

// MP3 파일 열기 함수
BOOL CMP3Player::LoadMP3(LPCTSTR lpszFileName)
{
	// 이미 열린 MP3 파일이 있다면 닫는다
	if(m_pigb != NULL)		Close();

	// 새 파일 경로를 저장한다
	m_strFileName = lpszFileName;

	// MP3 파일을 렌더링한다
	if(!RenderMP3())		return FALSE;

	// MP3 파일의 재생 시간을 얻어 저장한다
	LONGLONG lDuration;
	if(SUCCEEDED(m_pims->GetDuration(&lDuration)))
		m_dDuration = (double) lDuration;

	// MP3 파일의 시작 위치와 끝 위치를 얻어 저장한다
	LONGLONG lSPos, lEPos;
	if(SUCCEEDED(m_pims->GetAvailable(&lSPos, &lEPos)))
	{
		m_dStartPos = (double) lSPos;
		m_dEndPos = (double) lEPos;
	}

	SetCurPosition(m_dStartPos);

	// 현재 재생 상태를 정지 상태로 변경한다
	SetStatus(Stopped);

	return TRUE;
}

// MP3 파일 재생을 위한 필터 렌더링을 실행하는 함수
BOOL CMP3Player::RenderMP3()
{
	// 필터 그래프 메니저 생성
    if(FAILED(CoCreateInstance(CLSID_FilterGraph,
								 NULL,
								 CLSCTX_INPROC_SERVER,
								 IID_IGraphBuilder,
								 (void **) &m_pigb)))
	{
		// 필터 그래프 매니저 생성에 실패하면 초기화한다
		Close();
		return FALSE;
	}

	// 파일명을 유니코드로 변환한다
	WCHAR wFileName[MAX_PATH];
    MultiByteToWideChar(CP_ACP, 0, (LPCTSTR) m_strFileName,
                        -1, wFileName, MAX_PATH);

	// 필터 그래프를 구성한다
	if(FAILED(m_pigb->RenderFile(wFileName, NULL)))
	{
		Close();
		return FALSE;
	}

	// 미디어 컨트롤 인터페이스를 얻는다
	if(FAILED(m_pigb->QueryInterface(IID_IMediaControl, (void **) &m_pimc)))
	{
		Close();
		return FALSE;
	}
	// 이벤트 인터페이스를 얻는다
	if(FAILED(m_pigb->QueryInterface(IID_IMediaEventEx, (void **) &m_pimex)))
	{
		Close();
		return FALSE;
	}
	// 위치 이동 인터페이스를 얻는다
	if(FAILED(m_pigb->QueryInterface(IID_IMediaSeeking, (void **) &m_pims)))
	{
		Close();
		return FALSE;
	}
	// 오디오 인터페이스를 얻는다
	if(FAILED(m_pigb->QueryInterface(IID_IBasicAudio, (void **) &m_piba)))
	{
		Close();
		return FALSE;
	}

	// 미디어에 관한 이벤트 수신 윈도우를 설정한다
	if(FAILED(m_pimex->SetNotifyWindow((OAHWND)m_hNotifyWnd, WM_MP3_GRAPHNOTIFY, (long)this)))
	{
		Close();
		return FALSE;
	}
	// 미디어 이동의 단위를 미디어 시간 단위로 설정한다
	if(FAILED(m_pims->SetTimeFormat(&TIME_FORMAT_MEDIA_TIME)))
	{
		Close();
		return FALSE;
	}

	// 멀티미디어 타이머 인자에 알림 대상 윈도우의 핸들을 설정한다
	m_TimerParameter.m_hTimerOwner = m_hNotifyWnd;

	return TRUE;
}

// 재생 함수
BOOL CMP3Player::Play()
{
	// 재생 가능한 상태라면
	if(CanPlay())
	{
		// 재생을 시작한다
		if(SUCCEEDED(m_pimc->Run()))
		{
			// 현재 상태를 저장한다
			SetStatus(Playing);

			// 위치 이동을 반영할 수 있도록 멀티미디어 타이머를 실행한다
			m_TimerNum = MCSetTimer();

			return TRUE;
		}
	}

	return FALSE;
}

// 정지 함수
BOOL CMP3Player::Stop()
{
	// 정지 가능한 상태라면
	if(CanStop())
	{
		// 재생을 정지한다
		if(SUCCEEDED(m_pimc->Stop()))
		{
			// 현재 상태를 저장한다
			SetStatus(Stopped);

			// 멀티미디어 타이머를 정지한다
			MCKillTimer();

			// 현재 위치를 처음으로 옮긴다
			SetCurPosition(0);

			// 알림 대상 윈도우에게 정지 상태를 알린다
			if(m_TimerParameter.m_hTimerOwner)
				::PostMessage(m_TimerParameter.m_hTimerOwner, WM_MP3_STOPED, 0, LPARAM(this));

			return TRUE;
		}
	}

	return FALSE;
}

// 일시 정지 함수
BOOL CMP3Player::Pause()
{
	// 일시 정지 가능한 상태라면
	if(CanPause())
	{
		// 일시 정지한다
		if(SUCCEEDED(m_pimc->Pause()))
		{
			// 현재 상태를 저장한다
			SetStatus(Paused);

			// 멀티미디어 타이머를 정지한다
			MCKillTimer();

			return TRUE;
		}
	}

	return FALSE;
}

// MP3 파일 닫기 함수
void CMP3Player::Close()
{
	// 현재 실행 중인 멀티미디어 타이머를 종료한다
	if(m_TimerNum) MCKillTimer();

	// 인터페이스들을 해제한다
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

	// 멤버 변수들을 초기화한다
	ResetVariables();
}

// DirectShow 이벤트를 처리하는 함수
long CMP3Player::OnGraphNotify(long &wParam, long &lParam)
{
	if(!m_pigb)		return -1;

	IMediaEventEx *pimex;
    long lEventCode;

	// 미디어 이벤트 인터페이스를 얻는다
	if(SUCCEEDED(m_pigb->QueryInterface(IID_IMediaEventEx, (void **) &pimex)))
	{
		// 현재 발생한 이벤트를 얻어온다
        if(SUCCEEDED(pimex->GetEvent(&lEventCode, &wParam, &lParam, 0)))
		{
			// 이벤트 인자들을 해제한다
            HRESULT hr = pimex->FreeEventParams(lEventCode, wParam, lParam);

			// 만약 재생 완료 이벤트라면
			if(lEventCode == EC_COMPLETE)
			{
				// 재생을 정지한다
				Stop();

				// 현재 위치를 처음 위치로 이동한다
				if(m_pims != NULL && m_pimc != NULL)
				{
					SetCurPosition(0.0);
				}
			}

			// 미디어 이벤트 인터페이스를 해제한다
			pimex->Release();

			// 이벤트를 리턴한다
			return lEventCode;
        }
		// 미디어 이벤트 인터페이스를 해제한다
    	pimex->Release();
	}
	return -1;
}

// 재생 위치가 변경되었을 때 호출되는 함수
void CMP3Player::OnPosChanged(WPARAM wParam, LPARAM lParam)
{
	if((HWND)wParam != NULL)
	{
		// 알림 대상 윈도우에게 재생 위치 변경을 알린다
		::PostMessage(HWND(wParam), WM_MP3_POSCHANGED, 0, (LPARAM)this);
	}
}

// 멀티미디어 타이머를 실행하는 함수
MMRESULT CMP3Player::MCSetTimer()
{
	MMRESULT nTimer;

	// 이전의 멀티미디어 타이머를 정지한다
	if(m_TimerNum) MCKillTimer();

	// 멀티미디어 타이머를 실행한다
	nTimer = timeSetEvent(125, 0, TimerProc, DWORD_PTR(&m_TimerParameter), TIME_PERIODIC);

	return nTimer;
}

// 멀티미디어 타이머를 정지하는 함수
void CMP3Player::MCKillTimer()
{
	timeKillEvent(m_TimerNum);
	m_TimerNum = NULL;
}

// 멀티미디어 타이머 콜백 함수
void CALLBACK TimerProc (UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
	LPTIMERPARAMETER pParam = (LPTIMERPARAMETER)dwUser;

	// 현재 재생 위치를 얻는다
	LONGLONG lPos = (LONGLONG)pParam->m_pMP3Player->GetCurPosition();

	// 현재 재생 위치가 유효하지 않다면
	if(lPos < 0 || lPos >= pParam->m_pMP3Player->GetDuration())
	{
		// 재생을 정지한다
		pParam->m_pMP3Player->Stop();
		// 멀티미디어 타이머를 정지한다
		timeKillEvent(uID);

		// 알림 대상 윈도우에게 재생이 정지되었음을 알린다
		if(pParam->m_hTimerOwner)
			::PostMessage(pParam->m_hTimerOwner, WM_MP3_STOPED, 0, (LPARAM)pParam->m_pMP3Player);

		return;
	}

	// 알림 대상 윈도우에게 재생 위치 변경을 알린다
	pParam->m_pMP3Player->OnPosChanged((WPARAM)pParam->m_hTimerOwner, 0);
} 

// 현재 위치를 리턴하는 함수
double CMP3Player::GetCurPosition()
{
	if(!m_pims)		return -1;

	LONGLONG lCur;

	// 현재 재생 위치를 얻는다
	if(FAILED(m_pims->GetCurrentPosition(&lCur)))	return -1;

	return (double) lCur;
}

// 재생 위치를 변경하는 함수
BOOL CMP3Player::SetCurPosition(double dCurPos)
{
	if(m_pims == NULL || m_pimc == NULL)		return FALSE;

	LONGLONG lPos = (LONGLONG) dCurPos;

	// 재생 위치를 이동한다
	return SUCCEEDED(m_pims->SetPositions(&lPos, AM_SEEKING_AbsolutePositioning, NULL, AM_SEEKING_NoPositioning));
}

// 새 볼륨을 설정하는 함수
BOOL CMP3Player::SetVolume(LONG lVol)
{
	if(m_piba == NULL)		return FALSE;

	// 만약 볼륨 값이 0을 넘어서면 0으로 조정한다
	if(lVol > 0) lVol = 0;
	// 사람이 들을 수 있는 주파수를 고려하여,
	// 4000 (400 dB) 이하의 값인 경우는 -10000(Mute)으로 변경한다
	if(lVol <= -4000) lVol = -10000;

	// 볼륨을 설정한다
	if(SUCCEEDED(m_piba->put_Volume(lVol)))
	{
		m_lVolume = lVol;
		return TRUE;
	}

	return FALSE;
}

// 음소거를 설정하는 함수
BOOL CMP3Player::SetMute(BOOL bMute)
{
	if(m_piba == NULL)			return FALSE;

	if(bMute)
	{
		// 만약 음소거라면 -10000으로 볼륨을 설정한다
		if(SUCCEEDED(m_piba->put_Volume(-10000)))	return TRUE;
	}
	else
	{
		// 만약 음소거가 아니라면 이전 볼륨을 설정한다
		if(SetVolume(m_lVolume))			return TRUE;
	}

	return FALSE;
}

// 좌우 사운드 밸런스를  설정하는 함수
BOOL CMP3Player::SetBalance(LONG lBal)
{
	if(m_piba == NULL)		return FALSE;

	// 밸런스 값이 유효한지 검사한다 : -10000(Left) ~ 10000(Right)
	if(lBal > 10000)	lBal = 10000;
	if(lBal < -10000)	lBal = -10000;

	// 밸런스를 설정한다
	if(SUCCEEDED(m_piba->put_Balance(lBal)))
	{
		m_lBalance = lBal;
		return TRUE;
	}

	return FALSE;
}
