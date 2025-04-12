// MoviePlayerDemoDlg.h : ��� ����
//

#pragma once

// ������ �÷��̾� Ŭ���� ��� ����
#include "MoviePlayer.h"


// CMoviePlayerDemoDlg ��ȭ ����
class CMoviePlayerDemoDlg : public CDialog
{
// ����
public:
	CMoviePlayerDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
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
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
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
