// ExplorerTreeCtrlDemoDlg.h : 헤더 파일
//

#pragma once

// 디렉토리 트리 컨트롤 헤더 
#include "ExplorerTreeCtrl.h"


// CExplorerTreeCtrlDemoDlg 대화 상자
class CExplorerTreeCtrlDemoDlg : public CDialog
{
// 생성
public:
	CExplorerTreeCtrlDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CExplorerTreeCtrlDemoDlg)
	enum { IDD = IDD_EXPLORERTREECTRLDEMO_DIALOG };
	CExplorerTreeCtrl	m_ExplorerTree;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CExplorerTreeCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CExplorerTreeCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClickExplorerTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangedExplorerTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelectButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
