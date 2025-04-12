// DialogStatusBarDemoDlg.h : 헤더 파일
//

#pragma once

// 다이얼로그용 상태바 클래스 헤더
#include "DialogStatusBar.h"


// CDialogStatusBarDemoDlg 대화 상자
class CDialogStatusBarDemoDlg : public CDialog
{
// 생성
public:
	CDialogStatusBarDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

	// 다이얼로그용 상태바 클래스 변수
	CDialogStatusBar		m_wndStatusBar;

// 대화 상자 데이터
	//{{AFX_DATA(CDialogStatusBarDemoDlg)
	enum { IDD = IDD_DIALOGSTATUSBARDEMO_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDialogStatusBarDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CDialogStatusBarDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFileOpen();
	afx_msg void OnFileClose();
	afx_msg void OnAppExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
