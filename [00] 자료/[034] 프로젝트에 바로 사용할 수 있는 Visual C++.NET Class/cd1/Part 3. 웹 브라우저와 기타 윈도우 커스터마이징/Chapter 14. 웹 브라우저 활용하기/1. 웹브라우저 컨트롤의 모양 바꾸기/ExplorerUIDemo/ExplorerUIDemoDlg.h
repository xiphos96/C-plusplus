// ExplorerUIDemoDlg.h : 헤더 파일
//
//{{AFX_INCLUDES()
// 옵션 설정이 가능한 웹브라우저 컨트롤 헤더 파일
#include "WebBrowser2.h"
//}}AFX_INCLUDES

#pragma once

// CExplorerUIDemoDlg 대화 상자
class CExplorerUIDemoDlg : public CDialog
{
// 생성
public:
	CExplorerUIDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CExplorerUIDemoDlg)
	enum { IDD = IDD_EXPLORERUIDEMO_DIALOG };
	CWebBrowser2	m_wndExplorerUI;
	CString	m_strAddress;
	BOOL	m_bContextMenu;
	BOOL	m_bNo3DBorder;
	BOOL	m_bNoScrollBar;
	BOOL	m_bFlatScrollBar;
	CWebBrowser2	m_wndExplorerUI2;
	CString	m_strAddress2;
	BOOL	m_bContextMenu2;
	BOOL	m_bNo3DBorder2;
	BOOL	m_bNoScrollBar2;
	BOOL	m_bFlatScrollBar2;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CExplorerUIDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CExplorerUIDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGoButton();
	afx_msg void OnContextMenuCheck();
	afx_msg void OnNo3dBorderCheck();
	afx_msg void OnNoScrollCheck();
	afx_msg void OnFlatScrollCheck();
	afx_msg void OnGoButton2();
	afx_msg void OnContextMenuCheck2();
	afx_msg void OnNo3dBorderCheck2();
	afx_msg void OnNoScrollCheck2();
	afx_msg void OnFlatScrollCheck2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
