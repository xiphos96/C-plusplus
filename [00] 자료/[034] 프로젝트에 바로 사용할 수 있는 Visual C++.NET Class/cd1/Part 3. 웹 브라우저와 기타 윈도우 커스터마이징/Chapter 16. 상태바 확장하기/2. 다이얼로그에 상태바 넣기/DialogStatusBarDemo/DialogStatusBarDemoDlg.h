// DialogStatusBarDemoDlg.h : ��� ����
//

#pragma once

// ���̾�α׿� ���¹� Ŭ���� ���
#include "DialogStatusBar.h"


// CDialogStatusBarDemoDlg ��ȭ ����
class CDialogStatusBarDemoDlg : public CDialog
{
// ����
public:
	CDialogStatusBarDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

	// ���̾�α׿� ���¹� Ŭ���� ����
	CDialogStatusBar		m_wndStatusBar;

// ��ȭ ���� ������
	//{{AFX_DATA(CDialogStatusBarDemoDlg)
	enum { IDD = IDD_DIALOGSTATUSBARDEMO_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDialogStatusBarDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CDialogStatusBarDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFileOpen();
	afx_msg void OnFileClose();
	afx_msg void OnAppExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
