// ExplorerPrintDemoDlg.h : 헤더 파일
//
//{{AFX_INCLUDES()
// 인쇄와 미리보기 지원 웹브라우저 컨트롤 헤더
#include "WebBrowser2.h"
//}}AFX_INCLUDES

#pragma once


// CExplorerPrintDemoDlg 대화 상자
class CExplorerPrintDemoDlg : public CDialog
{
// 생성
public:
	CExplorerPrintDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CExplorerPrintDemoDlg)
	enum { IDD = IDD_EXPLORERPRINTDEMO_DIALOG };
	CString	m_strAddress;
	CWebBrowser2	m_wndBrowser;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CExplorerPrintDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CExplorerPrintDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGoButton();
	afx_msg void OnStopButton();
	afx_msg void OnRefreshButton();
	afx_msg void OnSaveAsButton();
	afx_msg void OnPrintButton();
	afx_msg void OnPrintPreviewButton();
	afx_msg void OnPageSetupButton();
	afx_msg void OnPropertyButton();
	afx_msg void OnFavoriteButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
