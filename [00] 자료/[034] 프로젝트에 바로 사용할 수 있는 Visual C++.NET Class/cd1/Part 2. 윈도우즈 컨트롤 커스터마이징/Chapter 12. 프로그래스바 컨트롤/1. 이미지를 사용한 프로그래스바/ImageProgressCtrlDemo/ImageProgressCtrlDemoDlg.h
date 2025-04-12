// ImageProgressCtrlDemoDlg.h : ��� ����
//

#pragma once

// �̹��� ���α׷����� ��Ʈ�� ���
#include "ImageProgressCtrl.h"


// CImageProgressCtrlDemoDlg ��ȭ ����
class CImageProgressCtrlDemoDlg : public CDialog
{
// ����
public:
	CImageProgressCtrlDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CImageProgressCtrlDemoDlg)
	enum { IDD = IDD_IMAGEPROGRESSCTRLDEMO_DIALOG };
	CImageProgressCtrl	m_HorzProgressCtrl;
	CImageProgressCtrl	m_VertProgressCtrl;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CImageProgressCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CImageProgressCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRestartButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
