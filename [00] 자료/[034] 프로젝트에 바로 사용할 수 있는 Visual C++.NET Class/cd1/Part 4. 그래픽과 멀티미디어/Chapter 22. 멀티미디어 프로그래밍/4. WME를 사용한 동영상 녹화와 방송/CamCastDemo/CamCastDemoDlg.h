// CamCastDemoDlg.h : ��� ����
//

#pragma once

// ������ ��ȭ ��� Ŭ����
#include "CamCast.h"


// CCamCastDemoDlg ��ȭ ����
class CCamCastDemoDlg : public CDialog
{
// ����
public:
	CCamCastDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CCamCastDemoDlg)
	enum { IDD = IDD_CAMCASTDEMO_DIALOG };
	CCamCast	m_CamCast;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCamCastDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CCamCastDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRecButton();
	afx_msg void OnCastButton();
	afx_msg void OnStopButton();
	afx_msg void OnConfigButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
