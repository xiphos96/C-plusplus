// ColorMessageBoxDlg.h : ��� ����
//

#pragma once

// �÷� ��� �� ������ ���� ���Ǵ� ����ƽ ��Ʈ��
#include "ColorStatic.h"

// CColorMessageBoxDlg ��ȭ ����
class CColorMessageBoxDlg : public CDialog
{
// ����
public:
	CColorMessageBoxDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CColorMessageBoxDlg)
	enum { IDD = IDD_COLORMESSAGEBOX_DIALOG };
	CColorStatic	m_clrBkgnd;					// ��� ���� ���� ��Ʈ��
	CColorStatic	m_clrText;					// �ؽ�Ʈ ���� ���� ��Ʈ��
	int		m_nUse;								// �÷��� ����� ������ ����
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CColorMessageBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CColorMessageBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAfxmessageboxButton();
	afx_msg void OnMessageboxButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
