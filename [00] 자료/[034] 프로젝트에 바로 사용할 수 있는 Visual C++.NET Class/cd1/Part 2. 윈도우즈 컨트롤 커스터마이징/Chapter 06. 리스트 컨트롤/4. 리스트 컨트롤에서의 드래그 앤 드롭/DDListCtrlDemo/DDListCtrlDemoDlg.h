// DDListCtrlDemoDlg.h : ��� ����
//

#pragma once

// �巡�� �� ��� ����Ʈ ��Ʈ�� ���
#include "DDListCtrl.h"


// CDDListCtrlDemoDlg ��ȭ ����
class CDDListCtrlDemoDlg : public CDialog
{
// ����
public:
	CDDListCtrlDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

	// ����Ʈ ��Ʈ�ѿ� ����� 32*32 ũ���� �̹��� ����Ʈ
	CImageList	m_BigImageList;
	// ����Ʈ ��Ʈ�ѿ� ����� 16*16 ũ���� �̹��� ����Ʈ
	CImageList	m_SmallImageList;


// ��ȭ ���� ������
	//{{AFX_DATA(CDDListCtrlDemoDlg)
	enum { IDD = IDD_DDLISTCTRLDEMO_DIALOG };
	CDDListCtrl	m_TargetList;
	CDDListCtrl	m_AllList;
	int		m_nMode;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDDListCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CDDListCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnIconRadio();
	afx_msg void OnSmallIconRadio();
	afx_msg void OnListRadio();
	afx_msg void OnReportRadio();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
