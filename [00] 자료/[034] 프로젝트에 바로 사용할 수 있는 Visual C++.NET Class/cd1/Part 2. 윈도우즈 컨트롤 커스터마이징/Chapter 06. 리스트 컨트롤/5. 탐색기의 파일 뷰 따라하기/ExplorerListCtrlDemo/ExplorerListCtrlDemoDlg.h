// ExplorerListCtrlDemoDlg.h : 헤더 파일
//

#pragma once

#include "ExplorerListCtrl.h"


// CExplorerListCtrlDemoDlg 대화 상자
class CExplorerListCtrlDemoDlg : public CDialog
{
// 생성
public:
	CExplorerListCtrlDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CExplorerListCtrlDemoDlg)
	enum { IDD = IDD_EXPLORERLISTCTRLDEMO_DIALOG };
	CComboBoxEx	m_DriveCombo;
	CExplorerListCtrl	m_ExplorerListCtrl;
	int		m_nType;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CExplorerListCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CExplorerListCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnIconRadio();
	afx_msg void OnSmallIconRadio();
	afx_msg void OnListRadio();
	afx_msg void OnReportRadio();
	afx_msg void OnGoUpButton();
	afx_msg void OnSelchangeDriveCombo();
	//}}AFX_MSG
	afx_msg LRESULT OnExplorerFileSelecct(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
