// ExplorerTreeCtrlDemoDlg.h : ��� ����
//

#pragma once

// ���丮 Ʈ�� ��Ʈ�� ��� 
#include "ExplorerTreeCtrl.h"


// CExplorerTreeCtrlDemoDlg ��ȭ ����
class CExplorerTreeCtrlDemoDlg : public CDialog
{
// ����
public:
	CExplorerTreeCtrlDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CExplorerTreeCtrlDemoDlg)
	enum { IDD = IDD_EXPLORERTREECTRLDEMO_DIALOG };
	CExplorerTreeCtrl	m_ExplorerTree;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CExplorerTreeCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
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
