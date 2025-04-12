#ifndef _MP3_PLAYER_H_
#define _MP3_PLAYER_H_


#include <Mmsystem.h>		// ��Ƽ�̵�� Ÿ�̸Ӹ� ���� ��� ����
#include <evcode.h>			// EC_COMPLETE ���� ����� ���� ��� ����
#include <control.h>		// IMediaControl �������̽��� ���� ��� ����
#include <uuids.h>			// CLSID_FilterGraph�� ���� ��� ����
#include <Strmif.h>			// IGraphBuilder ���� �������̽��� ���� ��� ����


// DirectShow�� �˸� �޽���
#define WM_MP3_GRAPHNOTIFY		(WM_USER + 3001)

// MP3�� ��� ��ġ ���濡 ���� �޽���
#define WM_MP3_POSCHANGED		(WM_USER + 3002)
// MP3 ����� ������ ���� �޽���
#define WM_MP3_STOPED			(WM_USER + 3003)

// MP3 ����� ���°� ����� �޽���
#define WM_MP3_CHANGE_STATUS	(WM_USER + 3004)


// MP3 �÷��̾� Ŭ���� ����
class CMP3Player;


// MP3 ���¿� ���� ������ ��� ����
typedef enum _MP3_PLAYER_STATUS
{
	Uninitialized	= 0, 
	Playing			= 1, 
	Paused			= 2, 
	Stopped			= 3 
} MP3_PLAYER_STATUS;

// ��Ƽ�̵�� Ÿ�̸Ӹ� ���� ���� ����ü
typedef struct _TIMER_PARAMETER 
{
	HWND			m_hTimerOwner;
	CMP3Player		*m_pMP3Player;
} TIMERPARAMETER, *LPTIMERPARAMETER;


// MP3 �÷��̾� Ŭ���� ����
class CMP3Player
{
public:
	CMP3Player();
	virtual ~CMP3Player();

	// MP3 ���� ���� �Լ�
	BOOL LoadMP3(LPCTSTR lpszFileName);
	// MP3 ���� �ݱ� �Լ�
	void Close();

	// ��� �Լ�
	BOOL Play();
	// ���� �Լ�
	BOOL Stop();
	// �Ͻ� ���� �Լ�
	BOOL Pause();

	// ���ϸ� ���� �Լ�
	inline LPCTSTR GetFileName()				{ return m_strFileName; }

	// ���� ��ġ�� �����ϴ� �Լ�
	double GetCurPosition();
	// ��� ��ġ�� �����ϴ� �Լ�
	BOOL SetCurPosition(double dCurPos);

	// ���� ������ �����ϴ� �Լ�
	inline LONG GetVolume();
	// �� ������ �����ϴ� �Լ�
	BOOL SetVolume(LONG lVol);
	// ���ҰŸ� �����ϴ� �Լ�
	BOOL SetMute(BOOL bMute);

	// ���� ���� �뷱���� �����ϴ� �Լ�
	inline LONG GetBalance();
	// �¿� ���� �뷱����  �����ϴ� �Լ�
	BOOL SetBalance(LONG lBal);

	// ���� ��� ������ �����ϴ� �Լ�
	inline double GetRate();
	// ���ο� ��� ������ �����ϴ� �Լ�
	inline void SetRate(double dRate);

	// ���� ��ġ�� �����ϴ� �Լ�
	inline double GetStartPos();
	// �� ��ġ�� �����ϴ� �Լ�
	inline double GetEndPos();
	// ��� �ð��� �����ϴ� �Լ�
	inline double GetDuration();

	// MP3 ��� ���� �޽����� ������ �����츦 �����ϴ� �Լ�
	inline HWND SetNotifyWnd(HWND hWnd)			{ return (m_hNotifyWnd = hWnd); }
	// MP3 ��� ���� �޽����� �����ϴ� �����츦 �����ϴ� �Լ�
	inline HWND GetNotifyWnd()					{ return m_hNotifyWnd; }

protected:
	// ���� ���¸� �����ϴ� �Լ�
	inline MP3_PLAYER_STATUS SetStatus(MP3_PLAYER_STATUS nStatus);
public:
	// ���� ���¸� �����ϴ� �Լ�
	inline MP3_PLAYER_STATUS GetStatus();

	// DirectShow �̺�Ʈ�� ó���ϴ� �Լ�
	long OnGraphNotify(long &wParam, long &lParam);
	// ��� ��ġ�� ����Ǿ��� �� ȣ��Ǵ� �Լ�
	void OnPosChanged(WPARAM wParam, LPARAM lParam);

private:
	// ��� ������ �ʱ�ȭ�ϴ� �Լ�
	void ResetVariables();

	// MP3 ���� ����� ���� ���� �������� �����ϴ� �Լ�
	BOOL RenderMP3();

	// ��Ƽ�̵�� Ÿ�̸Ӹ� �����ϴ� �Լ�
	MMRESULT MCSetTimer();
	// ��Ƽ�̵�� Ÿ�̸Ӹ� �����ϴ� �Լ�
	void MCKillTimer();

	// ������ �ε�Ǿ����� ���θ� �����ϴ� �Լ�
	BOOL IsInitialized()	{ return m_Status != Uninitialized; }
	// ����� ������ �������� �����ϴ� �Լ�
	BOOL CanPlay()			{ return (m_Status == Stopped || m_Status == Paused) && m_pigb != NULL; };
	// ������ ������ �������� �����ϴ� �Լ�
	BOOL CanStop()			{ return (m_Status == Playing || m_Status == Paused) && m_pigb != NULL; };
	// �Ͻ� ������ ������ �������� �����ϴ� �Լ�
	BOOL CanPause()			{ return (m_Status == Playing || m_Status == Stopped) && m_pigb != NULL; };

private:
	IGraphBuilder		*m_pigb;				// ���� �׷��� �Ŵ��� �������̽�
	IMediaControl		*m_pimc;				// ��Ʈ���� ���� �������̽�
	IMediaEventEx		*m_pimex;				// �̺�Ʈ�� ���� �������̽�
	IMediaSeeking		*m_pims;				// ��ġ �̵��� ���� �������̽� 
	IBasicAudio			*m_piba;				// ����� ��� ���� �������̽�

	HWND				m_hNotifyWnd;			// �˸� ��� ������

	CString				m_strFileName;			// ���ϸ�

	MP3_PLAYER_STATUS	m_Status;				// ��� ����

	double				m_dStartPos;			// ��� ���� ������ġ
	double				m_dEndPos;				// ��� ���� ����ġ
	double				m_dDuration;			// ��� �ð�

	LONG				m_lVolume;				// ����   (���� : -10000 ~ 0)
	LONG				m_lBalance;				// �뷱�� (���� : -10000 ~ 10000)

	MMRESULT			m_TimerNum;				// Ÿ�̸� ��ȣ
	TIMERPARAMETER		m_TimerParameter;		// Ÿ�̸� �Ķ����

	double				m_dRate;				// ��� �ӵ�
};

// ���� ������ �����ϴ� �Լ�
inline LONG CMP3Player::GetVolume()
{
	return m_lVolume;
}

// ���� ���� �뷱���� �����ϴ� �Լ�
inline LONG CMP3Player::GetBalance()
{
	return m_lBalance;
}

// ���� ��� ������ �����ϴ� �Լ�
inline double CMP3Player::GetRate()
{
	return m_dRate;
}

// ���ο� ��� ������ �����ϴ� �Լ�
inline void CMP3Player::SetRate(double dRate)
{
	m_dRate = dRate;
	m_pims->SetRate(m_dRate);
}

// ���� ��ġ�� �����ϴ� �Լ�
inline double CMP3Player::GetStartPos()
{
	return m_dStartPos;
}

// �� ��ġ�� �����ϴ� �Լ�
inline double CMP3Player::GetEndPos()
{
	return m_dEndPos;
}

// ��� �ð��� �����ϴ� �Լ�
inline double CMP3Player::GetDuration()
{
	return m_dDuration;
}

// ���� ���¸� �����ϴ� �Լ�
inline MP3_PLAYER_STATUS CMP3Player::SetStatus(MP3_PLAYER_STATUS nStatus)
{
	m_Status = nStatus;

	if(m_hNotifyWnd)
		::PostMessage(m_hNotifyWnd, WM_MP3_CHANGE_STATUS, m_Status, LPARAM(this));

	return m_Status;
}

// ���� ���¸� �����ϴ� �Լ�
inline MP3_PLAYER_STATUS CMP3Player::GetStatus()
{
	return m_Status;
}

#endif // _MP3_PLAYER_H_
