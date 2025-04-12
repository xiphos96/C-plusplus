// SectionLineDemoDlg.h : 헤더 파일
//

#pragma once

// 구분선 스태틱 컨트롤 헤더
#include "SectionLine.h"


// CSectionLineDemoDlg 대화 상자
class CSectionLineDemoDlg : public CDialog
{
// 생성
public:
	CSectionLineDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CSectionLineDemoDlg)
	enum { IDD = IDD_SECTIONLINEDEMO_DIALOG };
	CSectionLine	m_VertRight;
	CSectionLine	m_VertCenter;
	CSectionLine	m_VertLeft;
	CSectionLine	m_HorzRightDisable;
	CSectionLine	m_HorzCenterDisable;
	CSectionLine	m_HorzLeftDisable;
	CSectionLine	m_HorzRight;
	CSectionLine	m_HorzCenter;
	CSectionLine	m_HorzLeft;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CSectionLineDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CSectionLineDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
