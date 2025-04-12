// FlatComboBoxDemoDlg.h : ��� ����
//

#pragma once

// ��� �޺� �ڽ� ��Ʈ�� ���
#include "FlatComboBox.h"


// CFlatComboBoxDemoDlg ��ȭ ����
class CFlatComboBoxDemoDlg : public CDialog
{
// ����
public:
	CFlatComboBoxDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CFlatComboBoxDemoDlg)
	enum { IDD = IDD_FLATCOMBOBOXDEMO_DIALOG };
	CFlatComboBox	m_DropListCombo;
	CFlatComboBox	m_DropDownCombo;
	CFlatComboBox	m_AutoComplete;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFlatComboBoxDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CFlatComboBoxDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDroplistCheck();
	afx_msg void OnDropdownCheck();
	afx_msg void OnAutocompleteCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
