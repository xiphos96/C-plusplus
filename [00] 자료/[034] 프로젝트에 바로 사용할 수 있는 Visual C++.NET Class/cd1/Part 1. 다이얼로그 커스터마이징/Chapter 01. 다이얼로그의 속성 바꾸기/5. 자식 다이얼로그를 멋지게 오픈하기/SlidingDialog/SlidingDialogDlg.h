// SlidingDialogDlg.h : ��� ����
//

#pragma once

#include "ChildDlg.h"

// CSlidingDialogDlg ��ȭ ����
class CSlidingDialogDlg : public CDialog
{
// ����
public:
	CSlidingDialogDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CSlidingDialogDlg)
	enum { IDD = IDD_SLIDINGDIALOG_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CSlidingDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �̴��� �ڽ� ���̾�α�
	CChildDlg		m_wndChild;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CSlidingDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSlidingButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
