// EditableListBoxDemoDlg.h : ��� ����
//

#pragma once

// �ؽ�Ʈ ���� ����Ʈ �ڽ� ��Ʈ�� ���
#include "EditableListBox.h"


// CEditableListBoxDemoDlg ��ȭ ����
class CEditableListBoxDemoDlg : public CDialog
{
// ����
public:
	CEditableListBoxDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CEditableListBoxDemoDlg)
	enum { IDD = IDD_EDITABLELISTBOXDEMO_DIALOG };
	CEditableListBox	m_EditableList;
	CString	m_strText;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CEditableListBoxDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CEditableListBoxDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
