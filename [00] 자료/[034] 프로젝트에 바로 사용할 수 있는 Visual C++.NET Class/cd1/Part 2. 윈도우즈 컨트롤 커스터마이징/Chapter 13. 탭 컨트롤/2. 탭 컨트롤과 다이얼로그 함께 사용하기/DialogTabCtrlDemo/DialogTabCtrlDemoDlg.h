// DialogTabCtrlDemoDlg.h : ��� ����
//

#pragma once

// ���̾�α� �� ��Ʈ�� ���
#include "DialogTabCtrl.h"

// �ǿ� ���� ���̾�α� ���
#include "IncomeDlg.h"
#include "OutgoDlg.h"
#include "ReportDlg.h"


// CDialogTabCtrlDemoDlg ��ȭ ����
class CDialogTabCtrlDemoDlg : public CDialog
{
// ����
public:
	CDialogTabCtrlDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CDialogTabCtrlDemoDlg)
	enum { IDD = IDD_DIALOGTABCTRLDEMO_DIALOG };
	CDialogTabCtrl	m_DialogTab;
	//}}AFX_DATA

	CIncomeDlg		m_IncomeDlg;		// ���� ���� �����ϴ� ���̾�α�
	COutgoDlg		m_OutgoDlg;			// ���� ���� �����ϴ� ���̾�α�
	CReportDlg		m_ReportDlg;		// �հ� ���� �����ϴ� ���̾�α�


	//{{AFX_VIRTUAL(CDialogTabCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CDialogTabCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	afx_msg LRESULT OnATSelChange(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
