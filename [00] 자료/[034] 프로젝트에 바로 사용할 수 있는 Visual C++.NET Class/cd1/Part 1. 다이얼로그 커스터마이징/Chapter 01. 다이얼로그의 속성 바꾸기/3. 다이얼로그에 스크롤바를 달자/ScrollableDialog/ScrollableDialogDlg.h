// ScrollableDialogDlg.h : ��� ����
//

#pragma once

// CScrollableDialogDlg ��ȭ ����

// CDialog���� ��� ���� �ʰ�,
// CScrollableDlg���� ��� �޾� �����մϴ�.

#include "ScrollableDlg.h"

class CScrollableDialogDlg : public CScrollableDlg
{
// ����
public:
	CScrollableDialogDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CScrollableDialogDlg)
	enum { IDD = IDD_SCROLLABLEDIALOG_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CScrollableDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CScrollableDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
