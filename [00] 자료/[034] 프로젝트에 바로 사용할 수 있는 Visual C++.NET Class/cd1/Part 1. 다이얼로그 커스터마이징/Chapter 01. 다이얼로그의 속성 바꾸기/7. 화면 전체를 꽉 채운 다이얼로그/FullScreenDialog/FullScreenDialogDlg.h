// FullScreenDialogDlg.h : 헤더 파일
//

#pragma once


// CFullScreenDialogDlg 대화 상자

// 전체 화면 다이얼로그를 만들기 위해 CFullScreenDlg에서 상속 받습니다.

#include "FullScreenDlg.h"

class CFullScreenDialogDlg : public CFullScreenDlg
{
// 생성
public:
	CFullScreenDialogDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CFullScreenDialogDlg)
	enum { IDD = IDD_FULLSCREENDIALOG_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFullScreenDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CFullScreenDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
