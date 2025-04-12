// MoviePlayerDemoDlg.h : 헤더 파일
//

#pragma once

// 동영상 플레이어 클래스 헤더 파일
#include "MoviePlayer.h"


// CMoviePlayerDemoDlg 대화 상자
class CMoviePlayerDemoDlg : public CDialog
{
// 생성
public:
	CMoviePlayerDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CMoviePlayerDemoDlg)
	enum { IDD = IDD_MOVIEPLAYERDEMO_DIALOG };
	CMoviePlayer	m_MoviePlayer;
	CSliderCtrl	m_BalanceSlider;
	CSliderCtrl	m_VolumeSlider;
	CSliderCtrl	m_MediaSlider;
	BOOL	m_bMute;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CMoviePlayerDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CMoviePlayerDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenButton();
	afx_msg void OnPlayButton();
	afx_msg void OnStopButton();
	afx_msg void OnPauseButton();
	afx_msg void OnRewButton();
	afx_msg void OnFwdButton();
	afx_msg void OnMuteCheck();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	afx_msg LRESULT OnGraphNotify(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMoviePosChanged(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMovieStopped(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMovieChangeState(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
