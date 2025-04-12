// FilterEditDemoDlg.h : ��� ����
//

#pragma once

// ���� ����Ʈ Ŭ������ ��� ����
#include "FilterEdit.h"


// CFilterEditDemoDlg ��ȭ ����
class CFilterEditDemoDlg : public CDialog
{
// ����
public:
	CFilterEditDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CFilterEditDemoDlg)
	enum { IDD = IDD_FILTEREDITDEMO_DIALOG };
	CFilterEdit	m_FormatEdit;
	CFilterEdit	m_TimeEdit;
	CFilterEdit	m_DateEdit;
	CFilterEdit	m_CurrencyEdit;
	CFilterEdit	m_AlnumEdit;
	CFilterEdit	m_AlphaEdit;
	CFilterEdit	m_LowerCaseEdit;
	CFilterEdit	m_UpperCaseEdit;
	CFilterEdit	m_RealNumEdit;
	CFilterEdit	m_SignedNumEdit;
	CFilterEdit	m_NumberEdit;
	CFilterEdit	m_NoneEdit;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFilterEditDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CFilterEditDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
