// CaptureWindowDemoDlg.h : 헤더 파일
//

#pragma once

#include "CaptureWindow.h"


// CCaptureWindowDemoDlg 대화 상자
class CCaptureWindowDemoDlg : public CDialog
{
// 생성
public:
	CCaptureWindowDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CCaptureWindowDemoDlg)
	enum { IDD = IDD_CAPTUREWINDOWDEMO_DIALOG };
	CCaptureWindow	m_CaptureWindow;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCaptureWindowDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CCaptureWindowDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	afx_msg LRESULT OnSelectStart(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSelectEnd(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCaptureFinish(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
