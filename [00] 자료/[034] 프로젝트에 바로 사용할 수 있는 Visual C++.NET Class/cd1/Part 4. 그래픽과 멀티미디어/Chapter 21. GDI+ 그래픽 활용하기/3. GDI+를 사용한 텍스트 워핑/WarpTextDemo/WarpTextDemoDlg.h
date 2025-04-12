// WarpTextDemoDlg.h : 헤더 파일
//

#pragma once

// 텍스트 워핑 클래스 헤더파일
#include "WarpText.h"


// CWarpTextDemoDlg 대화 상자
class CWarpTextDemoDlg : public CDialog
{
// 생성
public:
	CWarpTextDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CWarpTextDemoDlg)
	enum { IDD = IDD_WARPTEXTDEMO_DIALOG };
	CWarpText	m_WarpText;
	CString	m_strText;
	BOOL	m_bShowGuide;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CWarpTextDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CWarpTextDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRefreshButton();
	afx_msg void OnShowGuideCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
