// ExplorerPrintDemoDlg.h : ��� ����
//
//{{AFX_INCLUDES()
// �μ�� �̸����� ���� �������� ��Ʈ�� ���
#include "WebBrowser2.h"
//}}AFX_INCLUDES

#pragma once


// CExplorerPrintDemoDlg ��ȭ ����
class CExplorerPrintDemoDlg : public CDialog
{
// ����
public:
	CExplorerPrintDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CExplorerPrintDemoDlg)
	enum { IDD = IDD_EXPLORERPRINTDEMO_DIALOG };
	CString	m_strAddress;
	CWebBrowser2	m_wndBrowser;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CExplorerPrintDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
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
