// MultiListBoxDemoDlg.h : ��� ����
//

#pragma once

// �̹����� ��Ȱ��ȭ ���� ����Ʈ �ڽ� ��Ʈ�� ���
#include "MultiListBox.h"


// CMultiListBoxDemoDlg ��ȭ ����
class CMultiListBoxDemoDlg : public CDialog
{
// ����
public:
	CMultiListBoxDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

	// ����Ʈ �ڽ��� ����� �̹��� ����Ʈ
	CImageList		m_ImageList;

// ��ȭ ���� ������
	//{{AFX_DATA(CMultiListBoxDemoDlg)
	enum { IDD = IDD_MULTILISTBOXDEMO_DIALOG };
	CMultiListBox	m_MultiList;
	CString	m_strText;
	int		m_nImage;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CMultiListBoxDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CMultiListBoxDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddButton();
	afx_msg void OnDblclkMultiList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
