// ScrollableDialogDlg.h : 헤더 파일
//

#pragma once

// CScrollableDialogDlg 대화 상자

// CDialog에서 상속 받지 않고,
// CScrollableDlg에서 상속 받아 생성합니다.

#include "ScrollableDlg.h"

class CScrollableDialogDlg : public CScrollableDlg
{
// 생성
public:
	CScrollableDialogDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CScrollableDialogDlg)
	enum { IDD = IDD_SCROLLABLEDIALOG_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CScrollableDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CScrollableDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
