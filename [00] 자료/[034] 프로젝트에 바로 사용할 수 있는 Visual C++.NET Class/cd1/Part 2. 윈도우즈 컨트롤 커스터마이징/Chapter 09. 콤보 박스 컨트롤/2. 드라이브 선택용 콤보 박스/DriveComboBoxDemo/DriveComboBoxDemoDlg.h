// DriveComboBoxDemoDlg.h : ��� ����
//

#pragma once

// ����̺� �޺� �ڽ� ��Ʈ�� ���
#include "DriveComboBox.h"


// CDriveComboBoxDemoDlg ��ȭ ����
class CDriveComboBoxDemoDlg : public CDialog
{
// ����
public:
	CDriveComboBoxDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CDriveComboBoxDemoDlg)
	enum { IDD = IDD_DRIVECOMBOBOXDEMO_DIALOG };
	CDriveComboBox	m_DriveCombo;
	CString	m_strCount;
	CString	m_strCurDrive;
	int		m_nIcon;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDriveComboBoxDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CDriveComboBoxDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBigRadio();
	afx_msg void OnSmallRadio();
	afx_msg void OnSelchangeDriveCombo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
