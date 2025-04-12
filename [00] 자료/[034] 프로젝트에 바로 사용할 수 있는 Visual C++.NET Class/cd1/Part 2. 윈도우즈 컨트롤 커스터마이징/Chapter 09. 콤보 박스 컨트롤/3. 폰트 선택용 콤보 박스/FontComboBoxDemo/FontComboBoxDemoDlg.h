// FontComboBoxDemoDlg.h : ��� ����
//

#pragma once

// ��Ʈ �޺� �ڽ� ��Ʈ�� ���
#include "FontComboBox.h"


// CFontComboBoxDemoDlg ��ȭ ����
class CFontComboBoxDemoDlg : public CDialog
{
// ����
public:
	CFontComboBoxDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CFontComboBoxDemoDlg)
	enum { IDD = IDD_FONTCOMBOBOXDEMO_DIALOG };
	CFontComboBox	m_FontCombo;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFontComboBoxDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CFontComboBoxDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeFontCombo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
