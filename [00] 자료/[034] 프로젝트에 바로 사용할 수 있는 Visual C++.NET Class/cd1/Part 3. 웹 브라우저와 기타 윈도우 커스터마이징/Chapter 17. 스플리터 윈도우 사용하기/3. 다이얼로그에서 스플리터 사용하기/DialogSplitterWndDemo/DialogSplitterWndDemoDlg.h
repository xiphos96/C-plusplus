// DialogSplitterWndDemoDlg.h : ��� ����
//

#pragma once


// ���̾�α׿� ���ø��� Ŭ���� ���
#include "DialogSplitterWnd.h"


// CDialogSplitterWndDemoDlg ��ȭ ����
class CDialogSplitterWndDemoDlg : public CDialog
{
// ����
public:
	CDialogSplitterWndDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CDialogSplitterWndDemoDlg)
	enum { IDD = IDD_DIALOGSPLITTERWNDDEMO_DIALOG };
	CDialogSplitterWnd	m_wndSplitter2;
	CDialogSplitterWnd	m_wndSplitter;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDialogSplitterWndDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CDialogSplitterWndDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
