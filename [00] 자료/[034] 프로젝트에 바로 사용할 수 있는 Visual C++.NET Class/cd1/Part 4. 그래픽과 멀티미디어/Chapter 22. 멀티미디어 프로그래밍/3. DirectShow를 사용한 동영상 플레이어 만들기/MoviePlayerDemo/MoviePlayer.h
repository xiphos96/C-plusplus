#if !defined(AFX_MOVIEPLAYER_H__01C9B0D4_E048_41C2_8DF0_03D470BE965D__INCLUDED_)
#define AFX_MOVIEPLAYER_H__01C9B0D4_E048_41C2_8DF0_03D470BE965D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MoviePlayer.h : header file
//

#include <Mmsystem.h>		// ��Ƽ�̵�� Ÿ�̸Ӹ� ���� ��� ����
#include <evcode.h>			// EC_COMPLETE ���� ����� ���� ��� ����
#include <control.h>		// IMediaControl �������̽��� ���� ��� ����
#include <uuids.h>			// CLSID_FilterGraph�� ���� ��� ����
#include <Strmif.h>			// IGraphBuilder ���� �������̽��� ���� ��� ����
#include <dshow.h>			// OATRUE, OAFALSE�� ���� ��� ����


// DirectShow�� �˸� �޽���
#define WM_MOVIE_GRAPHNOTIFY	(WM_USER + 3001)

// �������� ��� ��ġ ���濡 ���� �޽���
#define WM_MOVIE_POSCHANGED		(WM_USER + 3002)
// ������ ����� ������ ���� �޽���
#define WM_MOVIE_STOPED			(WM_USER + 3003)
// ������ ����� ���°� ����� �޽���
#define WM_MOVIE_CHANGE_STATUS	(WM_USER + 3004)

// ������ �÷��̾� Ŭ���� ����
class CMoviePlayer;


// ������ ���¿� ���� ������ ��� ����
typedef enum _MOVIE_PLAYER_STATUS
{
	Uninitialized	= 0, 
	Playing			= 1, 
	Paused			= 2, 
	Stopped			= 3 
} MOVIE_PLAYER_STATUS;

// ��Ƽ�̵�� Ÿ�̸Ӹ� ���� ���� ����ü
typedef struct _TIMER_PARAMETER 
{
	HWND			m_hTimerOwner;
	CMoviePlayer	*m_pMoviePlayer;
} TIMERPARAMETER, *LPTIMERPARAMETER;


/////////////////////////////////////////////////////////////////////////////
// CMoviePlayer window

class CMoviePlayer : public CStatic
{
// Construction
public:
	CMoviePlayer();

// Attributes
private:
	IGraphBuilder		*m_pigb;				// ���� �׷��� �Ŵ��� �������̽�
	IMediaControl		*m_pimc;				// ��Ʈ���� ���� �������̽�
	IMediaEventEx		*m_pimex;				// �̺�Ʈ�� ���� �������̽�
	IMediaSeeking		*m_pims;				// ��ġ �̵��� ���� �������̽� 
	IBasicAudio			*m_piba;				// ����� ��� ���� �������̽�
	IVideoWindow		*m_pivw;				// ���� �����쿡 ���� �������̽�
	IBasicVideo			*m_pibv;				// ���� ������ ���� �������̽�

	HWND				m_hNotifyWnd;			// �˸� ��� ������

	CString				m_strFileName;			// ���ϸ�

	MOVIE_PLAYER_STATUS	m_Status;				// ��� ����

	CSize				m_sizeSrc;				// ���� �ҽ� ������
	BOOL				m_bVideoSupport;		// ���� ���� ����
	BOOL				m_bFullScreenMode;		// ��üȭ�� ����

	double				m_dStartPos;			// ��� ���� ������ġ
	double				m_dEndPos;				// ��� ���� ����ġ
	double				m_dDuration;			// ��� �ð�

	LONG				m_lVolume;				// ����   (���� : -10000 ~ 0)
	LONG				m_lBalance;				// �뷱�� (���� : -10000 ~ 10000)

	MMRESULT			m_TimerNum;				// Ÿ�̸� ��ȣ
	TIMERPARAMETER		m_TimerParameter;		// Ÿ�̸� �Ķ����

	double				m_dRate;				// ��� �ӵ�

// Operations
public:

	// ������ ���� ���� �Լ�
	BOOL LoadMedia(LPCTSTR lpszFileName);
	// ������ ���� �ݱ� �Լ�
	void Close();

	// ��� �Լ�
	BOOL Play();
	// ���� �Լ�
	BOOL Stop();
	// �Ͻ� ���� �Լ�
	BOOL Pause();

	// ���ϸ� ���� �Լ�
	inline LPCTSTR GetFileName()				{ return m_strFileName; }

	// ���� �����츦 ��üȭ������ �����ϰų� �����ϴ� �Լ�
	BOOL SetFullScreenMode(BOOL bFullMode);

	// ������ �ִ� �̵�� �������� �����ϴ� �Լ�
	inline BOOL IsVideoSupport();
	// ��ü ȭ�� �������� �����ϴ� �Լ�
	inline BOOL IsFullScreenMode();

	// ������ ���� ���̸� �����ϴ� �Լ�
	inline void GetSourceSize(CSize *pSize);

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

	// ������ ��� ���� �޽����� ������ �����츦 �����ϴ� �Լ�
	inline HWND SetNotifyWnd(HWND hWnd)			{ return (m_hNotifyWnd = hWnd); }
	// ������ ��� ���� �޽����� �����ϴ� �����츦 �����ϴ� �Լ�
	inline HWND GetNotifyWnd()					{ return m_hNotifyWnd; }

protected:
	// ���� ���¸� �����ϴ� �Լ�
	inline MOVIE_PLAYER_STATUS SetStatus(MOVIE_PLAYER_STATUS nStatus);
public:
	// ���� ���¸� �����ϴ� �Լ�
	inline MOVIE_PLAYER_STATUS GetStatus();

	// DirectShow �̺�Ʈ�� ó���ϴ� �Լ�
	long OnGraphNotify(long &wParam, long &lParam);
	// ��� ��ġ�� ����Ǿ��� �� ȣ��Ǵ� �Լ�
	void OnPosChanged(WPARAM wParam, LPARAM lParam);

private:
	// ��� ������ �ʱ�ȭ�ϴ� �Լ�
	void ResetVariables();

	// ������ ���� ����� ���� ���� �������� �����ϴ� �Լ�
	BOOL RenderMedia();

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

public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoviePlayer)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMoviePlayer();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMoviePlayer)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnNcPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

// ������ �ִ� �̵�� �������� �����ϴ� �Լ�
inline BOOL CMoviePlayer::IsVideoSupport()
{
	return m_bVideoSupport;
}

// ��ü ȭ�� �������� �����ϴ� �Լ�
inline BOOL CMoviePlayer::IsFullScreenMode()
{
	return m_bFullScreenMode;
}

// ������ ���� ���̸� �����ϴ� �Լ�
inline void CMoviePlayer::GetSourceSize(CSize *pSize)
{
	pSize->cx = m_sizeSrc.cx;
	pSize->cy = m_sizeSrc.cy;
}

// ���� ������ �����ϴ� �Լ�
inline LONG CMoviePlayer::GetVolume()
{
	return m_lVolume;
}

// ���� ���� �뷱���� �����ϴ� �Լ�
inline LONG CMoviePlayer::GetBalance()
{
	return m_lBalance;
}

// ���� ��� ������ �����ϴ� �Լ�
inline double CMoviePlayer::GetRate()
{
	return m_dRate;
}

// ���ο� ��� ������ �����ϴ� �Լ�
inline void CMoviePlayer::SetRate(double dRate)
{
	m_dRate = dRate;
	m_pims->SetRate(m_dRate);
}

// ���� ��ġ�� �����ϴ� �Լ�
inline double CMoviePlayer::GetStartPos()
{
	return m_dStartPos;
}

// �� ��ġ�� �����ϴ� �Լ�
inline double CMoviePlayer::GetEndPos()
{
	return m_dEndPos;
}

// ��� �ð��� �����ϴ� �Լ�
inline double CMoviePlayer::GetDuration()
{
	return m_dDuration;
}

// ���� ���¸� �����ϴ� �Լ�
inline MOVIE_PLAYER_STATUS CMoviePlayer::SetStatus(MOVIE_PLAYER_STATUS nStatus)
{
	m_Status = nStatus;

	if(m_hNotifyWnd)
		::PostMessage(m_hNotifyWnd, WM_MOVIE_CHANGE_STATUS, m_Status, LPARAM(this));

	return m_Status;
}

// ���� ���¸� �����ϴ� �Լ�
inline MOVIE_PLAYER_STATUS CMoviePlayer::GetStatus()
{
	return m_Status;
}

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVIEPLAYER_H__01C9B0D4_E048_41C2_8DF0_03D470BE965D__INCLUDED_)
