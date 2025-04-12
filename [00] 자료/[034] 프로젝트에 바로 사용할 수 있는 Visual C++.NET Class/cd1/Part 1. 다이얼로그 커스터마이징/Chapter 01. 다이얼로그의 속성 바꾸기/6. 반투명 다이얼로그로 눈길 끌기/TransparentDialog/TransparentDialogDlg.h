// TransparentDialogDlg.h : 헤더 파일
//

#pragma once


// CTransparentDialogDlg 대화 상자

// 반투명 다이얼로그를 만들기 위해 CTransparentDlg에서 상속 받는다

#include "TransparentDlg.h"

class CTransparentDialogDlg : public CTransparentDlg
{
// 생성
public:
	CTransparentDialogDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CTransparentDialogDlg)
	enum { IDD = IDD_TRANSPARENTDIALOG_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CTransparentDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CTransparentDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
