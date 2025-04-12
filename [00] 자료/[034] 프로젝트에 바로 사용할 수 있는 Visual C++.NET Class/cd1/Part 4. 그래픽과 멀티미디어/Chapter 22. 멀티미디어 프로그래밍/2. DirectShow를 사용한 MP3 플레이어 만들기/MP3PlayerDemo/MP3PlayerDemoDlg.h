// MP3PlayerDemoDlg.h : 헤더 파일
//

#pragma once

// MP3 플레이어 클래스 헤더 파일
#include "MP3Player.h"


// CMP3PlayerDemoDlg 대화 상자
class CMP3PlayerDemoDlg : public CDialog
{
// 생성
public:
	CMP3PlayerDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

	// MP3 플레이어 클래스
	CMP3Player		m_MP3Player;


// 대화 상자 데이터
	//{{AFX_DATA(CMP3PlayerDemoDlg)
	enum { IDD = IDD_MP3PLAYERDEMO_DIALOG };
	CSliderCtrl	m_BalanceSlider;
	CSliderCtrl	m_VolumeSlider;
	CSliderCtrl	m_MediaSlider;
	BOOL	m_bMute;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CMP3PlayerDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CMP3PlayerDemoDlg)
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
	afx_msg LRESULT OnMP3PosChanged(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMP3Stopped(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMP3ChangeState(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
