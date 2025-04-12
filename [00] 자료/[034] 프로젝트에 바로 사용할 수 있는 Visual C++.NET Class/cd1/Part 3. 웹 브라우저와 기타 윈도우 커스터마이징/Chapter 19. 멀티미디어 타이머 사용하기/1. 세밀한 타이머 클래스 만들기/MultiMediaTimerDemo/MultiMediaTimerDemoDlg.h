// MultiMediaTimerDemoDlg.h : ��� ����
//

#pragma once


#include "MultiMediaTimer.h"


// CMultiMediaTimerDemoDlg ��ȭ ����
class CMultiMediaTimerDemoDlg : public CDialog
{
// ����
public:
	CMultiMediaTimerDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

	CMultiMediaTimer<CMultiMediaTimerDemoDlg>	m_Timer;

	void OnMMTimer(UINT uID);

// ��ȭ ���� ������
	//{{AFX_DATA(CMultiMediaTimerDemoDlg)
	enum { IDD = IDD_MULTIMEDIATIMERDEMO_DIALOG };
	CListBox	m_OnTimerList;
	int		m_nCount;
	int		m_nInterval;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CMultiMediaTimerDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CMultiMediaTimerDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartButton();
	afx_msg void OnStopButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
