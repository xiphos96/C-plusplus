// MCIMediaPlayerDemoDlg.h : 헤더 파일
//

#pragma once


// MCI 미디어 플레이어 클래스 헤더 파일
#include "MCIMediaPlayer.h"


// CMCIMediaPlayerDemoDlg 대화 상자
class CMCIMediaPlayerDemoDlg : public CDialog
{
// 생성
public:
	CMCIMediaPlayerDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CMCIMediaPlayerDemoDlg)
	enum { IDD = IDD_MCIMEDIAPLAYERDEMO_DIALOG };
	CSliderCtrl	m_MediaSlider;
	CMCIMediaPlayer	m_MediaPlayer;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CMCIMediaPlayerDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CMCIMediaPlayerDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenButton();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnPlayButton();
	afx_msg void OnStopButton();
	afx_msg void OnPauseButton();
	afx_msg void OnRewButton();
	afx_msg void OnFwdButton();
	//}}AFX_MSG
	// 미디어 재생 상태의 변화 이벤트 함수
	afx_msg LRESULT OnChangeStatus(WPARAM wParam, LPARAM lParam);
	// 미디어 재생 위치 변화 이벤트 함수
	afx_msg LRESULT OnChangePos(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
