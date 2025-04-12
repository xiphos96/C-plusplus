// MCIMediaPlayerDemoDlg.h : ��� ����
//

#pragma once


// MCI �̵�� �÷��̾� Ŭ���� ��� ����
#include "MCIMediaPlayer.h"


// CMCIMediaPlayerDemoDlg ��ȭ ����
class CMCIMediaPlayerDemoDlg : public CDialog
{
// ����
public:
	CMCIMediaPlayerDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CMCIMediaPlayerDemoDlg)
	enum { IDD = IDD_MCIMEDIAPLAYERDEMO_DIALOG };
	CSliderCtrl	m_MediaSlider;
	CMCIMediaPlayer	m_MediaPlayer;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CMCIMediaPlayerDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
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
	// �̵�� ��� ������ ��ȭ �̺�Ʈ �Լ�
	afx_msg LRESULT OnChangeStatus(WPARAM wParam, LPARAM lParam);
	// �̵�� ��� ��ġ ��ȭ �̺�Ʈ �Լ�
	afx_msg LRESULT OnChangePos(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
