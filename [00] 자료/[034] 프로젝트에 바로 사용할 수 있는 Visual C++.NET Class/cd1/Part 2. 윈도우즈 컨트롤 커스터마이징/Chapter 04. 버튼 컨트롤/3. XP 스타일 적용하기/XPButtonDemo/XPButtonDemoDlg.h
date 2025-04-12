// XPButtonDemoDlg.h : 헤더 파일
//

#pragma once

// XP 테마 버튼 클래스 헤더
#include "XPButton.h"


// CXPButtonDemoDlg 대화 상자
class CXPButtonDemoDlg : public CDialog
{
// 생성
public:
	CXPButtonDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CXPButtonDemoDlg)
	enum { IDD = IDD_XPBUTTONDEMO_DIALOG };
	CXPButton	m_Button1;			// 테스트 버튼1
	CXPButton	m_Button2;			// 테스트 버튼2
	CXPButton	m_Button3;			// 테스트 버튼3
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CXPButtonDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CXPButtonDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
