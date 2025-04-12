// XPButtonDemoDlg.h : ��� ����
//

#pragma once

// XP �׸� ��ư Ŭ���� ���
#include "XPButton.h"


// CXPButtonDemoDlg ��ȭ ����
class CXPButtonDemoDlg : public CDialog
{
// ����
public:
	CXPButtonDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CXPButtonDemoDlg)
	enum { IDD = IDD_XPBUTTONDEMO_DIALOG };
	CXPButton	m_Button1;			// �׽�Ʈ ��ư1
	CXPButton	m_Button2;			// �׽�Ʈ ��ư2
	CXPButton	m_Button3;			// �׽�Ʈ ��ư3
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CXPButtonDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CXPButtonDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
