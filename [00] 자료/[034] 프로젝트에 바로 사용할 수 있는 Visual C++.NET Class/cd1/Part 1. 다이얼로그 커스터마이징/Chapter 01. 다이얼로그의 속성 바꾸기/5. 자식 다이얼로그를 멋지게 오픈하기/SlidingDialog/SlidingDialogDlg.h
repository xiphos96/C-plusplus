// SlidingDialogDlg.h : 헤더 파일
//

#pragma once

#include "ChildDlg.h"

// CSlidingDialogDlg 대화 상자
class CSlidingDialogDlg : public CDialog
{
// 생성
public:
	CSlidingDialogDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CSlidingDialogDlg)
	enum { IDD = IDD_SLIDINGDIALOG_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CSlidingDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 미닫이 자식 다이얼로그
	CChildDlg		m_wndChild;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CSlidingDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSlidingButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
