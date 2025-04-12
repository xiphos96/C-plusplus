// LinkStaticDemoDlg.h : ��� ����
//

#pragma once

// ������ ��ũ ����ƽ ��Ʈ�� ���
#include "LinkStatic.h"


// CLinkStaticDemoDlg ��ȭ ����
class CLinkStaticDemoDlg : public CDialog
{
// ����
public:
	CLinkStaticDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CLinkStaticDemoDlg)
	enum { IDD = IDD_LINKSTATICDEMO_DIALOG };
	CLinkStatic	m_MailStatic;
	CLinkStatic	m_LinkStatic;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CLinkStaticDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CLinkStaticDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
