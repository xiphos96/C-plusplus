// AutoTabCtrlDemoDlg.h : ��� ����
//

#pragma once

// �ڵ����� ��Ʈ���� �����ϴ� �� ��Ʈ�� ���
#include "AutoTabCtrl.h"


// CAutoTabCtrlDemoDlg ��ȭ ����
class CAutoTabCtrlDemoDlg : public CDialog
{
// ����
public:
	CAutoTabCtrlDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CAutoTabCtrlDemoDlg)
	enum { IDD = IDD_AUTOTABCTRLDEMO_DIALOG };
	CListCtrl	m_OutgoList;
	CListCtrl	m_IncomeList;
	CAutoTabCtrl	m_AutoTab;
	CString	m_strName;
	CString	m_strMoney;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAutoTabCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CAutoTabCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddButton();
	//}}AFX_MSG
	afx_msg LRESULT OnATSelChange(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
