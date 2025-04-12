// WarpTextDemoDlg.h : ��� ����
//

#pragma once

// �ؽ�Ʈ ���� Ŭ���� �������
#include "WarpText.h"


// CWarpTextDemoDlg ��ȭ ����
class CWarpTextDemoDlg : public CDialog
{
// ����
public:
	CWarpTextDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CWarpTextDemoDlg)
	enum { IDD = IDD_WARPTEXTDEMO_DIALOG };
	CWarpText	m_WarpText;
	CString	m_strText;
	BOOL	m_bShowGuide;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CWarpTextDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CWarpTextDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRefreshButton();
	afx_msg void OnShowGuideCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
