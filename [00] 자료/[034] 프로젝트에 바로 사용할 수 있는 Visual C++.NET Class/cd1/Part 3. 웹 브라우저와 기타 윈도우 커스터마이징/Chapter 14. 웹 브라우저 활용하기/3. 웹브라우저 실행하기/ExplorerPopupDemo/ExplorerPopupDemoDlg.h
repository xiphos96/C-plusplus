// ExplorerPopupDemoDlg.h : ��� ����
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#pragma once

// �������� ������ �����ϴ� Ŭ���� ���
#include "ExplorerPopup.h"


// CExplorerPopupDemoDlg ��ȭ ����
class CExplorerPopupDemoDlg : public CDialog
{
// ����
public:
	CExplorerPopupDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
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

	// �������� ���� Ŭ���� ��� ����
	CExplorerPopup		m_ExplorerPopup;


	//{{AFX_VIRTUAL(CExplorerPopupDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
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
