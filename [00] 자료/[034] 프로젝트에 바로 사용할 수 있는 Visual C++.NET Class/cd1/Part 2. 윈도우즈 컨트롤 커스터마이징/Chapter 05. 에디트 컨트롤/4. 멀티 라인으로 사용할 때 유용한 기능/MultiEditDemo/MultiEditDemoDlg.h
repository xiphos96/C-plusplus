// MultiEditDemoDlg.h : ��� ����
//

#pragma once

// CMultiEdit ����� ���� ��� ����
#include "MultiEdit.h"

// CMultiEditDemoDlg ��ȭ ����
class CMultiEditDemoDlg : public CDialog
{
// ����
public:
	CMultiEditDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CMultiEditDemoDlg)
	enum { IDD = IDD_MULTIEDITDEMO_DIALOG };
	CEdit	m_NormalEdit;
	CMultiEdit	m_MultiEdit;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CMultiEditDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CMultiEditDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
