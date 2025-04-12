// ImageProgressCtrlDemoDlg.h : 헤더 파일
//

#pragma once

// 이미지 프로그레스바 컨트롤 헤더
#include "ImageProgressCtrl.h"


// CImageProgressCtrlDemoDlg 대화 상자
class CImageProgressCtrlDemoDlg : public CDialog
{
// 생성
public:
	CImageProgressCtrlDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CImageProgressCtrlDemoDlg)
	enum { IDD = IDD_IMAGEPROGRESSCTRLDEMO_DIALOG };
	CImageProgressCtrl	m_HorzProgressCtrl;
	CImageProgressCtrl	m_VertProgressCtrl;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CImageProgressCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CImageProgressCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRestartButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
