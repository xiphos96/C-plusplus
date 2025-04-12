// BitmapDialogDlg.h : ��� ����
//

#pragma once

#include "ImageDialog.h"

// CBitmapDialogDlg ��ȭ ����
class CBitmapDialogDlg : public CImageDialog
{
// ����
public:
	CBitmapDialogDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CBitmapDialogDlg)
	enum { IDD = IDD_BITMAPDIALOG_DIALOG };
	int		m_nBkgndMode;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CBitmapDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CBitmapDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnModeRadio1();
	afx_msg void OnModeRadio2();
	afx_msg void OnModeRadio3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
