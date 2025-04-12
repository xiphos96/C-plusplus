// MultiMediaTimerDemoDlg.h : 헤더 파일
//

#pragma once


#include "MultiMediaTimer.h"


// CMultiMediaTimerDemoDlg 대화 상자
class CMultiMediaTimerDemoDlg : public CDialog
{
// 생성
public:
	CMultiMediaTimerDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

	CMultiMediaTimer<CMultiMediaTimerDemoDlg>	m_Timer;

	void OnMMTimer(UINT uID);

// 대화 상자 데이터
	//{{AFX_DATA(CMultiMediaTimerDemoDlg)
	enum { IDD = IDD_MULTIMEDIATIMERDEMO_DIALOG };
	CListBox	m_OnTimerList;
	int		m_nCount;
	int		m_nInterval;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CMultiMediaTimerDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CMultiMediaTimerDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartButton();
	afx_msg void OnStopButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
