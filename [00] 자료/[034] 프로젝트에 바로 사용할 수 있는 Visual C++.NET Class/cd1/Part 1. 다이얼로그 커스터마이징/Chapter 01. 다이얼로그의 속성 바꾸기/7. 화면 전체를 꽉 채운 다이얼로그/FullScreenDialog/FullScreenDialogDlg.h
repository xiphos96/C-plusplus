// FullScreenDialogDlg.h : ��� ����
//

#pragma once


// CFullScreenDialogDlg ��ȭ ����

// ��ü ȭ�� ���̾�α׸� ����� ���� CFullScreenDlg���� ��� �޽��ϴ�.

#include "FullScreenDlg.h"

class CFullScreenDialogDlg : public CFullScreenDlg
{
// ����
public:
	CFullScreenDialogDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CFullScreenDialogDlg)
	enum { IDD = IDD_FULLSCREENDIALOG_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFullScreenDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CFullScreenDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
