// ConsistenceDialogDlg.h : 헤더 파일
//

#pragma once

// CConsistenceDialogDlg 대화 상자

// 일관성 있는 다이얼로그를 생성하기 위해 CConsistenceDlg에서 상속 받는다

#include "ConsistenceDlg.h"

class CConsistenceDialogDlg : public CConsistenceDlg
{
// 생성
public:
	CConsistenceDialogDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CConsistenceDialogDlg)
	enum { IDD = IDD_CONSISTENCEDIALOG_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CConsistenceDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	CBitmap	m_bmpBkgnd;					// 실제 동일하게 나타나는지를 확인하기 위한 비트맵
	BITMAP	m_bmpInfo;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CConsistenceDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
