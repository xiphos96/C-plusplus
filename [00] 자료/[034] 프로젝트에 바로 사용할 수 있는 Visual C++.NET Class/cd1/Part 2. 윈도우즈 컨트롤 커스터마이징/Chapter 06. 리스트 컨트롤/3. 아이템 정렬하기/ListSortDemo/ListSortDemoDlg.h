// ListSortDemoDlg.h : ��� ����
//

#pragma once

// ���� ����� ���� ����Ʈ ��Ʈ�� ��� ����
#include "FlatListCtrl.h"


// CListSortDemoDlg ��ȭ ����
class CListSortDemoDlg : public CDialog
{
// ����
public:
	CListSortDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CListSortDemoDlg)
	enum { IDD = IDD_LISTSORTDEMO_DIALOG };
	CFlatListCtrl	m_FlatList;
	CString	m_strName;
	CString	m_strAge;
	CString	m_strAddr;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CListSortDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CListSortDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
