// AutoTabCtrlDemoDlg.h : 헤더 파일
//

#pragma once

// 자동으로 컨트롤을 관리하는 탭 컨트롤 헤더
#include "AutoTabCtrl.h"


// CAutoTabCtrlDemoDlg 대화 상자
class CAutoTabCtrlDemoDlg : public CDialog
{
// 생성
public:
	CAutoTabCtrlDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CAutoTabCtrlDemoDlg)
	enum { IDD = IDD_AUTOTABCTRLDEMO_DIALOG };
	CListCtrl	m_OutgoList;
	CListCtrl	m_IncomeList;
	CAutoTabCtrl	m_AutoTab;
	CString	m_strName;
	CString	m_strMoney;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAutoTabCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CAutoTabCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddButton();
	//}}AFX_MSG
	afx_msg LRESULT OnATSelChange(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
