// ListCtrlTipDemoDlg.h : ��� ����
//

#pragma once

// ���� ����� ������ ����Ʈ ��Ʈ�� ���
#include "FlatListCtrl.h"


// CListCtrlTipDemoDlg ��ȭ ����
class CListCtrlTipDemoDlg : public CDialog
{
// ����
public:
	CListCtrlTipDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CListCtrlTipDemoDlg)
	enum { IDD = IDD_LISTCTRLTIPDEMO_DIALOG };
	CFlatListCtrl	m_FlatList;
	CString	m_strName;
	CString	m_strAge;
	CString	m_strAddr;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CListCtrlTipDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CListCtrlTipDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
