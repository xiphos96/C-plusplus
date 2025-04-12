// ExplorerListCtrlDemoDlg.h : ��� ����
//

#pragma once

#include "ExplorerListCtrl.h"


// CExplorerListCtrlDemoDlg ��ȭ ����
class CExplorerListCtrlDemoDlg : public CDialog
{
// ����
public:
	CExplorerListCtrlDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CExplorerListCtrlDemoDlg)
	enum { IDD = IDD_EXPLORERLISTCTRLDEMO_DIALOG };
	CComboBoxEx	m_DriveCombo;
	CExplorerListCtrl	m_ExplorerListCtrl;
	int		m_nType;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CExplorerListCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
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
