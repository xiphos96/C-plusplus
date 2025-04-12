// CoolButtonDemoDlg.h : 헤더 파일
//

#pragma once

#include "CoolButton.h"


// CCoolButtonDemoDlg 대화 상자
class CCoolButtonDemoDlg : public CDialog
{
// 생성
public:
	CCoolButtonDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CCoolButtonDemoDlg)
	enum { IDD = IDD_COOLBUTTONDEMO_DIALOG };
	CCoolButton	m_btnBmp;						// 비트맵을 입힌 버튼
	CCoolButton	m_btnIcon;						// 아이콘을 입힌 버튼
	CCoolButton	m_btnTransparent;				// 비트맵을 입히고 특정 색을 투명 처리한 버튼
	CCoolButton	m_btnPosition;					// 위치 지정 버튼
	int		m_nAlign;							// 위치 지정
	BOOL	m_bEnable;							// 버튼의 활성화 여부
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCoolButtonDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CCoolButtonDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLeftRadio();
	afx_msg void OnRightRadio();
	afx_msg void OnTopRadio();
	afx_msg void OnBottomRadio();
	afx_msg void OnOverRadio();
	afx_msg void OnEnableCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
