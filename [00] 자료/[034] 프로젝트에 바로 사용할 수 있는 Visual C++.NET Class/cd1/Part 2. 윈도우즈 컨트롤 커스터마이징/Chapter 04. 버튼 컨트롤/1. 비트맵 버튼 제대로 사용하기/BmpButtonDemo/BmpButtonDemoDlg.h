// BmpButtonDemoDlg.h : 헤더 파일
//

#pragma once

// 빠른 클릭을 처리를 위한 비트맵 버튼 클래스 헤더
#include "SpeedBmpButton.h"

// CBmpButtonDemoDlg 대화 상자
class CBmpButtonDemoDlg : public CDialog
{
// 생성
public:
	CBmpButtonDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CBmpButtonDemoDlg)
	enum { IDD = IDD_BMPBUTTONDEMO_DIALOG };
	CBitmapButton	m_btnOrigin;				// 원래 비트맵 버튼 클래스 변수
	CSpeedBmpButton	m_btnSpeed;					// 빠른 비트맵 버튼 클래스 변수
	int		m_nOrigin;							// 원래 비트맵 버튼 클릭 횟수
	int		m_nSpeed;							// 빠른 비트맵 버튼 클릭 횟수
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CBmpButtonDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CBmpButtonDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOriginBitmapButton();
	afx_msg void OnSpeedBitmapButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnDoubleclickedSpeedBitmapButton();
//	afx_msg void OnBnDoubleclickedOriginBitmapButton();
};
