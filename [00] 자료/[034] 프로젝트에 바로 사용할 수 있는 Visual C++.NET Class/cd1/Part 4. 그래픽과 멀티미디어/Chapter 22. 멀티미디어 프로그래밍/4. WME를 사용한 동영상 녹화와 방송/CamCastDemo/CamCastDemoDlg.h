// CamCastDemoDlg.h : 헤더 파일
//

#pragma once

// 동영상 녹화 방송 클래스
#include "CamCast.h"


// CCamCastDemoDlg 대화 상자
class CCamCastDemoDlg : public CDialog
{
// 생성
public:
	CCamCastDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CCamCastDemoDlg)
	enum { IDD = IDD_CAMCASTDEMO_DIALOG };
	CCamCast	m_CamCast;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCamCastDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CCamCastDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRecButton();
	afx_msg void OnCastButton();
	afx_msg void OnStopButton();
	afx_msg void OnConfigButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
