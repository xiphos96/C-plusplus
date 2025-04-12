// FilterEditDemoDlg.h : 헤더 파일
//

#pragma once

// 필터 에디트 클래스의 헤더 파일
#include "FilterEdit.h"


// CFilterEditDemoDlg 대화 상자
class CFilterEditDemoDlg : public CDialog
{
// 생성
public:
	CFilterEditDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CFilterEditDemoDlg)
	enum { IDD = IDD_FILTEREDITDEMO_DIALOG };
	CFilterEdit	m_FormatEdit;
	CFilterEdit	m_TimeEdit;
	CFilterEdit	m_DateEdit;
	CFilterEdit	m_CurrencyEdit;
	CFilterEdit	m_AlnumEdit;
	CFilterEdit	m_AlphaEdit;
	CFilterEdit	m_LowerCaseEdit;
	CFilterEdit	m_UpperCaseEdit;
	CFilterEdit	m_RealNumEdit;
	CFilterEdit	m_SignedNumEdit;
	CFilterEdit	m_NumberEdit;
	CFilterEdit	m_NoneEdit;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFilterEditDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CFilterEditDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
