// FoldDialogDlg.h : ��� ����
//

#pragma once


// CFoldDialogDlg ��ȭ ����

// CDialog���� ��� ���� �ʰ�
// CFolderDlg���� ��� �޾� �����Ѵ�

#include "FolderDlg.h"

class CFoldDialogDlg : public CFolderDlg
{
// ����
public:
	CFoldDialogDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CFoldDialogDlg)
	enum { IDD = IDD_FOLDDIALOG_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFoldDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CFoldDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFoldButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
