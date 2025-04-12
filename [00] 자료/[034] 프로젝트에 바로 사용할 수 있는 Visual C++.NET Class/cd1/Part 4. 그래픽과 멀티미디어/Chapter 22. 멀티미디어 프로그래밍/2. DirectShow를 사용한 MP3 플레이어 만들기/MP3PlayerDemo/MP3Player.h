#ifndef _MP3_PLAYER_H_
#define _MP3_PLAYER_H_


#include <Mmsystem.h>		// 멀티미디어 타이머를 위한 헤더 파일
#include <evcode.h>			// EC_COMPLETE 등의 상수를 위한 헤더 파일
#include <control.h>		// IMediaControl 인터페이스를 위한 헤더 파일
#include <uuids.h>			// CLSID_FilterGraph를 위한 헤더 파일
#include <Strmif.h>			// IGraphBuilder 등의 인터페이스를 위한 헤더 파일


// DirectShow의 알림 메시지
#define WM_MP3_GRAPHNOTIFY		(WM_USER + 3001)

// MP3의 재생 위치 변경에 대한 메시지
#define WM_MP3_POSCHANGED		(WM_USER + 3002)
// MP3 재생이 정지된 상태 메시지
#define WM_MP3_STOPED			(WM_USER + 3003)

// MP3 재생의 상태가 변경된 메시지
#define WM_MP3_CHANGE_STATUS	(WM_USER + 3004)


// MP3 플레이어 클래스 선언
class CMP3Player;


// MP3 상태에 대한 나열형 상수 정의
typedef enum _MP3_PLAYER_STATUS
{
	Uninitialized	= 0, 
	Playing			= 1, 
	Paused			= 2, 
	Stopped			= 3 
} MP3_PLAYER_STATUS;

// 멀티미디어 타이머를 위한 인자 구조체
typedef struct _TIMER_PARAMETER 
{
	HWND			m_hTimerOwner;
	CMP3Player		*m_pMP3Player;
} TIMERPARAMETER, *LPTIMERPARAMETER;


// MP3 플레이어 클래스 정의
class CMP3Player
{
public:
	CMP3Player();
	virtual ~CMP3Player();

	// MP3 파일 열기 함수
	BOOL LoadMP3(LPCTSTR lpszFileName);
	// MP3 파일 닫기 함수
	void Close();

	// 재생 함수
	BOOL Play();
	// 정지 함수
	BOOL Stop();
	// 일시 정지 함수
	BOOL Pause();

	// 파일명 리턴 함수
	inline LPCTSTR GetFileName()				{ return m_strFileName; }

	// 현재 위치를 리턴하는 함수
	double GetCurPosition();
	// 재생 위치를 변경하는 함수
	BOOL SetCurPosition(double dCurPos);

	// 현재 볼륨을 리턴하는 함수
	inline LONG GetVolume();
	// 새 볼륨을 설정하는 함수
	BOOL SetVolume(LONG lVol);
	// 음소거를 설정하는 함수
	BOOL SetMute(BOOL bMute);

	// 현재 사운드 밸런스를 리턴하는 함수
	inline LONG GetBalance();
	// 좌우 사운드 밸런스를  설정하는 함수
	BOOL SetBalance(LONG lBal);

	// 현재 재생 비율을 리턴하는 함수
	inline double GetRate();
	// 새로운 재생 비율을 설정하는 함수
	inline void SetRate(double dRate);

	// 시작 위치를 리턴하는 함수
	inline double GetStartPos();
	// 끝 위치를 리턴하는 함수
	inline double GetEndPos();
	// 재생 시간을 리턴하는 함수
	inline double GetDuration();

	// MP3 재생 관련 메시지를 수신할 윈도우를 설정하는 함수
	inline HWND SetNotifyWnd(HWND hWnd)			{ return (m_hNotifyWnd = hWnd); }
	// MP3 재생 관련 메시지를 수신하는 윈도우를 리턴하는 함수
	inline HWND GetNotifyWnd()					{ return m_hNotifyWnd; }

protected:
	// 현재 상태를 설정하는 함수
	inline MP3_PLAYER_STATUS SetStatus(MP3_PLAYER_STATUS nStatus);
public:
	// 현재 상태를 리턴하는 함수
	inline MP3_PLAYER_STATUS GetStatus();

	// DirectShow 이벤트를 처리하는 함수
	long OnGraphNotify(long &wParam, long &lParam);
	// 재생 위치가 변경되었을 때 호출되는 함수
	void OnPosChanged(WPARAM wParam, LPARAM lParam);

private:
	// 멤버 변수를 초기화하는 함수
	void ResetVariables();

	// MP3 파일 재생을 위한 필터 렌더링을 실행하는 함수
	BOOL RenderMP3();

	// 멀티미디어 타이머를 실행하는 함수
	MMRESULT MCSetTimer();
	// 멀티미디어 타이머를 정지하는 함수
	void MCKillTimer();

	// 파일이 로드되었는지 여부를 리턴하는 함수
	BOOL IsInitialized()	{ return m_Status != Uninitialized; }
	// 재생이 가능한 상태인지 리턴하는 함수
	BOOL CanPlay()			{ return (m_Status == Stopped || m_Status == Paused) && m_pigb != NULL; };
	// 정지가 가능한 상태인지 리턴하는 함수
	BOOL CanStop()			{ return (m_Status == Playing || m_Status == Paused) && m_pigb != NULL; };
	// 일시 정지가 가능한 상태인지 리턴하는 함수
	BOOL CanPause()			{ return (m_Status == Playing || m_Status == Stopped) && m_pigb != NULL; };

private:
	IGraphBuilder		*m_pigb;				// 필터 그래프 매니저 인터페이스
	IMediaControl		*m_pimc;				// 컨트롤을 위한 인터페이스
	IMediaEventEx		*m_pimex;				// 이벤트를 위한 인터페이스
	IMediaSeeking		*m_pims;				// 위치 이동을 위한 인터페이스 
	IBasicAudio			*m_piba;				// 오디오 제어를 위한 인터페이스

	HWND				m_hNotifyWnd;			// 알림 대상 윈도우

	CString				m_strFileName;			// 파일명

	MP3_PLAYER_STATUS	m_Status;				// 재생 상태

	double				m_dStartPos;			// 재생 가능 시작위치
	double				m_dEndPos;				// 재생 가능 끝위치
	double				m_dDuration;			// 재생 시간

	LONG				m_lVolume;				// 볼륨   (범위 : -10000 ~ 0)
	LONG				m_lBalance;				// 밸런스 (범위 : -10000 ~ 10000)

	MMRESULT			m_TimerNum;				// 타이머 번호
	TIMERPARAMETER		m_TimerParameter;		// 타이머 파라미터

	double				m_dRate;				// 재생 속도
};

// 현재 볼륨을 리턴하는 함수
inline LONG CMP3Player::GetVolume()
{
	return m_lVolume;
}

// 현재 사운드 밸런스를 리턴하는 함수
inline LONG CMP3Player::GetBalance()
{
	return m_lBalance;
}

// 현재 재생 비율을 리턴하는 함수
inline double CMP3Player::GetRate()
{
	return m_dRate;
}

// 새로운 재생 비율을 설정하는 함수
inline void CMP3Player::SetRate(double dRate)
{
	m_dRate = dRate;
	m_pims->SetRate(m_dRate);
}

// 시작 위치를 리턴하는 함수
inline double CMP3Player::GetStartPos()
{
	return m_dStartPos;
}

// 끝 위치를 리턴하는 함수
inline double CMP3Player::GetEndPos()
{
	return m_dEndPos;
}

// 재생 시간을 리턴하는 함수
inline double CMP3Player::GetDuration()
{
	return m_dDuration;
}

// 현재 상태를 설정하는 함수
inline MP3_PLAYER_STATUS CMP3Player::SetStatus(MP3_PLAYER_STATUS nStatus)
{
	m_Status = nStatus;

	if(m_hNotifyWnd)
		::PostMessage(m_hNotifyWnd, WM_MP3_CHANGE_STATUS, m_Status, LPARAM(this));

	return m_Status;
}

// 현재 상태를 리턴하는 함수
inline MP3_PLAYER_STATUS CMP3Player::GetStatus()
{
	return m_Status;
}

#endif // _MP3_PLAYER_H_
