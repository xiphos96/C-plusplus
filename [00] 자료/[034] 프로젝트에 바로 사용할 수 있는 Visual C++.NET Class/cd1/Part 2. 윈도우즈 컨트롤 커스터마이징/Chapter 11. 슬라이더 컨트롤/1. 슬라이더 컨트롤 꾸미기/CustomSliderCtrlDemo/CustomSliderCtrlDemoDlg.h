// CustomSliderCtrlDemoDlg.h : 헤더 파일
//

#pragma once

// 사용자 정의 슬라이더 컨트로 헤더
#include "CustomSliderCtrl.h"


// CCustomSliderCtrlDemoDlg 대화 상자
class CCustomSliderCtrlDemoDlg : public CDialog
{
// 생성
public:
	CCustomSliderCtrlDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

	int		m_nThumbStep;					// 핸들의 이동 간격
	int		m_nSelectionStep;				// 범위의 이동 간격

// 대화 상자 데이터
	//{{AFX_DATA(CCustomSliderCtrlDemoDlg)
	enum { IDD = IDD_CUSTOMSLIDERCTRLDEMO_DIALOG };
	CCustomSliderCtrl	m_CustomHorzSlider;
	CCustomSliderCtrl	m_CustomVertSlider;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCustomSliderCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CCustomSliderCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRestartButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
