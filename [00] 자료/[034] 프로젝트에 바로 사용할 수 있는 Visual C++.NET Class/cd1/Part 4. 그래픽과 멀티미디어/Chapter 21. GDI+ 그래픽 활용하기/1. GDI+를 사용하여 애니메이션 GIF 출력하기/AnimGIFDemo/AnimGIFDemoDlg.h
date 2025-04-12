// AnimGIFDemoDlg.h : 헤더 파일
//

#pragma once

#include "AnimGIF.h"


// CAnimGIFDemoDlg 대화 상자
class CAnimGIFDemoDlg : public CDialog
{
// 생성
public:
	CAnimGIFDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CAnimGIFDemoDlg)
	enum { IDD = IDD_ANIMGIFDEMO_DIALOG };
	CAnimGIF	m_AnimGIF;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAnimGIFDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CAnimGIFDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlayButton();
	afx_msg void OnPauseButton();
	afx_msg void OnResumeButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnDestroy();
};
