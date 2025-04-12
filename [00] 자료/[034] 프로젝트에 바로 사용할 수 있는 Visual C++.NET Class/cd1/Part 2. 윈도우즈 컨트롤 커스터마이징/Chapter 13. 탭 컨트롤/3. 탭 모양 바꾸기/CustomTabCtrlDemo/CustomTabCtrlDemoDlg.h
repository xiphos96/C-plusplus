// CustomTabCtrlDemoDlg.h : ��� ����
//

#pragma once

// ����� ���� �� ��Ʈ�� ���
#include "CustomTabCtrl.h"


// CCustomTabCtrlDemoDlg ��ȭ ����
class CCustomTabCtrlDemoDlg : public CDialog
{
// ����
public:
	CCustomTabCtrlDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������
	virtual ~CCustomTabCtrlDemoDlg();

// ��ȭ ���� ������
	//{{AFX_DATA(CCustomTabCtrlDemoDlg)
	enum { IDD = IDD_CUSTOMTABCTRLDEMO_DIALOG };
	CCustomTabCtrl	m_CustomTab;
	//}}AFX_DATA

	// �� ��Ʈ�ѿ� ����� �̹��� ����Ʈ
	CImageList		m_ImageList;

	//{{AFX_VIRTUAL(CCustomTabCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CCustomTabCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
