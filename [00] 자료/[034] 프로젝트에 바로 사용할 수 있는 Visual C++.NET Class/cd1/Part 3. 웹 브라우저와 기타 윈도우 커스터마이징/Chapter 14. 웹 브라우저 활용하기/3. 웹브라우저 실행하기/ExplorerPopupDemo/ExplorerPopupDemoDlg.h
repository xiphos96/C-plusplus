// ExplorerPopupDemoDlg.h : 헤더 파일
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#pragma once

// 웹브라우저 실행을 제어하는 클래스 헤더
#include "ExplorerPopup.h"


// CExplorerPopupDemoDlg 대화 상자
class CExplorerPopupDemoDlg : public CDialog
{
// 생성
public:
	CExplorerPopupDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CExplorerPopupDemoDlg)
	enum { IDD = IDD_EXPLORERPOPUPDEMO_DIALOG };
	CString	m_strAddress;
	CWebBrowser2	m_wndBrowser;
	BOOL	m_bMenu;
	BOOL	m_bToolBar;
	BOOL	m_bAddressBar;
	BOOL	m_bStatusBar;
	BOOL	m_bResize;
	int		m_nPosX;
	int		m_nPosY;
	int		m_nCX;
	int		m_nCY;
	//}}AFX_DATA

	// 웹브라우저 제어 클래스 멤버 변수
	CExplorerPopup		m_ExplorerPopup;


	//{{AFX_VIRTUAL(CExplorerPopupDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CExplorerPopupDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShellexecuteButton();
	afx_msg void OnNewButton();
	afx_msg void OnNewUsingWebbrowserButton();
	afx_msg void OnNewExButton();
	afx_msg void OnCloseButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
