// SlideEditDemoDlg.h : 헤더 파일
//

#pragma once

// 슬라이드 에디트 컨트롤을 사용하기 위한 클래스 헤더 파일
#include "SlideEdit.h"
// 컬러 스태틱 컨트롤을 사용하기 위한 클래스 헤더 파일
#include "ColorStatic.h"


// CSlideEditDemoDlg 대화 상자
class CSlideEditDemoDlg : public CDialog
{
// 생성
public:
	CSlideEditDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CSlideEditDemoDlg)
	enum { IDD = IDD_SLIDEEDITDEMO_DIALOG };
	CColorStatic	m_ColorStatic;
	CSlideEdit	m_SlideEditR;
	CSlideEdit	m_SlideEditG;
	CSlideEdit	m_SlideEditB;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CSlideEditDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL

// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CSlideEditDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	// 슬라이드 에디트 컨트롤에서 보내는 메시지에 대한 핸들러
	afx_msg LRESULT OnSlidePosChange(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSlideEndSelect(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
