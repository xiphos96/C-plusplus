// TransparentDialogDlg.h : ��� ����
//

#pragma once


// CTransparentDialogDlg ��ȭ ����

// ������ ���̾�α׸� ����� ���� CTransparentDlg���� ��� �޴´�

#include "TransparentDlg.h"

class CTransparentDialogDlg : public CTransparentDlg
{
// ����
public:
	CTransparentDialogDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CTransparentDialogDlg)
	enum { IDD = IDD_TRANSPARENTDIALOG_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CTransparentDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CTransparentDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
