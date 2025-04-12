// ConsistenceDialogDlg.h : ��� ����
//

#pragma once

// CConsistenceDialogDlg ��ȭ ����

// �ϰ��� �ִ� ���̾�α׸� �����ϱ� ���� CConsistenceDlg���� ��� �޴´�

#include "ConsistenceDlg.h"

class CConsistenceDialogDlg : public CConsistenceDlg
{
// ����
public:
	CConsistenceDialogDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CConsistenceDialogDlg)
	enum { IDD = IDD_CONSISTENCEDIALOG_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CConsistenceDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	CBitmap	m_bmpBkgnd;					// ���� �����ϰ� ��Ÿ�������� Ȯ���ϱ� ���� ��Ʈ��
	BITMAP	m_bmpInfo;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CConsistenceDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
