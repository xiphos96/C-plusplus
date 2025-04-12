#if !defined(AFX_MCIMEDIAPLAYER_H__05850C33_BD73_477A_BA8B_D26F087B2487__INCLUDED_)
#define AFX_MCIMEDIAPLAYER_H__05850C33_BD73_477A_BA8B_D26F087B2487__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MCIMediaPlayer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMCIMediaPlayer window


// Video for Windows 헤더 파일 인크루드
#include "vfw.h"


// 미디어 상태 변화에 대한 알림 메시지
#define WM_MMP_CHANGE_STATUS		(WM_USER + 500)
// 미디어 위치 변화에 대한 알림 메시지
#define WM_MMP_CHANGE_POSITION		(WM_USER + 501)


class CMCIMediaPlayer : public CStatic
{
// Construction
public:
	CMCIMediaPlayer();

// Attributes
public:
	HWND		m_hMCIWnd;			// MCI 윈도우 핸들

	CString		m_strFileName;		// 미디어 파일 경로
	LONG		m_nMediaTime;		// 전체 미디어 시간
	LONG		m_nCurPos;			// 현재 재생 위치
	BOOL		m_bSeek;			// 현재 위치 이동 중인지 여부

// Operations
public:
	// 미디어 파일을 로드하는 함수
	BOOL LoadMedia(LPCTSTR pFileName);
	// 미디어 파일을 닫는 함수
	BOOL CloseMedia();

	// 재생 함수
	void Play();
	// 정지 함수
	void Stop();
	// 일시 정지 함수
	void Pause();
	// 재시작 함수
	void Resume();

	// 미디어의 전체 재생 시간을 리턴하는 함수
	LONG GetMediaTime();
	// 미디어의 현재 재생 위치를 리턴하는 함수
	LONG GetCurPos();
	// 미디어의 재생 위치를 옮기는 함수
	BOOL SetCurPos(LONG nPos);

	// 현재 로드된 상태인지 리턴하는 함수
	BOOL IsLoaded()					{ return (BOOL)m_hMCIWnd; }
	// 현재 재생 상태를 리턴하는 함수
	LONG GetStatus();

	// 현재 볼륨을 리턴하는 함수
	LONG GetVolume();
	// 볼륨을 설정하는 함수
	void SetVolume(LONG nVolume);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMCIMediaPlayer)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMCIMediaPlayer();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMCIMediaPlayer)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnNcPaint();
	//}}AFX_MSG
	afx_msg LRESULT OnChangeStatus(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnChangePos(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MCIMEDIAPLAYER_H__05850C33_BD73_477A_BA8B_D26F087B2487__INCLUDED_)
