// FoldDialogDlg.h : 헤더 파일
//

#pragma once


// CFoldDialogDlg 대화 상자

// CDialog에서 상속 받지 않고
// CFolderDlg에서 상속 받아 생성한다

#include "FolderDlg.h"

class CFoldDialogDlg : public CFolderDlg
{
// 생성
public:
	CFoldDialogDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CFoldDialogDlg)
	enum { IDD = IDD_FOLDDIALOG_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFoldDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CFoldDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFoldButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
