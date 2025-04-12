// DialogTabCtrlDemoDlg.h : 헤더 파일
//

#pragma once

// 다이얼로그 탭 컨트롤 헤더
#include "DialogTabCtrl.h"

// 탭에 대한 다이얼로그 헤더
#include "IncomeDlg.h"
#include "OutgoDlg.h"
#include "ReportDlg.h"


// CDialogTabCtrlDemoDlg 대화 상자
class CDialogTabCtrlDemoDlg : public CDialog
{
// 생성
public:
	CDialogTabCtrlDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CDialogTabCtrlDemoDlg)
	enum { IDD = IDD_DIALOGTABCTRLDEMO_DIALOG };
	CDialogTabCtrl	m_DialogTab;
	//}}AFX_DATA

	CIncomeDlg		m_IncomeDlg;		// 수입 탭을 구현하는 다이얼로그
	COutgoDlg		m_OutgoDlg;			// 지출 탭을 구현하는 다이얼로그
	CReportDlg		m_ReportDlg;		// 합계 탭을 구현하는 다이얼로그


	//{{AFX_VIRTUAL(CDialogTabCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CDialogTabCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	afx_msg LRESULT OnATSelChange(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
