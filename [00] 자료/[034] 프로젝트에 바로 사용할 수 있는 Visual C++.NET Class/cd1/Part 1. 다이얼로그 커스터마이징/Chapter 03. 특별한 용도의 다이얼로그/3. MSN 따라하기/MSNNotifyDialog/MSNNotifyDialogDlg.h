// MSNNotifyDialogDlg.h : ��� ����
//

#pragma once

// �ؽ�Ʈ ������ �Է� �ޱ� ���� ����ƽ ��Ʈ��
#include "ColorStatic.h"

// MSN �޽��� ���̾�α׷� �̿��� ���̾�α�
#include "MsgDlg.h"

// CMSNNotifyDialogDlg ��ȭ ����
class CMSNNotifyDialogDlg : public CDialog
{
// ����
public:
	CMSNNotifyDialogDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CMSNNotifyDialogDlg)
	enum { IDD = IDD_MSNNOTIFYDIALOG_DIALOG };
	CColorStatic	m_clrText;					// �޽��� ��� ���� ���� ����ƽ ��Ʈ��
	CComboBox	m_FontCombo;					// �޽��� ��Ʈ �޺� �ڽ�
	int		m_nFontPoint;						// �޽��� ��Ʈ ũ��
	CString	m_strMessage;						// �޽��� �ؽ�Ʈ
	int		m_nTimeShow;						// �˸� â�� ��Ÿ���� ����
	int		m_nTimeUp;							// �˸� â�� ��µǴ� �ð�
	int		m_nTimeDown;						// �˸� â�� ������� ����
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CMSNNotifyDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	CMsgDlg		m_MsgDlg;						// MSN �޽��� ���̾�α�

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CMSNNotifyDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShowMsgButton();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
