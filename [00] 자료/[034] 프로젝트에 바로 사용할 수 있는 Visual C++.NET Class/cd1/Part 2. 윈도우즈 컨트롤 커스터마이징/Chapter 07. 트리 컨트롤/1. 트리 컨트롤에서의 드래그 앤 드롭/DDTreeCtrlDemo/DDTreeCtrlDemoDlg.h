// DDTreeCtrlDemoDlg.h : ��� ����
//

#pragma once

// �巡�� �� ��� Ʈ�� ��Ʈ�� ��� ����
#include "DDTreeCtrl.h"


// CDDTreeCtrlDemoDlg ��ȭ ����
class CDDTreeCtrlDemoDlg : public CDialog
{
// ����
public:
	CDDTreeCtrlDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

	// Ʈ���� ����� �̹��� ����Ʈ
	CImageList		m_TreeImageList;

// ��ȭ ���� ������
	//{{AFX_DATA(CDDTreeCtrlDemoDlg)
	enum { IDD = IDD_DDTREECTRLDEMO_DIALOG };
	CDDTreeCtrl	m_TargetTree;
	CDDTreeCtrl	m_AllTree;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDDTreeCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CDDTreeCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
