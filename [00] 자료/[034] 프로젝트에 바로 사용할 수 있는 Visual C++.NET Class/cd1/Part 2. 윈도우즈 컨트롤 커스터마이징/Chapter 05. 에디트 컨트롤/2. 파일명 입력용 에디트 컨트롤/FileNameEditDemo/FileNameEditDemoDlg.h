// FileNameEditDemoDlg.h : ��� ����
//

#pragma once

// ���ϸ� �Է¿� ����Ʈ ��Ʈ��
#include "FileNameEdit.h"

// CFileNameEditDemoDlg ��ȭ ����
class CFileNameEditDemoDlg : public CDialog
{
// ����
public:
	CFileNameEditDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CFileNameEditDemoDlg)
	enum { IDD = IDD_FILENAMEEDITDEMO_DIALOG };
	CFileNameEdit	m_FolderEdit2;
	CFileNameEdit	m_FolderEdit;
	CFileNameEdit	m_FileEdit2;
	CFileNameEdit	m_FileEdit;
	CString	m_strFilePath;
	CString	m_strFolderPath;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFileNameEditDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CFileNameEditDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetTextButton();
	afx_msg void OnGetTextButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
