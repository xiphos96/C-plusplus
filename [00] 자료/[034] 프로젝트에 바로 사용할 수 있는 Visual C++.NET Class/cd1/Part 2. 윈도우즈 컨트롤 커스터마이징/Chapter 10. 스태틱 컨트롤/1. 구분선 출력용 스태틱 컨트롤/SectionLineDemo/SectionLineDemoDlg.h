// SectionLineDemoDlg.h : ��� ����
//

#pragma once

// ���м� ����ƽ ��Ʈ�� ���
#include "SectionLine.h"


// CSectionLineDemoDlg ��ȭ ����
class CSectionLineDemoDlg : public CDialog
{
// ����
public:
	CSectionLineDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CSectionLineDemoDlg)
	enum { IDD = IDD_SECTIONLINEDEMO_DIALOG };
	CSectionLine	m_VertRight;
	CSectionLine	m_VertCenter;
	CSectionLine	m_VertLeft;
	CSectionLine	m_HorzRightDisable;
	CSectionLine	m_HorzCenterDisable;
	CSectionLine	m_HorzLeftDisable;
	CSectionLine	m_HorzRight;
	CSectionLine	m_HorzCenter;
	CSectionLine	m_HorzLeft;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CSectionLineDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CSectionLineDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
